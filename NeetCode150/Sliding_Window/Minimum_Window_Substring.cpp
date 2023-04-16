class Solution {
public:
    string minWindow(string s, string t)
    {
        if(s.length() == 0 || t.length() == 0)
        {
            return "";
        }
        vector<pair<int, char>> filterS;
        unordered_map<char,int> tCount;

        for(int i=0; i<t.size(); i++)
        {
            tCount[t[i]] += 1;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(t.find(s[i]) != string::npos)
            {
                filterS.push_back(make_pair(i,s[i]));
            }
        }

        int left = 0, right = 0;
        int required = tCount.size();
        int formed = 0;
        int ans[] = {-1,0,0};
        map<char, int> windowCounts;

        while(right < filterS.size())
        {
            char tempChar = filterS[right].second;
            windowCounts[tempChar] += 1;

            if(windowCounts[tempChar] == tCount[tempChar])
            {
                formed++;
            }

            while(left <= right && formed == required)
            {
                tempChar = filterS[left].second;

                int end = filterS[right].first;
                int start = filterS[left].first;

                if(ans[0] == -1 || end - start + 1 < ans[0])
                {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts[tempChar] -= 1;

                if(tCount[tempChar] > windowCounts[tempChar])
                {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return ans[0] == - 1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};Minimum Window Substring
