from itertools import combinations

class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        rls = []
        for c in combinations(range(10), num):
            p = ['0'] * 10
            for t in c:
                p[t] = '1'
            hour = int(''.join(p[:4]), 2)
            minute = int(''.join(p[4:]), 2)
            if hour < 12 and minute < 60:
                rls.append('%d:%02d' % (hour, minute))
        return rls
