#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, t;
    cin >> n >> t;

    vector<int> books(n);

    for (int i=0; i<n; i++) {
        cin >> books[i];
    }

    int start = 0;
    int sum = 0;
    int total_max = 0;

    for (int i=0; i<n; i++) {
        sum += books[i];

        while (sum > t) {
            sum -= books[start];
            start++;
        }

        total_max = max(total_max, i-start+1);
    }

    cout << total_max;
}