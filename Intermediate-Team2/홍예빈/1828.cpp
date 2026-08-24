// Weekend  - 정올 1828 : 냉장고
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int low;
    int high;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Interval> intervals(N);

    for (int i = 0; i < N; i++) {
        cin >> intervals[i].low >> intervals[i].high;
    }

    // 최고 보관 온도 기준 오름차순 정렬
    sort(intervals.begin(), intervals.end(),
         [](const Interval& a, const Interval& b) {
             return a.high < b.high;
         });

    int answer = 0;
    int refrigeratorTemperature = 0;

    for (int i = 0; i < N; i++) {
        // 현재 냉장고 온도가 구간에 포함되지 않는 경우
        if (answer == 0 ||
            refrigeratorTemperature < intervals[i].low ||
            refrigeratorTemperature > intervals[i].high) {
            
            // 현재 구간의 최고 보관 온도에 냉장고 설치
            refrigeratorTemperature = intervals[i].high;
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
