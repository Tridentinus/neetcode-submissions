class Solution:
    def isPalindrome(self, s: str) -> bool:
        L , R = 0, len(s)-1

        while L < R:
            lChar, rChar = s[L],s[R]
            print(lChar,rChar)
            if not lChar.isalnum():
                print(f"skipping {lChar}")
                L+=1
                continue
            if not rChar.isalnum():
                R-=1
                continue
            
            if s[L].lower() != s[R].lower():
                return False
            L+=1
            R-=1
        return True
