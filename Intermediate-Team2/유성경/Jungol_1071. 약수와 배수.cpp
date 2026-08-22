// 정올 1071. 약수와 배수
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[45];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    int sumDiv = 0;
    int sumMul = 0;

    for (int i = 0; i < n; i++)
    {
        if (m % arr[i] == 0)
        {
            sumDiv += arr[i];
        }

        if (arr[i] % m == 0)
        {
            sumMul += arr[i];
        }
    }

    cout << sumDiv << "\n";
    cout << sumMul << "\n";

    return 0;
}
#endif