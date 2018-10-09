from random import randint

class Solution(object):
    def __init__(self, N, blacklist):
        """
        :type N: int
        :type blacklist: List[int]
        """
        N, blacklist = N-1, set(blacklist)
        M, m = N - len(blacklist), {}
        for b in blacklist:
            if b <= M:
                while N in blacklist:
                    N -= 1
                m[b] = N
                N -= 1
        self.M, self.m = M, m

    def pick(self):
        """
        :rtype: int
        """
        r = randint(0, self.M)
        if r in self.m:
            return self.m[r]
        else:
            return r

# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
