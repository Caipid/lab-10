#include <fstream>
#include <iostream>
#include <string>
#include <clocale>
using namespace std;
//��� ������ ������� N. ����� ������ ��� ��������� �������, ����-��� ������ ������ ������� ������, 
// � ���������� ����� ���������. ������-��� ������ �������� � ������� �� �����������.
int user_number() {
	int a;
	string prom;
	cout << "������� ���������� ��������� �������:";
	getline(cin, prom);
	a = stoi(prom);
	return a;
}

void makefile(int userlen) {
	ofstream file("1.txt");
	string s;
	cout << "������� �������� �������:";
	getline(cin, s);
	file << userlen << endl;
	file << s;
}

int* crmassiv() {
	ifstream file("1.txt");
	string s;
	int usernum;
	file >> usernum;
	int i = 0;
	int* a = new int[usernum];
	while (i < usernum) {
		getline(file, s, ' ');
		a[i] = stoi(s);
		i++;
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	int i = user_number();
	int count = 0;
	makefile(i);
	int* a = crmassiv();
	for (int j = 0; j < i - 1; j++) {
		if (a[j] > a[j + 1]) {
			cout << "���������� �����:" << j+1 << endl;
			count++;
		}
	}
	cout << "���-�� �����: " << count;
}
