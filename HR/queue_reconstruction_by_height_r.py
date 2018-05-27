class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        sr = sorted(people[:], key = lambda psn: (-psn[0], psn[1]))
        rt = []
        for psn in sr:
            rt.insert(psn[1], psn)
        return rt
