#include  <iostream>
#include <string>
using namespace std;

int main() {
	/*//Question 1
	string grendel = "endl";
	cout << "endl";
	cout << grendel;
	cout << endl;
	cout << "grendel";

	cout << endl;

	//Question 2
	int side;

	cout << "Enter a number: ";
	cin >> side;

	for (int i = 0; i < side; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			cout << "#";
		}
		cout << "\n";
	}

	// Question 3
	int side;

	cout << "Enter a number: ";
	cin >> side;

	for (int i = 0; i < side; i++)
	{
		int j = i;
		while (j >= 0)
		{
			cout << "#";
			j--;
		}
		cout << "\n";
	}

	// Question 4
	int side;

	cout << "Enter a number: ";
	cin >> side;

	if (side > 0) {

		int i = 0;
		do
		{
			int j = i;
			while (j >= 0)
			{
				cout << "#";
				j--;
			}
			cout << "\n";
			i++;
		} while (i < side);
	}

	//Question 5
	int codeSection;
	for (int i = 0; i < 6; i++) {
		cout << "Insert code section." << endl;
		cin >> codeSection;
		if (codeSection == 281)
			cout << "bigamy" << endl;
		else if (codeSection == 321 || codeSection == 322)
			cout << "selling illegal lottery tickets" << endl;
		else if (codeSection == 383)
			cout << "selling rancid butter" << endl;
		else if (codeSection == 598)
			cout << "injuring a bird in a public cemetery" << endl;
		else
			cout << "some other crime" << endl;
	}

	int codeSection2;
	for (int i = 0; i < 6; i++) {
		cout << "Insert code section." << endl;
		cin >> codeSection2;
		switch (codeSection2)
		{
		case 281:
			cout << "bigamy" << endl;
			break;
		case 321:
		case 322:
			cout << "selling illegal lottery tickets" << endl;
			break;
		case 383:
			cout << "selling rancid butter" << endl;
			break;
		case 598:
			cout << "injuring a bird in a public cemetery" << endl;
			break;
		default:
			cout << "some other crime" << endl;
		}
	}*/

	cout << "insert" << endl;
	int codeSection;
	cin >> codeSection;

	if (codeSection == 281)
		cout << "bigamy";
	else if (codeSection == 321 || codeSection == 322)
		cout << "selling illegal lottery tickets";
	else if (codeSection == 383)
		cout << "selling rancid butter";
	else if (codeSection == 598)
		cout << "injuring a bird in a public cemetery";
	else
		cout << "some other crime";

	/*switch (codeSection)
	{
	case 281:
		cout << "bigamy";
		break;
	case 321:
	case 322:
		cout << "selling illegal lottery tickets";
		break;
	case 383:
		cout << "selling rancid butter";
		break;
	case 598:
		cout << "injuring a bird in a public cemetery";
		break;
	default:
		cout << "some other crime";
	}*/
}