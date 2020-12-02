
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <clocale>
#include <Windows.h>
#include <map>
#include<iomanip>
#include <queue>
using namespace std;
int multiplyOrder(vector<int>r) {
	int n = r.size() - 1;
	cout << n;
	int a[6][6];
	for (int i = 0; i < n; ++i) {
		a[i][i] = 0;
	}
	for (int l = 1; l < n; ++l) {
		for (int i = 0; i < n - l; ++i) {
			int j = i + l;
			a[i][j] = 100000;
			for (int k = i; k < j; ++k) {
				a[i][j] = min(a[i][j],
					a[i][k] + a[k + 1][j] + r[i] * r[k + 1] * r[j + 1]);
			}
		}
	}
	return a[0][n - 1];

}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<int>r = {
		5, 10, 3, 12, 5, 50, 6
	};
	cout << "Минимальное колличество скалярных умножений: " << multiplyOrder(r) << endl;
	cout << "Эмпирическая оценка сложности алгоритма: О(n^3)" << endl;
	system("pause");
	return 0;
}
