# 1 读写文件
1. 读取文件
```
#include  <QDebug>
#include  <QTextStream>
#include  <QStringList>

QFile  file("D:\\work\\data.csv");
if(!file.open(QIODevice::ReadOnly)){
	qDebug()<<"open  file  failed";
	return;
}
QTextStream  *  out  =  new  QTextStream(&file);//文本流
QStringList  tempOption  =  out->readAll().split("\n");//每行以\n区分
for(int  i  =  0  ;  i  <  tempOption.count()  ;  i++)
{
	QStringList  data  =  tempOption.at(i).split(",");//一行中的单元格以，区分
	qDebug()  <<  data;
}
file.close();//关闭文件
```
2. 写文件
<!--stackedit_data:
eyJoaXN0b3J5IjpbNTgwNjQ2MDcwLDU4MDY0NjA3MF19
-->