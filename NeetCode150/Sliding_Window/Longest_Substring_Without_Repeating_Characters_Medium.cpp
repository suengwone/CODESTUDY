class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), answer = 0;
        unordered_map<char, int> uniqueChar;

        for(int i=0, j=0; j<n; j++)
        {
            if(uniqueChar[s[j]] > 0)
            {
                i = max(uniqueChar[s[j]], i);
            }
            answer = max(answer, j - i + 1);
            uniqueChar[s[j]] = j + 1;
        }

        return answer;
    }
};
