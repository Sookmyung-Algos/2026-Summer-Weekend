//DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> sum(100001); // i값 * i개수

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum[a] += a;
    }

    vector<long long> dp(100001);
    dp[0] = 0;
    dp[1] = sum[1];

    for (int i = 2; i <= 100000; i++){
        // i 미선택 시 dp[i-1], i 선택 시 직전 최댓값(dp[i-2])에 i점수 더하기
        dp[i] = max(dp[i-1], dp[i-2]+sum[i]);
    }

    cout << dp[100000] << "\n";

    return 0;
}