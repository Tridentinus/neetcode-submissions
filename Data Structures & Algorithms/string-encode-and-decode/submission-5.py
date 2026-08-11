class Solution:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        string = ""
        for s in strs:
            string += s + '\n'
        print(string)
        return string
        

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        currStr = ""
        dec = []
        i=0
        while i < len(s):
            if s[i] == '\n':
                dec.append(currStr)
                currStr = ""
            else:
                currStr += s[i]
            i+=1
        print(dec)
        return dec

                


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))