class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int start = 0;
        int frequencyChar[26];
        int maxFrequency = 0;
        int answer = 0;

        for(int i=0; i<sizeof(frequencyChar)/sizeof(int); i++)
        {
            frequencyChar[i] = 0;
        }

        for(int end = 0; end<s.size(); end++)
        {
            int currentChar = s[end] - 'A';

            frequencyChar[currentChar] += 1;

            maxFrequency = max(maxFrequency, frequencyChar[currentChar]);

            if(end + 1 - start - maxFrequency > k)
            {
                int outgoingChar = s[start] - 'A';

                frequencyChar[outgoingChar] -= 1;

                start += 1;
            }

            answer = end + 1 - start;
        }

        return answer;
    }
};
