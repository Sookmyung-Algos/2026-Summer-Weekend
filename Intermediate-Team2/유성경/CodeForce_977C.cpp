// CodeForce 977C. Less or Equal
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[200005];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    if (k == 0)
    {
        if (arr[0] > 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    else
    {
        int ans = arr[k - 1];
        if (k < n && arr[k] == ans)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }

    return 0;
}
#endif