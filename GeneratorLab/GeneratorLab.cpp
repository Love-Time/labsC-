// FILES.cpp: определяет точку входа для приложения.
//

#include "GeneratorLab.h"
#include <chrono>



int main() {
	long long size = 100000;
	std::cout << size;
	int* arr = RandomArrayGenerator<int>(size);
	int NThread = 4;
	writeArray("myGeneratedArray.data", arr, size);
	MyArray<int> fileArray = readArray<int>("myGeneratedArray.data");
	//printFArray(fileArray);
	auto begin = std::chrono::steady_clock::now();
	long long mySum = getSum<long long>(fileArray.arr, size, NThread);
	long long myMax = getMax(fileArray.arr, size, NThread);
	long long myMin = getMin(fileArray.arr, size, NThread);
	std::cout << std::endl;
	std::cout << mySum << std::endl;
	std::cout << myMax << std::endl;
	std::cout << myMin << std::endl;

	auto end = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";
	return 0;
}
