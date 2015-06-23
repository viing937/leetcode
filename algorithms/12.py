class Solution:
    # @param {integer} num
    # @return {string}
    def __translate(self, num, one, five, ten):
        if  num < 4:
            return one*num
        elif num == 4:
            return one+five
        elif num < 9:
            return five+one*(num-5)
        else:
            return one+ten
    def intToRoman(self, num):
        ans = ''
        if num > 0:
            ans = self.__translate(num%10, "I", "V", "X")+ans
            num //= 10
        if num > 0:
            ans = self.__translate(num%10, "X", "L", "C")+ans
            num //= 10
        if num > 0:
            ans = self.__translate(num%10, "C", "D", "M")+ans
            num //= 10
        if num > 0:
            ans = self.__translate(num%10, "M", "", "")+ans
            num //= 10
        return ans

solution = Solution()
print(solution.intToRoman(3999))
