#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, num;
	unordered_set<int> cardList;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (cardList.find(num) == cardList.end()) {
			cardList.insert(num);
		}
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> num;

		if (cardList.find(num) != cardList.end()) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
	cout << '\n';
}
