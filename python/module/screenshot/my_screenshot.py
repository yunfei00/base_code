#!/usr/bin/python3
# -- coding: utf-8 --

import os
import re
import sys
import time
import pyscreenshot as ImageGrab

'''
1 截取屏幕并保存  暂时只验证linux版本
'''

def screenshot_save_pic(pic_name,pic_path):
    '''
    截取屏幕，并保存到指定位置
    '''
    cur_path = os.getcwd()
    if not os.path.exists(pic_path):
        return False
    os.chdir(pic_path)
    print(pic_name)
    im = ImageGrab.grab()
    #im = ImageGrab.grab(bbox=(10, 10, 510, 510))  # X1,Y1,X2,Y2
    im.save(pic_name)
    os.chdir(cur_path)
    #im.show()
    return True


if __name__=='__main__':
    name = "test.png"
    pic_path = "./"
    screenshot_save_pic(name,pic_path)

  
