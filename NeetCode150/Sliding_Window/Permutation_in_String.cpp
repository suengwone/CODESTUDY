class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int size_s1 = s1.length();
        int size_s2 = s2.length();
        
        sort(s1.begin(), s1.end());
        string temp;

        for(int i=0; i<=size_s2 - size_s1; i++)
        {
            temp = s2.substr(i, size_s1);
            sort(temp.begin(), temp.end());

            if(s1 == temp)
            {
                return true;
            }
        }

        return false;
    }
};
