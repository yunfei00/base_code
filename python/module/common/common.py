#!/usr/bin/env python3
# -- coding: utf-8 --

import tarfile
import os


version = '1.0.0 获取文件夹下文件'
#1 get_dircoty_files(file_dir)  获取文件夹下的文件

def get_dircoty_files(file_dir):
    if not os.path.exists(file_dir):
        return []
    file_list = []
    for root,dirs,files in os.walk(file_dir):
        for file in files:
            all_file_name = os.path.join(root,file)
            file_list.append(all_file_name)
    return file_list


if __name__ == '__main__':

    pass

