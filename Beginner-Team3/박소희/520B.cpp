#include <iostream>
using namespace std;

int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    int cnt = 0;
    while (n < m){ // 타겟보다 작은 경우 역연산
        cnt++;
        if (m % 2 == 1){ //홀수면 +1
            m += 1;
        }
        else
            m /= 2;
    }
    cnt = cnt + n - m; // m <= n 인 경우, -1 (카운트는 +)

    cout << cnt << '\n';
    return 0;
}