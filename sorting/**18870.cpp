// 좌표 압축

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 첫번째 풀이
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


// 좌표 압축 두번째 풀이

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> originArr = vector<int>(N);
    vector<int> tmpArr = vector<int>(N);

    for(int i=0; i<N; i++)
    {
        cin >> originArr[i];
        tmpArr[i] = originArr[i];
    }

    sort(tmpArr.begin(),tmpArr.end());
    tmpArr.resize(unique(tmpArr.begin(),tmpArr.end()) - tmpArr.begin());

    for(auto i : originArr)
    {
        int output = lower_bound(tmpArr.begin(), tmpArr.end(), i) - tmpArr.begin();

        cout << output << " ";
    }
    
    return 0;
}
