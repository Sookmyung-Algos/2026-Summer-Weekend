#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    int maxb = 0;
    int sum = 0, left = 0;

 
    cin >> n >> t;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 계속 sum 계산하는 방식 말고 계산하고 left 하나씩 빼가는 식
    for (int right = 0; right < n; right++) {
        sum += v[right];
        // t 초과했을 때
        while (sum > t) {
            // left번째 책 제거
            sum -= v[left];
            left++;
        }
        maxb = max(maxb, right - left + 1);
    }

    cout << maxb;

    return 0;
}