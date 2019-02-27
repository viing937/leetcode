class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs: return ''
        l, n = 0, min(map(len, strs))
        while l < n and all(map(lambda s: s[l] == strs[0][l], strs)):
            l += 1
        return strs[0][:l]
