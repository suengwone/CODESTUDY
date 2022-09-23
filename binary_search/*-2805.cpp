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


// 나무 자르기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> trees;
long long int targetLength;

long long int findMax(long long int high, long long int low)
{
    long long int mid = (high + low) / 2, restLength = 0;
    
    if(low>high)
    {
        return mid + 1;
    }
    else if(low == high)
    {
        return mid - 1;
    }

    for(int i=0; i<trees.size(); i++)
    {
        if(trees[i] > mid)
        {
            restLength += (trees[i] - mid);
        }
    }
    
    if(targetLength == restLength)
    {
        return mid;
    }
    else if(targetLength > restLength)
    {
        return findMax(mid, low - 1);
    }
    else
    {
        return findMax(high, mid + 1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long int N,M,MaxSizeTree = 0;

    cin >> N >> M;

    trees.resize(N);

    for(int i=0; i<N; i++)
    {
        cin >> trees[i];
        if(MaxSizeTree < trees[i])
        {
            MaxSizeTree = trees[i];
        }
    }

    targetLength = M;

    cout << findMax(MaxSizeTree, 0) << '\n';

    return 0;
}
