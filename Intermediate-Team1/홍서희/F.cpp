#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Brick {
    int area, height, weight, order;
};
bool cmp(Brick a, Brick b) {
    return a.area > b.area;
}

int main() {
    int N, M;
    cin >> N;

    vector < Brick > v;
    for (int i = 0; i < N; i++) {
        int a, h, w;
        cin >> a >> h >> w;
        v.push_back(Brick {a, h, w, i + 1});
    }
    sort(v.begin(), v.end(), cmp);

    vector < int > dp(N);
    vector < int > parent(N, -1);

    for (int i = 0; i < N; i++) {
        dp[i] = v[i].height;
        for (int j = 0; j < i; j++) {
            if (v[j].area > v[i].area && v[j].weight > v[i].weight) {
                if (dp[i] < dp[j] + v[i].height) {
                    dp[i] = dp[j] + v[i].height;
                    parent[i] = j;
                }
            }
        }
    }

    int last = 0;
    for (int i = 1; i < N; i++) {
        if (dp[i] > dp[last]) {
            last = i;
        }
    }

    vector < int > res;
    while (last != -1) {
        res.push_back(v[last].order);
        last = parent[last];
    }

    cout << res.size() << '\n';
    for (int x: res) {
        cout << x << '\n';
    }

    return 0;
}
