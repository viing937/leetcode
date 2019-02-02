from collections import Counter
class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        J = set(J)
        S = Counter(S)
        rls = sum(map(lambda x: S[x] if x in J else 0, S))
        return rls
