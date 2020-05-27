# 1 time,datetime
1. 获取一段时间内的日期和星期
比如：2020-05-28 星期三
```
import time
import datetime
import pandas as pd
begin_time = '2020-05-01'
end_time = '2020-05-05'

def get_target_format(start_time,finish_time):
	data_week = []
	week_dict = {0:'星期一',1:'星期二',2:'星期三',3:'星期四',4:'星期五',5:'星期六',6:'星期日'}
	for current_date in pd.date_range(start=start_time,end=finish_time):
		
		current_time = datetime.datetime.strptime(str(current_date), "%Y-%m-%d %H:%M:%S")
		one_data = str(current_date).split(' ')[0]
		one_data += ' ' + week_dict[current_time.weekday()]
		data_week.append(one_data)
	return data_week
res = get_target_format(begin_time ,end_time)

for tmp in res:
	print(tmp)
2020-05-01 星期五
2020-05-02 星期六
2020-05-03 星期日
2020-05-04 星期一
2020-05-05 星期二
```

2. 计算两个时间中间的天数
```
import datetime

start_time = datetime.datetime(2020,5,1)
finish_time = datetime.datetime(2020,5,21)
diff = finish_time - start_time
diff.days + 1
21
```

3. 获取当前日期
```
>>> date_object = datetime.date.today()
>>> print(date_object)
2020-05-27
```
4. 从时间戳获取时间
```
import time
import datetime
current_time = datetime.datetime.fromtimestamp(time.time())
print(current_time)
2020-05-27 13:22:20.549956

current_date = datetime.date.fromtimestamp(time.time())
print(current_date)
2020-05-27
```
5. 获取年月日
```
>>> current_time = datetime.datetime.today()
>>>
print(current_time.year,current_time.month,current_date.day,current_time.hour,current_time.minute,current_time.second,current_time.microsecond)
2020 5 27 13 25 11 606496

>>> print(current_date.year,current_date.month,current_date.day)
2020 5 27



```
	

	

``` 
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTU5NDc4MzA1NiwtMTcwMzQ5MjMzMiwzOT
A0MjMyMjQsLTQ3OTc4Nzg4LDE1OTY1ODc2NywtMTczNDA2NDY5
MSwxMzk5Njc2NzAwXX0=
-->