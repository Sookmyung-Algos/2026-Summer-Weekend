// 투포인터
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; // 책 권수, 여유 시간
    vector<int> a(100001);

    cin >> n >> t;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 0; int r = 0;
    int sum = 0; int cnt = 0;

    while(r < n){
        sum += a[r];
        while (sum > t){
            sum -= a[l];
            l++;
        }
        cnt = max(cnt, r-l+1);
        r++;
    }
    cout << cnt << '\n';
}