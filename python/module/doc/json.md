# 目录

# 读取json文件内容,返回字典格式
with open('./source_file/info.json','r',encoding='utf8')as fp:
    json_data = json.load(fp) print('这是文件中的json数据：',json_data) print('这是读取到文件数据的数据类型：', type(json_data))
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEwNTE0MDU2NV19
-->