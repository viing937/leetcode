class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry, idx = 1, len(digits)-1
        while carry and idx >= 0:
            t = digits[idx]
            digits[idx] = (t + carry) % 10
            carry = (t + carry) // 10
            idx -= 1
        if carry:
            digits = [carry] + digits
        return digits
