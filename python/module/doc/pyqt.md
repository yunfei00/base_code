# 目录

<h3><a href="#title1">1 ui 界面转化为python程序 </a> </h3>
<h3><a href="#title2">2 mainwindow.ui 文件显示 </a> </h3>
<h3><a href="#title3">3 widget.ui 文件显示 </a> </h3>
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
**注意** 当ui文件中含有table widget时，需要删除生成文件中的1 2 3 4等

  <h1 id="title2">2 mainwindow.ui 文件显示</h1>  
  新建python文件，将ui文件包含进来，并运行显示。

```
#!/usr/bin/python3
# -*- coding:UTF-8 -*-

import sys
from ui.ui import Ui_MainWindow
from PySide2.QtWidgets import QMainWindow,QApplication

class  MyWindow(QMainWindow, Ui_MainWindow):
	def  __init__(self, parent=None):
		super(MyWindow, self).__init__(parent)
		self.setupUi(self)

if  __name__ == '__main__':
	app = QApplication(sys.argv)
	window = MyWindow()
	window.setWindowTitle('test')
	window.show()
	sys.exit(app.exec_())
```


  <h1 id="title3">3 widget.ui 文件显示</h1>  
  新建python文件，将ui文件包含进来，并运行显示。

```
#!/usr/bin/python3
# -*- coding:UTF-8 -*-

class MyWidget(QtWidgets.QWidget, Ui_Widget):
    def __init__(self, parent=None):
        super(MyWidget, self).__init__(parent)
        self.setupUi(self)
```






<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE1NDMxODcxNjksLTEzOTk4OTI3NTcsMT
cwNTA1MzczMl19
-->