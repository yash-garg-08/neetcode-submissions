class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        array = []
        num = 1
        # left to right
        for i in nums:
            array.append([num])
            num *= i
        
        num = 1
        # right to left
        for idx, i in enumerate(nums[::-1]):
            array[len(nums) - 1 - idx].append(num)
            num *= i
        
        result = []

        for value in array:
            result.append(value[0] * value[1])
        
        return result