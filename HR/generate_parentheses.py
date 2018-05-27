from Queue import *

# Use recursion O(2^N)
'''
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        left = right = n
        rt = []
        def recur(left, right, comb):
            if left:
                recur(left - 1, right, comb + "(")
            if right > left:
                recur(left, right - 1, comb + ")")
            if left == right == 0:
                rt.append(comb)
        recur(left, right, "")
        return rt
'''

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        left = right = n
        rt = []
        q = Queue()
        q.put(("", left, right))
        # recursion can be converted to loop using Queue when top->bottom
        while not q.empty():
            n = q.get()
            cmb = n[0]
            left = n[1]
            right = n[2]
            if left == right == 0:
                rt.append(cmb)
            if left > 0:
                q.put((cmb + "(", left - 1, right))
            if right > left:
                q.put((cmb + ")", left, right - 1))
        return rt

if __name__ == "__main__":
    sol = Solution()
    print sol.generateParenthesis(3)
