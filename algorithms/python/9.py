class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        x = str(x)
        return x == x[::-1]