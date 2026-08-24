#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a, b;
int cnt;
int parent[200001];


int find(int x){
    if (parent[x] == x) return x;
    return parent[x] = find (parent[x]);
}

bool unionNodes(int u, int v){ // 각 집합의 루트 조회 후 연결
    int rootU = find(u); 
    int rootV = find(v);
    if (rootU != rootV){
        parent[rootV] = rootU;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;


    for (int i = 1; i <= n; i++)
        parent[i] = i;

    cnt = n;

    for (int i = 0; i < m; i++){
            cin >> a >> b;
            if(unionNodes(a, b))
                cnt--;
    }
    
    cout << cnt << '\n';

    return 0;
}