from bisect import bisect_left


class Solution:
    def buildArr(self, word1, word2):
        m = {}
        for idx, ch in enumerate(word2):
            if ch not in m:
                m[ch] = []
            m[ch].append(idx)
        arr = []
        for ch in word1:
            if ch in m:
                arr += m[ch][::-1]
        return arr

    def lis(self, arr):
        if not arr:
            return 0
        dp = [arr[0]]
        for num in arr:
            idx = bisect_left(dp, num)
            if idx == len(dp):
                dp.append(num)
            else:
                dp[idx] = num
        return len(dp)

    def minDistance(self, word1: str, word2: str) -> int:
        arr = self.buildArr(word1, word2)
        rls = self.lis(arr)
        return len(word1) + len(word2) - 2 * rls
