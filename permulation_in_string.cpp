class Solution {
public:
    bool isAlphaNum(char ch) {
        // Check if character is a digit or an alphabet letter
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;
        
        while (st < end) {
            // Skip non-alphanumeric characters from the left
            if (!isAlphaNum(s[st])) {
                st++;
            } 
            // Skip non-alphanumeric characters from the right
            else if (!isAlphaNum(s[end])) {
                end--;
            } 
            // Both characters are alphanumeric, so compare them
            else {
                if (tolower(s[st]) != tolower(s[end])) {
                    return false;
                }
                st++;
                end--;
            }
        }
        return true;
    }
};