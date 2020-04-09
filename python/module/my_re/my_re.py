#!/usr/bin/python3
# -- coding: utf-8 --

import re
import time
import math
version="1.0.0"
#1 返回行匹配的列表

def get_match_list(pattern_str,line):
    '''
    获取匹配到的列表 如果 没有匹配到  则返回空列表
    '''
    ret = []
    pattern = re.compile(r'{}'.format(pattern_str))
    ret = re.findall(pattern,line)

    return ret


if __name__ == '__main__':

    test = "AABBB2334sdf34435345436"
    ret = get_match_list('AA.*(\d{4})',test)
    print(ret)
    
    