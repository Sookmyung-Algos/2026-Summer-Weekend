#include <iostream>
using namespace std;

int N;
int a[14][14];
bool visited[14];
int best = 1e9;

void dfs(int cur, int cnt, int cost) { // 현재 장소, 방문수, 누적이동비용
    if (cost >= best) return;

    if (cnt == N) { // 모든 장소 방문 후 회사 돌아오기
        if (a[cur][0] > 0)
            best = min(best, cost + a[cur][0]);
        return;
    }

    for (int next = 1; next < N; next++) { // 다음 장소 선택
        if (visited[next]) continue;
        if (a[cur][next] == 0) continue;

        visited[next] = true;
        dfs(next, cnt + 1, cost + a[cur][next]);
        visited[next] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i=0; i < N; i++){
        for (int j=0; j < N; j++){
            cin >> a[i][j];
        }
    }
    visited[0] = true;
    dfs(0, 1, 0);

    cout << best << "\n";

    return 0;
}