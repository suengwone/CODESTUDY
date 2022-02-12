// 국영수

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;

class Datas {
public:
	string name;
	int korean, english, math;

	Datas(string _name, int _korean, int _english, int _math) {
		this->name = _name;
		this->korean = _korean;
		this->english = _english;
		this->math = _math;
	}

	bool operator <(Datas& datas) {
		if (this->korean != datas.korean) {
			return this->korean > datas.korean;
		}
		else {
			if (this->english != datas.english) {
				return this->english < datas.english;
			}
			else {
				if (this->math != datas.math) {
					return this->math > datas.math;
				}
				else {
					return this->name < datas.name;
				}
			}
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<Datas> students;

	for (int i = 0; i < N; i++) {
		string name;
		int korean, english, math;

		cin >> name >> korean >> english >> math;

		students.push_back(Datas(name, korean, english, math));
	}

	sort(students.begin(), students.end());

	for (int i = 0; i < N; i++) {
		cout << students[i].name << '\n';
	}
}
