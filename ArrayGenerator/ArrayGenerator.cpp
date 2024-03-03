// FILES.cpp: определяет точку входа для приложения.
//

#include "ArrayGenerator.h"
#include <thread>

template<typename T>
T* RandomArrayGenerator(int size) {
	T* arr = new T[size];
	for (int i = 0; i < size; i++) {
		arr[i] = std::rand();
	}
	return arr;
}

template<typename T>
int getMaxInterval(T* arr, int start, int end) {
	if (start == end) {
		return arr[start];
	}

	T max = arr[start];
	for (int i = start+1; i < end; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}


template<typename T>
int getMinInterval(T* arr, int start, int end) {
	if (start == end) {
		return arr[start];
	}

	T min = arr[start];
	for (int i = start + 1; i < end; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

template<typename T1, typename T2>
T1 getSumInterval(T2 *arr, int start, int end) {
	T1 sum = 1;
	for (int i = start; i < end; i++) {
		sum =  sum + arr[i];
		
	}
	return sum;
}
int* getPointsForInterval(int size, int NThreads) {
	int interval = size / NThreads;

	int* points = new int[NThreads + 1];
	for (int i = 0; i < NThreads; i += 1) {
		points[i] = interval * i;
	}
	points[NThreads] = size;
	return points;
}
template<typename T1, typename T2>
T1 getSum(T2* arr, int size, int NThreads) {
	if (size == 0) {
		return 0;
	}
	if (NThreads < 1) {
		NThreads = 1;
	}

	int* points = getPointsForInterval(size, NThreads);
	T1* results = new T1[NThreads];

	std::thread *threads = new std::thread[NThreads];
	for (int i = 0; i < NThreads; i += 1) {
		threads[i] = std::thread([arr, &points, i, results]() {
			results[i] = getSumInterval<T1>(arr, points[i], points[i + 1]);
			});
	}
	for (int i = 0; i < NThreads; i += 1) {
		threads[i].join();
	}
	return getSumInterval<T1>(results, 0, NThreads);
}

template<typename T>
T getMin(T* arr, int size, int NThreads) {
	if (size == 0) {
		return 0;
	}
	if (NThreads < 1) {
		NThreads = 1;
	}

	int* points = getPointsForInterval(size, NThreads);
	T* results = new T[NThreads];
	std::thread* threads = new std::thread[NThreads];
	for (int i = 0; i < NThreads; i += 1) {
		threads[i] = std::thread([arr, &points, i, results]() {
			results[i] = getMinInterval(arr, points[i], points[i + 1]);
			});
	}
	for (int i = 0; i < NThreads; i += 1) {
		threads[i].join();
	}
	return getMinInterval(results, 0, NThreads);
}

template<typename T>
T getMax(T* arr, int size, int NThreads) {
	if (size == 0) {
		return 0;
	}
	if (NThreads < 1) {
		NThreads = 1;
	}

	int* points = getPointsForInterval(size, NThreads);
	T* results = new T[NThreads];
	std::thread* threads = new std::thread[NThreads];
	for (int i = 0; i < NThreads; i += 1) {
		threads[i] = std::thread([arr, &points, i, results]() {
			results[i] = getMaxInterval(arr, points[i], points[i + 1]);
			});
	}
	for (int i = 0; i < NThreads; i += 1) {
		threads[i].join();
	}
	return getMaxInterval(results, 0, NThreads);
}

template<typename T>
void doBigArray(std::string filename, long long size, int maxSizeArray) {
	FILE* fp = fopen(filename.c_str(), "wb");
	writeLong(fp, size);
	T* arr;
	int count = size / maxSizeArray + 1;
	long long tempSize = size;
	std::cout << count;
	for (int i = 0; i<count; i++) {
		arr = RandomArrayGenerator<T>(fmin(maxSizeArray, tempSize));
		writeArray(arr, fmin(maxSizeArray, tempSize), fp);
		tempSize -= maxSizeArray;
		delete arr;
	}
}



