# 信息脱敏
# fr = open("data.in", "r", encoding='utf-8')
# fw = open("data.out", "w", encoding='utf-8')
#
# for line in fr:
#     if line[0] == "姓":
#         line = line.replace(line[3:5], '*' * 2)
#         line = line[3:6][::-1]
#         fw.write("姓名："+line+"\n")
#     elif line[0] == "居":
#         fw.write(line)
#     elif line[0] == "手":
#         line = line.replace(line[7:11], "*"*4)
#         fw.write(line)
#     elif line[0] == "身":
#         line = line.replace(line[11:19], "*" * 8)
#         fw.write(line)
#
# fr.close()
# fw.close()


# # csv存json格式
# import csv
# import json
#
# with open('movie.in', 'r', encoding='utf-8') as csv_file:
#     csv_reader = csv.DictReader(csv_file)
#     data = list(csv_reader)
#
# with open('movie.out', 'w', encoding='utf-8') as json_file:
#     json.dump(data, json_file, ensure_ascii=False, indent=4)



# csv文件计算
# import csv
# with open("salary.in", "r", encoding="utf-8") as fr:
#     csv_r = csv.reader(fr)
#     headline = next(csv_r) #读取并记录第一行到headline
#     data = []
#     for line in csv_r:
#         ID = line[0]
#         m1 = int(line[1])
#         m2 = int(line[2])
#         m3 = int(line[3])
#         total = m1+m2+m3
#         data.append([ID, m1, m2, m3, total])
#     data.sort(key = lambda x: x[4], reverse = True)
#
# with open("salary.out", "w", encoding="utf-8") as fw:
#     csv_w = csv.writer(fw)
#     csv_w.writerow(headline + ["一季度总收入"])
#     for i in data:
#         csv_w.writerow(i)


# # 信息存csv文件
# import csv
# with open('inf.in', 'r', encoding='utf-8') as f:
#     file = f.readlines()
#     info = {}
#     data = []
#     count = 0
#     for line in file:
#
#         line = line.strip() #删除行前后的空格和换行
#
#         key, value = line.split("：")
#         info[key] = value
#         count += 1
#         if count == 4:
#             data.append([info['姓名'],info['手机号'],info['身份证号'],info['居住地']])
#             count = 0
#             info = {}

# with open('inf.out', 'w', encoding='utf-8', newline='') as file:
#     fw = csv.writer(file)
#     fw.writerow(['姓名','手机号','身份证号','居住地'])
#     for line in data:
#         fw.writerow(line)

# # 唱歌比赛统计
# with open('sing.in', 'r', encoding='utf-8') as f:
#     dict = {}
#     for line in f:
#         items = line.strip().split(',')
#         name = items[0]
#         scores = [float(x) for x in items[1:]]
#         scores.sort()
#         scores = scores[1:-1]
#         ave = round(sum(scores) / 8, 2)
#         ave = '{:.2f}'.format(ave)
#         dict[name] = ave
# lst = sorted(dict.items(), key = lambda x: x[1], reverse= True)
# with open('sing.out', 'w', encoding='utf-8') as f:
#     for name, score in lst:
#         f.write(f'{name}:{score}\n')

# # 天气数据筛选
# with open('weather.in', 'r', encoding='utf-8') as f:
#     data = []
#     headline = f.readline()
#     data.append(headline)
#     lines = f.readlines()
#     for line in lines:
#         parts = line.split(',')
#         print(line, end='')
#         if parts[1] == '阴' and int(parts[3].strip("℃")) >= 1:
#             print('yes')
#             data.append(line)
#
# with open('weather.out', 'w', encoding='utf-8') as f:
#     for row in data:
#         f.write(row)

# json格式转存csv文件
import json
import csv
with open('movie_inf.in', 'r', encoding='utf-8') as f:
    data = json.load(f)

headline = list(data[0].keys())

with open('movie_inf.out', 'w', newline='', encoding='utf-8') as f:
    writer = csv.DictWriter(f, fieldnames = headline)
    writer.writeheader()
    for row in data:
        writer.writerow(row)


# key = input().lower()
# text = input()
# upper_words = []
# lower_words = []
# digit_words = []
# for i in range(26):
#     upper_list = [chr((i + j) % 26 + ord('A')) for j in range(26)]
#     upper_words.append(upper_list)
#     lower_list = [chr((i + k) % 26 + ord('a')) for k in range(26)]
#     lower_words.append(lower_list)
# for i in range(10):
#     digit_list = [chr((i + j) % 10 + ord('0')) for j in range(10)]
#     digit_words.append(digit_list)
#
# row = 0
# for ch in text:
#     if ch.islower():
#         print(lower_words[ord(key[row % len(key)]) - ord('a')][ord[ch] - ord('a')], end= '')
#     elif ch.isupper():
#         print(lower_words[ord(key[row % len(key)]) - ord('a')][ord[ch] - ord('A')],end= '')
#     elif ch.isdigit():
#         print(lower_words[(ord(key[row % len(key)]) - ord('a')) % 10][ord[ch] - ord('0')],end= '')
#     else:
#         print('ch', end='')
#         row -= 1
#     row += 1


