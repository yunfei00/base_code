
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
5 高级用法
logger = logging.getLogger(__name__)

# 3 日志级别
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTY2MzI0MDg3MSwtMTczMDM4NDM5XX0=
-->