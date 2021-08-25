# 目录

# 1 读取json文件内容,返回字典格式

```
with open('info.json','r',encoding='utf8') as fp:
	json_data = json.load(fp) 
```

# 2 将字典数据写入json文件

```
dict1 = {'name': '张三', 'age': 18, 'sex': '男'}
with open('info.json','a',encoding='utf8') as fp:
	json.dump(dict1,fp,ensure_ascii=False)　　
# 如果ensure_ascii ' '为false，则返回值可以包含非ascii值
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTE2MTU2NDYxNF19
-->