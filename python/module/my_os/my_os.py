#!/usr/bin/python3
# -- coding: utf-8 --

import os
import shutil
version="1.0.0"
#1 执行os命令

def excute_os_cmd(cmd):
    try:
        result = os.popen(cmd).readlines()
        return True,result
    except Exception as e:
        return False,e

def remove_directory(target_path):
    if os.path.exists(target_path):
        shutil.rmtree(target_path)
        
if __name__ == '__main__':

    test = "cd /home/jiayunfei/air/new_log/src_log_tar && /bin/tar xf air-hardware-20191022.tar.gz -C tmp2"
    is_ok,detail = excute_os_cmd(test)
    if not is_ok:
        print('excute cpmmand [{}] failed,reason is {}'.format(test,detail))
    
    