#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;
    cin >> n >> m;

    if (n > m) {
        cout << n-m;
    }
    else {
        int num = 0;
        while (m > n) {
            if (m%2 == 0) {
                m /= 2;
            }
            else {
                m++;
            }
            num++;
        }
        num += n-m;
        cout << num;
    }
}