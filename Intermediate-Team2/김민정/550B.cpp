#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    long long l, r;
    cin >> n >> l >> r >> x;
 
    vector<int> a(n);
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int ans = 0;
    int all = (1 << n) - 1;
 
    for(int mask = all; mask; mask = (mask - 1) & all) {
        int cnt = 0;
        long long sum = 0;
        int mn = 1000000000;
        int mx = 0;
 
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                cnt++;
                sum += a[i];
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        }
 
        if(cnt >= 2 && sum >= l && sum <= r && mx - mn >= x) {
            ans++;
        }
    }
 
    cout << ans;
}
