class Solution {
public:
    vector<vector<int>> findNums(vector<int>& nums, int startIdx, int target)
    {
        int start = startIdx, end = nums.size() - 1;
        vector<vector<int>> tempAnswer;
        vector<int> temp;
        int prev = nums[start] - 1, next = nums[end] - 1;

        while(start<end)
        {
            if(nums[start] + nums[end] > -target)
            {
                end--;
            }
            else if(nums[start] + nums[end] < -target)
            {
                start++;
            }
            else
            {
                if(prev != nums[start] || next != nums[end])
                {
                    temp.push_back(nums[startIdx - 1]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);

                    tempAnswer.push_back(temp);
                    temp.clear();

                    prev = nums[start];
                    next = nums[end];
                }

                start++;
                end--;
            }
        }

        return tempAnswer;
    }

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> answer;
        vector<vector<int>> temp;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++)
        {
            temp = findNums(nums, i+1, nums[i]);

            if(temp.size() != 0)
            {
                for(int j=0; j<temp.size(); j++)
                {
                    answer.push_back(temp[j]);
                }
            }

            while(i < nums.size() - 1)
            {
                if(nums[i] == nums[i+1])
                {
                    i+=1;
                }
                else
                {
                    break;
                }
            }
        }

        return answer;
    }
};
