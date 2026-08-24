#include <iostream>
using namespace std;

int N, type;
int a[10];
bool used[7];

void go(int depth, int start) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            cout << a[i];
            if (i != N - 1) cout << " ";
        }
        cout << "\n";
        return;
    }

    if (type == 1) {
        
        for (int v = 1; v <= 6; v++) {
            a[depth] = v;
            go(depth + 1, 1);
        }
    }
    else if (type == 2) {
        
        for (int v = start; v <= 6; v++) {
            a[depth] = v;
            go(depth + 1, v);
        }
    }
    else {
       
        for (int v = 1; v <= 6; v++) {
            if (used[v]) continue;
            used[v] = true;
            a[depth] = v;
            go(depth + 1, 1);
            used[v] = false;
        }
    }
}

int main() {
    cin >> N >> type;
    go(0, 1);
    return 0;
}
