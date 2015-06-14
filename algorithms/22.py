class Solution:
    # @param {integer} n
    # @return {string[]}
    def generateParenthesis(self, n):
        s = set(["()"])
        news = set()
        for i in range(1,n):
            for com in s:
                for j in range(0,i*2):
                    news.add(com[:j]+"()"+com[j:])
            s = news.copy()
            news.clear()
        return list(s)

solution = Solution()
ans = solution.generateParenthesis(3)
print(ans)
