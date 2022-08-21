// 수 찾기 첫번째 풀이

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

void solution(int n, int key){
    int start = 0;
    int end = n-1;
    int mid;

    while(end-start >= 0) {
        mid = (end + start) / 2;
        
        if(arr[mid] == key) {
            printf("1\n");
            return;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    printf("0\n");
    return;
}

int main(void){
    int N,M,find_key;

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }

    sort(arr, arr+N);

    scanf("%d",&M);

    for(int i=0;i<M;i++){
        scanf("%d", &find_key);
        solution(N, find_key);
    }
}

// 수 찾기 두번째 풀이

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M,temp;
    set<long long int> CheckSet;
    
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin>>temp;
        CheckSet.insert(temp);
    }
    
    cin >> M;
    int searchNum;
    for(int i=0; i<M; i++)
    {
        cin >> searchNum;
        CheckSet.find(searchNum) == CheckSet.end() ? cout << 0 : cout << 1;
        cout << '\n';
    }
    
    return 0;
}
