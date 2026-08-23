#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    if (k == 0) {
        if (a[0] > 1) cout << 1 << "\n";
        else cout << -1 << "\n";
    } else {
        int x = a[k - 1];
        if (k < n && a[k] == x) {
            cout << -1 << "\n";
        } else {
            cout << x << "\n";
        }
    }
    
    return 0;
}
