class TimeMap:
    #constructor
    def __init__(self):
        self.Store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.Store:
            self.Store[key] = []
        self.Store[key].append([value,timestamp])
        
    #a classic search would be O(n)
    #we opt for binary one
    def get(self, key: str, timestamp: int) -> str:
        res = ""
        values = self.Store.get(key,[]) #pull the list for key (init to empty ([]) if not set yet)
        l,r =0, len(values) -1
        while l <= r:
            m = (l + r)//2
            if values[m][1] <= timestamp:    
                res = values[m][0]
                l = m + 1
            else:
                r = m - 1
        return res
