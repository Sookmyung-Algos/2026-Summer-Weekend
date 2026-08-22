#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        int low, high;
        cin >> low >> high;
        v[i] = {high, low};
    }

    sort(v.begin(), v.end());

    int answer = 0;
    int temperature = -1000000000;

    for (int i = 0; i < n; i++) {
        int high = v[i].first;
        int low = v[i].second;

        if (temperature < low) {
            answer++;
            temperature = high;
        }
    }

    cout << answer;

    return 0;
}