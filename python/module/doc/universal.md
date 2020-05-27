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
5. 获取年月日时分秒毫秒
```
>>> current_time = datetime.datetime.today()
>>>
print(current_time.year,current_time.month,current_date.day,current_time.hour,current_time.minute,current_time.second,current_time.microsecond)
2020 5 27 13 25 11 606496

>>> current_date = datetime.date.today()
>>> print(current_date.year,current_date.month,current_date.day)
2020 5 27
```
6. 两个时间间隔的时间差
```
>>> from datetime import timedelta
>>> t1 = timedelta(weeks = 2, days = 5, hours = 1, seconds = 33)
>>> t2 = timedelta(days = 4, hours = 11, minutes = 4, seconds = 54)
>>> t3 = t1 - t2
>>> print("t3 =", t3)
t3 = 14 days, 13:55:39
``` 
7. 负时间差
```
>>> from datetime import timedelta
>>> t1 = timedelta(seconds = 33)
>>> t2 = timedelta(seconds = 54)
>>> t3 = t1 - t2
>>> print("t3 =", t3)
t3 = -1 day, 23:59:39
>>> print("t3 =", abs(t3))
t3 = 0:00:21
```
8. 用秒表示时间间隔
```
>>> from datetime import timedelta

>>> t = timedelta(days = 5, hours = 1, seconds = 33, microseconds = 233423)
>>> print("total seconds =", t.total_seconds())
total seconds = 435633.233423

```
9. 格式化输出
```
>>> from datetime import datetime
>>> now = datetime.now()
>>> 
>>> t = now.strftime("%H:%M:%S")
>>> print("time:", t)
time: 13:40:10
>>> 
>>> s1 = now.strftime("%m/%d/%Y, %H:%M:%S")
>>> print("s1:", s1)
s1: 05/27/2020, 13:40:10
>>> 
>>> s2 = now.strftime("%d/%m/%Y, %H:%M:%S")
>>> # dd/mm/YY H:M:S format
... print("s2:", s2)
s2: 27/05/2020, 13:40:10

``` 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE4ODIwNzE4MDEsMTEyOTM2NDk0OSwtMT
cwMzQ5MjMzMiwzOTA0MjMyMjQsLTQ3OTc4Nzg4LDE1OTY1ODc2
NywtMTczNDA2NDY5MSwxMzk5Njc2NzAwXX0=
-->