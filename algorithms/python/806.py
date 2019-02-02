class Solution:
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        lines, units = 0, 0
        for ch in S:
            t = widths[ord(ch)-ord('a')]
            if units < t:
                lines += 1
                units = 100
            units -= t
        return [lines, 100-units]
