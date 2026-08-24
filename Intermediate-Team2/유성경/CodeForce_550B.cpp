// CodeForce 550B. Preparing Olympiad
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[20];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    int limit = 1 << n;

    for (int i = 0; i < limit; i++)
    {
        int cnt = 0;
        int sum = 0;
        int minVal = 999999999;
        int maxVal = -1;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                sum += arr[j];

                if (arr[j] < minVal)
                {
                    minVal = arr[j];
                }
                if (arr[j] > maxVal)
                {
                    maxVal = arr[j];
                }
            }
        }

        if (cnt >= 2 && sum >= l && sum <= r && (maxVal - minVal) >= x)
        {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif