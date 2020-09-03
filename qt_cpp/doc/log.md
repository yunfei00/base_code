# qt c++ log 文件使用说明
1. 添加日志文件到工程里面
2. 根据具体需要，修改log.cpp文件中日志文件名称或者格式
	格式修改
	```
	QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss-zzz");
	QString current_date = QString("(%1)").arg(current_date_time);
	QString message = QString("%1 %2 %3 %4").arg(current_date).arg(text).arg(msg).arg(context_info);
	```
	名称及路径修改
	```
	QString filename = QDateTime::currentDateTime().toString("./log/yyyy_MM_dd.log");
	```
3. 在工程里面添加宏。打开日志输出
	```
	DEFINES += QT_MESSAGELOGCONTEXT
	```
4.  在程序开始的地方安装日志
	```
	qInstallMessageHandler(outputMessage);
	```
5. 使用日志
	```
	qDebug() << debug;
	qInfo() << info;
	qWarning() << warning;
	qCritical() << Critical;
	```
6. 发行版本不输出debug日志
在pro文件中增加``DEFINES += QT_NO_DEBUG_OUTPUT``
或者在头文件中


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTk5NzIzMTg4Miw1ODkxMTAzMjUsLTk2MD
k0OTA1N119
-->