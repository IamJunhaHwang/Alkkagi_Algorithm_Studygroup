#include <iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int>q;
	int N, K;
	int visit[100001];
	cin >> N >> K;
	int index[100001];
	for (int i = 0; i < 100001;i++) {
		index[i] = 0;
	}
	index[0] = 0;
	int index2 = 0;
	int index3 = 1;
	if (N == K) {
		cout << 0;
	}
	else if ((N - 1) == K || (N + 1) == K || (N * 2) == K) {
		cout << 1;
	}
	else {
		if ((N-1) >= 0) {
			q.push(N - 1);
			visit[N - 1] = 1;
			index[0]++;
		}
		if ((N+1) <= 100000) {
			q.push(N + 1);
			visit[N + 1] = 1;
			index[0]++;
		}
		if ((N * 2) <= 100000) {
			q.push(N * 2);
			visit[N * 2] = 1;
			index[0]++;
		}
		while (1) {
			if ((q.front() - 1) == K || (q.front() + 1) == K || (q.front() * 2) == K) {
				index3++;
				break;
	
			}
			else {
				if ((q.front() - 1) >= 0 && visit[q.front() - 1] != 1) {
					q.push(q.front() - 1);
					index[index2 + 1]++;
					visit[q.front() - 1] = 1;
				}
				if ((q.front() + 1) <= 100000 && visit[q.front() + 1] != 1) {
					q.push(q.front() + 1);
					index[index2 + 1]++;
					visit[q.front() + 1] = 1;
				}
				if ((q.front() * 2) <= 100000 && visit[q.front() * 2]!=1) {
					q.push(q.front() * 2);
					index[index2 + 1]++;
					visit[q.front() * 2] = 1;
				}
				q.pop();
				index[index2]--;
				if (index[index2] == 0) {
					index2++;
					index3++;
				}
			}
		}
		cout << index3;
	}
	return 0;
}
