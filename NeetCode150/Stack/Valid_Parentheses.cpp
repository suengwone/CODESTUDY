class Solution {
public:
    bool isValid(string s)
    {
        stack<char> save;

        if(s.size() % 2 != 0)
        {
            return false;
        }

        char temp;
        for(int i=0; i<s.size(); i++)
        {
            if(save.empty() != true)
            {
                temp = save.top();
            }
            else
            {
                temp = '.';
            }

            switch(s[i])
            {
                case '{':
                    save.push(s[i]);
                    break;
                case '(':
                    save.push(s[i]);
                    break;
                case '[':
                    save.push(s[i]);
                    break;
                case '}':
                    if(temp == '{')
                    {
                        save.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ')':
                    if(temp == '(')
                    {
                        save.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if(temp == '[')
                    {
                        save.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }

        return save.empty();
    }
};
