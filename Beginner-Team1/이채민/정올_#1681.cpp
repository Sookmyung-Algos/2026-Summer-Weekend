#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int cost[13][13];
int dp[13][1 << 13];

const int INF = 1000000000;

int dfs(int now, int visited){
    if (visited == (1 << N) - 1){
        if (cost[now][0] == 0)
            return INF;

        return cost[now][0];
    }

    if (dp[now][visited] != -1)
        return dp[now][visited];

    dp[now][visited] = INF;

    for (int next = 0; next < N; next++) {

        if (visited & (1 << next))
            continue;
        if (cost[now][next] == 0)
            continue;

        int nextVisited = visited |(1 << next);
        int result = cost[now][next] + dfs(next, nextVisited);

        dp[now][visited] = min(dp[now][visited], result);
    }
    return dp[now][visited];
}

int main(){
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    if (N == 1) {
        cout << 0;
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    //1번 회사에서 시작하므로 0번 비트를 방문 처리
    cout << dfs(0, 1);

    return 0;
}