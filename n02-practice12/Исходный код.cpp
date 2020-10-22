#include <iostream>
#include <iomanip>
#include <cmath>
#include<string>
#include <fstream>
#include<vector>
using namespace std;
struct bank_account{
	int num;
	string name;
	string surname;
	string second_name;
	string address;
};
vector<bank_account>bk;
void print_data(bank_account a){
	cout << "Number : " << a.num << " Name : " << a.name << " Surname : " << a.surname << " Second Name : " << a.second_name << " Address : " << a.address << endl;
}
void read_data_from_file(){
	bank_account temp;
	ifstream in("hello.txt");

	while (!in.eof()) {
		in >> temp.num >> temp.name >> temp.surname >> temp.second_name >> temp.address;
		bk.push_back(temp);
	}
}
void read_data_from_binary_file(){
	ifstream fin("output.txt", istream::binary);
	bank_account temp;
	int size = bk.size();	
	for (int i = 0; i < size; i++){
		fin.read((char*)&bk.at(i), sizeof(bank_account));
	}
	fin.close();
}

void write_data_to_binary()
{
	bank_account temp;
	ofstream fout("output.txt", ostream::binary);
	for (int i = 0; i <bk.size(); ++i)
	{
		fout.write((char*)&bk.at(i), sizeof(bank_account));
	}
	fout.close();
}
void find(){
	int a;
	cout << "input number of account, which you want to find : ";
	cin >> a;	
	for (int i = 0; i < bk.size(); i++){
		if (bk[i].num == a){
			print_data(bk[i]);
		}
	}
}
void change(){
	int a;
	string b;
	cout << "input number of account, which you want to change : ";
	cin >> a;
	cout << "Input new surname : ";
	cin >> b;
	read_data_from_binary_file();
	for (int i = 0; i < bk.size(); i++){
		if (bk[i].num == a){
			bk[i].surname = b;
		}
	}
	write_data_to_binary();
}
void deletik(){
	int a;
	cout << "input number of account, which you want to delete : ";
	cin >> a;
	read_data_from_binary_file();
	for (int i = 0; i < bk.size(); i++){
		if (bk[i].num == a){
			bk.erase(bk.begin() + i);
		}
	}
	write_data_to_binary();
}
void print_all_data(){
	for (int i = 0; i < bk.size(); i++){
		print_data(bk[i]);
	}
}
int main(){
	string line;
	read_data_from_file();
	write_data_to_binary();
	read_data_from_binary_file();
	print_all_data();
	find();
	change();
	print_all_data();
	deletik();	
	print_all_data();
}


