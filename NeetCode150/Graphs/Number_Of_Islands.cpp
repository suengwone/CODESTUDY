class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        typedef pair<int,int> point;
        int col[4] = {0,0,-1,1};
        int row[4] = {-1,1,0,0};
        int answer = 0;
        // bfs
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(),false));

        queue<point> remains;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(check[i][j] == false && grid[i][j] == '1')
                {
                    answer += 1;
                    remains.push(point(i,j));
                    check[i][j] = true;

                    while(remains.empty() != true)
                    {
                        point temp = remains.front();
                        remains.pop();
                        int tmpRow, tmpCol;

                        for(int i=0; i<4; i++)
                        {
                            tmpCol = temp.first + col[i];
                            tmpRow = temp.second + row[i];

                            if(tmpCol >= 0 && tmpRow >= 0 && tmpCol < grid.size() && tmpRow < grid[0].size())
                            {
                                if(grid[tmpCol][tmpRow] == '1' && check[tmpCol][tmpRow] == false)
                                {
                                    check[tmpCol][tmpRow] = true;
                                    remains.push(point(tmpCol,tmpRow));
                                }
                            }
                        }
                    }
                }
            }
        }

        return answer;        
    }
};
