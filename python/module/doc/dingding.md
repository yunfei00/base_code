# 目录

<h3><a href="#title1">1 钉钉机器人设置</a> </h3>
<h3><a href="#title2">2 python 示例代码</a> </h3>


<div style="page-break-after:always"></div>

  <h1 id="title1">1 钉钉机器人设置</h1>  
  
  钉钉机器人设置，需要管理员权限，可参考 [机器人开发](https://ding-doc.dingtalk.com/doc?spm=a1zb9.8233112.0.0.340c3a88sgMlJJ#/serverapi2/qf2nxq)
  <h1 id="title2">2 python 示例代码</h1>  

python 代码如下
 ```
 #!/usr/bin/env python3
#author tom
import sys
import requests
import json

def dingSendMarkdown(out_str,target_url):
	headers={
		"Content-Type": "application/json"
	}
	
	data={
		"msgtype": "markdown",
		"markdown": {
			"text": out_str,
			"title": "体重零飘问题",
			}
		}
	
	json_data=json.dumps(data)
	#print(json_data)
	requests.post(url=target_url,data=json_data,headers=headers)

dingSendMarkdown(display_str,url_test)
 ```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjAwMjE1MjUyXX0=
-->