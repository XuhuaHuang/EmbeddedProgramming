// https://leetcode.com/problems/first-letter-to-appear-twice

// case 1: "abccbaacz", ouput "c"
// case 2: "abcdd", output "d"
class Solution
{
public:
    char repeatedCharacter(string s)
    {
        char ans;
        int  min_index = INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    min_index = min(min_index, j);
                    ans       = s[min_index];
                    break;
                }
            }
        }
        return ans;
    }
};
