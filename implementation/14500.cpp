// 테트로미노

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int Max_value = 0, N, M;

pair<int,int> dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

void find_maxValue(int count, int cur_value, vector<vector<bool>> check, int row, int col){
    if(count == 4){
        Max_value = Max_value < cur_value ? cur_value : Max_value;
        return;
    }
    for(int i=0;i<4;i++){
        int move_row = dir[i].first + row;
        int move_col = dir[i].second + col;
        
        if(move_row >= 0 && move_col >=0 && move_row < N && move_col < M){
            if(check[move_row][move_col]) continue;
            check[move_row][move_col] = true;
            find_maxValue(count + 1, cur_value + board[move_row][move_col], check, move_row, move_col);
            check[move_row][move_col]=false;
        }
    }
    return;
}

int main(void){
    scanf("%d%d",&N,&M);
    
    board = vector<vector<int>>(N,vector<int>(M));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&board[i][j]);
        }
    }
    
    vector<vector<bool>> check(N,vector<bool>(M,false));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            check[i][j]=true;
            find_maxValue(1,board[i][j],check,i,j);
            check[i][j]=false;
        }
    }
    
    printf("%d\n",Max_value);
}
