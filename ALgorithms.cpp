// ALgorithms.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  

using namespace std;


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
  
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}



void Open_Files(ifstream* fin , ofstream* fout) {
	string input = "INPUT.txt";
	(*fin).open(input);
	string output = "OUTPUT.txt";
	(*fout).open(output);
}
bool Binary_Search(int array[], int* sValue, int* l, int* r) {
	//cout << *sValue<<endl;


	/*for (int i = 0; i < 10; ++i) {
		cout << array[i] << endl;
	}
	//system("pause");*/
	int pivot = (*r + *l) / 2;
	//cout << *l << "\t" << pivot << "\t" << *r << endl;
	if ((*sValue == array[pivot])) {
		return true;
	}
	if (*l == *r) {
		return false;
	}
	if (*sValue < array[pivot]) {
		*r = pivot;
		return Binary_Search(array, sValue, l, r);
	}
	if (*sValue > array[pivot]) {
		*l = pivot+1;
		return Binary_Search(array, sValue, l, r);
	}
	
}

bool binarySearch(int arr[], int* l, int* r, int* x)
{
	if (*r >= *l) {
		int mid = *l + (*r - *l) / 2;

		if (arr[mid] == *x)
			return true;
 
		if (arr[mid] > *x) {
			*r = mid-1;
			return binarySearch(arr, l, r, x);
		}
			
		*l = mid + 1;
		return binarySearch(arr, l, r, x);
	}

	return false;
}


int main()
{
	
	ifstream fin;
	ofstream fout;
	Open_Files(&fin, &fout);

	int* random_numbers = new int[10];
	int value;

	

	int* buffer = new int;
	
	for (int i = 0; i < 10; ++i) {
		fin >> random_numbers[i];
		//cout << random_numbers[i]<< endl;
	}
	bubbleSort(random_numbers, 10);

	for (int i = 0; i < 10; ++i) {
		
		cout << random_numbers[i]<< endl;
	}

	int n;
	bool isPresents=false;
	int count = 0;

	int* l = new int;
	int* r = new int;

	*l = 0;
	*r = 9;

	fin >> n;
	for (int i = 0; i < n; ++i) {
		for (int i = 0; i < 6; ++i) {
			fin >> *buffer;
			isPresents = binarySearch(random_numbers, l, r, buffer);
			if (isPresents) {
				count++;
				isPresents = false;
			}
			*l = 0;
			*r = 9;
			//cout << *buffer << count << "\t";
		}

		if (count >= 3) {
			fout << "Lucky" << endl;
			cout << "Lucky" << endl;
		}
		else {
			fout << "Unlucky" << endl;
			cout << "Unlucky" << endl;
		}
		count = 0;


	}

	system("pause");
    return 0;
}

