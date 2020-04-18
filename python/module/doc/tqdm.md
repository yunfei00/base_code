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
3. tqdm 进度描述
```
>>> from time import sleep
>>> from tqdm import tqdm
>>> pbar = tqdm(["a", "b", "c", "d"])                                                                                                      >>> for char in pbar:                                                              | 0/4 [00:00<?, ?it/s]
...     sleep(1)
...     pbar.set_description("Processing %s" % char)
... 
Processing d: 100%|███████████████████████████████████████████████████████| 4/4 [00:25<00:00,  6.39s/it]
>>> essing d: 100%|███████████████████████████████████████████████████████| 4/4 [00:25<00:00,  8.39s/it]
```
4. tqdm 手工更新
```
>>> from tqdm import tqdm
>>> from time import sleep

>>> with tqdm(total=100) as pbar:
...     
...     for i in range(10):
...             pbar.update(10)
...             sleep(0.1)
... 
100%|█████████████████████████████████████████████████████████████████| 100/100 [00:01<00:00, 99.50it/s]
```
# 3 tqdm高级用法

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTU4NDk3MjgyNCw3NTk3ODU3MzBdfQ==
-->