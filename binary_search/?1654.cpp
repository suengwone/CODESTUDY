// 랜선 자르기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int split_lines(vector<int> lines, int need_count, int cutting_count) {
    int cut_length, cur_count;

    sort(lines.begin(), lines.end());

    int left = 0, right = lines.size() - 1;
    int mid = (left + right) / 2; 
    cut_length = lines[mid] / cutting_count;

    bool isFind = false;

    while(left <= right) {
        cur_count = 0;

        for(int i=0; i<lines.size(); i++) { 
            cur_count += lines[i] / cut_length;
        }

        if(cur_count > need_count) {
            left = mid + 1;
            int mid = (left + right) / 2;
            cut_length = lines[mid] / cutting_count;
        }
        else if(cur_count < need_count) {
            if(isFind){
                cut_length -= 1;
                break;
            }
            right = mid - 1;
            mid = (left + right) / 2;
            cut_length = lines[mid] / cutting_count;
        }
        else {
            isFind = true;
            cut_length++;
        }
    }

    if(!isFind) {
        while(true){
            cur_count = 0;

            cut_length--;

            for(int i=0; i<lines.size(); i++) { 
                cur_count += lines[i] / cut_length;
            }
            if (cur_count == need_count) break;
        }
    }

    return cut_length;
}

int main(void){
    int K, N;
    scanf("%d %d", &K, &N);

    vector<int> lines(K);
    for(int i=0; i<K;i++) {
        scanf("%d", &lines[i]);
    }

    printf("%d\n", split_lines(lines, N, N / K));
}
