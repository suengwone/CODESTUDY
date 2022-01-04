// 치킨 배달

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int a, int b){
    int result = a - b;
    return result > 0 ? result : -result;
}

int distance(pair<int,int> house, pair<int,int> chick){
    return abs(house.first - chick.first) + abs(house.second - chick.second);
}

int main(void){
    int N,M,temp;
    scanf("%d %d",&N,&M);
    
    vector<pair<int,int>> house_pos,chick_pos;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&temp);
            if(temp == 1){
                house_pos.push_back(pair<int,int>(i,j));
            } else if(temp == 2){
                chick_pos.push_back(pair<int,int>(i,j));
            }
        }
    }
    
    vector<int> check(chick_pos.size());
    
    for(int i=0;i<M;i++){
        check[i]=1;
    }
    
    int result = 2 * N * house_pos.size();
    
    do{
        int least_dis=0;
        for(int i=0;i<house_pos.size();i++){
            int least_value = 2 * N, count = 0;
            for(int j=0;j<chick_pos.size();j++){
                if(count == M) break;
                if(check[j] == 0) continue;
                int cur_dis = distance(house_pos[i], chick_pos[j]);
                if(least_value > cur_dis)
                    least_value = cur_dis;
                count += 1;
            }
            least_dis += least_value;
        }
        if(result > least_dis)
            result = least_dis;
    } while(prev_permutation(check.begin(),check.end()));
    
    printf("%d\n",result);
}
