#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    int divisorSum = 0;
    int multipleSum = 0;

    for (int x : a) {
        if (m % x == 0) {
            divisorSum += x;
        }

        if (x % m == 0) {
            multipleSum += x;
        }
    }

    cout << divisorSum << '\n';
    cout << multipleSum << '\n';

    return 0;
}