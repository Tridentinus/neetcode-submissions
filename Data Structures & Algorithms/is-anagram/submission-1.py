class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        S_letters = dict()
        T_letters = dict()

        for i in range(len(s)):
            if s[i] not in S_letters.keys():
                S_letters[s[i]] =1
            else:
                S_letters[s[i]] +=1
            if t[i] not in T_letters.keys():
                T_letters[t[i]] =1
            else:
                T_letters[t[i]] +=1
        if S_letters != T_letters:
            return False
        else:
            return True