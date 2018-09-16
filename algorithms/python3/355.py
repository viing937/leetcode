import heapq
from collections import defaultdict

class Twitter:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.timestamp = 0
        self.tweets, self.followers = defaultdict(list), defaultdict(set)

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        tweets, followers = self.tweets, self.followers
        tweets[userId].append((tweetId, self.timestamp))
        self.timestamp += 1

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        tweets, followers = self.tweets, self.followers
        pq = []
        if len(tweets[userId]) > 0:
            p = (-tweets[userId][-1][1], userId, len(tweets[userId])-1)
            heapq.heappush(pq, p)
        for twitter in followers[userId]:
            if len(tweets[twitter]) <= 0:
                continue
            p = (-tweets[twitter][-1][1], twitter, len(tweets[twitter])-1)
            heapq.heappush(pq, p)
        rls = []
        for i in range(10):
            if len(pq) <= 0:
                break
            _, twitter, idx = heapq.heappop(pq)
            rls.append(tweets[twitter][idx][0])
            if idx - 1 >= 0:
                heapq.heappush(pq, (-tweets[twitter][idx-1][1], twitter, idx-1))
        return rls

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId == followeeId:
            return
        tweets, followers = self.tweets, self.followers
        followers[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        tweets, followers = self.tweets, self.followers
        if followeeId not in followers[followerId]:
            return
        followers[followerId].remove(followeeId)

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
