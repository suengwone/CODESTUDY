// 나무 자르기

#include <iostream>

using namespace std;

long long trees[1000001];

int N;
long long M;

bool isPossible(unsigned int height) {
	unsigned int taken = 0;
	for (int i = 0; i < N; i++) {
		if (trees[i] >= height)
			taken += (trees[i] - height);
		if (taken >= M) return true;
	}
	return false;
}

int solve() {
	unsigned int left = 0, right = 1000000000;
	unsigned int mid,ret;
	while (left <= right) {
		mid = (left + right) / 2;
		if (isPossible(mid)) {
			ret = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ret;
}
int main() {
	scanf("%d %lld", &N, &M);
    
	for (int i = 0; i < N; i++)
        scanf("%lld",&trees[i]);

    printf("%d\n",solve());
}
