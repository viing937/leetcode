import re

class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip()
        return bool(re.fullmatch(r'[+-]?(\d+|\d*\.\d+|\d+\.\d*)(e[+-]?\d+)?', s))
