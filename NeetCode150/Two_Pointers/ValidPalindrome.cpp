class Solution {
public:
    bool isPalindrome(string s) {
        // 아스키 코드로 32 차이
        // 인덱스 두개로 이동하면서 같은지 확인
        // 두 인덱스가 크로스하게 될때까지 동일한지 판단

        int frontIdx = 0;
        int backIdx = s.length() - 1;
        
        while(frontIdx < backIdx)
        {
            if((int)s[frontIdx] < 48 || (int)s[frontIdx] > 57)
            {
                if((int)s[frontIdx] < 97 || (int)s[frontIdx] > 122)
                {
                    if((int)s[frontIdx] >= 65 && (int)s[frontIdx] <= 90)
                    {
                        s[frontIdx] = tolower(s[frontIdx]);
                    }
                    else
                    {
                        frontIdx += 1;
                        continue;
                    }
                }
            }
            
            if((int)s[backIdx] < 48 || (int)s[backIdx] > 57)
            {
                if((int)s[backIdx] < 97 || (int)s[backIdx] > 122)
                {
                    if((int)s[backIdx] >= 65 && (int)s[backIdx] <= 90)
                    {
                        s[backIdx] = tolower(s[backIdx]);
                    }
                    else
                    {
                        backIdx -= 1;
                        continue;
                    }
                }
            }

            if(s[frontIdx] == s[backIdx])
            {
                frontIdx += 1;
                backIdx -= 1;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
