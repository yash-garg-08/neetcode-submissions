class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dic = {}
        for i in nums:
            dic[i] = dic.get(i, 0) + 1
    
        for key in dic:
            if dic[key] > 1:
                return True
        return False