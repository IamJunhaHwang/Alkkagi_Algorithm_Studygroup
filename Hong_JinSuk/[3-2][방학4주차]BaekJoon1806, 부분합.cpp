#include<iostream>

using namespace std;

int N, S;
int Left = 0;
int Right = 0;
int Min = 100001;

int main() {

	cin >> N >> S;
	int* Arr = new int[N];
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		Arr[i] = num;
	}

	int Sum = Arr[0];

	while (Left <= Right && Right<N) {

		// 부분합 길이
		int Length_Sum = Right - Left + 1;

		// 부분합이 S보다 작으면
		if (S > Sum) {
			//오른칸으로 확장하고 Sum에 더해준다.
			cout << "Sum : " << Sum << ", Right++" << " ,Min : " << Min << endl;
			Right++;
			Sum += Arr[Right];
		}
		// 부분합이 S이상이면
		else{
			// 부분합의 길이가 Min보다 작으면, 바꿔준다.
			if (Length_Sum < Min) Min = Length_Sum;
			// 왼쪽으로 한칸 줄여주고 Sum에서 빼준다.
			cout << "Sum : " << Sum << ", Left++" << " ,Min : " << Min << endl;
			Sum -= Arr[Left];
			Left++;	
		}
	}

	if (Min == 100001) {
		cout << 0;
		return 0;
	}
	else cout << Min;

	return 0;
}