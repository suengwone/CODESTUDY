// 좌표 압축

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> point, idx;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		point.push_back(num);
		idx.push_back(num);
	}

	sort(idx.begin(), idx.end());
	idx.resize(unique(idx.begin(), idx.end()) - idx.begin());

	for (int target : point) {
		int pos = lower_bound(idx.begin(), idx.end(), target) - idx.begin();
		cout << pos << " ";
	}

	cout << '\n';
}
