// 배열 합치기

#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	vector<int> arr_1, arr_2, result;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr_1.push_back(num);
	}

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		arr_2.push_back(num);
	}

	int idx_1 = 0, idx_2 = 0, idx_res = 0;

	while (idx_1 < N && idx_2 < M) {
		if (arr_1[idx_1] < arr_2[idx_2]) {
			result.push_back(arr_1[idx_1]);
			idx_1 += 1;
		}
		else {
			result.push_back(arr_2[idx_2]);
			idx_2 += 1;
		}
	}

	while (idx_1 < N) {
		result.push_back(arr_1[idx_1]);
		idx_1 += 1;
	}

	while (idx_2 < M) {
		result.push_back(arr_2[idx_2]);
		idx_2 += 1;
	}

	for (int print_num : result) {
		cout << print_num << " ";
	}
	cout << '\n';
}
