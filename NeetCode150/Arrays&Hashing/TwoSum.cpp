class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        int tempAnswer;

        for(int i=0; i<nums.size(); i++)
        {
            tempAnswer = target - nums[i];

            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[j] == tempAnswer)
                {
                    answer.push_back(i);
                    answer.push_back(j);

                    return answer;
                }
            }
        }

        return answer;
    }
};
