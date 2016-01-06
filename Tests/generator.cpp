#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;

void generateTest0();
void generateTest1();
void generateTest2();
void generateTest3();
void generateTest4();
void generateTest5();
void generateTest6();
void generateTest7();
void generateTest8();
void generateTest9();
void generateTest10();
void generateTest11();
void generateTest12();

int main() 
{
	generateTest0();
	generateTest1();
	generateTest2();
	generateTest3();
	generateTest4();
	generateTest5();
	generateTest6();
	generateTest7();
	generateTest8();
	generateTest9();
	//generateTest10();
	//generateTest11();
	//generateTest12();
	
	return 0;
}

void writeToFile(int* T, const long long size, ofstream & file) {
	file << size << std::endl;
	for (long long i=0; i<size; ++i) {
		file << T[i];
		if (i %10 == 9)
			file << std::endl;
		else if (i == size-1)
			file << std::endl;
		else
			file << " ";
	}
}

void generateTest0() {
	ofstream outputFile;
	outputFile.open("test0.in");
	constexpr int SIZE = 10;
	constexpr int MAX_VALUE = 25;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution0.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test0 generated" << std::endl;
}

void generateTest1() {
	ofstream outputFile;
	outputFile.open("test1.in");
	constexpr int SIZE = 50;
	constexpr int MAX_VALUE = 2500;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution1.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test1 generated" << std::endl;
}

void generateTest2() {
	ofstream outputFile;
	outputFile.open("test2.in");
	constexpr int SIZE = 250;
	constexpr int MAX_VALUE = 25000;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution2.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test2 generated" << std::endl;
}

void generateTest3() {
	ofstream outputFile;
	outputFile.open("test3.in");
	constexpr int SIZE = 1000;
	constexpr int MAX_VALUE = 100000;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution3.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test3 generated" << std::endl;
}

void generateTest4() {
	ofstream outputFile;
	outputFile.open("test4.in");
	constexpr int SIZE = 5000;
	constexpr int MAX_VALUE = 500000;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution4.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test4 generated" << std::endl;	
}

void generateTest5() {
	ofstream outputFile;
	outputFile.open("test5.in");
	constexpr int SIZE = 50000;
	constexpr int MAX_VALUE = 8000000;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution5.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test5 generated" << std::endl;
}

void generateTest6() {
	ofstream outputFile;
	outputFile.open("test6.in");
	constexpr int SIZE = 250000;
	constexpr int MAX_VALUE = 100000000;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution6.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test6 generated" << std::endl;
}

void generateTest7() {
	ofstream outputFile;
	outputFile.open("test7.in");
	constexpr int SIZE = 2000000;
	constexpr int MAX_VALUE = INT_MAX;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution7.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test7 generated" << std::endl;
}

void generateTest8() {
	ofstream outputFile;
	outputFile.open("test8.in");
	constexpr int SIZE = 10000000;
	constexpr int MAX_VALUE = INT_MAX;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution8.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test8 generated" << std::endl;
}

void generateTest9() {
	ofstream outputFile;
	outputFile.open("test9.in");
	constexpr int SIZE = 100000000; // 10^8
	constexpr int MAX_VALUE = INT_MAX;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	std::cout << "Numbers generated" << std::endl;
	
	std::sort(T, T+SIZE);
	std::cout << "Numbers sorted" << std::endl;
	outputFile.open("solution9.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test9 generated" << std::endl;
}

void generateTest10() {
	ofstream outputFile;
	outputFile.open("test10.in");
	constexpr long long SIZE = 5000000000; // 5*10^9
	constexpr int MAX_VALUE = INT_MAX;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (long long i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution10.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test10 generated" << std::endl;
}

void generateTest11() {
	ofstream outputFile;
	outputFile.open("test11.in");
	constexpr long long SIZE = 50000000000; // 50 * 10^9
	constexpr int MAX_VALUE = INT_MAX;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (long long i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution11.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test11 generated" << std::endl;
}

void generateTest12() {
	ofstream outputFile;
	outputFile.open("test12.in");
	constexpr long long SIZE = 200000000000; // 200 * 10^9
	constexpr int MAX_VALUE = INT_MAX;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (long long i=0; i<SIZE; ++i) {
		T[i] = rand() % MAX_VALUE;
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution12.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test12 generated" << std::endl;
}
