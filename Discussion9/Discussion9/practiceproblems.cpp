#include <iostream>
#include <string>


using namespace std;

class Person {
	public:
		Person();
		Person(int age, string catchprase);
		int getAge() const;
		void haveBirthday();
		void speak() const;
	private:
		int m_age;
		string m_catchphrase;
};

Person::Person() {
	m_age = 0;
	m_catchphrase = "";
}

Person::Person(int age, string catchphrase) {
	m_age = age;
	m_catchphrase = catchphrase;
}

int Person::getAge() const {
	return m_age;
}

void Person::haveBirthday() {
	m_age++;
}

void Person::speak() const {
	cout << m_catchphrase << endl;
}

int main() {
	Person p = { 45, "Hey what's crackalackin!" };
	int age = p.getAge();
	cout << p.getAge() << endl;
	p.haveBirthday();
	cout << p.getAge() << endl;
	p.speak();
}
