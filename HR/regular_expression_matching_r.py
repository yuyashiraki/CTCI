class Solution(object):
    def isMatch(self, text, pattern):
        dp = [[False] * (len(pattern) + 1)] * (len(text) + 1)
        dp[len(pattern)][len(text)] = True
        for i in range(len(text) - 1, -1, -1):
            for j in range(len(pattern) - 1, -1, -1):
                match = text[i] in {pattern[j], '.'}
                if j + 1 < len(pattern) && pattern[j+1] == '*':
                    dp[i][j] = match and dp[i+1][j] or dp[i][j+2]
                else:
                    dp[i][j] = match and dp[i+1][j+1]
