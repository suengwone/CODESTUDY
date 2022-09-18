// 외판원 순회 2 첫번째 풀이

#include <iostream>

using namespace std;

int arr[11][11];
int check[11];
int n;
int m = 999999999;

void dfs(int start, int y, int sum, int cnt) {
    if(cnt == n && start == y){
        if(m>sum)
            m=sum;
        return;
    }

    for(int x=0; x<n; x++){
        if(arr[y][x] == 0) continue;

        if(!check[y] && arr[y][x] > 0){
            check[y] = true;

            if(sum <= m) {
                dfs(start,x,sum + arr[y][x],cnt+1);
            }

            check[y] = false;
        }
    }
}

int main(void) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        dfs(i,i,0,0);
    }

    printf("%d\n",m);
}


// 외판원 순회 2 두번째 풀이

#include <iostream>
#include <vector>

using namespace std;

int N;

unsigned int minAnswer = 100000000;

vector< vector<unsigned int> > arr;

void TravelVillage(int curVille, vector<bool> check, int curValue, int startVille, int travelVilleCount)
{
    check[curVille] = true;

    if(travelVilleCount == N)
    {
        if(arr[curVille][startVille] == 0)
        {
            return;
        }
        else
        {
            curValue += arr[curVille][startVille];

            if(curValue < minAnswer)
            {
                minAnswer = curValue;
            }

            return;
        }
    }
    else
    {
        for(int i=0; i<N; i++)
        {
            if(check[i] != true && arr[curVille][i] != 0)
            {
                TravelVillage(i, check, curValue + arr[curVille][i], startVille, travelVilleCount + 1);
            }
        }
    }
}

int main()
{
    cin >> N;

    arr = vector< vector<unsigned int> >(N, vector<unsigned int>(N));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<bool> checkArr = vector<bool>(N,false);

    for(int i=0; i<N; i++)
    {
        TravelVillage(i, checkArr, 0, i, 1); 
    }

    cout << minAnswer << '\n';

    return 0;
}
