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


int main() 
{
	//generateTest0();
	//generateTest1();
	//generateTest2();
	//generateTest3();
	generateTest4();
	
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
	constexpr int SIZE = 1 << 10;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand();
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
	constexpr int SIZE = 1 << 15;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand();
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
	constexpr int SIZE = 1 << 20;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand();
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
	constexpr int SIZE = 1 << 23;
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
	outputFile.open("test5.in");
	constexpr int SIZE = 1 << 25;

	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i) {
		T[i] = rand();
	}
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	std::sort(T, T+SIZE);
	outputFile.open("solution5.out");
	writeToFile(T, SIZE, outputFile);
	outputFile.close();
	
	delete [] T;
	std::cout << "Test4 generated" << std::endl;	
}
