#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

bool isSubset(int a1[], int n1, int a2[], int n2) {
	if (n2 == 0) {
		return true;
	}
	bool equals;
	for (int i = 0; i < n2; i++) {
		equals = false;
		for (int j = 0; j < n1; j++) {
			if (a2[i] == a1[j]) {
				equals = true;
				break;
			}
			if (!equals) {
				return false;
			}
		}
	}
	return equals; 
}

void strcat(char str1[], char str2[]) {
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	for (int i = n1; i < n1 + n2; i++) {
		str1[i] = str2[i - n1];
	}
}


void eraseDuplicates(char str[]) {
	char temp[20] = "";
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		int val = 1;
		for (int j = i+1; j < n; j++) {
			if (str[i] == str[j]) {
				//val++;
				char tempo = str[n-1];
				str[n-1] = str[i];
				str[i] = tempo;
			}
		}
		if (val < 3) {
			temp[i] = str[i];
		}
	}
	strcpy(str, temp);
}


bool balanceParens(char str[]) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			count++;
		}
		if (str[i] == ')') {
			count--;
			if (count < 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	/*int n1 = 3;
	int n2 = 2;
	int a1[2] = { 20, 30 };
	int a2[3] = { 20, 30, 40 };
	cout << isSubset(a1, n1, a2, n2) << endl;

	char str1[20] = "Hello";
	char str2[8] = " World";
	strcat(str1, str2);
	cout << str1 << endl;*/

	char str3[8] = "memes";
	eraseDuplicates(str3);
	cout << str3 << endl;

	/*char str4[10] = "())(()";
	cout << balanceParens(str4) << endl;*/

	
}