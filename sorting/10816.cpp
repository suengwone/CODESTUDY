// 숫자 카드 2

#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, num;
	unordered_map<int, int> cardList;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (cardList.find(num) != cardList.end()) {
			cardList[num] += 1;
		}
		else {
			cardList[num] = 1;
		}
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> num;

		if (cardList.find(num) != cardList.end()) {
			cout << cardList[num]<<" ";
		}
		else {
			cout << "0 ";
		}
	}
	cout << '\n';
}
