// K번째 수

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> point;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		point.push_back(num);
	}

	sort(point.begin(), point.end());

	cout << point[K - 1];
}
