'''
Descripttion: my code for learning
Author: chenggong Pan
Date: 2023-11-09 21:15:26
LastEditors: chenggong Pan
LastEditTime: 2023-11-09 21:15:31
'''
# my python
n = int(input())
sum = 0

for  i in range(n):
    s = input().split("=")
    a = eval(s[0])
    b = s[-1]
    if b == '?':
        continue
    else:
        b = int(b)
        if a == b:
            sum = sum + 1
print(sum)
