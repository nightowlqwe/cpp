class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        ss << x;
        string str = ss.str();
        string rrr = ss.str();
        reverse(str.begin(), str.end());

        if (rrr == str) {
            return true;
        } else {
            return false;
        }
    }
};
