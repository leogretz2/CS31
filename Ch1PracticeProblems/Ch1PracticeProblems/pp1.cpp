#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	cout << "Input an integer, please!" << endl;
	int input;
	cin >> input;

	string out_string = std::to_string(input);
	int length = out_string.length();
	//cout << length << endl;

	int div = pow(10,(length - 1));
	int digit = input / div;
	//cout << div << endl;
	//cout << digit;
	int total = digit;
	input -= (digit * div);
	//cout << input;

	for (int i = 0; i < (length-1); i++) {
		div /= 10;
		//cout << div << endl;
		digit = input / div;
		total += digit;
		//cout << total << endl;
		input -= (digit * div);
		//cout << i << endl;
	}
	
	cout << "The sum of the digits in your number is: " << total << "!" << endl;
	cout << "Thank you for using my program!" << endl;

}