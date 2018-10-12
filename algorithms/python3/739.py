class Solution:
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        rls = [0] * len(T)
        m = {}
        for i in range(len(T)-1, -1, -1):
            if T[i] in m:
                rls[i] = m[T[i]] - i
            for j in range(30, T[i]):
                m[j] = i
        return rls
