
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
1. 格式化时间，datefmt 参数的格式与 time.strftime() 支持的格式相同。
```
import logging
logging.basicConfig(format='%(asctime)s  %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p')
logging.warning('is when this event was logged.')
```
指令|意义|注释
|----|------|---|
%a|本地化的缩写星期中每日的名称|周六为 'Sat'
%A|本地化的星期中每日的完整名称|周六为 'Saturday'
%b|本地化的月缩写名称|二月为 'Feb'
%B|本地化的月完整名称|二月为 'February'
%c|本地化的适当日期和时间表示|当前时间：Sat Feb 22 13:28:57 2020
%d|十进制数 [01,31] 表示的月中日|哪一天
%H|十进制数 [00,23] 表示的小时（24小时制）|如：13
%I|十进制数 [01,12] 表示的小时（12小时制）|如：01
%j|十进制数 [001,366] 表示的年中日|如2020年2月22日 为'053'
%m|十进制数 [01,12] 表示的月
%M|十进制数 [00,59] 表示的分钟
%p|本地化的 AM 或 PM|如 PM
%S|十进制数 [00,61] 表示的秒|由于历史原因支持值 61
%U|十进制数 [00,53] 表示的一年中的周数（星期日作为一周的第一天）。在第一个星期**日**之前的新年中的所有日子都被认为是在第0周。
%w|十进制数 [0(星期日),6] 表示的周中日
%W|十进制数 [00,53] 表示的一年中的周数（星期一作为一周的第一天）。在第一个星期**一**之前的新年中的所有日子被认为是在第0周。
%x|本地化的适当日期表示|如 '02/22/20'
%X|本地化的适当时间表示|如 '13:40:30'
%y|十进制数 [00,99] 表示的没有世纪的年份
%Y|十进制数表示的带世纪的年份
%z|时区偏移以格式 +HHMM 或 -HHMM 形式的 UTC/GMT 的正或负时差指示，其中H表示十进制小时数字，M表示小数分钟数字 [-23:59, +23:59] |如：'+0800'
%Z|时区名称（如果不存在时区，则不包含字符）|如：'UTC'
%%|字面的 '%' 字符

# 8 logging 类
[logging 类参考官方文档](https://docs.python.org/zh-cn/3/library/logging.html#logging.basicConfig)


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE4Njk1ODEzOTksLTY1Mjc3NzkwNywtMT
A0MjcwODk1NywyMDM0NjgzNTQ2LDExMzUyODg0MTUsLTE3MzAz
ODQzOV19
-->