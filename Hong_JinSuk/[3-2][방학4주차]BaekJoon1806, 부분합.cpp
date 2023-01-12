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

		// �κ��� ����
		int Length_Sum = Right - Left + 1;

		// �κ����� S���� ������
		if (S > Sum) {
			//����ĭ���� Ȯ���ϰ� Sum�� �����ش�.
			cout << "Sum : " << Sum << ", Right++" << " ,Min : " << Min << endl;
			Right++;
			Sum += Arr[Right];
		}
		// �κ����� S�̻��̸�
		else{
			// �κ����� ���̰� Min���� ������, �ٲ��ش�.
			if (Length_Sum < Min) Min = Length_Sum;
			// �������� ��ĭ �ٿ��ְ� Sum���� ���ش�.
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