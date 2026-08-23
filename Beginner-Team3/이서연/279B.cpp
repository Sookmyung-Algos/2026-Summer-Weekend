#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    int sum = 0;
    int answer = 0;

    for (int right = 0; right < n; right++) {
        sum += a[right];

        while (sum > t) {
            sum -= a[left];
            left++;
        }

        int num = right - left + 1;

        if (num > answer) {
            answer = num;
        }
    }

    cout << answer;

    return 0;
}