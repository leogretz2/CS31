#include <iostream>
#include <string>
using namespace std;

int main() {

	double base_charge;
	double rental_charge = 0;

	//Asking for and taking in starting miles
	cout << "Odometer at start: ";
	int od_start;
	cin >> od_start;
	if (od_start < 0) {
		cout << "---" << endl;
		cout << "The starting odometer reading must be nonnegative." << endl;
		return 1;
	}
	

	//Asking for and taking in ending miles
	cout << "Odometer at end: ";
	int od_end;
	cin >> od_end;
	if (od_end < od_start) {
		cout << "---" << endl;
		cout << "The final odometer reading must be at least as large as the starting reading." << endl;
		return 1;
	}

	//Asking for and taking in rental days
	cout << "Rental days: ";
	int days;
	cin >> days;
	if (days <= 0) {
		cout << "---" << endl;
		cout << "The number of rental days must be positive." << endl;
		return 1;
	}
	cin.ignore(10000, '\n');

	//Asking for and taking in customer name
	cout << "Customer name: ";
	string cust_name;
	getline(cin, cust_name);
	if (cust_name == "") {
		cout << "---" << endl;
		cout << "You must enter a customer name." << endl;
		return 1;
	}

	//Asking for and taking in whether luxury or not
	cout << "Luxury car? (y/n): ";
	string lux;
	getline(cin, lux);
	if ((lux != "y") && (lux != "n")) {
		cout << "---" << endl;
		cout << "You must enter y or n." << endl;
		return 1;
	}

	//Asking for and taking in start month
	cout << "Month (1=Jan, 2=Feb, etc.): ";
	int month;
	cin >> month;
	if ((month > 12) || (month < 1)) {
		cout << "---" << endl;
		cout << "The month number must be in the range 1 through 12." << endl;
		return 1;
	}

	// Compute base charge
	if (lux == "y") {
		base_charge = 61 * days;
	} else {
		base_charge = 33 * days;
	}
	rental_charge += base_charge;

	// Calculate miles traveled
	int miles = od_end - od_start;

	// Compute rental charge
	if (miles > 100) {
		rental_charge += 27;
		if (miles > 400) {
			rental_charge += (miles - 400) * 0.19;
			if (month > 3 && month < 12) {
				rental_charge += 63;
			}
			else {
				rental_charge += 81;
			}
		}
		else if (month > 3 && month < 12) {
			rental_charge += (miles - 100) * 0.21;
		}
		else {
			rental_charge += (miles - 100) * 0.27;
		}
	} else {
		rental_charge += 0.27 * miles;
	}


	// Final statement
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "---" << endl;
	cout << "The rental charge for " << cust_name << " is $" << rental_charge << endl;
}