#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    int a[100001];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    int answer = 0;
    long long sum = 0;

    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > t) {
            sum -= a[left];
            left++;
        }
        answer = max(answer, right - left + 1);
    }

    cout << answer <<'\n';
    return 0;
}