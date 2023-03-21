class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;

        for(auto element : nums)
        {
            mp[element]++;
        }

        priority_queue<pair<int,int>> queue;

        for(auto element : mp)
        {
            queue.push(make_pair(element.second, element.first));
        }

        vector<int> answer;
        while(k--)
        {
            answer.push_back(queue.top().second);
            queue.pop();
        }

        return answer;
    }
};
