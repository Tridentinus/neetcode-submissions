class Solution {
public:
    bool isPalindrome(string s) {
        size_t l =0;
        size_t r = s.size()-1;


        while (l <= r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (l >= r) return true;
            cout << tolower(s[l]) << " " << tolower(s[r]);
            cout << " " <<  s[l] << " " << s[r] << endl;
            if (tolower(s[l]) != tolower(s[r])) return false;

            l++; r--;
        }
        return true;
    }
};
