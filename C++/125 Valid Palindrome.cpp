using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string res;
        for (auto &c : s)
        {
            if (isalpha(c) || isdigit(c))
            {
                if (isupper(c))
                    res += tolower(c);
                else
                    res += c;
            }
        }
        int n = res.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (res[i] != res[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};