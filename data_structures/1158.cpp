// 요세푸스 문제

#include <iostream>
#include <list>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	list<int> _list(N), result;
	
	for (auto i = _list.begin(); i != _list.end(); i++) {
		*i = distance(_list.begin(), i) + 1;
	}

	auto idx = _list.begin();
	int count = 0;

	while (true) {
		if (idx == _list.end()) {
			break;
		}

		count += 1;

		if (count == K) {
			auto temp = idx;
			result.push_back(*temp);
			idx = _list.erase(temp);
			count = 0;
		}
		else {
			idx++;
		}

		if (idx == _list.end()) {
			idx = _list.begin();
		}
	}

	cout << "<";
	count = 0;
	for (auto i : result) {
		cout << i;
		count += 1;
		if (count != N) {
			cout << ", ";
		}
	}
	cout << ">\n";
}
