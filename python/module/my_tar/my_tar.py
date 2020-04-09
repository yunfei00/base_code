#!/usr/bin/env python3
# -- coding: utf-8 --

import tarfile
import os


version = '1.0.0 增加解压和压缩功能' 
#1 extract_tar_file(tar_file,out_dir='.')  解压tar包到指定路径
#2 create_tar_file(tar_file,input_dir) 打包


def extract_tar_file(tar_file,out_dir='.'):
    '''
    解压缩到指定路径
    '''
    tar = tarfile.open(tar_file)
    tar.extractall(path = out_dir)
    tar.close()

def create_tar_file(tar_file,input_dir):
    '''
    打包
    '''
    #'w:gz'	以gzip的方式压缩并写入
    tar = tarfile.open(tar_file,"w:gz")
    tar.add(input_dir)
    tar.close()


if __name__ == '__main__':
    
    
    tar_file = 'test.tar.gz'
    out_dir = '.'
    print(os.getcwd())
    create_tar_file(tar_file,'input')
    print(os.getcwd())

    extract_tar_file(tar_file)



    