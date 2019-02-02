class Solution:
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        rls = ''
        for word in d:
            cur = 0
            for ch in word:
                cur = s.find(ch, cur)
                if cur == -1:
                    break
                else:
                    cur += 1
            else:
                if len(word) > len(rls):
                    rls = word
                elif len(word) == len(rls):
                    rls = min(rls, word)
        return rls
