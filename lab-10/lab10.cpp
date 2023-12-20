#include <fstream>
#include <iostream>
#include <string>
#include <clocale>
using namespace std;
//Дан массив размера N. Найти номера тех элементов массива, кото-рые больше своего правого соседа, 
// и количество таких элементов. Найден-ные номера выводить в порядке их возрастания.
int user_number() {
	int a;
	string prom;
	cout << "Введите количество элементов массива:";
	getline(cin, prom);
	a = stoi(prom);
	return a;
}

void makefile(int userlen) {
	ofstream file("1.txt");
	string s;
	cout << "Введите элементы массива:";
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
			cout << "порядковый номер:" << j+1 << endl;
			count++;
		}
	}
	cout << "кол-во чисел: " << count;
}
