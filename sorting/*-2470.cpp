// 두 용액

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2022.02.15 첫번째 풀이
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

// 2022.08.07 두번째 풀이
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> liqList = vector<int>(N);

    for(int i=0; i<N; i++)
    {
        cin >> liqList[i];
    }

    sort(liqList.begin(),liqList.end());

    auto front = liqList.begin();
    auto back = liqList.rbegin();

    int base = 2000000001;
    pair<int,int> answer = pair<int,int>(*front, *back);

    auto fisrtIt = liqList.begin();
    auto lastIt = liqList.rbegin();

    while(true)
    {
        int tmp = *front + *back;

        if(base > abs(tmp))
        {
            answer = pair<int,int>(*front, *back);
            base = abs(tmp);
        }

        if(tmp > 0)
        {
            back++;
            if(front - fisrtIt + 1 + back - lastIt >= N)
            {
                break;
            }
        }
        else if(tmp < 0)
        {
            front++;
            if(front - fisrtIt + 1 + back - lastIt >= N)
            {
                break;
            }
        }
        else
        {
            answer = pair<int,int>(*front, *back);
            break;
        }
    }

    cout << answer.first << " " << answer.second << '\n';

    return 0;
}
