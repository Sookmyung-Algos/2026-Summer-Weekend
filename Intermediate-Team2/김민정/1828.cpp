#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    int ans = 1;
    int r = a[0].second;

    for(int i = 1; i < n; i++) {
        if(a[i].first <= r) {
            r = min(r, a[i].second);
        }
        else {
            ans++;
            r = a[i].second;
        }
    }

    cout << ans;
}
