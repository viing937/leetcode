class Solution:
    def reachingPoints(self, sx, sy, tx, ty):
        """
        :type sx: int
        :type sy: int
        :type tx: int
        :type ty: int
        :rtype: bool
        """
        if sx == tx and sy == ty:
            return True
        elif tx == ty or sx > tx or sy > ty:
            return False
        elif tx > ty:
            subtract = max(1, (tx - sx) // ty)
            return self.reachingPoints(sx, sy, tx-ty*subtract, ty)
        else:
            subtract = max(1, (ty - sy) // tx)
            return self.reachingPoints(sx, sy, tx, ty-tx*subtract)
