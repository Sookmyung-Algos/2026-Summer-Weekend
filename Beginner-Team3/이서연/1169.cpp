#include <iostream>
using namespace std;

int N, type;
int a[10];
bool used[7];

void dfs(int n, int start) {
    if (n == N) {
        for (int i = 0; i < N; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }

    int s = (type == 2) ? start : 1;

    for (int i = s; i <= 6; i++) {
        if (type == 3 && used[i])
            continue;

        a[n] = i;

        if (type == 3)
            used[i] = true;

        dfs(n + 1, (type == 2) ? i : 1);

        if (type == 3)
            used[i] = false;
    }
}

int main() {
    cin >> N >> type;

    dfs(0, 1);

    return 0;
}