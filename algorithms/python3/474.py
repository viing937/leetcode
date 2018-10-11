class Solution:
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        strs.sort(key=len)
        dic = {}
        dic[(0, 0)] = 0
        for s in strs:
            zeroes = s.count('0')
            ones = len(s) - zeroes
            tmp = {}
            for k, v in dic.items():
                tmp[k] = v
                z, o = k
                if z + zeroes > m or o + ones > n:
                    continue
                tmp[(z+zeroes, o+ones)] = max(dic.get((z+zeroes, o+ones), 0), v + 1)
            dic = tmp
        return max(dic.values())
