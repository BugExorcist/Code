# import matplotlib.pyplot as plt
#
# # 日期数据
# dates = ['2024-04-01','2024-04-08',  '2024-04-15','2024-04-22','2024-04-29','2024-05-06', '2024-05-13','2024-05-20','2024-05-27', '2024-06-03', '2024-06-10', '2024-06-17','2024-06-24','2024-07-01', '2024-07-08', '2024-07-15', '2024-07-22','2024-07-29','2024-08-05','2024-08-12','2024-08-19','2024-08-26','2024-09-02', '2024-09-09', '2024-09-16','2024-09-23','2024-09-30' ]
# # 对应日期的成本数据
# costs = [1200, 1200, 1200, 1200, 1200, 1200, 1352, 880, 880, 1236, 1320,1000,1200,1080,1100,1100,2700,1000,3000,2000,2000,2000,2000,2000,1360,1200,960]
#
# # 将日期转换成从第一天开始的天数
# from datetime import datetime
# dates = [datetime.strptime(date, "%Y-%m-%d") for date in dates]
# days = [(date - dates[0]).days for date in dates]
#
# cumulative_costs = [sum(costs[:i+1]) for i in range(len(costs))]
# # 绘制CBC曲线
# plt.plot(days, costs, marker='o')
# plt.title('Cumulative Budget Cost (CBC) Curve')
# plt.xlabel('Days Since Project Start')
# plt.ylabel('Cost (Currency)')
# plt.grid(True)
# plt.show()


import matplotlib.pyplot as plt

# 日期数据
dates = ['2024-04-01','2024-04-08',  '2024-04-15','2024-04-22','2024-04-29','2024-05-06', '2024-05-13','2024-05-20','2024-05-27', '2024-06-03', '2024-06-10', '2024-06-17','2024-06-24','2024-07-01', '2024-07-08', '2024-07-15', '2024-07-22','2024-07-29','2024-08-05','2024-08-12','2024-08-19','2024-08-26','2024-09-02', '2024-09-09', '2024-09-16','2024-09-23','2024-09-30' ]
# 对应日期的成本数据
costs = [1200, 1200, 1200, 1200, 1200, 1200, 1352, 880, 880, 1236, 1320,1000,1200,1080,1100,1100,2700,1000,3000,2000,2000,2000,2000,2000,1360,1200,960]

# 将日期转换成从第一天开始的天数
from datetime import datetime
dates = [datetime.strptime(date, "%Y-%m-%d") for date in dates]
days = [(date - dates[0]).days for date in dates]

cumulative_costs = [sum(costs[:i+1]) for i in range(len(costs))]
# 绘制CBC曲线
plt.plot(days, cumulative_costs, marker='o')
plt.title('Cumulative Budget Cost (CBC) Curve')
plt.xlabel('Days Since Project Start')
plt.ylabel('Cumulative Cost (Currency)')
plt.grid(True)
plt.show()

