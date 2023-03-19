class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> tempHash;

        for(int i=0; i<strs.size(); i++)
        {
            string tempStr = strs[i];
            sort(tempStr.begin(), tempStr.end());

            if(tempHash.find(tempStr) != tempHash.end())
            {
                tempHash[tempStr].push_back(strs[i]);
            }
            else
            {
                tempHash[tempStr].push_back(strs[i]);
            }
        }

        for(auto list : tempHash)
        {
            answer.push_back(list.second);
        }

        return answer;
    }
};
