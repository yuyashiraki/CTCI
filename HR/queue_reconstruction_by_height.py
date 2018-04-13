class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        sr = sorted(people[:], key=lambda psn: (psn[0], -psn[1]))
        fl = [True] * len(people)
        rt = [None] * len(people)
        for psn in sr:
            bfr = psn[1]
            for pos in range(len(fl)):
                if fl[pos]:
                    if 0 == bfr:
                        break
                    bfr -= 1
            rt[pos] = psn
            fl[pos] = False
        return rt
