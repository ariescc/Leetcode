class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        dic = dict()
        dic = {'U': 0, 'D': 0, 'L': 0, 'R': 0}
        for index in range(len(moves)):
            dic[moves[index]] += 1
        if dic['U'] == dic['D'] and dic['R'] == dic['L']:
            return True
        else:
            return False