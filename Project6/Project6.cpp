# include <iostream>

using namespace std;

//Question 1

//Part A

//int main()
//{
//	int arr[3] = { 5, 10, 15 };
//	int* ptr = arr;
//
//	*ptr = 10;          // set arr[0] to 10. Switch assignments around so they work with the while loop
//	*(ptr + 1) = 20;      // set arr[1] to 20. Need (ptr + 1) in parantheses, otherwise adding one to the value
//	ptr += 2;
//	*ptr = 30;			// set arr[2] to 30. If incrementing by two in previous line, need * operator
//
//	while (ptr >= arr)
//	{
//		cout << *ptr << endl;    // print values 
//		ptr--;					// Switch decrement to after print statement
//	}
//}

//Part B

void findmax(int arr[], int n, int*& ptomax)
{
	if (n <= 0)
		return;      // no items, no maximum!

	ptomax = arr;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > *ptomax)
			ptomax = arr + i;
	}
}

int main()
{
	int nums[4] = { 5, 3, 15, 6 };
	int* ptr;

	findmax(nums, 4, ptr);
	cout << "the maximum is at address " << ptr << endl;
	cout << "it's at position " << ptr - nums << endl;
	cout << "its value is " << *ptr << endl;
}

// Part C

//void computeCube(int n, int* ncubed)
//{
//	*ncubed = n * n * n;
//}
//
//int main()
//{
//	int* ptr = new int();
//	computeCube(5, ptr);
//	cout << "Five cubed is " << *ptr << endl;
//}

// Part D

   // return true if two C strings are equal
//bool strequal(const char str1[], const char str2[])
//{
//	if (strlen(str1) != strlen(str2))
//		return false;
//	while (*str1 != 0 && *str2 != 0)
//	{
//		if (*str1 != *str2)  // compare corresponding characters
//			return false;
//		str1++;            // advance to the next character
//		str2++;
//	}
//	return *str1 == *str2;   // both ended at same time
//}
//
//int main()
//{
//	char a[15] = "Zhou";
//	char b[15] = "Zou";
//
//	if (strequal(a, b))
//		cout << "They're the same person!\n";
//	else
//		cout << "NO\n"; 
//}


// Part E

//int* nochange(int* p)
//{
//	return p;
//}
//
//int* getPtrToArray(int& m)
//{
//	int anArray[100];
//	for (int j = 0; j < 100; j++)
//		anArray[j] = 100 - j;
//	m = 100;
//	return nochange(anArray);
//	//return anArray;
//}
//
//void f()
//{
//	int junk[100];
//	for (int k = 0; k < 100; k++)
//		junk[k] = 123400000 + k;
//	junk[50]++;
//}
//
//int main()
//{
//	int n;
//	int* ptr = getPtrToArray(n);
//	cout << ptr[0] << endl;
//	cout << ptr[0] << endl;
//
//	//f();
//	for (int i = 0; i < 3; i++) {
//		cout << ptr[i] << ' ';
//	}
//	for (int i = n - 3; i < n; i++)
//		cout << ptr[i] << ' ';
//	cout << endl;
//}

// Question 2

//int main() {
//	double* cat;
//	double mouse[5];
//	cat = &mouse[4];
//	*cat = 25;
//	*(mouse + 3) = 42;
//	cat -= 3;
//	cat[1] = 27;
//	cat[0] = 54;
//	bool b = (*cat == *(cat + 1));
//	bool d = (cat == mouse);
//}

// Question 3

// Part A

//Rewrite the following function so that it returns the same result, but does not increment the variable
//ptr. Your new program must not use any square brackets, but must use an integer variable to visit each
//double in the array. You may eliminate any unneeded variable.
//double mean(const double* scores, int numScores)
//{
//	double tot = 0;
//	int i = 0;
//	while (i < numScores)
//	{
//		tot += *(scores + i);
//		i++;
//	}
//	return tot / numScores;
//}
//
//int main() {
//	double scores[5] = { 5.0,6.2,7.65,8.265,9.45 };
//	cout << mean(scores, 5) << endl;
//}

// Part B

//Rewrite the following function so that it does not use any square brackets(not even in the parameter
//declarations) but does use the integer variable k.Do not use any of the <cstring> functions such as 
//strlen, strcpy, etc.

// This function searches through str for the character chr.
// If the chr is found, it returns a pointer into str where
// the character was first found, otherwise nullptr (not found).

//const char* findTheChar(const char* str, char chr)
//{
//	for (int k = 0; *(str + k) != 0; k++)
//		if (*(str + k) == chr)
//			return (str + k);
//
//	return nullptr;
//}
//
//int main() {
//	char str[] = "Zhoursdf";
//	char chr = 'o';
//	cout << *(findTheChar(str, chr)) << endl;
//}

// Part C

//const char* findTheChar(const char* str, char chr)
//{
//	while (*str != 0) {
//		if (*str == chr)
//			return str;
//		str++;
//	}
//	return nullptr;
//}
//
//int main() {
//	char str[] = "Zhoursdf";
//	char chr = 'o';
//	cout << (findTheChar(str, chr)) << " " << &str[2] << endl;
//}

// Question 4

//int* maxwell(int* a, int* b)
//{
//	if (*a > *b)
//		return a;
//	else
//		return b;
//}
//
//void swap1(int* a, int* b)
//{
//	int* temp = a;
//	a = b;
//	b = temp;
//}
//
//void swap2(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main()
//{
//	int array[6] = { 5, 3, 4, 17, 22, 19 };
//
//	int* ptr = maxwell(array, &array[2]);  // Points to index 0 of array because maxwell chooses the greater of the two inputted pointer values
//	*ptr = -1;		// Sets index 0 of the array to -1
//	ptr += 2;		// Moves the pointer up to index 2 of array
//	ptr[1] = 9;		// Sets index 3 of array to 9 (because ptr[1] adds 1 to where ptr points to)
//	*(array + 1) = 79;	// Sets index 1 of array to 79 because 'array' points to index 0, and '+1' adds 1
//
//	cout << &array[5] - ptr << endl;	// ptr is currently pointing to index 2 and the difference between the pointer to index 5 and the pointer to index 2 is essentially the distance between the two: 3. This line prints "3" and enters. 
//
//	swap1(&array[0], &array[1]);		// The swap1 function swaps the memory addresses of two pointers and returns nothing, so the call to this function doesn't have any effect on the array. 
//	swap2(array, &array[2]);			// The swap2 function swaps the values of two pointers, which ends of swapping the two values in the array. Swapping index 0 and index 2 of array makes array now 4 79 -1 9 22 19
//
//	for (int i = 0; i < 6; i++)
//		cout << array[i] << endl;		// This for loop cycles through array and prints every value, so this line prints the values of array, each on a new line: 4 79 -1 9 22 19
//}

// Question 5

//void removeS(char* str) {
//	while (*str != 0) {
//		if (*str == 's' || *str == 'S') {
//			char* ptr = str;
//			while (*ptr != 0) {
//				*ptr = *(ptr + 1);
//				ptr++;
//			}
//		}
//		else {
//			str++;
//		}
//	}
//}
//
//int main() {
//	char msg[50] = "She'll be a massless princess.";
//	removeS(msg);
//	cout << msg;  // prints    he'll be a male prince.
//}