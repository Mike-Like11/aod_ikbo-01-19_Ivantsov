
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
/*
struct Bukva {//структура буквы в строке
	char name;
	int kolvo;
	float ver;
	string code;
	Bukva(char name, int inputs, float probability) {
		this->name = name;
		this->kolvo = inputs;
		this->ver = probability;
		this->code = "";
	}
	Bukva(int inputs) {
		this->kolvo = inputs;
	}
}; 
 
class Node {// Класс-узел для связей
public:
	Bukva* bukva;
	Node* left;
	Node* right;
	Node(Node* left, Node* right) {
		this->left = left;
		this->right = right;
		this->bukva = new Bukva(left->bukva->kolvo + right->bukva->kolvo);
	}

	Node(Bukva* bukva) {
		this->bukva = bukva;
	}
};
map<char, string> symbols_code;//структура буква-закодированная строка
struct Sort_Nodes {//структура для сортировки букв по частоте
	bool operator()( Node* a,  Node* b) {
		return b->bukva->kolvo < a->bukva->kolvo;
	}
};
void print_table(const list<Node*>& list) {// вывод таблицы частот		
	cout << "Алфавит:              ";	
	for (auto item : list) {
		cout << setw(4)<< item->bukva->name << " ";
	}
	cout<<endl<<"Количество вхождений: ";
	for (auto item : list) {
		cout << setw(4)<< item->bukva->kolvo << " ";
	}
	cout<<endl<<"Вероятность:          ";
	for (auto item : list) {
		cout.setf(std::ios::fixed);
		cout << setprecision(2)<< item->bukva->ver << " ";
	}
	cout << endl;
	cout << endl;
}
list<Node*> ver_tabl(string  a) {//построение таблицы частот
	map<char, int> chastota;
	for (char i : a) {
		chastota[i]++;
	}
	list<Node*> nodes;
	for (auto& ch : chastota) {		
		nodes.push_back(new Node(new Bukva(ch.first, ch.second, (float)ch.second / a.size())));
	}
	cout << "Таблица частот"<<endl;
	print_table(nodes);
	return nodes;
}
list<Node*> sortik_tabl(list<Node*> nodes) {//сортировка дерева
	nodes.sort(Sort_Nodes());
	cout << "Таблица отсортированных частот" << endl;
	print_table(nodes);
	return nodes;
}
list<Node*> build_tree(list<Node*> nodes) {//построение дерева	букв
	while (nodes.size() != 1) {
		Node* smr = nodes.back();
		nodes.pop_back();
		Node* sml = nodes.back();
		nodes.pop_back();
		nodes.push_back(new Node(sml, smr));
		nodes.sort(Sort_Nodes());
	}
	return nodes;
}
void build_code_table(Node* root, string code) {//построение дерева кодов для букв
	Node* l = root->left;
	Node* r = root->right;
	

	if (l == nullptr && r == nullptr) {	
		cout << root->bukva->name<< code <<endl;
		root->bukva->code = code;
		symbols_code[root->bukva->name] = root->bukva->code;
	}
	else {
		build_code_table(l, code + "0");
		build_code_table(r, code + "1");
	}
}
void sviaz_codov() {//вывод связей буква- кода
	for ( auto s : symbols_code) {
		cout << s.first << ": " << s.second <<endl;
	}
}
void vivodi(list<Node*> nodes) {	
}
string haffman_code(string input) {//преобразование строки в код Хаффмана	
	string counter;
	for (char ch : input) {		
		counter += symbols_code[ch];
	}
	return counter;
}
int dec2bin(int num)//перевод числа в 2 систему счисления
{
	int bin = 0, k = 1;
	while (num)
	{
		bin += (num % 2) * k;
		k *= 10;
		num /= 2;
	}
	return bin;
}
string ascii_code(string input) {//преобразование строки в аски код
	string asci="";
	for (int i = 0; i < input.size(); ++i) {
		asci +=to_string(dec2bin((int(input[i]))));
	}	
	return asci;
}
void results(string a) {//вывод результатов кода по Хаффману и сравнение его с аски кодом
cout << "Коды символов: " << endl; sviaz_codov();
cout <<	"Код по Хаффману: " << haffman_code(a) << endl;
cout << "Длина кода по алгоритму Хаффмана: " << haffman_code(a).length() << endl;
cout << "Код по ASCII: " << ascii_code(a) << endl;
cout << "Длина кода по ASCII: " << ascii_code(a).length() << endl;
cout << "Дисперсия " << ((float)haffman_code(a).length() / ascii_code(a).length()) << endl;
}
int main() {//главная функция
	setlocale(LC_ALL, "Russian");
	string a="ivantsov mihail nikolaevich";	
	list<Node*> nodes = ver_tabl(a); // Таблица частот
	nodes = sortik_tabl(nodes);	
	nodes = build_tree(nodes); // Дерево Хаффмана
	build_code_table(nodes.front(), ""); // Таблица кодов символов
	results(a);	
	return 0;
}
*/

using namespace std;
map<char, string> codes;//структура буква-код
map<char, int> freq;//структура буква-количество появлений

struct MinHeapNode//структура узла буквы
{
	char data;             // One of the input characters 
	int freq;             // Frequency of the character 
	MinHeapNode* left, * right; // Left and right child 

	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


struct compare//структура сортировки для таблицы частот
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};



void storeCodes(struct MinHeapNode* root, string str)//придача буквам кодов
{
	if (root == NULL)
		return;
	if (root->data != '$')
		codes[root->data] = str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}


priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
template<typename T> void print_queue(T& q,int size) {//вывод отсортированной таблицы частот
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> q1=q;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> q2 = q;
	cout << "Алфавит:              ";
	while(!q.empty()) {
		if (q.top() != NULL) {					
			cout << setw(4) << q.top()->data << " ";			
			}		
			
			q.pop();		

    }
	cout << endl << "Количество вхождений: ";
	while (!q1.empty()) {
		if (q1.top() != NULL) {			
			cout << setw(4) << q1.top()->freq << " ";
		}
		q1.pop();
	}
	cout << endl << "Вероятность:          ";
	while (!q2.empty()) {
		if (q2.top() != NULL) {
			cout << setw(4) << float(q2.top()->freq)/size << " ";
		}
		q2.pop();
	}

    std::cout << '\n';
}
void HuffmanCodes(int size)//преобразование в код Хаффмана
{
	struct MinHeapNode* left, * right, * top;
	for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));	
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap2=minHeap;
	print_queue(minHeap2,size);
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}
void calcFreq(string str, int n)//вычисление вероятности буквы
{
	for (int i = 0; i < str.size(); i++) {
		freq[str[i]]++;
		
	}
}
string haffman_code(string input) {//преобразование строки в код Хаффмана	
	string encodedString;
	for (auto i : input)
		encodedString += codes[i];
	return encodedString;
}
void print_table(string str) {// вывод таблицы частот		
	cout << "Алфавит:              ";
	for (auto item : freq) {
		cout << setw(4) << item.first << " ";
	}
	cout << endl << "Количество вхождений: ";
	for (auto item : freq) {
		cout << setw(4) << item.second << " ";
	}
	cout << endl << "Вероятность:          ";
	for (auto item : freq) {
		cout.setf(std::ios::fixed);
		cout << setprecision(2) << float(item.second)/str.length() << " ";
	}
	cout << endl;
	cout << endl;
}
void sviaz_codov() {//вывод связей буква- кода	
	for (auto s : codes) {
		cout << s.first << ": " << s.second << endl;
	}
}
int dec2bin(int num)//перевод числа в 2 систему счисления
{
	int bin = 0, k = 1;
	while (num)
	{
		bin += (num % 2) * k;
		k *= 10;
		num /= 2;
	}
	return bin;
}
string ascii_code(string input) {//преобразование строки в аски код
	string asci = "";
	for (int i = 0; i < input.size(); ++i) {
		asci += to_string(dec2bin((int(input[i]))));
	}
	return asci;
}
void results(string a) {//вывод результатов кода по Хаффману и сравнение его с аски кодом
	cout << "Коды символов: " << endl; sviaz_codov();
	cout << "Код по Хаффману: " << haffman_code(a) << endl;
	cout << "Длина кода по алгоритму Хаффмана: " << haffman_code(a).length() << endl;
	cout << "Код по ASCII: " << ascii_code(a) << endl;
	cout << "Длина кода по ASCII: " << ascii_code(a).length() << endl;
	cout << "Дисперсия " << ((float)haffman_code(a).length() / ascii_code(a).length()) << endl;
}
int main()//главная функция
{
	setlocale(LC_ALL, "Russian");
	string str = "ivantsov mihail nikolaevich";	
	calcFreq(str, str.length());
	print_table(str);
	HuffmanCodes(str.length());
	results(str);
	return 0;
}





