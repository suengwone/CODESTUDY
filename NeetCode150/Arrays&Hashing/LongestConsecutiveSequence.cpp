class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return 1;
        }
        else if(nums.size() == 0)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());
        unique(nums.begin(), nums.end());

        int count = 1, max = 0;
        for(int i=0; i<nums.size() - 1; i++)
        {
            if(nums[i + 1] - nums[i] == 1)
            {
                count += 1;
            }
            else
            {
                if(max < count)
                {
                    max = count;
                }

                if(nums[i+1] <= nums[i])
                {
                    break;
                }
                else
                {
                    count = 1;
                }
            }
        }

        if(max < count)
        {
            max = count;
        }

        return max;
    }
};
