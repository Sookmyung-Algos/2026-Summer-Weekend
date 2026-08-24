// 정올 1539. 가장높은탑쌓기 
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

struct Block
{
    int id;
    int area;
    int h;
    int w;
};

Block arr[105];
int dp[105];
int trace[105];
int ans[105];

bool cmp(Block a, Block b)
{
    return a.area > b.area;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr[i].id = i + 1;
        cin >> arr[i].area >> arr[i].h >> arr[i].w;
    }

    sort(arr, arr + n, cmp);

    int maxH = 0;
    int topIdx = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i].h;
        trace[i] = -1;

        for (int j = 0; j < i; j++)
        {
            if (arr[i].w < arr[j].w)
            {
                if (dp[j] + arr[i].h > dp[i])
                {
                    dp[i] = dp[j] + arr[i].h;
                    trace[i] = j;
                }
            }
        }

        if (dp[i] > maxH)
        {
            maxH = dp[i];
            topIdx = i;
        }
    }

    int curr = topIdx;
    int cnt = 0;

    while (curr != -1)
    {
        ans[cnt] = arr[curr].id;
        cnt++;
        curr = trace[curr];
    }

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
#endif