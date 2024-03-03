// FILES.cpp: определяет точку входа для приложения.
//

#include "FILES2.h"



int main()
{
	double* arr = new double[100];

	for (int i = 0; i < 100; i++) {
		arr[i] = i;
	}
	std::cout << sizeof(arr) << std::endl;
	writeArray("../filename.data", arr, 100);
	MyArray<double> fileArray = readArray<double>("../filename.data");
	printFArray(fileArray);
	return 0;
}
