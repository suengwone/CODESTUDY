class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftMin = 10000;
        int answer = 0;

        for(int i=0; i<prices.size(); i++)
        {
            if(leftMin > prices[i])
            {
                leftMin = prices[i];
            }
            else if(leftMin < prices[i])
            {
                if(answer < prices[i] - leftMin)
                {
                    answer = prices[i] - leftMin;
                }
            }
        }

        return answer;
    }
};
