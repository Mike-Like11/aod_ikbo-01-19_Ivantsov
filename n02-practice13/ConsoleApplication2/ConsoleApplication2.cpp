#include <iostream>
#include<iomanip>
using namespace std;
const int INF = 9999999;
const int V = 5;


int G[V][V] = {
{0,1,2,0,10},
{1,0,0,3,6},
{2,0,0,4,7},
{0,3,4,0,11},
{10,6,7,11,0}
};

int main() {
	int no_edge;
	int selected[V];
	memset(selected, false, sizeof(selected));
	no_edge = 0;
	selected[0] = true;
	int x;     
	int y; 
	cout << "Edge" << " : " << "Weight";
	cout << endl;
	int min_sum = 0;
	while (no_edge < V - 1) {
		int min = INF;
		x = 0;
		y = 0;
		for (int i = 0; i < V; i++) {
			if (selected[i]) {
				for (int j = 0; j < V; j++) {
					if (!selected[j] && G[i][j]) { 
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		cout << x+1 << " - " << y+1 << " :  " << G[x][y];
		min_sum += G[x][y];
		cout << endl;
		selected[y] = true;
		no_edge++;
	}
	cout << "min_sum: " << min_sum;
	return 0;
}