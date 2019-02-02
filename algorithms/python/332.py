class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        tickets.sort()
        visited = [False] * len(tickets)
        rls = ['JFK']
        self.helper(tickets, visited, rls)
        return rls

    def helper(self, tickets, visited, rls):
        if len(rls) == len(tickets)+1:
            return True
        for i in range(len(tickets)):
            s, d = tickets[i]
            if s != rls[-1]:
                continue
            if visited[i]:
                continue
            visited[i] = True
            rls.append(d)
            if self.helper(tickets, visited, rls):
                return True
            rls.pop()
            visited[i] = False
        return False
