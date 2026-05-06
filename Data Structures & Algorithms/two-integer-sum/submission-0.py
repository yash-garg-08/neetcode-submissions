class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}

        for i in range(len(nums)):
            neg = target - nums[i]

            if neg in dic:
                return [dic[neg], i]
            
            dic[nums[i]] = i

        return []