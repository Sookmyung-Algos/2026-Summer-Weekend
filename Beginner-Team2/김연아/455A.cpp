#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    vector<long long> cnt(maxVal + 1, 0);
    for (int x : a) cnt[x]++;

    vector<long long> dp(maxVal + 1, 0);
    dp[1] = cnt[1] * 1;
    for (int i = 2; i <= maxVal; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }

    cout << dp[maxVal] << "\n";
    return 0;
}
