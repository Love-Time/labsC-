// FILES.cpp: определяет точку входа для приложения.
//

#include "BigArrayGenerator.h"

int main() {
	long long size_vector = 10000000000L;
	//doBigArray<int>("vector2.data", size_vector, 1000000);
	long long result = scalar<int>("vector1.data", "vector2.data", 10000000);


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << result;

}



