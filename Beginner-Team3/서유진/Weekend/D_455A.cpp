#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> cnt(100001, 0);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<long long> dp(100001, 0);

    dp[1] = cnt[1];

    for (int i=2; i<=100000; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i] * i);
    }

    cout << dp[100000];
}