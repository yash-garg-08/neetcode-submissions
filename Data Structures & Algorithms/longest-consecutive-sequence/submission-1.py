class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numset = set(nums)
        longest = 0

        for i in numset:
            length = 1
            if i - 1 not in numset:
                while i + length in numset:
                    length += 1
                longest = max(longest, length)

        return longest 


        

        