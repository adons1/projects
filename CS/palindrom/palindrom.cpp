#include <string>
#include <iostream>
#include <fstream>

using namespace std;
bool isPalindrom(string window) {
	int count = 0;
	for (int j = 0; j < window.length()/2; ++j) {
		if (window[j] == window[window.length() - 1 - j]) {
			count++;
		}
	}
	if (count == window.length() / 2) {

		return true;
	}
	else {
		return false;
	}
}
string least_palindrom = "";
void PalindromWindow(string str) {
	string window = "";

	int l = 0;
	int r = 2;
	bool leave = false;
	int window_length = 2;
	for (int i = 2; i <= 3/*str.length()*/; ++i) {

		if ((leave == true)&(window_length==(i-1))) {
			return;
		}

		for (int k = 0; k < str.length()-i+1; ++k) {
			for (int j = 0; j < i; ++j) {
				window = window + str[k + j];
			}
			//cout << "OKNO:" << window << endl;
			if (isPalindrom(window)) {
				if (least_palindrom.length() < 2) {

					least_palindrom = window;
					window_length = i;
					//cout << window_length << endl;
					leave = true;
				}
				else {
					if ((window).compare(least_palindrom)<0){
						//cout << window << endl;
						least_palindrom = window;
					}
				}

			}
			window = "";
		}

	}
}
int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	string text;

	fin >> text;
	PalindromWindow(text);
	if (least_palindrom.length() >= 2) {
		fout << least_palindrom << endl;

	}
	else {
		fout << -1 << endl;
	}
	fin.close();
	fout.close();
	system("pause");
    return 0;
}
