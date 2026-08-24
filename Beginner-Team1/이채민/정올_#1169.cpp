#include <iostream>
using namespace std;

int N, type;
int dice[5];
bool used[7];

void printDice() {
    for (int i = 0; i < N; i++) {
        cout << dice[i];
        if (i != N - 1) cout << ' ';
    }
    cout << '\n';
}

void dfs1(int depth) {
    if (depth == N) {
        printDice();
        return;
    }

    for (int i = 1; i <= 6; i++) {
        dice[depth] = i;
        dfs1(depth + 1);
    }
}

void dfs2(int depth, int start) {
    if (depth == N) {
        printDice();
        return;
    }

    for (int i = start; i <= 6; i++) {
        dice[depth] = i;
        dfs2(depth + 1, i);
    }
}

void dfs3(int depth) {
    if (depth == N) {
        printDice();
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if (used[i]) continue;

        used[i] = true;
        dice[depth] = i;

        dfs3(depth + 1);

        used[i] = false;
    }
}

int main() {
    cin >> N >> type;

    if (type == 1)
        dfs1(0);
    else if (type == 2)
        dfs2(0, 1);
    else
        dfs3(0);

    return 0;
}