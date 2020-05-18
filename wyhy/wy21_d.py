#
# 
# @param boxes int整型二维数组 
# @return int整型
#
class Solution:
    def findBoxes(self, boxes, a, b, c):
        for i in range(self.len):
            if not self.used[i] and boxes[i][0] < a and boxes[i][1] < b and boxes[i][2] < c:
                self.used[i] = 1
                self.count += 1
                if self.count > self.ans:
                    self.ans = self.count
                self.findBoxes(boxes, boxes[i][0], boxes[i][1], boxes[i][2])
                self.count -= 1
                self.used[i] = 0

    def maxBoxes(self , boxes):
        self.len = len(boxes)
        self.count = 0
        self.ans = 0
        self.used = [0 for i in range(self.len)]
        self.findBoxes(boxes, 9999, 9999, 9999)
        return self.ans

s = Solution()
print(s.maxBoxes([[5,4,3], [5,4,5], [6,6,6]]))