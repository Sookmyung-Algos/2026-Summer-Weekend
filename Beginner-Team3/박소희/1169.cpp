#include <iostream>
using namespace std;

int N, type;
int a[6];
bool used[7]; 

void dfs(int depth){
    if (depth == N){
        for (int i=0; i < N; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }

    if (type == 1){
        for (int i = 1; i <=6; i++){
           a[depth] = i;
           dfs(depth + 1); 
        }
    }
        
    else if (type == 2){ // 오름차순만 가능하게 함
        int start = 1;
        if (depth != 0){
            start = a[depth - 1]; // 이전 값 이상만 다음 자리 가능
        }
        for (int i = start; i <= 6; i++){
            a[depth] = i;
            dfs(depth + 1);
        }
    }

    else if (type == 3){ // 같은 숫자가 두 번 이상 나오면 안 됨
        for (int i = 1; i <= 6; i++){
            if (used[i]) continue;
            used[i] = true;
            a[depth] = i;
            dfs(depth + 1);
            used[i] = false; // 다시 쓸 수 있도록
        }
    }
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> type;

    dfs(0);
    return 0;
}