# import random
#
# f = ["♠", "♥", "♣", "♦"]
# d = ["2","3","4","5","6","7","8","9","10","J","Q","K","A"]
# jok = ["jokers", "JOKERS"]
# new = []
# for i in f:
#     for j in d:
#         new.append(i + j)
# new += jok
# p = input()
# seed = int(input())
# random.seed(seed)
# print("参与游戏的人数：" + p)
# print("新牌顺序")
# for i in new:
#     print(i, end=' ')
# random.shuffle(new)
# print("\n洗牌顺序")
# for i in new:
#     print(i, end=' ')
# print("\n每个人手上分到的牌")
# for i in range(int(p)):
#     ls = new[i: : int(p)]
#     for card in ls:
#         print(card, end = " ")
#     print("\n", end= "")
# print("每个人手上排序的牌")
# for i in range(int(p)):
#     ls = new[i: : int(p)]
#     ls.sort()
#     if "jokers" in ls:
#         ls.remove("jokers")
#         ls.append("jokers")
#     if "JOKERS" in ls:
#         ls.remove("JOKERS")
#         ls.append("JOKERS")
#     for i in ls:
#         print(i,end= " ")
#     print("\n", end= "")
import csv
import random

# key = 3
# text = 'Open Box PassWord:2021'
# for i in range(0, len(text)):
#     if text[i].isupper():
#         print(chr((ord(text[i]) - ord('A') + key) % 26 + ord('A')), end='')
#     elif text[i].islower():
#         print(chr((ord(text[i]) - ord('a') + key) % 26 + ord('a')), end='')
#     elif text[i].isdigit():
#         print(chr((ord(text[i]) - ord('0') + key) % 10 + ord('0')), end='')
#     else:
#         print(text[i], end='')

# def isPrime(x: int):
#     if x <= 2:
#         return False
#     else:
#         for i in range(2, x):
#             if x % i == 0:
#                 return False
#         return True
#
#
# ls = map(int, input().split())
# for i in ls:
#     if isPrime(i):
#         print(i, end=" ")

# a = eval(input())
# re_dict = {v:k for k, v in a.items()}
# print(re_dict)


# counts_dict = {}
# for key in range(8):
#     ch = input()
#     counts_dict[ch] = counts_dict.get(ch, 0) + 1
# sort_lt = sorted(list(counts_dict.items()), key=lambda x: x[1], reverse=True)
# print(sort_lt[0][0], sort_lt[0][1])


# morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
#          ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
# msdigit = ['-----', '.----', '..---', '...--', '....-', '.....', '-....', '--...', '---..', '----.']
# punctuation = {'.': '.-.-.-', ':': '---...', ',': '--..--', ';': '-.-.-.', '?': '..- -..', '=': '-...-', "'": '.----.',
#                '/': '-..-.', '!': '-.-.--', '-': '-....-', '_': '..--.-', '"': '.-..-.', '(': '-.--.', ')': '-.--.-',
#                '$': '...-..-', '&': '·-···', '@': '.--.-.', ' ': ''}
# upper = []
# looer = []
# digit = []
# for i in range(ord('A'), ord('Z') + 1):
#     upper.append(chr(i))
# for i in range(ord('a'), ord('z') + 1):
#     looer.append(chr(i))
# for i in range(10):
#     digit.append(i)
# upperdic = dict(zip(upper, morse))
# looerdic = dict(zip(looer, morse))
# digitdic = dict(zip(digit, msdigit))
#
# instr = input()
# for i in range(len(instr)):
#     if instr[i] in upperdic:
#         print(upperdic[instr[i]], end="")
#     elif instr[i] in looerdic:
#         print(looerdic[instr[i]], end="")
#     elif instr[i] in digitdic:
#         print(digitdic[instr[i]], end="")
#     elif instr[i] in punctuation:
#         print(punctuation[instr[i]], end="")
#     else:
#         print(instr[i], end="")


# txt = '''Ifthereisonlyoneargument,itmustbeadictionarymappingUnicode |ordinals(integers)orcharacterstoUnicodeordinals,stringsorNone. |Characterkeyswillbethenconvertedtoordinals. |Iftherearetwoarguments,theymustbestringsofequallength,and |intheresultingdictionary,eachcharacterinxwillbemappedtothe |characteratthesamepositioniny.Ifthereisathirdargument,it |mustbeastring,whosecharacterswillbemappedtoNoneintheresult.'''
# ls = list(txt)
# seed, n, m = map(int, input().split(" "))
# random.seed(seed)
# random.shuffle(ls)
# newls = ls[n: m + 1]
# dic = {}
# for i in newls:
#     if i in dic:
#         dic[i] += 1
#     else:
#         dic[i] = 1
#
# sls = sorted(dic.items(), key = lambda x: x[1], reverse=True)[:5]
# for key, val in sls:
#     print(key, val)


# def encryption(x: str):
#     rel = ""
#     for i in range(len(x)):
#         rel += str((ord(x[i]) + 5) % 10)
#     return rel[::-1]
#
#
# l = input()
# if l.isdigit():
#     if len(str(int(l))) != 4:
#         print("输入不合法！")
#     else:
#         re = encryption(l)
#         print(re)
# else:
#     print("输入不合法！")


# ch = list(input())
# new = ""
# for i in ch:
#     if 0 <= ord(i) <= 127:
#         new += " "
#     else:
#         new += i
# ls = sorted(set(new.split(" ")))
# for i in range(len(ls)):
#     for j in range(i + 1, len(ls)):
#         print(ls[i] + "+" + ls[j], end=" ")

# m = int(input())
# if m <= 1:
#     print("1")
# else:
#     num = 1
#     sum = 1
#     for i in range(1, m + 1):
#         num *= i
#         sum += num
#     print(sum)


# def isPrime(x: int):
#     if x <= 2:
#         return False
#     else:
#         for i in range(2, x):
#             if x % i == 0:
#                 return False
#         return True
#
#
# n, m = str(input()).split(" ")
# for i in range(int(n), int(m) + 1):
#     if isPrime(i) and isPrime(int(str(i)[::-1])) and str(i) != str(i)[::-1]:
#         print(i)


# with open('data.in', "r", encoding='utf-8') as fi:
#     lines = fi.readlines()
#     with open("data.out", 'w', encoding='utf-8')as fo:
#         for line in lines:
#             line = line.strip()
#             if line[0] == "姓":
#                 line = "姓名：" + line[-1] + "**"
#             elif line[0] == '身':
#                 line = line.replace(line[11:19], '*' * 8)
#             elif line[0] == '手':
#                 line = line.replace(line[7:11], "*" * 4)
#             fo.write(line + '\n')

# import csv
# import json
#
# with open("movie.in", 'r', encoding='utf-8') as f:
#     reader = csv.DictReader(f)
#     data = list(reader)
#
# with open('movie.out', 'w', encoding='utf-8') as f:
#     json.dump(data, f, ensure_ascii=False, indent=4)

# import csv
# with open("salary.in", "r", encoding="utf-8") as f:
#     reader = csv.reader(f)
#     title = next(reader)
#     title += ["一季度总收入"]
#     data = []
#     for line in reader:
#         id = line[0]
#         m1 = line[1]
#         m2 = line[2]
#         m3 = line[3]
#         total = int(m1) + int(m2) + int(m3)
#         data.append([id, m1, m2, m3, total])
#     data.sort(key= lambda x: x[4], reverse=True)
#
# with open("salary.out", "w", encoding="utf-8", newline="") as f:
#     writer = csv.writer(f)
#     writer.writerow(title)
#     writer.writerows(data)

# import csv
#
# with open('inf.in', 'r', encoding='utf-8') as fr:
#     with open('inf.out', 'w', encoding='utf-8', newline="") as fw:
#         writer = csv.writer(fw)
#         writer.writerow(['姓名', '手机号', '身份证号', '居住地'])
#         count = 0
#         data = []
#         for line in fr:
#             line.strip()
#             k, v = line.split('：')
#             v = v.strip()
#             data.append(v)
#             count += 1
#             if count == 4:
#                 writer.writerow(data)
#                 print(data)
#                 count = 0
#                 data = []

# import csv
#
# with open('sing.in', 'r', encoding='utf-8') as fr:
#     with open('sing.out', 'w', encoding='utf-8', newline="") as fw:
#         reader = csv.reader(fr)
#         info = {}
#         for line in reader:
#             name = line[0]
#             data = line[1:]
#             data = list(map(float, data))
#             data.sort()
#             data = data[1:-1]
#             total = 0
#             for i in data:
#                 total += float(i)
#             total /= len(data)
#             total = '{:.2f}'.format(total)
#             info[name] = total
#         ls = sorted(info.items(), key=lambda x: x[1] ,reverse=True)
#         for name, val in ls:
#             fw.write(f"{name}:{val}\n")


# import csv
# with open('weather.in', 'r', encoding='utf-8') as fr:
#     with open('weather.out', 'w', encoding='utf-8', newline="") as fw:
#         reader = csv.reader(fr)
#         writer = csv.writer(fw)
#         title = next(fr)
#         fw.write(title)
#         for line in reader:
#             if line[1] == '阴' and int(line[3].strip('℃')) >= 1:
#                 writer.writerow(line)

# import json
# import csv
# with open("movie_inf.in", 'r', encoding='utf-8') as f:
#     data = json.load(f)
#
# headline = list(data[0].keys())
# with open('movie_inf.out', 'w', encoding='utf-8', newline="") as f:
#     writer = csv.DictWriter(f, fieldnames=headline)
#     writer.writeheader()
#     for row in data:
#         writer.writerow(row)

# key = input().lower()
# txt = input()
# upper = []
# lower = []
# digit = []
# for i in range(26):
#     for j in range(26):
#         ch = [chr((i + j) % 26 + ord('A'))]
#         upper.append(ch)
#         ch = [chr((i + j) % 26 + ord('a'))]
#         lower.append(ch)
# for i in range(10):
#     for j in range(10):
#         ch = [chr((i + j) % 10 + ord('0'))]
#         digit.append(ch)
#
# row = 0
# for i in txt:
#     if i.islower():
#         print(lower[ord(key[row % len(key)]) - ord('a')][ord(i) - ord('a')], end='')
#     elif i.isupper():
#         print(upper[ord(key[row % len(key)]) - ord('a')][ord(i) - ord('A')], end='')
#     elif i.isdigit():
#         print(digit[(ord(key[row % len(key)]) - ord('a')) % 10][ord(i) - ord('0')], end='')
#     else:
#         print(i, end='')
#         row -= 1
#     row += 1


# key = input().lower()
# txt = input()
#
# def shift_char(c, shift):
#     if 'a' <= c <= 'z':
#         return chr((ord(c) - ord('a') + shift) % 26 + ord('a'))
#     elif 'A' <= c <= 'Z':
#         return chr((ord(c) - ord('A') + shift) % 26 + ord('A'))
#     elif '0' <= c <= '9':
#         return chr((ord(c) - ord('0') + shift) % 10 + ord('0'))
#     else:
#         return c
#
# key_len = len(key)
# key_shifts = [ord(k) - ord('a') for k in key]
#
# result = []
# row = 0
# for i in txt:
#     if i.isalnum():
#         shift = key_shifts[row % key_len]
#         result.append(shift_char(i, shift))
#         row += 1
#     else:
#         result.append(i)
#
# print(''.join(result))

key = input().lower()
txt = input()


def shift_char(ch, shift):
    if 'A' <= ch <= 'Z':
        return chr((ord(ch) - ord('A') + shift) % 26 + ord('A'))
    elif 'a' <= ch <= 'z':
        return chr((ord(ch) - ord('a') + shift) % 26 + ord('a'))
    elif '0' <= ch <= '1':
        return chr((ord(ch) - ord('0') + shift) % 10 + ord('0'))
    else:
        return ch


shifts = [ord(k) - ord('a') for k in key]
data = []
row = 0
for i in txt:
    if i.isalpha():
        shitf = shifts[row % len(key)]
        data.append(shift_char(i, shitf))
        row += 1
    else:
        data.append(i)

print(''.join(data))
