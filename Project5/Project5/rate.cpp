#define _CRT_SECURE_NO_WARNINGS

# include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>

using namespace std;

const int MAX_WORD_LENGTH = 20;
const int SPACES = 15;
const int MAX_DOC_LENGTH = 250;

// 	Checks if the words in a pattern are valid, fixes the patterns and returns the final number of 
//patterns
int makeProper(char word1[][MAX_WORD_LENGTH + 1],
	char word2[][MAX_WORD_LENGTH + 1],
	int separation[],
	int nPatterns);

// Returns the rating of a document based on the number of specified patterns it contains
int rate(const char document[],
	const char word1[][MAX_WORD_LENGTH + 1],
	const char word2[][MAX_WORD_LENGTH + 1],
	const int separation[],
	int nPatterns);

// Validates a word based on if it has alphabetical characters only, and switches it to lowercase
bool validateWord(char word[], int n);

// Shifts a double array of c strings up and effectively removes a specified string
void strRemove(char word[][MAX_WORD_LENGTH + 1], int i, int n);

// Shifts a array of characters up and effectively removes a specified character
void charRemove(char word[], int i, int n);

// Shifts a array of integers up and effectively removes a specified integer
void intRemove(int a[], int i, int n);

// Combines strRemove and intRemove to effectively remove a pattern
void patRemove(char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1],
	int separation[], int i, int n);

// Splits the individual words in a C string sentence and places them in a double array of chars 
// (an array of C strings) with a while loop inside a for loop
int splitWords(const char document[], char document2[][MAX_WORD_LENGTH + 1]);

// 	Loops through a double array that contains C strings and returns if a pattern is within a document
bool hasPattern(const char document2[][MAX_WORD_LENGTH + 1], const char word1[], const char word2[],
	int separator, int n);

// 	Loops backwards from a given point and returns if any elements match a given word
bool checkBack(const char document2[][MAX_WORD_LENGTH + 1], const char checkFor[], int start, int end);

// 	Loops forwards from a given point and returns if any elements match a given word
bool checkForw(const char document2[][MAX_WORD_LENGTH + 1], const char checkFor[], int start, int end);


int main() {
	/*char word1[5][MAX_WORD_LENGTH + 1] = { "ma-", "sa-", "bad", "dad", "had" };
	char word2[5][MAX_WORD_LENGTH + 1] = { "mar", "sar", "bar", "dar", "har" };
	int separation[5] = { 1, 2, 3, 4, 5 };*/

	/*const int length = 1;
	char word1[length][MAX_WORD_LENGTH + 1] = { "mad" };
	char word2[length][MAX_WORD_LENGTH + 1] = { "" };
	int separation[length] = { 1 };
	*/


	const int length = 8;
	char word1[length][MAX_WORD_LENGTH + 1] = { "mad", "deranged", "NEFARIOUS", "half-witted", "robot" , "plot", "have", "NeFaRiOuS"};
	char word2[length][MAX_WORD_LENGTH + 1] = { "scientist", "robot", "PLOT",  "assistant", "deranged", "Nefarious", "mad", "pLoT" };
	int separation[length] = { 1, 3, 0, 2, 1, 0, 12, 0};


	//printPatterns(word1, word2, separation, length);
	int mp = makeProper(word1, word2, separation, length);
	//printPatterns(word1, word2, separation, mp);

	char document[] = "The mad UCLA scientist unleashed a deranged evil giant robot.";
	assert(rate(document, word1, word2, separation, mp) == 2);
	char document2[] = "The mad UCLA scientist unleashed    a deranged robot.";
	assert(rate(document2, word1, word2, separation, mp)==2); 
	char document3[] = "**** 2018 * ***";	
	assert(rate(document3, word1, word2, separation, mp) == 0);
	char document4[] = "  That plot: NEFARIOUS!";
	assert(rate(document4, word1, word2, separation, mp) == 1);
	char document5[] = "deranged deranged robot deranged robot robot";
	assert(rate(document5, word1, word2, separation, mp) == 1);
	char document6[] = "That scientist said two mad scientists suffer from deranged-robot fever.";
	assert(rate(document6, word1, word2, separation, mp) == 0);
	char document7[] = "        ";
	assert(rate(document7, word1, word2, separation, mp) == 0);
	char document8[] = "Mad scientist mad     UCLA scientist unleashed a deranged evil giant robot.";
	assert(rate(document8, word1, word2, separation, mp) == 2);
	char document9[] = "Mad scientistasldfkjsadfk mad     UCLA scientist unleashed a deranged evil giant robot.";
	assert(rate(document9, word1, word2, separation, mp) == 2);
	cout << "All Test Cases Have Succeeded!" << endl;
}


int makeProper(char word1[][MAX_WORD_LENGTH + 1],
	char word2[][MAX_WORD_LENGTH + 1],
	int separation[],
	int nPatterns) {
	int length = nPatterns;
	for (int i = 0, j = 0; i < nPatterns; i++, j++) {
		bool isValidPat = validateWord(word1[j], strlen(word1[j]));
		bool isValidPat2 = validateWord(word2[j], strlen(word2[j]));
		if (!isValidPat) {
			// swap to back, decrement number of patterns and position
			patRemove(word1, word2, separation, j, nPatterns);
			j--;
			length--;
		}
		else {
			if (!isValidPat2) {
				// swap to back, decrement number of patterns and position
				patRemove(word1, word2, separation, j, nPatterns);
				j--;
				length--;
			}
			else {
				if (separation[j] < 0) {
					// swap to back, decrement number of patterns and position
					j--;
					length--;
				}
			}
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if ((strcmp(word1[i], word1[j]) == 0 && strcmp(word2[i], word2[j]) == 0) ||
			(strcmp(word1[i], word2[j]) == 0 && strcmp(word2[i], word1[j]) == 0)){
				if (separation[i] < separation[j]) {
					separation[i] = separation[j];	// use largest separator
				}
				patRemove(word1, word2, separation, j, nPatterns);		// swap repeated to back
				length--;
			}
		}
	}
	return length;
}

bool validateWord(char word[], int n) {
	if (n < 1) return false;  // If length = 0, invalid
	for (int i = 0; i < n; i++) {
		if (isalpha(word[i]) && n > 0) {
			if (isupper(word[i])) {
				word[i] = tolower(word[i]); // If alphabetical, then make lowercase
			}
		}
		else {
			return false;
		}
	}
	return true;
}

void strRemove(char word[][MAX_WORD_LENGTH + 1], int i, int n) {
	for (int j = i; j < n - 1; j++) {
		strcpy(word[j], word[j + 1]);  // Shift strings up from last 
	}
}

void charRemove(char word[], int i, int n) {
	for (int j = i; j < n - 1; j++) {
		word[j] = word[j + 1];		// Shift characters up from last 
	}
	word[n - 1] = '\0';				// Last element is null
}

void intRemove(int a[], int i, int n) {
	for (int j = i; j < n - 1; j++) {
		a[j] = a[j + 1];			// Shifts integers up from last
	}
}

void patRemove(char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1],
	int separation[], int i, int n) {
	strRemove(word1, i, n);
	strRemove(word2, i, n);
	intRemove(separation, i, n);
}

int splitWords(const char document[], char document2[][MAX_WORD_LENGTH + 1]) {
	int i, j, k;
	j = 0; 
	k = 0;
	for (i = 0; i <= (strlen(document)); i++) {
		// if space or null found, assign null into document2[k]
		if (document[i] == ' ' || document[i] == '\0') {
			document2[k][j] = '\0';
			k++;		//for next word
			j = 0;    //for next word, init index to 0
		}
		else {
			document2[k][j] = document[i];
			document2[k][j] = tolower(document2[k][j]);
			j++;
		}
	}
	const int K = k;
	for (int p = 0, t = 0; p < K; p++, t++) {
		if (strcmp(document2[t], "\0") == 0 || strcmp(document2[t], " ") == 0) {
			strRemove(document2, t, k);		// Remove spaces
			t--;
			k--;
		}
	}
	for (int p = 0, t = 0; p < K; p++, t++) {
		const int len = strlen(document2[t]);
		for (int h = 0, y = 0; h < len && h < MAX_WORD_LENGTH; h++, y++) {
			if (!isalpha(document2[t][y])) {
				charRemove(document2[t], y, (strlen(document2[t])));	// Remove non-alphabetical
				y--;
			}
		}
	}
	for (int p = 0; p < K; p++) {
		if (strlen(document2[p]) > MAX_WORD_LENGTH) {
			document2[p][MAX_WORD_LENGTH - 1] = '\0';
		}
	}
	return k;
}

bool checkBack(const char document2[][MAX_WORD_LENGTH + 1], const char checkFor[], int start, int end) {
	for (int j = start; j > end && j >= 0; j--) {
		if (strcmp(document2[j], checkFor) == 0) { // Compare backwards until separator
			return true;
		}
	}
	return false;
}

bool checkForw(const char document2[][MAX_WORD_LENGTH + 1], const char checkFor[], int start, int end) {
	for (int j = start; j < end && j < MAX_WORD_LENGTH; j++) {
		if (strcmp(document2[j], checkFor) == 0) { // Compare forwards until separator
			return true;
		}
	}
	return false;
}

bool hasPattern(const char document2[][MAX_WORD_LENGTH + 1], const char word1[], const char word2[],
	int separator, int n) {
	for (int i = 1; i < n - 1; i++) {
		if (strcmp(document2[i], word1) == 0) {
			if (checkBack(document2, word2, i - 1, i - separator - 2)) return true;
			if (checkForw(document2, word2, i + 1, i + separator + 2)) return true;
		}
		if (strcmp(document2[i], word2) == 0) {
			if (checkBack(document2, word1, i - 1, i - separator - 2)) return true;
			if (checkForw(document2, word1, i + 1, i + separator + 2)) return true;
		}
	}
	return false;
}

int rate(const char document[],
	const char word1[][MAX_WORD_LENGTH + 1],
	const char word2[][MAX_WORD_LENGTH + 1],
	const int separation[],
	int nPatterns) {
	int rate = 0;
	char document2[MAX_DOC_LENGTH][MAX_WORD_LENGTH + 1];
	int numWords = splitWords(document, document2);  // Split the sentence into words
	for (int i = 0; i < nPatterns; i++) {
		if (hasPattern(document2, word1[i], word2[i], separation[i], numWords)) {
			rate++;		// increment if pattern exists at least once
			continue;
		}
	}
	return rate;
}

