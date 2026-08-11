class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        nCount = {}
        freq = [[] for i in range(len(nums)+1)]
        for n in nums:
            nCount[n] = nCount.get(n,0) +1
        
        freqDict= defaultdict(list)
        for n,c in nCount.items():
            freq[c].append(n)

        res = []
        for c in reversed(freq):
            for n in c:
                res.append(n)
                if len(res) == k:
                    return res
