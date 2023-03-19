class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letter(26,0);

        if(s.length() != t.length())
        {
            return false;
        }

        for(int i=0; i<s.length(); i++)
        {
            letter[s[i] - 'a'] += 1;
            letter[t[i] - 'a'] -= 1; 
        }

        for(int i=0; i<letter.size(); i++)
        {
            if(letter[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};
