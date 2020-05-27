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
>>>for tmp in res:
...     print(tmp)
... 
2020-05-01 星期五
2020-05-02 星期六
2020-05-03 星期日
2020-05-04 星期一
2020-05-05 星期二


begin_time = datetime.datetime(2020,5,1)
end_time = datetime.datetime(2020,5,10)
	

	

``` 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE0MTY4Njk2NDIsMTU5NjU4NzY3LC0xNz
M0MDY0NjkxLDEzOTk2NzY3MDBdfQ==
-->