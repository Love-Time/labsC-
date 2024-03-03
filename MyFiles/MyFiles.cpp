// FILES.cpp: определяет точку входа для приложения.
//

#include "MyFiles.h"
#include <cstdio>
#include <iostream>

template<typename T>
struct MyArray {
	int size;
	T* arr;
}; 


template<typename T>
void writeArray(std::string filename, T* arr, long long size) {
	FILE* fp = fopen(filename.c_str(), "wb");
	size_t written = fwrite(&size, sizeof(long long), 1, fp);
	size_t written2 = fwrite(arr, sizeof(T), size, fp);
	fclose(fp);
}



template<typename T>
MyArray<T> readArray(std::string filename) {
	FILE* fp = fopen(filename.c_str(), "rb");
	MyArray<T> fileArray;
	long long size = 1;
	fread(&size, sizeof(long long), size, fp);
	std::cout<< std::endl<< "size " << size << " size";
	T* arr = new T[size];
	fread(arr, sizeof(T), size, fp);
	fclose(fp);
	fileArray.size = size;
	fileArray.arr = arr;
	return fileArray;
}

long long readFirstLong(FILE* fp) {
	long long size = 1;
	fread(&size, sizeof(long long), size, fp);
	return size;
}

void writeLong(FILE *fp, long long number){
	fwrite(&number, sizeof(long long), 1, fp);
}

template<typename T>
void writeArray(T* arr, int size, FILE* fp) {
	size_t written = fwrite(arr, sizeof(T), size, fp);
}


template<typename T>
void printFArray(MyArray<T> fArray) {
	for (int i = 0; i < fArray.size; i++) {
		std::cout << fArray.arr[i] << " ";
	}
}

template<typename T>
T* readSliseArray(FILE* fp, int size) {
	MyArray<T> fileArray;
	T* arr = new T[size];
	fread(arr, sizeof(T), size, fp);
	return arr;
}





