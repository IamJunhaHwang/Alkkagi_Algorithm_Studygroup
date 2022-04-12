#include <iostream> // 2606
#include <vector>
using namespace std;
int m; int cunt = 0;
//int c[101][101] = { 0 }; 
vector<int> c[101];
bool v[101];
void search(int san) {
//	int c[100][100], v[100];
	//	int count = 0;
	//cunt++; 
	v[san] = true;
	for (int i = 0; i < c[san].size(); i++) {
		int what = c[san][i];
		if (!v[what]) {
			search(what);
			cunt++;
		}
		/*if (c[san][i] && !v[i]) {
			search(i);
		}*/
	}
}
int main() { // 1 2 3 5 6 \ 4 7
	int n; cin >> n;
	//int m; 
	cin >> m;
//	int c[100][100]; int p = 0; 
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		c[a].push_back(b);
		c[b].push_back(a);
		c[a][b] = c[b][a] = 1;
		//++p;
		cout << c[a][b] << endl;
	}
	/*int v[100];
	for (int i = 0; i < m; i++) {
		if (v[1]) {
			return;
		}
		v[1] = true;
		for (int i = 0; i < m; i++) {

		}
	}*/
//	cout << p << endl;
	search(1);
	cout << cunt << endl;
}