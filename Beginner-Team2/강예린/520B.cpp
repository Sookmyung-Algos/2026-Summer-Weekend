#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int count = 0;
	cin >> n >> m;

	while (m > n) {
		if (m % 2 == 0) {
			m /= 2;
		}
		else {
			m++;
		}
		count++;
	}

	count += (n - m);

	cout << count;
	return 0;
}