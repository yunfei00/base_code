
# 1 logging 模块说明
logging 模块是python的标准库，[官方网址](https://docs.python.org/3/howto/logging.html)
# 2 logging 基本使用
1. 默认的打印级别为warning
```
import logging
logging.warning('Watch out!')  # will print a message to the console
logging.info('I told you so')  # will not print anything
```
2. 写入日志
```
import logging
logging.basicConfig(filename='example.log',level=logging.DEBUG)
logging.debug('This message should go to the log file')
logging.info('So should this')
logging.warning('And this, too’)
```
3. 输出日期
```
import logging
logging.basicConfig(format='%(asctime)s %(message)s')
logging.warning('is when this event was logged.’)
2010-12-12 11:41:42,612 is when this event was logged.

import logging
logging.basicConfig(format='%(asctime)s %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p')
logging.warning('is when this event was logged.’)
12/12/2010 11:46:36 AM is when this event was logged.
```

# 3 日志级别

|级别|说明|
|-----|---|
|DEBUG|细节信息，仅当诊断问题时适用。
|INFO|确认程序按预期运行
|WARNING|表明有已经或即将发生的意外（例如：磁盘空间不足）。程序仍按预期进行
|ERROR|由于严重的问题，程序的某些功能已经不能正常执行
|CRITICAL|严重的错误，表明程序已不能继续执行

默认的级别是``WARNING``，意味着只会追踪该级别及以上的事件，除非更改日志配置。
所追踪事件可以以不同形式处理。最简单的方式是输出到控制台。另一种常用的方式是写入磁盘文件。

# 4 配置文件使用
1. 配置文件
# 5 日志事件处理流程
# 6 日志文件使用说明
# 7 格式化配置
···import logging
logging.basicConfig(format='%(asctime)s  %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p')
logging.warning('is when this event was logged.')

<!--stackedit_data:
eyJoaXN0b3J5IjpbNDc5MTQ0ODg4LC02NTI3Nzc5MDcsLTEwND
I3MDg5NTcsMjAzNDY4MzU0NiwxMTM1Mjg4NDE1LC0xNzMwMzg0
MzldfQ==
-->