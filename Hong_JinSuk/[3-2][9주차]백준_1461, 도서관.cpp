#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int> Book;

vector<int> Book_P;
vector<int> Book_M;

int div_p, div_m;
int answer = 0;

bool compare(int a, int b) {
	return a > b;
}

void init() {
	for (int i = 0; i < N; i++) {
		int Book_loc;
		cin >> Book_loc;
		Book.push_back(Book_loc);
	}
}

void Push() {
	for (int i = 0; i < size(Book); i++) {
		if (Book[i] > 0) {
			Book_P.push_back(Book[i]);
		}
		else Book_M.push_back(abs(Book[i]));
	}
}

void Div() {
	// 나머지가 있으면 한번더 실행
	div_p = size(Book_P) / M;
	if (size(Book_P) % M != 0) div_p++;
	div_m = size(Book_M) / M;
	if (size(Book_M) % M != 0) div_m++;
}

void Select() {
	if (Book_P[0] > Book_M[0]) {
		int Loc = 0;
		for (int i = 0; i < div_m; i++) {
			answer += (Book_M[Loc] * 2);
			Loc += M;
		}

		Loc = 0;
		for (int i = 0; i < div_p; i++) {
			answer += (Book_P[Loc] * 2);
			Loc += M;
		}
		answer -= Book_P[0]; // 마지막은 돌아올 필요 없음
	}
	else {
		int Loc = 0;
		for (int i = 0; i < div_p; i++) {
			answer += (Book_P[Loc] * 2);
			Loc += M;
		}

		Loc = 0;
		for (int i = 0; i < div_m; i++) {
			answer += (Book_M[Loc] * 2);
			Loc += M;
		}
		answer -= Book_M[0]; // 마지막은 돌아올 필요 없음
	}
}
int main() {

	cin >> N >> M;

	// 값을 넣어줌
	init();

	// 음수랑 양수 따로 넣어주지만, 음수도 양수로 바꿔서 넣어줌.
	Push();

	// 숫자가 큰 순서대로
	sort(Book_P.begin(), Book_P.end(), compare);
	sort(Book_M.begin(), Book_M.end(), compare);

	// 얼마나 시행해줘야 하는지 나눠봄
	Div();


	Select();

	cout << answer;

	return 0;
}