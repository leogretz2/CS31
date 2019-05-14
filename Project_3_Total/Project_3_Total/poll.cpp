#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

bool isValidUppercaseStateCode(string stateCode);
bool hasProperSyntax(string pollData);
int tallySeats(string pollData, char party, int& seatTally);
bool isValidStateForecast(string pollData);

// Return true if the argument is a two-uppercase-letter state code, or false otherwise.
bool isValidUppercaseStateCode(string stateCode) {
	const string codes =
		"AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
		"LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
		"OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
	return (stateCode.size() == 2 &&
		stateCode.find('.') == string::npos  &&  // no '.' in stateCode
		codes.find(stateCode) != string::npos);  // match found
}

// Determines if the inputed state forecast string is valid according to the given definition
bool isValidStateForecast(string pollData) {
	int n = pollData.size();
	if (pollData == "") {
		return true;		// Empty string is valid
	}
	if (n > 1) {
		string state_code = pollData.substr(0, 2);
		if (isalpha(state_code[0]) && isalpha(state_code[1])) {
			state_code[0] = toupper(state_code[0]);
			state_code[1] = toupper(state_code[1]);
		}
		if (isValidUppercaseStateCode(state_code)) {	// Validates State Code (with uppercase letters)
			if (n == 2) {
				return true;							// Just the state code is valid
			}
			int i = 2;
			while (i < n) {								// While loop for every combination of digits and party code
				if (isdigit(pollData[i]) && n != (3 + (i - 2))) {	 // Continues if character is a digit and it's not the end of the string
					i++;												
					if (isalpha(pollData[i]) && n == (4 + (i - 3))) {	// Valid if the order is state code digit then party
						return true;
					}
					else if (isalpha(pollData[i]) && n != (4 + (i - 2))) {	// Continues if there is one digit, one party code and it's not the end of the string
						i++;
					}
					else if (isdigit(pollData[i]) && n != (4 + (i - 3))) {	// Continues if there are two digits in a row and it's not the end of the string
						i++;
						if (isalpha(pollData[i])) {							// Valid if the next character is a letter
							if (n == (5 + (i - 4))) {						// Valid if the string ends here
								return true;
							}
							else {											// Continues if it is not the end of the string
								i++;
							}
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return true;
}

// Determines if the inputed poll data string, consisting of zero, one, or multiple state forecasts, 
//is valid according to the given definition
bool hasProperSyntax(string pollData) {
	int n = pollData.size();
	int numForecasts = 0;
	if (pollData == "") {					// Valid if the string is empty
		return true;
	}
	if (n > 0 && pollData[n-1] != ',') {	// Continues if there is one or more state forecasts and if the last character is not a comma
		numForecasts = 1;
		for (int i = 0; i < n; i++) {		// Counts number of state forecasts based on number of commas
			if (pollData[i] == ',') {
				numForecasts++;
			}
		}
		int j = 0;
		int k = 0;
		while (j < numForecasts - 1) {		// Cycles through and assesses each state forecast
			string temp = "";
			while (pollData[k] != ',') {	// Creates individual state forecasts (except for the last one) with a temporary string
				temp += pollData[k];
				k++;
			}
			k++;
			if (isValidStateForecast(temp)) {
				j++;
			}
			else {
				return false;
			}
		}
		string temp2 = "";
		while (k < n) {						// Creates and assesses the last state forecast
			temp2 += pollData[k];
			k++;
		}
		if (isValidStateForecast(temp2)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return true;
}


// Tallys the number of seats in a string of poll data for one political party
int tallySeats(string pollData, char party, int& seatTally) {	
	if (!hasProperSyntax(pollData)) {								// returns 1 if the poll data string syntax is incorrect
		return 1;		
	} else if (!isalpha(party)) {											// returns 2 if the party code is not a letter
		return 2;
	}
	else {
		seatTally = 0;
		for (int i = 0; i < pollData.size(); i++) {
			if (pollData[i] == tolower(party) || pollData[i] == toupper(party)) {
				seatTally += (pollData[i - 1] - '0');				// Adds the integer before the indicated party code to seatTally
				if (isdigit(pollData[i - 2])) {
					seatTally += ((pollData[i - 2] - '0') * 10);	// Adds the integer two indexes before the indicated party code to seatTally (if it exists)
				}
			}
		}
		return 0;
	}
	
}

int main() {
	assert(hasProperSyntax(""));
	assert(!hasProperSyntax("2"));
	assert(hasProperSyntax("ny"));
	assert(hasProperSyntax("ny3d"));
	assert(!hasProperSyntax("ny2"));
	assert(hasProperSyntax("ny3r4d"));
	assert(hasProperSyntax("ny3r34f,ga34f6d,ct6y5t,az5g66h"));
	assert(hasProperSyntax("ny33r34f54r23f67j4h88j3f1d,ga34f6d,ct6y5t,az5g66h"));
	assert(hasProperSyntax("ny33r4f,ga34f6d,ct6y5t,az5g66h"));
	assert(hasProperSyntax("ny3r4f,ga34f6d,ct6y5t,az5g66h"));
	assert(!hasProperSyntax("ny3r4,ga34f6d,ct6y5t,az5g66h"));
	assert(!hasProperSyntax("ny3r4d,ga34f6d,ct6y5t,az5g66h,"));
	assert(hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D"));
	assert(!hasProperSyntax("ZT5D,NY9R17D1I,VT,ne3r00D"));
	int seats;
	seats = -999;    // so we can detect whether tallySeats sets seats
	assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", 'd', seats) == 0 && seats == 22);
	seats = -999;    // so we can detect whether tallySeats sets seats
	assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", '%', seats) == 2 && seats == -999);
	assert(tallySeats("", 'd', seats) == 0 && seats == 0);
	seats = -999;
	assert(tallySeats("2", 'd', seats) == 1 && seats == -999);
	assert(tallySeats("ny", 'd', seats) == 0 && seats == 0);
	assert(tallySeats("ny3r4d", 'd', seats) == 0 & seats == 4);
	assert(tallySeats("ny3r34f,ga34f6d,ct6y5t,az5g66f", 'f', seats) == 0 && seats == 134);
	assert(tallySeats("ny33r34f54r23f67j4h88j3f1d,ga34f6d,ct6y5t,az5g66h", 'j', seats) == 0 && seats == 155);
	assert(tallySeats("ny33r4f,ga34f6d,ct6y5t,az5g66h", 'f', seats) == 0 && seats == 38);
	assert(tallySeats("ny3r4f,ga34f6h,ct6y5t,az5g66h", 'h', seats) == 0 && seats == 72);
	seats = -999;
	assert(tallySeats("ny3y4,ga34f6d,ct6y5t,az5g66h", 'd', seats) == 1 && seats == -999);
	seats = -999;
	assert(tallySeats("ny3r4d,ga34f6d,ct6y5t,az5g66h,", 'd', seats) == 1 && seats == -999);
	seats = -999;
	assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", '*', seats) == 2 && seats == -999);
	seats = -999;
	assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", '0', seats) == 2 && seats == -999);
	cout << "All tests succeeded" << endl;
}