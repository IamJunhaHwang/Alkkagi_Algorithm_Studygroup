#include <iostream>
using namespace std;
void sol(int num2[], int dp[],int dp2[], int num, int index) {
	dp[1] = num2[1];
	dp[2] = num2[1] + num2[2];
	dp[3] = num2[1] + num2[3];
	dp2[3] = num2[2] + num2[3];
	if (dp[3] < dp2[3]) dp[3] = dp2[3];
	if (num == 1)cout<< dp[1];
	else if (num == 2)cout << dp[2];
	else if (num == 3)cout << dp[3];
	else if (num > 3) {
		dp[index] = dp[index - 3] + num2[index-1]+ num2[index];
		dp2[index] = dp[index - 2] + num2[index];
		if (dp[index] < dp2[index])dp[index] = dp2[index];
		if (index == num)cout << dp[index];
		if(index<=num)sol(num2, dp, dp2, num, index + 1);
	}
}
int main()
{
	int num;
	int dp[300];
	int dp2[300];
	int index = 4;
	cin >> num;
	if (num == 0)return 0;
	int num2[300];
	for (int i = 0; i <= num; i++) {
		dp[i] = 0;
		dp2[i] = 0;
	}
	for (int i = 1; i <= num; i++) {
		cin >> num2[i];
	}
	num2[0] = 0;
	sol(num2, dp,dp2, num, index);
	return 0;
}
