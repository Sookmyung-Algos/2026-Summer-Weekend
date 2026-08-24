#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int answer = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        int cnt = 0;
        int mn = 1e9;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
                cnt++;
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        }
        if (cnt >= 2 &&
            sum >= l && sum <= r &&
            mx - mn >= x) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}