// Weekend - 코드포스 977C : Less or Equal
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    if (k == 0) {
        // x = 1일 때도 어떤 원소가 포함되면 안 됨
        if (a[0] == 1)
            cout << -1 << '\n';
        else
            cout << 1 << '\n';
    } else {
        // x = a[k - 1]을 선택
        // a[k]까지 같은 값이면 k개보다 많이 포함됨
        if (k < n && a[k - 1] == a[k])
            cout << -1 << '\n';
        else
            cout << a[k - 1] << '\n';
    }

    return 0;
}
