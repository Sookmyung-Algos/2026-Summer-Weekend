#include <iostream>
#include <vector>
using namespace std;

int n, type;
int arr[10];
bool visited[7];

void type1(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= 6; i++) {
        arr[depth] = i;
        type1(depth + 1);
    }
}

void type2(int depth, int start) {
    if (depth == n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i <= 6; i++) {
        arr[depth] = i;
        type2(depth + 1, i);
    }
}

void type3(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= 6; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;
            type3(depth + 1);
            visited[i] = false; // 백트래킹 (탐색 후 상태 복구)
        }
    }
}

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);

	cin >> n >> type;

    if (type == 1) type1(0);
    else if (type == 2) type2(0, 1);
    else if (type == 3) type3(0);

    return 0;
}