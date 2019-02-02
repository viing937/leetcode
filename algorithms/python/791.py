class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        m = {}
        for idx, ch in enumerate(S):
            m[ch] = idx
        rls = sorted(T, key=lambda x: -1 if x not in m else m[x])
        return ''.join(rls)
