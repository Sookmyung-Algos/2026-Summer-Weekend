#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Chemical {
    int min_temp, max_temp;
};

// 최고 온도를 기준으로 오름차순 정렬
bool compare(const Chemical& a, const Chemical& b) {
    if (a.max_temp == b.max_temp) {
        return a.min_temp < b.min_temp;
    }
    return a.max_temp < b.max_temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Chemical> chemicals(n);
    for (int i = 0; i < n; ++i) {
        cin >> chemicals[i].min_temp >> chemicals[i].max_temp;
    }

    sort(chemicals.begin(), chemicals.end(), compare);

    int count = 0;
    int current_max_temp = -9999; // 초기 온도는 제한(-270도)보다 훨씬 낮은 값으로 세팅

    for (int i = 0; i < n; ++i) {
        // 현재 물질의 최저 온도가 기존 냉장고의 최고 온도 범위를 벗어난다면 새 냉장고 필요
        if (chemicals[i].min_temp > current_max_temp) {
            count++;
            current_max_temp = chemicals[i].max_temp;
        }
    }

    cout << count << "\n";
    return 0;
}
