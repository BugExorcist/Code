# morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
#          ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
# letter_list = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
#                "V", "W", "X", "Y", "Z"]
# letter_list_lower = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
#                      "u", "v", "w", "x", "y", "z"]
# digit = ['-----', '.----', '..---', '...--', '....-', '.....', '-....', '--...', '---..', '----.']
# digit_list = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
# punctuation = {'.': '.-.-.-', ':': '---...', ',': '--..--', ';': '-.-.-.', '?': '..- -..', '=': '-...-', "'": '.----.',
#                '/': '-..-.', '!': '-.-.--', '-': '-....-', '_': '..--.-', '"': '.-..-.', '(': '-.--.', ')': '-.--.-',
#                '$': '...-..-', '&': '·-···', '@': '.--.-.', ' ': ''}
#
# let_dict = dict(zip(letter_list, morse))
# letlow_dict = dict(zip(letter_list_lower, morse))
# dig_dict = dict(zip(digit_list, digit))
# morse_str = ''
# in_str = input()
#
# for ch in in_str:
#     if ch in let_dict:
#         morse_str += let_dict[ch] + " "
#     elif ch in letlow_dict:
#         morse_str += letlow_dict[ch] + " "
#     elif ch in dig_dict:
#         morse_str += dig_dict[ch] + " "
#     elif ch in punctuation:
#         morse_str += punctuation[ch] + " "
#     else:
#         morse_str += ch + " "
#
# print(morse_str)


# Tom
# Tom
# Bill
# Rose
# Tom
# Bill
# Bill
# Bill

# dict = {"Tom": 0, "Rose": 0, "Bill": 0}
# names = {"Tom", "Rose", "Bill"}
#
# for i in range(8):
#     input_str  = input()
#     if input_str  in dict:
#         dict[input_str ] += 1
# max_val = 0
# ta_name = ""
# for name in names:
#     if dict[name] > max_val:
#         max_val = dict[name]
#         ta_name = name
#
# print (ta_name + " " + str(max_val))

import random

txt = '''Ifthereisonlyoneargument,itmustbeadictionarymappingUnicode |ordinals(integers)orcharacterstoUnicodeordinals,stringsorNone. |Characterkeyswillbethenconvertedtoordinals. |Iftherearetwoarguments,theymustbestringsofequallength,and |intheresultingdictionary,eachcharacterinxwillbemappedtothe |characteratthesamepositioniny.Ifthereisathirdargument,it |mustbeastring,whosecharacterswillbemappedtoNoneintheresult.'''

txt_list = list(txt)
x, m1, n1, m2, n2 = map(int, input().split())

random.seed(x)
random.shuffle(txt_list)

lt1 = txt_list[m1:n1]
lt2 = txt_list[m2:n2]
dict1 = {}
dict2 = {}

for ch in lt1:
    if ch in dict1:
        dict1[ch] += 1
    else:
        dict1[ch] = 1

for ch in lt2:
    if ch in dict2:
        dict2[ch] += 1
    else:
        dict2[ch] = 1

both_have = set()
only_lt1 = set()
for ch in dict1.keys():
    if ch in dict2:
        both_have.add(ch)
    else:
        only_lt1.add(ch)

both_have = sorted(both_have)
only_lt1 = sorted(only_lt1)

print("lt1中出现了" + str(len(dict1)) + "个不同的字符")
print("lt2中出现了" + str(len(dict2)) + "个不同的字符")
print("同时出现在lt1和lt2中的字符为：" + " ".join(both_have))
print("出现在lt1，但没在lt2中的字符为：" + " ".join(only_lt1))

