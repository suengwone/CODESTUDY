// 통계학

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;

int average(vector<int> numbers){
    double sum=0;
    for(int i=0;i<N;i++){
        sum+=numbers[i];
    }
    
    return floor(sum/N + 0.5);
}

int middle(vector<int> numbers){
    return numbers[N/2];
}

int least_value(vector<int> numbers){
    int find_value, prev_value = 4001, min_count=0;
    vector<int> answer;
    for(int i=0;i<N;i++){
        find_value = numbers[i];
        if(prev_value==find_value) continue;
        int cur_count = 1;
        for(int j=i;j<N;j++){
            if(find_value < numbers[j]) break;
            cur_count+=1;
        }
        if(min_count < cur_count){
            min_count = cur_count;
            answer.clear();
            answer.push_back(numbers[i]);
        } else if(min_count == cur_count){
            answer.push_back(numbers[i]);
        }
        prev_value = find_value;
    }
    
    if(answer.size() != 1){
        return answer[1];
    }else{
        return answer[0];
    }
}

int range(vector<int> numbers){
    return *numbers.rbegin() - *numbers.begin();
}

int main(void){
    scanf("%d",&N);
    
    vector<int> numbers(N);
    
    for(int i=0;i<N;i++){
        scanf("%d",&numbers[i]);
    }
    
    sort(numbers.begin(),numbers.end());
    
    printf("%d\n%d\n%d\n%d\n",average(numbers),middle(numbers),least_value(numbers),range(numbers));
}
