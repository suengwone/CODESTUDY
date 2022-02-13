// 중복 빼고 정렬하기

#include <iostream>
#include <set>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	set<int> arr;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.emplace(num);
	}

	for (int print_num : arr) {
		cout << print_num << " ";
	}
	cout << '\n';
}
