#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool dice_up(int num, vector<int> & dice) {
    if (dice[num] < 6) {
        dice[num]++;
        return true;
    }
    else {
        if (num == 1) return false;
        
        dice[num] = 1;
        return dice_up(num-1,dice);
    }
}

bool same_check_2(int n, vector<int> dice, set<vector<int>> & setting) {
    sort(dice.begin(), dice.end());
    if (setting.find(dice) == setting.end()) {
        setting.insert(dice);
        return true;
    }
    return false;
}

bool same_check_3(int n, vector<int> & dice) {
    int arr[7] = {0};
    for (int i=1; i<n+1; i++) {
        arr[dice[i]]++;
        if (arr[dice[i]] > 1) {
            return false;
        }
    } 
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,t;
    
    cin >> n >> t;
    vector<int> dice(n+1,1);

    if (t == 1) {
        while (true) {
            for (int i=1; i<n+1; i++) {
                cout << dice[i] << " ";
            }
            cout << '\n';
            if (!dice_up(n,dice)) break;
        }
    }

    else if (t == 2) {
        set<vector<int>> setting;
        while (true) {
            if (same_check_2(n,dice,setting)){
                for (int i=1; i<n+1; i++) {
                    cout << dice[i] << " ";
                }
                cout << '\n';
            }
            if (!dice_up(n,dice)) break;
        }
    }

    else {
        while (true) {
            if (same_check_3(n,dice)){
                for (int i=1; i<n+1; i++) {
                    cout << dice[i] << " ";
                }
                cout << '\n';
            }
            if (!dice_up(n,dice)) break;
        }
    }
}