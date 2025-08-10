# # 食材搭配
# import re
#
# ls = list()
# str = input()
# chinese = re.compile(r'[^\u4e00-\u9fa5]+')
# ch_ls = chinese.split(str)
# set1 = set(ch_ls)
# ls = sorted(set1)
# for i in range(len(ls)):
#     for j in range(i + 1, len(ls)):
#         print(f"{ls[i]}+{ls[j]}", end = " ")

# # 摩斯密码解密
# morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
# digit = ['-----', '.----', '..---', '...--', '....-', '.....', '-....', '--...', '---..', '----.']
# punctuation = {'.': '.-.-.-', ':': '---...', ',': '--..--', ';': '-.-.-.', '?': '..- -..', '=': '-...-', "'": '.----.', '/': '-..-.', '!': '-.-.--', '-': '-....-', '_': '..--.-', '"': '.-..-.', '(': '-.--.', ')': '-.--.-', '$': '...-..-', '&': '·-···', '@': '.--.-.', ' ': ''}
# morse_to_char = {value: key for key, value in punctuation.items()}
#
# str = input().split(' ')
# return_list = ""
# for i in str:
#     if i in morse:
#         return_list += chr(ord('a') + morse.index(i))
#     elif i in digit:
#         return_list += digit.index(i)
#     elif i in morse_to_char:
#         return_list += morse_to_char[i]
#     else:
#         return_list += i
# print(return_list)

# #  公式计算
# m = int(input())
# total = 0
# px = 1
# for i in range(1, m + 1):
#     px *= i
#     total += px
#
# print(total + 1) # 0的阶乘是1

# # 反素数
# def hunwen(num):
#     if str(num) == str(num)[::-1]:
#         return True
#     else:
#         return False
#
# def reverse(num):
#     re_num = int(str(num)[::-1])
#     return re_num
#
# def is_prime(x):
#     if x < 2:
#         return False
#     for i in range(2, int(x ** 0.5) + 1):
#         if x % i == 0:
#             return False
#     return True
#
# n, m = map(int, input().split())
# for i in range(n, m + 1):
#     if is_prime(i) and is_prime(reverse(i)) and not hunwen(i):
#         print(i , end = " ")

