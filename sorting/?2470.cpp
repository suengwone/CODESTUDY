// 두 용액

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, result = 2000000000;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<int> liq_list(N);

	for (int i = 0; i < N; i++) {
		cin >> liq_list[i];
	}

	sort(liq_list.begin(), liq_list.end());

	int idx_1 = 0, idx_2 = N - 1, res_idx_1 = -1, res_idx_2 = -1;

	while (idx_1 < idx_2) {
		int sum = liq_list[idx_1] + liq_list[idx_2];

		if (result > abs(sum)) {
			result = abs(sum);
			res_idx_1 = liq_list[idx_1];
			res_idx_2 = liq_list[idx_2];

			if (sum == 0) {
				break;
			}
		}

		if (sum < 0) {
			idx_1 += 1;
		}
		else {
			idx_2 -= 1;
		}
	}

	cout << res_idx_1 << " " << res_idx_2 << '\n';
}
