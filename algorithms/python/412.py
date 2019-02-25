class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def f(x):
            if not x % 15:
                return 'FizzBuzz'
            elif not x % 3:
                return 'Fizz'
            elif not x % 5:
                return 'Buzz'
            else:
                return str(i)
        return [f(i) for i in range(1, n+1)]
