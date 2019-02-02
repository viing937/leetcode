from collections import defaultdict, deque

class Solution:
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        if S == T:
            return 0

        station2routeIdx = defaultdict(set)
        for idx, route in enumerate(routes):
            routes[idx] = set(route)
            for station in route:
                station2routeIdx[station].add(idx)

        queue = deque()
        visited = defaultdict(bool)
        for routeIdx in station2routeIdx[S]:
            queue.append((1, routeIdx))
            visited[routeIdx] = True

        while len(queue):
            time, routeIdx = queue.popleft()
            if T in routes[routeIdx]:
                return time
            for station in routes[routeIdx]:
                for routeIdx in station2routeIdx[station]:
                    if visited[routeIdx]:
                        continue
                    queue.append((time+1, routeIdx))
                    visited[routeIdx] = True
        return -1
