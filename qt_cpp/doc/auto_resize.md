# qt c++ 自动缩放大小文件使用说明
1. 添加文件到工程里
	[auto_resize文件](https://github.com/yunfei00/base_code/tree/master/qt_cpp/auto_resize)
2. 定义控制大小的对象，并重写 resizeEvent 函数
	```
	AutoResize *m_autoResizeHandler;    
	void resizeEvent(QResizeEvent * event);
	void Widget::resizeEvent(QResizeEvent *event)
	{
		Q_UNUSED(event);
		m_autoResizeHandler->doAutoResize();
	}
	```
3. 在初始化函数中，增加大小动态变化的控件(如果有table 需要设置为表格自适应)
    ```
    //自动缩放大小
    m_autoResizeHandler=new AutoResize(this,this->rect().width(),this->rect().height());
    m_autoResizeHandler->setAutoResizeFlag(
            AutoResize::INCLUDE_BUTTON|AutoResize::INCLUDE_COMBOBOX|
            AutoResize::INCLUDE_EDITOR|AutoResize::INCLUDE_LABEL|
            AutoResize::INCLUDE_TEXTBROSER|AutoResize::INCLUDE_GROUPBOX|
            AutoResize::INCLUDE_TABLEWIDGET
            );
    //add widget* manualy
    m_autoResizeHandler->pushAllResizeItem();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置表格宽度自适应
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置表格高度自适应

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTkyMDE3Mjc5OF19
-->