#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<pair<int,int>>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i].first>>v[i].second;
    }
    
    sort(v.begin(),v.end());
    
    int low=v[0].first;
    int high=v[0].second;
    int ans=1;
    
    for(int i=1;i<N;i++){
        if(v[i].first>high){
            ans++;
            low=v[i].first;
            high=v[i].second;
            continue;
        }
        if(v[i].first>=low)low=v[i].first;
        if(v[i].second<=high)high=v[i].second;
    }
    cout<<ans;
    return 0;
}
