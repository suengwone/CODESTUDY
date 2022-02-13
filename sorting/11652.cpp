// 카드

#include <iostream>
#include <map>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	map<long long int, int> arr;

	for (int i = 0; i < N; i++) {
		long long int num;
		cin >> num;
		if (arr.find(num) != arr.end()) {
			arr[num] += 1;
		}
		else {
			arr[num] = 1;
		}
	}

	int count = 0;
    long long int idx = 0;

	for (auto i : arr) {
		if (count < i.second) {
			count = i.second;
			idx = i.first;
		}
	}

	cout << idx << '\n';
}
