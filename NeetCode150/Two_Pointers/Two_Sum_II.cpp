class Solution {
public:
    int findNum(vector<int>& numbers, int target, int startIdx)
    {
        int prevIdx = startIdx, nextIdx = numbers.size() - 1;
        int midIdx, answer = 0;

        while(prevIdx <= nextIdx)
        {
            midIdx = (prevIdx + nextIdx) / 2;

            if(target > numbers[midIdx])
            {
                prevIdx = midIdx + 1;
            }
            else if(target < numbers[midIdx])
            {
                nextIdx = midIdx - 1;
            }
            else
            {
                answer = midIdx;
                break;
            }
        }

        return answer;
    }

    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int remain, findIdx;
        vector<int> answer;

        for(int i=0; i<numbers.size() - 1; i++)
        {
            remain = target - numbers[i];
            findIdx = findNum(numbers, remain, i + 1);

            if(findIdx != 0)
            {
                answer.push_back(i+1);
                answer.push_back(findIdx+1);
                break;
            }
        }

        return answer;
    }
};
