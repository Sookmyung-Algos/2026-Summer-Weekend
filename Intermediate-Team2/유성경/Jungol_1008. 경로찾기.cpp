// 정올 1008. 경로찾기 
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

struct State
{
    int cost;
    int time;
    int r;
    int c;
    bool operator<(const State& o) const
    {
        return cost > o.cost;
    }
};

int n, t;
int arr[105][105];
int minTime[105][105];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;

    int stR = -1;
    int stC = -1;
    int enR = -1;
    int enC = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
            {
                stR = i;
                stC = j;
            }
            else if (arr[i][j] == -2)
            {
                enR = i;
                enC = j;
            }
            minTime[i][j] = 999999999;
        }
    }

    priority_queue<State> pq;
    pq.push({ 0, 0, stR, stC });

    int ans = -1;

    while (!pq.empty())
    {
        State curr = pq.top();
        pq.pop();

        if (curr.r == enR && curr.c == enC)
        {
            ans = curr.cost;
            break;
        }

        if (curr.time >= minTime[curr.r][curr.c])
        {
            continue;
        }
        minTime[curr.r][curr.c] = curr.time;

        for (int i = 0; i < 4; i++)
        {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n)
            {
                if (arr[nr][nc] == 0)
                {
                    continue;
                }

                int nxtTime = curr.time + 1;
                if (nxtTime > t)
                {
                    continue;
                }

                int nxtCost = curr.cost;
                if (arr[nr][nc] > 0)
                {
                    nxtCost += arr[nr][nc];
                }

                if (nxtTime < minTime[nr][nc])
                {
                    pq.push({ nxtCost, nxtTime, nr, nc });
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif