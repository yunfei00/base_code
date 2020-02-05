#include "log.h"
#include <time.h>
#include <sys/time.h>
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;
    case QtInfoMsg:
        text = QString("Info:");
        break;
    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss-zzz");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(current_date).arg(text).arg(msg).arg(context_info);

//    time_t nowtime;
//    nowtime = time(NULL); //获取日历时间
//    struct tm *local,*gm;
//    local=localtime(&nowtime);  //获取当前系统时间

//    int year    = local->tm_year + 1900 ;
//    int mon     = local->tm_mon + 1     ;
//    int day     = local->tm_mday        ;
//    int hour    = local->tm_hour        ;
//    int minites = local->tm_min         ;
//    int second  = local->tm_sec         ;

//    char filename[128];
//    bzero(ret, sizeof(ret));
//    sprintf(ret, "%d_%02d_%02d.log", year, mon, day);

    QString filename = QDateTime::currentDateTime().toString("./log/yyyy_MM_dd.log");
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}
