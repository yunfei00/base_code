# 1 time,datetime
1. 获取一段时间内的日期和星期
比如：2020-05-28 星期三
```
import time
import datetime
import pandas as pd
begin_time = '2020-05-01'
end_time = '2020-05-31'

def get_target_format(start_time,finish_time):
	data_week = []
	for current_date in pd.date_range(start=start_time,end=finish_time):
		
		current_time = datetime.datetime.strptime(str(current_date), "%Y-%m-%d %H:%M:%S")
		one_data = str(current_date).split(' ')[0]
		if current_time.weekday():
	

begin_time = datetime.datetime(2020,5,1)
end_time = datetime.datetime(2020,5,10)
	

	

``` 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEzNDU2NDkxNjIsMTU5NjU4NzY3LC0xNz
M0MDY0NjkxLDEzOTk2NzY3MDBdfQ==
-->