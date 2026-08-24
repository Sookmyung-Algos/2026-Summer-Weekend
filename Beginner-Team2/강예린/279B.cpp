#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;

	vector<int> books(n);

	for (int i = 0; i < n; i++) {
		cin >> books[i];
	}

	int sum = 0; //읽은 시간 합
	int s = 0, e = 0; //투 포인터
	int answer = 0; //읽은 책 개수

	for (e = 0; e < n; e++) {
		sum += books[e];

		while (sum > t) {
			sum -= books[s];
			s++;
		}

		answer = max(answer, e - s + 1);
	}

	cout << answer;
	return 0;
}