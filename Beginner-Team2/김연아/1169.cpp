#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, type;
vector<int> dice;

void dfs(int depth, int start, vector<bool>& used) {
    if (depth == N) {
        for (int x : dice) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if (type == 1) {
            dice.push_back(i);
            dfs(depth + 1, start, used);
            dice.pop_back();
        }
        else if (type == 2) { // 중복 허용, 순서 무시
            if (i >= start) {
                dice.push_back(i);
                dfs(depth + 1, i, used);
                dice.pop_back();
            }
        }
        else if (type == 3) { // 모두 다른 수
            if (!used[i]) {
                used[i] = true;
                dice.push_back(i);
                dfs(depth + 1, start, used);
                dice.pop_back();
                used[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> type;
    vector<bool> used(7, false); // 주사위 눈 1~6
    dfs(0, 1, used);
    return 0;
}
