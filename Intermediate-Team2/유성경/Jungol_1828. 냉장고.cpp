// 정올 1823. 냉장고
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

struct Chem {
    int minT;
    int maxT;
};

Chem arr[105];

bool cmp(Chem a, Chem b)
{
    if (a.maxT == b.maxT)
    {
        return a.minT < b.minT;
    }
    return a.maxT < b.maxT;
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
        cin >> arr[i].minT >> arr[i].maxT;
    }

    sort(arr, arr + n, cmp);

    int ans = 1;
    int currMax = arr[0].maxT;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].minT > currMax)
        {
            ans++;
            currMax = arr[i].maxT;
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif