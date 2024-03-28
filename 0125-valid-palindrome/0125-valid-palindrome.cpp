// This problem is to check for "alphanemerical" palindrome, not just alphabetical palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        for(auto& x:s)
        {
            x = tolower(x);
        }

        if(s.size() == 1)
        {
            return true;
        }

        while(left < right)
        {
            while(left < right && isalpha(s[left]) == 0 && isdigit(s[left]) == 0)
            {
                left++;
            }
        
            while(left < right && isalpha(s[right]) == 0 && isdigit(s[right]) == 0)
            {
                right--;
            }
        
            if(isalpha(s[left]) == 0 && isalpha(s[right]) == 0 && isdigit(s[left]) == 0 && isdigit(s[right]) == 0)
            {
                return true;
            }
            else if(s[left] != s[right])
            {
                return false;
            }
            
            left++;
            right--;
        }

        return true;
    }
};
