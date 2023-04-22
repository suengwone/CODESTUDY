class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // start point, end point
        // find max value in first area
        // after find max value, subtract first element and add next element at last
        int start = 0, maxValueIdx, maxValue;

        vector<int> answer;

        map<int,int,greater<int>> valueIdx;

        // first area
        for(int i=start; i<start+k; i++)
        {
            valueIdx[nums[i]] = i;
        }

        maxValueIdx = valueIdx.begin()->second;
        maxValue = valueIdx.begin()->first;

        answer.push_back(maxValue);

        while(start + k < nums.size())
        {
            start += 1;
            valueIdx[nums[start+k-1]] = start+k-1;

            if(nums[start+k-1] >= maxValue)
            {
                maxValue = nums[start+k-1];
                maxValueIdx = start + k - 1;
            }
            else
            {
                while(maxValueIdx < start)
                {
                    valueIdx.erase(valueIdx.begin());
                    if(valueIdx.empty() == true)
                    {
                        break;
                    }
                    maxValue = valueIdx.begin()->first;
                    maxValueIdx = valueIdx.begin()->second;
                }
            }


            answer.push_back(maxValue);
        }

        return answer;
    }
};
