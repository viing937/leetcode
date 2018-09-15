class Solution:
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        cur, rls, length = 0, '', len(indexes)
        rep = [(indexes[i], sources[i], targets[i]) for i in range(length)]
        rep.sort()
        for i in range(length):
            idx, src, tar = rep[i]
            if cur < idx:
                rls += S[cur:idx]
                cur = idx
            if S[idx:idx+len(src)] == src:
                rls += tar
                cur += len(src)
        rls += S[cur:]
        return rls
