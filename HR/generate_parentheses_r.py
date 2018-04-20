# Solution using DP O(N^2)
# dp[0] = [""]
# dp[1] = ["()"]
# dp[2] = ["()()", "(())"]
# ...
# dp[i] = ["(dp[0])dp[i - 1]", "(dp[1])dp[i - 2]", "(dp[2])dp[i - 3]"]

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        dp = [[] for i in range(n + 1)]
        dp[0].append('')
        for i in range(n + 1):
            for j in range(i):
                dp[i] += ['(' + x + ')' + y for x in dp[j] for y in dp[i - j - 1]]
        return dp[n]

if __name__ == "__main__":
    sol = Solution()
    print sol.generateParenthesis(3)
