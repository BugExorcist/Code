ID = '659001200402241213'
birthday = ID[6:14]
if int(ID[-2])%2 == 0:
    m = "女"
else:
    m = "男"

print("生日是："+birthday+" 性别是："+m)

print("我叫{}，我的年龄是{}。".format("张三",18))