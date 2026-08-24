#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> count(100001, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		count[x]++;
	}

	long long dp[100001] = { 0 };

	dp[1] = count[1];

	for (int i = 2; i <= 100000; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + (long long)i * count[i]); 
	}

	cout << dp[100000];

	return 0;

}