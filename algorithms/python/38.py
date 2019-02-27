class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def say(s):
            rls, idx = '', 0
            ch, cnt = s[0], 0
            while idx < len(s):
                if ch == s[idx]:
                    cnt += 1
                else:
                    rls += str(cnt) + ch
                    ch, cnt = s[idx], 1
                idx += 1
            rls += str(cnt) + ch
            return rls

        s = '1'
        for _ in range(n-1):
            s = say(s)
        return s
