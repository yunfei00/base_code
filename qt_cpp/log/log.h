#ifndef LOG_H
#define LOG_H

#include <QMutex>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

/*
//在main函数中注册qInstallMessageHandler
qInstallMessageHandler(outputMessage);
//打印日志到文件中
qDebug("This is a debug message");          //  qDebug：调试信息
qWarning("This is a warning message");      //  qWarning：警告信息
qCritical("This is a critical message");    //  qCritical：严重错误
qFatal("This is a fatal message");          //  qFatal：致命错误(会报错，然后准备退出)
*/

#endif // LOG_H
