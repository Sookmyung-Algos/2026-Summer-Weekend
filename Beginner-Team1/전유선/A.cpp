#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, type;
vector<int> arr;
// type 3에서 해당 숫자 사용했는지 여부 검사할 거임
vector<bool> used(7, false);
// type 2에서 사용
vector<vector<int>> v;

// depth는 n번째 주사위. depth=0이면 첫 번째, 1이면 두 번째 ...
// 첫 번째 주사위 고르고 두 번째 주사위 고르고 ... 하니까 dice(depth + 1) 호출.
void dice(int depth) {
    // 끝까지 왔을 때 출력하고 이전으로 돌아감.
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= 6; i++) {
        arr[depth] = i;
        dice(depth + 1);

    }
}

void dice2(int depth) {

    if (depth == n) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
    
        // 이미 있는 조합이면 return
        if (find(v.begin(), v.end(), temp) != v.end()) {
            return;
        }
            
        v.push_back(temp);
    
        for (int i = 0; i < n; i++) {
            cout << temp[i] << ' ';
        }
    
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= 6; i++) {            
        arr[depth] = i;
        dice2(depth + 1);
    
    }
}
// type==3일때
void dice3(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= 6; i++) {
        if (used[i]) {
            continue;
        }
        else {
            arr[depth] = i;
            // 선택하고 재귀하고 선택 취소
            used[i] = true;
            dice3(depth + 1);
            used[i] = false;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    
    
    cin >> n >> type;
    // 전역 변수 크기 재조정
    arr.resize(n);

    if (type == 1) {
        dice(0);
    }

    else if (type == 2) {
        dice2(0);
    }

    else if (type == 3) {
        dice3(0);
    }
}