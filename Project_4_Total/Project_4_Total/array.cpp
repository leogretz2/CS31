#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);


// Function to append a certain value to the end of a specified number of indexes in an array
int appendToAll(string a[], int n, string value) {
	if (n >= 0) {
		for (int i = 0; i < n; i++) {
			a[i] += value;
		}
	}
	else {
		return -1;
	}
	return n;
}

// Function that finds the position of a specified target string
int lookup(const string a[], int n, string target) {
	if (n >= 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] == target) {
				return i;
			}
		}
	}
	else {
		return -1;
	}
	return -1;
}

// Function that finds the position with the string with the largest characters
int positionOfMax(const string a[], int n) {
	if (n >= 0) {
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[max]) {
				max = i;
			}
		}
		return max;
	}
	else {
		return -1;
	}
	return -1;
}

// Function that rotates an array one place to the left after a specified position and puts the object 
// at the specified position at the end
int rotateLeft(string a[], int n, int pos) {
	if (n >= 0 && pos >= 0 && n > pos) {
		string rotatee = a[pos];
		int i = 0;
		while (pos + i + 1 < n) {
			a[pos + i] = a[pos + i + 1];
			i++;
		}
		a[n - 1] = rotatee;
		return pos;
	}
	else {
		return -1;
	}
	return -1;
}

// Functions that counts the number of distinct runs of objects in an array
int countRuns(const string a[], int n) {
	int runs = 0;
	if (n == 0) {
		return 0;
	}else if (n > 0) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] != a[i + 1]) {
				runs++;
			}
		}
		return runs + 1;
	}
	else {
		return -1;
	}
	return -1;
}

// Function that flips the element in the array
int flip(string a[], int n) {
	if (n >= 0) {
		for (int i = 0; i < n / 2; i++) {
			string temp = a[i];
			a[i] = a[n - 1 - i];
			a[n - 1 - i] = temp;
		}
		return n;
	}
	else {
		return -1;
	}
	return -1;
}

// Function that analyzes two arrays side by side and determines when they differ
int differ(const string a1[], int n1, const string a2[], int n2) {
	if (n1 >= 0 && n2 >= 0) {
		int len = 0;
		//int pos = 0;
		if (n2 >= n1) {
			len = n1;
		}
		else {
			len = n2;
		}
		int i = 0;
		while (i < len) {
			if (a1[i] == a2[i]) {
				i++;
			}
			else {
				return i;
			}
		}
		return len;
	}
	else {
		return -1;
	}
	return -1;
}

// Functions that determines if the second array is in the first array and returns the position where 
// the match starts
int subsequence(const string a1[], int n1, const string a2[], int n2) {
	if (n1 >= 0 && n2 >= 0) {
		for (int i = 0; i < n1; i++) {
			if (a1[i] == a2[0]) {
				int pos = i;
				if (pos >= 0 && pos <= (n1 - n2)) {
					int j = 1;
					while (j < n2) {
						if (a1[pos + j] == a2[j]) {
							j++;
						}
						else {
							break;
						}
					}
					if (j == n2) {
						return pos;
					}
				}
			}
		}
		return -1;
	}
	else {
		return -1;
	}
	return -1;
}

// Function that finds if any object of one array can be found in another and returns the position if found
int lookupAny(const string a1[], int n1, const string a2[], int n2) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (a1[i] == a2[j]) {
				return i;
			}
		}
	}
	return -1;
}

// Function that places objects less than a specified divider before all the others and objects greater than 
// a specified divider after all the others
int divide(string a[], int n, string divider) {
	if (n == 0) {
		return 0;
	}else if (n > 0) {
		/*int min;
		for (int i = 0; i < n; i++) {
			min = i;
			for (int j = i + 1; j < n; j++) {
				if (a[j] < a[min]) {
					min = j;
				}
			}
			string temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}*/	
		for (int i = 0; i < n; i++) {
			if (a[i] > divider) {
				rotateLeft(a, n, i);
				for (int j = i; j < n; j++) {
					if (a[j] <= divider) {
						i--;
						j = n - 1; 
					}
				}
			}
		}
		for (int k = 0; k < n; k++) {
			if (a[k] >= divider) {
				return k;
			}
		}
	}
	else {
		return -1;
	}
	return n;
}

int main() {
	string a[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string b[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string c[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Zarry", "Pairy", "Zarry" };
	string d[10] = { "Zzrry", "Perry", "Larry", "Gary", "Harry", "Zarry", "Pairy", "Zarry" };
	string e[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Carry", "Pairy", "Zarry" };
	string f[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Zarry", "Pairy", "Zarry" };
	string g[10] = { "Jerry", "Perry", "Lawrry", "Gary", "Harry", "Zarry", "Pairy", "Zarry" };
	string h[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Zarry", "Pairy", "Zarry" };
	string i[10] = { "Jerry", "Jerry", "Jerry", "Gary", "Harry", "Zarry", "Zarry", "Larry" };
	string ia[10] = { "Jerry", "Jerry", "Jerry", "Gary", "Harry", "Zarry", "Zarry", "Zarry" };
	string j[10] = { "Jerry", "Harry", "Jerry", "Gary", "Harry", "Zarry", "Zarry", "Larry" };
	string k[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string l[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry", "Larry" };
	string m[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string n[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry", "Larry" };
	string o[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string p[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string q[10] = { "Jerry", "Perry", "Jerwy", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string r[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string s[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string t[10] = { "Perry", "Larry", "Gary", "Gary", "Harry", "Jerry", "Perry", "Larry" };
	string u[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string v[10] = { "Hairy", "Pairy", "Carry", "Gary", "Harry", "Hairy", "Pairy", "Jerry" };
	string w[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string x[10] = { "Carry", "Pwrry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string y[10] = { "Jwrry", "Pwrry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string z[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string aa[10] = { "Jerry", "Larry", "Gary", "Cherry", "Larry", "Gary", "Harry", "Carry" };
	string ab[10] = { "Larry", "Gary", "Harry", "Gary", "Harry", "Hairy", "Pairy", "Carry" };
	string names[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
	string set1[10] = { "dianne", "betty", "greg", "gavin" };
	string set2[10] = { "xavier", "ed" };  
	string ac[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Zarry", "Pairy", "Zarry" };
	string ad[10] = { "Jwrry", "Pwrry", "Lwrry", "Gwry", "Hwrry", "Zwrry", "Pwiry", "Zwrry" };
	string ae[10] = { "Jerry", "Perry", "Larry", "Gary", "Harry", "Zarry", "Pairy", "Zarry" };
	string af[10] = { "Jwrry", "Pwrry", "Lwrry", "Gwry", "Hwrry", "Zwrry", "Pwiry", "Zarry" };
	string ag[10] = { "array", "zrray", "crray", "wrray", "orray", "zrray" };
	string ah[10] = { "zrray", "zrray", "zrray", "zrray", "zrray", "zrray" };
	string ai[10] = { "zrray", "zrray", "zrray", "array", "zrray" };
	string candidate[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
	string candidate2[4] = { "gavin", "kevin", "fiona", "john" };
	string lastTest[7] = { "G", "G", "E", "X", "A", "E", "F" };

	assert(appendToAll(a, 3, "!!!") == 3 && a[0] == "Jerry!!!" && a[2] == "Larry!!!");
	assert(appendToAll(a, 0, "!!!") == 0);
	assert(appendToAll(a, -1, "!!!") == -1);

	assert(lookup(b, 7, "Pairy") == 6);
	assert(lookup(b, 7, "Larry") == 2);
	assert(lookup(b, 7, "Jerry") == 0);
	assert(lookup(b, 2, "Larry") == -1);
	assert(lookup(b, 0, "Larry") == -1);
	assert(lookup(b, -1, "Larry") == -1);

	assert(positionOfMax(c, 8) == 5);
	assert(positionOfMax(d, 8) == 0);
	assert(positionOfMax(e, 8) == 7);
	assert(positionOfMax(f, 0) == 0);
	assert(positionOfMax(g, -1) == -1);

	assert(rotateLeft(h, 8, 4) == 4 && h[1] == "Perry" && h[5] == "Pairy" && h[7] == "Harry");
	assert(rotateLeft(h, 8, 0) == 0 && h[0] == "Perry" && h[5] == "Zarry" && h[7] == "Jerry");
	assert(rotateLeft(h, 8, 7) == 7 && h[0] == "Perry" && h[5] == "Zarry" && h[7] == "Jerry");
	assert(rotateLeft(h, 0, 0) == -1);

	assert(countRuns(i, 8) == 5);
	assert(countRuns(i, 0) == 0);
	assert(countRuns(i, 7) == 4);
	assert(countRuns(j, 1) == 1);
	assert(countRuns(ia, 8) == 4);

	assert(flip(k, 8) == 8 && k[0] == "Carry" && k[7] == "Jerry");
	assert(flip(l, 9) == 9 && l[0] == "Larry" && l[8] == "Jerry");
	assert(flip(l, 2) == 2 && l[0] == "Carry" && l[1] == "Larry");

	assert(differ(m, 8, n, 9) == 8);
	assert(differ(o, 2, p, 1) == 1);
	assert(differ(q, 8, r, 8) == 2);
	assert(differ(q, 0, r, 1) == 0);

	assert(subsequence(s, 8, t, 3) == 1);
	assert(subsequence(u, 8, v, 3) == 5);
	assert(subsequence(w, 8, x, 1) == 7);
	assert(subsequence(y, 8, z, 2) == -1);
	assert(subsequence(aa, 8, ab, 3) == 4);

	assert(lookupAny(names, 6, set1, 4) == 1);
	assert(lookupAny(names, 6, set2, 2) == -1);
	assert(lookupAny(ac, 8, ad, 8) == -1);
	assert(lookupAny(ae, 8, af, 8) == 5);

	assert(divide(ag, 6, "orray") == 2); //&& ag[1] == "crray" && ag[2] == "orray" && ag[5] == "zrray");
	assert(divide(ah, 6, "orray") == 0);
	assert(divide(ai, 5, "orray") == 1); //&& ag[0] == "array" && ag[4] == "zrray");
	assert(divide(candidate, 6, "eleni") == 3);
	assert(divide(candidate2, 4, "john") == 2);

	cout << "All Tests Have Succeeded!" << endl;
}


		
