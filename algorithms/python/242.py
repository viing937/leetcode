class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s = ''.join(sorted(list(s)))
        t = ''.join(sorted(list(t)))
        return s == t
