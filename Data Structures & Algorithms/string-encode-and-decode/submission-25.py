class Solution:

    def encode(self, strs: List[str]) -> str:
        s = ""

        for st in strs:
            s += str(len(st)) + "#" + st
        print(s)            
        return(s)
        
    def decode(self, s: str) -> List[str]:
        strs = []
        i = 0
        print("decoding",i)
        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            span = int(s[i:j])
            print(span)
            i = j +1
            if span == 0:
                st = ""
            else:
                st = s[i:i+span]
            print(st)
            strs.append(st)
            i+=span
            
        return strs
        