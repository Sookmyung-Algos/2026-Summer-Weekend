#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        }
        else {
            m += 1;
        }
        count++;
    }
    count += (n - m); // 남은 차이는 -1 버튼으로 맞춤
    cout << count << "\n";
    return 0;
}