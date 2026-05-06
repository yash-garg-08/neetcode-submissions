class Solution:
    def checkAnag(self, a: str, b:str):
        return sorted(a) == sorted(b)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}

        for i in strs:
            temp = tuple(sorted(i))
            if temp in dic:
                dic[temp].append(i)
            else:
                dic[temp] = [i]

        result = []
        for key, values in dic.items():
            result.append(values)
        
        return result