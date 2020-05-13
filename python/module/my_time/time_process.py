#!/usr/bin/python3
# -- coding: utf-8 --

import re
import time
import math
version="1.0.0"
#1 将时间转换成时间戳
version="1.1.0"
#2 将时间戳转换成时间
#3 获取当前时间的时间戳
#4 获取当前时间的指定格式 2019-04-20 08:35:45 或者 2019-04-20 08:35:45-390

def trans_time_to_timestamp(my_time):
    '''
    将给定的事件格式转换成时间戳(当地时间，比如中国的1970-01-01 08:00:01 对应1s)
    时间必须按顺序包含 年 月 日 时 分 秒 （毫秒）
    例如：2016-05-05 20:28:54-254
    '''
    pattern_usecond = re.compile(r'(\d{4}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{6})')
    pattern_msecond = re.compile(r'(\d{4}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{3})')
    pattern_second = re.compile(r'(\d{4}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{2}).*?(\d{2})')
    try:
        ret = list(re.findall(pattern_usecond,my_time)[-1])
        #print(ret)#['1970', '01', '01', '08', '00', '01', '234567']
        dt = "{}-{}-{} {}:{}:{}".format(ret[0],ret[1],ret[2],ret[3],ret[4],ret[5])
        #转换成时间数组
        timeArray = time.strptime(dt, "%Y-%m-%d %H:%M:%S")
        #转换成时间戳
        timestamp = time.mktime(timeArray)
        timestamp += float(ret[6]) / 1000000.0
        #print(timestamp)
        return timestamp
    except:
        #print(e)
        pass


    try:
        ret = list(re.findall(pattern_msecond,my_time)[-1])
        #print(ret)#['1970', '01', '01', '08', '00', '01', '234']
        dt = "{}-{}-{} {}:{}:{}".format(ret[0],ret[1],ret[2],ret[3],ret[4],ret[5])
        #转换成时间数组
        timeArray = time.strptime(dt, "%Y-%m-%d %H:%M:%S")
        #转换成时间戳
        timestamp = time.mktime(timeArray)
        timestamp += float(ret[6]) / 1000.0
        #print(timestamp)
        return timestamp
    except:
        #print(e)
        pass
    
    try:
        ret = list(re.findall(pattern_second,my_time)[-1])
        #print(ret)#['2016', '05', '05', '20', '28', '54']
        dt = "{}-{}-{} {}:{}:{}".format(ret[0],ret[1],ret[2],ret[3],ret[4],ret[5])
        #转换成时间数组
        timeArray = time.strptime(dt, "%Y-%m-%d %H:%M:%S")
        #转换成时间戳
        timestamp = time.mktime(timeArray)
        #print(timestamp)
        return timestamp
    except Exception as e:
        #print("parameter is illegal. {}".format(my_time)) 
        return None

def trans_timestamp_to_time(timestamp):
    '''
    利用localtime()函数将时间戳转化成localtime的格式
    利用strftime()函数重新格式化时间
    '''
    #print(type(timestamp))
    #转换成localtime
    try:
        time_local = time.localtime(timestamp)
    #转换成新的时间格式(2016-05-05 20:28:54)
        dt = time.strftime("%Y-%m-%d %H:%M:%S",time_local)
        #print(dt)
        return dt
    except:
        #print(e)
        return None

def get_current_timestamp():
    '''
    获取当前时间的时间戳
    '''
    #获取当前时间
    time_now = time.time()
    #print(time_now)
    return time_now

def get_current_time(msecond_flag=False):
    '''
    获取当前时间
    默认返回不带毫秒，当参数为true时，带毫秒
    '''
    #获取当前时间
    time_now = time.time()

    #print(math.modf(time_now))
    time_second = math.modf(time_now)[1]
    msecond = math.modf(time_now)[0]
    #转换成localtime
    time_local = time.localtime(time_second)

    #转换成新的时间格式(2016-05-09 18:59:20)

    dt = time.strftime("%Y-%m-%d %H:%M:%S",time_local)
    if msecond_flag:
        #print(type(dt))
        #print(msecond)
        #msecond = 0.012
        dt = '{}-{:03d}'.format(dt,int(msecond * 1000))
    #print(dt)
    return dt

def diff_time(msecond1,msecond2):
    '''
    返回连个时间的秒差
    '''
    diff = abs(msecond1 - msecond2)
    return diff


if __name__ == '__main__':

    
    aa = 0x01
    if aa & 0x01:
        print("trans_time_to_timestamp test begin")
        dt = '1970-01-01 08:00:01'
        print("input is:{}".format(dt))
        print("ret is {}".format(trans_time_to_timestamp(dt)))

        dt = '1970-01-01 08:00:01-234'
        print("input is:{}".format(dt))
        print("ret is {}".format(trans_time_to_timestamp(dt)))

        
        dt = '1970-01-01 08:00:01'
        print("input is:{}".format(dt))
        print("ret is {}".format(trans_time_to_timestamp(dt)))

        dt = '1970-01-01 08:0'
        print("input is:{}".format(dt))
        print("ret is {}".format(trans_time_to_timestamp(dt)))

        dt = '1970-01-01 08:00:01-123456'
        print("input is:{}".format(dt))
        print("ret is {}".format(trans_time_to_timestamp(dt)))

        print("trans_time_to_timestamp test end")
    if aa & 0x02:
        print("trans_timestamp_to_time test begin")
        timestamp = 12
        print("input is:{}".format(timestamp))
        print("ret is {}".format(trans_timestamp_to_time(timestamp)))

        timestamp = 12.5
        print("input is:{}".format(timestamp))
        print("ret is {}".format(trans_timestamp_to_time(timestamp)))

        
        timestamp = "12"
        print("input is:{}".format(timestamp))
        print("ret is {}".format(trans_timestamp_to_time(timestamp)))

        timestamp = int(time.time())
        print("input is:{}".format(timestamp))
        print("ret is {}".format(trans_timestamp_to_time(timestamp)))

        print("trans_time_to_timestamp test end")

    if aa & 0x04:    
        print("get_current_timestamp test begin")
        print("current time stamp is {}".format(get_current_timestamp()))
        print("get_current_timestamp test end")

    if aa & 0x08:    
        print("get_current_time test begin")
        print("current time is {}".format(get_current_time()))
        print("current time with second is {}".format(get_current_time(True)))
        print("get_current_time test end")


