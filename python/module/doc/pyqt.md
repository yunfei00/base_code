# 目录

<h3><a href="#title1">1 ui 界面转化为python程序 </a> </h3>
<h3><a href="#title2">2 Excel中分列相关函数</a> </h3>
		<h4><ul><a href="#title2.1">2.1 LEFT函数</a> </h4>
		<h4><ul><a href="#title2.2">2.2 RIGHT函数</a> </h4>
		<h4><ul><a href="#title2.3">2.3 MID函数</a> </h4>
		<h4><ul><a href="#title2.4">2.4 SEARCH 函数</a> </h4>
		<h4><ul><a href="#title2.5">2.5 SUBSTITUTE 函数</a> </h4>
		<h4><ul><a href="#title2.6">2.6 FIND 函数</a> </h4>

<div style="page-break-after:always"></div>

  <h1 id="title1">1 ui 界面转化为python程序</h1>  
  windows电脑上，使用脚本tran_ui_to_python.bat  进行转换。
  脚本内容如下：
  
	```
	pyside2-uic %1  > ui.py
	```
直接把对应的ui文件，拖入脚本中，即可生成对应的ui.py文件。
**注意** 当ui文件中含有tabl了

<!--stackedit_data:
eyJoaXN0b3J5IjpbMjAyODUyNTA0NV19
-->