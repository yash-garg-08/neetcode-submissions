class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}

        for i in nums:
            freq[i] = freq.get(i, 0) + 1
        
        sorted_freq = dict(sorted(freq.items(), key=lambda item : item[1], reverse=True))

        result = []
        c = 0
        for key, val in sorted_freq.items():
            if c == k:
                break
            result.append(key)
            c += 1
        return result
            
