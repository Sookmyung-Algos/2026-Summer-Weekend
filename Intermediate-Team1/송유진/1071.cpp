#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int m;
    cin >> m;

    int sum_divisors = 0;
    int sum_multiples = 0;

    for (int i = 0; i < n; ++i) {
        int val = nums[i];
        
        if (val > 0) {
            if (m % val == 0) {
                sum_divisors += val;
            }
            if (val % m == 0) {
                sum_multiples += val;
            }
        }
    }

    cout << sum_divisors << "\n";
    cout << sum_multiples << "\n";

    return 0;
}
