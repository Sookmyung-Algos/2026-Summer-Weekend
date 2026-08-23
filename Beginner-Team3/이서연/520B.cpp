#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;

    if (n < m) {
        while (m > n) {
            if (m % 2 == 0)
                m /= 2;
            else
                m++;

            cnt++;
        }

        cnt += n - m;
        cout << cnt;
    }

    else {
        cout << n - m;
    }

    return 0;
}