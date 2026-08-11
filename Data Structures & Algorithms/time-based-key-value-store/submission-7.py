class TimeMap:

    def __init__(self):
        self.dict = defaultdict(list)
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dict[key].append((value,timestamp))
    def get(self, key: str, timestamp: int) -> str:
        nums = [e[1] for e in self.dict[key]]

        if len(nums) < 1:
            return ""
        
        L, R = 0, len(nums)-1

        while L<=R:
            M = (L+R)//2
            if timestamp < nums[M]:
                R = M -1
            elif timestamp > nums[M]:
                L = M +1
            else:
                return self.dict[key][M][0]

        M = (L+R)//2
        if M>=len(nums):
            return self.dict[key][:-1][0]
        if M< 0:
            return ""

        return self.dict[key][R][0]      
