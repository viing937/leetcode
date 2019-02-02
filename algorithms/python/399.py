class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        m, tokens = {}, set()
        for i in range(len(equations)):
            e, v = equations[i], values[i]
            tokens.update([e[0], e[1]])
            m[(e[0], e[1])] = v
            m[(e[1], e[0])] = 1/v
            m[(e[0], e[0])] = 1
            m[(e[1], e[1])] = 1

        for k in tokens:
            for i in tokens:
                for j in tokens:
                    if (i, k) in m and (k, j) in m:
                        m[(i, j)] = m[(i, k)] * m[(k, j)]

        rls = [m.get((q[0], q[1]), -1.0) for q in queries]
        return rls
