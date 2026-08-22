#include <bits/stdc++.h>
using namespace std;

struct Brick {
    int area, height, weight, num;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Brick> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].area >> a[i].height >> a[i].weight;
        a[i].num = i + 1;
    }

    sort(a.begin(), a.end(), [](const Brick& x, const Brick& y) {
        return x.area > y.area;
        });

    vector<int> dp(n);
    vector<int> pre(n, -1);

    int best = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = a[i].height;

        for (int j = 0; j < i; j++) {
            if (a[j].weight > a[i].weight && dp[i] < dp[j] + a[i].height) {
                dp[i] = dp[j] + a[i].height;
                pre[i] = j;
            }
        }

        if (dp[i] > dp[best]) {
            best = i;
        }
    }

    vector<int> answer;

    while (best != -1) {
        answer.push_back(a[best].num);
        best = pre[best];
    }

    cout << answer.size() << '\n';

    for (int x : answer) {
        cout << x << '\n';
    }

    return 0;
}