#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N,M;
    cin>>N;
    vector<int>num(N);
    for(int i=0;i<N;i++)cin>>num[i];
    cin>>M;
    int ans1=0,ans2=0;
    for(int i=1;i<=M;i++){
        if(M%i==0){
            for(int k:num){
                if(k==i){
                    ans1+=i;
                }
            }
        }
        
    }
    for(int k:num){
        if(k%M==0)ans2+=k;
    }
    cout<<ans1<<'\n'<<ans2;
    return 0;
}
