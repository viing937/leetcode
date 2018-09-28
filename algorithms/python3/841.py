class Solution:
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        stack = [0]
        visited = [False] * len(rooms)
        while len(stack):
            nextvisit = stack.pop()
            visited[nextvisit] = True
            for key in rooms[nextvisit]:
                if not visited[key]:
                    stack.append(key)
        return False not in visited
