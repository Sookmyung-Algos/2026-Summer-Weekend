#include <iostream>
using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    int a[100000];
    for (int i = 0; i < n; i++) cin >> a[i];

    int best = 0;
    long long sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > t) {
            sum -= a[left];
            left++;
        }
        int len = right - left + 1;
        if (len > best) best = len;
    }

    cout << best << "\n";
    return 0;
}
