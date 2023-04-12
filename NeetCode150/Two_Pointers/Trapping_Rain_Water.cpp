#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int start = 0, end = 0;
        int tempEnd = 0, tempIdx = 0;
        
        while(height[start] == 0)
        {
            start += 1;

            if(start >= height.size())
            {
                return 0;
            }
        }

        int answer = height[start];

        for(int i=start+1; i<height.size(); i++)
        {
            answer += height[i];

            if(height[start] <= height[i])
            {
                if(i - start == 1)
                {
                    start = i;
                }
                else
                {
                    end = i;
                }
            }
            else
            {
                if(height[i-1] <= height[i])
                {
                    if(tempEnd <= height[i])
                    {
                        tempEnd = height[i];
                        tempIdx = i;
                    }
                }
                else
                {
                    if(tempEnd != 0)
                    {
                        for(int j = start + 1; j < tempIdx; j++)
                        {
                            if(height[j] < tempEnd)
                            {
                                height[j] = tempEnd;
                            }
                        }
                        tempEnd = 0;
                        tempIdx = 0;
                    }
                }
            }

            if(end != 0)
            {
                for(int j = start + 1; j<end; j++)
                {
                    height[j] = height[start];
                }

                start = end;
                end = 0;
                tempEnd = 0;
                tempIdx = 0;
            }
        }

        for(int i = start + 1; i < tempIdx; i++)
        {
            if(height[i] < tempEnd)
            {
                height[i] = tempEnd;
            }
        }

        for(int i=0; i<height.size(); i++)
        {
            answer -= height[i];
        }

        return -answer;
    }
};

int main()
{
    Solution s;

    vector<int> height;
    int temp[] = {9,6,8,8,5,6,3};

    int size = sizeof(temp) / sizeof(temp[0]);

    for(int i=0; i<size; i++)
    {
        height.push_back(temp[i]);
    }

    cout << s.trap(height) << '\n';
}
