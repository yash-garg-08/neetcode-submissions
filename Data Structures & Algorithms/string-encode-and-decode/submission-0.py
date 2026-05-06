class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for i in strs:
            length = len(i)
            res += str(length) + "#" + i
        return res

    def decode(self, s: str) -> List[str]:
        i = 0
        num = ""
        res = []
        while i < len(s):
            num = ""
            while s[i] != "#":
                num += s[i]
                i += 1
            num = int(num)
            res.append(s[i+1:i+num+1])
            i += num + 1
        return res