# 1 tqdm 简介
Tqdm 是 Python 进度条库

# 2 tqdm 基本用法
1. tqdm 包裹一个可迭代对象，显示进度条信息，便于时间较长的处理时，查看处理进度。
```
>>> from tqdm import tqdm
>>> from time import sleep
>>> for i in tqdm(range(10000)):
...     sleep(0.001)
... 
100%|████████████████████████████████████████████████████████████| 10000/10000 [00:10<00:00, 921.99it/s]
>>> 
```

2. trange，和tqdm类似的一个工具
```
>>> from time import sleep
>>> from tqdm import trange
>>> for i in trange(10000):
...     sleep(0.001)
... 
100%|████████████████████████████████████████████████████████████| 10000/10000 [00:10<00:00, 923.32it/s]
```
# 3 tqdm高级用法

<!--stackedit_data:
eyJoaXN0b3J5IjpbNzU5Nzg1NzMwXX0=
-->