#
# 接收两个表示9进制数的字符串，返回表示它们相加后的9进制数的字符串
# @param num1 string字符串 第一个加数
# @param num2 string字符串 第二个加数
# @return string字符串
#
class Solution:
    def add(self , num1:str , num2:str ):
        # write code here
        len1 = len(num1)
        len2 = len(num2)
        len1_int = 0
        len2_int = 0
        len1_dot = 0
        len2_dot = 0

        num1_dot_pos = num1.find('.')
        num2_dot_pos = num2.find('.')

        if num1_dot_pos == -1:
            len1_int = len1
        else:
            len1_int = num1_dot_pos
            len1_dot = len1 - num1_dot_pos - 1
        if num2_dot_pos == -1:
            len2_int = len2
        else:
            len2_int = num2_dot_pos
            len2_dot = len2 - num2_dot_pos - 1

        if len1_int < len2_int:
            num1 = '0' * (len2_int - len1_int) + num1
        elif len1_int > len2_int:
            num2 = '0' * (len1_int - len2_int) + num2
        if len1_dot < len2_dot:
            if len1_dot == 0:
                num1 = num1 + '.'
            num1 = num1 + '0' * (len2_dot - len1_dot)
        elif len1_dot > len2_dot:
            if len2_dot == 0:
                num2 = num2 + '.'
            num2 = num2 + '0' * (len1_dot - len2_dot) 

        len_tot = len(num1)
        ans = [None]*len_tot
        carry = 0
        for i in range(len_tot):
            if num1[len_tot - i - 1] == '.':
                ans[len_tot - i - 1] = '.'
                continue
            temp = int(num1[len_tot - i - 1]) + int(num2[len_tot - i - 1]) + carry
            carry = 0
            if temp >= 9:
                temp %= 9
                carry += 1
            ans[len_tot - i - 1] = temp
        
        result = ''
        for i in ans:
            result += str(i)
        if carry:
            result = '1' + result 
        return result

s = Solution()
print(s.add('1.00', '15'))
