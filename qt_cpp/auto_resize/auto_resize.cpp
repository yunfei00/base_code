#include "auto_resize.h"
#include <QLabel>
#include <QMapIterator>
#include <QObject>
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>
#include <QLayout>
#include <QTextBrowser>
#include <QDebug>
#include <QTableWidget>

AutoResize::AutoResize(QWidget* obj,float base_width,float base_height):m_autoResizeObj(obj)
{
    m_autoResize=false;
    m_baseWidth=base_width;
    m_baseHeight=base_height;
    m_horRatio=1.0;
    m_verRatio=1.0;
    m_fontRatio=1.0;
    dealLayoutItems();
}


AutoResize::~AutoResize(void)
{
}

void AutoResize::pushAllResizeItem()
{
    //qDebug()<<"get item start";
    QWidget *item=NULL;
    AutoResizeOriginalData resizeData;
    QRect tmp;
    //add other items
    for(QList<QWidget*>::iterator it=m_otherItem.begin();it!=m_otherItem.end();it++)
    {
        //qDebug()<<*it;
        item=*it;
        tmp=item->geometry();
        tmp.setX(item->x());
        tmp.setY(item->y());
        tmp.setWidth(abs(tmp.width()));
        tmp.setHeight(abs(tmp.height()));
        resizeData.data_rect=tmp;
        resizeData.data_font=item->font();
        m_resizeMap[item]=resizeData;
    }
    if(m_autoResizeFlag&INCLUDE_LABEL)
    {
        QList<QLabel*> _labelList=m_autoResizeObj->findChildren<QLabel *>();
        for(QList<QLabel*>::iterator it=_labelList.begin();it!=_labelList.end();it++)
        {
            item=*it;
            tmp=item->geometry();
            tmp.setX(item->x());
            tmp.setY(item->y());
            tmp.setWidth(abs(tmp.width()));
            tmp.setHeight(abs(tmp.height()));
            resizeData.data_rect=tmp;
            resizeData.data_font=item->font();
            m_resizeMap[item]=resizeData;
        }
    }
    if(m_autoResizeFlag&INCLUDE_COMBOBOX)
    {
        QList<QComboBox*> _comboxList=m_autoResizeObj->findChildren<QComboBox *>();
        for(QList<QComboBox*>::iterator it=_comboxList.begin();it!=_comboxList.end();it++)
        {
            item=*it;
            tmp=item->geometry();
            tmp.setX(item->x());
            tmp.setY(item->y());
            tmp.setWidth(abs(tmp.width()));
            tmp.setHeight(abs(tmp.height()));
            resizeData.data_rect=tmp;
            resizeData.data_font=item->font();
            m_resizeMap[item]=resizeData;
        }
    }
    if(m_autoResizeFlag&INCLUDE_BUTTON)
    {
        QList<QAbstractButton*> _buttonList=m_autoResizeObj->findChildren<QAbstractButton*>();
        for(QList<QAbstractButton*>::iterator it=_buttonList.begin();it!=_buttonList.end();it++)
        {
            //qDebug()<<*it;
            item=*it;
            tmp=item->geometry();
            tmp.setX(item->x());
            tmp.setY(item->y());
            tmp.setWidth(abs(tmp.width()));
            tmp.setHeight(abs(tmp.height()));
            resizeData.data_rect=tmp;
            resizeData.data_font=item->font();
            m_resizeMap[item]=resizeData;
        }
    }
    if(m_autoResizeFlag&INCLUDE_TEXTBROSER)
    {
        QList<QTextBrowser*> _textBroserList=m_autoResizeObj->findChildren<QTextBrowser*>();
        for(QList<QTextBrowser*>::iterator it=_textBroserList.begin();it!=_textBroserList.end();it++)
        {

            item=*it;
            tmp=item->geometry();
            tmp.setX(item->x());
            tmp.setY(item->y());
            tmp.setWidth(abs(tmp.width()));
            tmp.setHeight(abs(tmp.height()));
            resizeData.data_rect=tmp;
            resizeData.data_font=item->font();
            m_resizeMap[item]=resizeData;
        }
    }
    if(m_autoResizeFlag&INCLUDE_EDITOR)
    {
        QList<QLineEdit*> _editorList=m_autoResizeObj->findChildren<QLineEdit*>();
        for(QList<QLineEdit*>::iterator it=_editorList.begin();it!=_editorList.end();it++)
        {
            item=*it;
            tmp=item->geometry();
            tmp.setX(item->x());
            tmp.setY(item->y());
            tmp.setWidth(abs(tmp.width()));
            tmp.setHeight(abs(tmp.height()));
            resizeData.data_rect=tmp;
            resizeData.data_font=item->font();
            m_resizeMap[item]=resizeData;
        }
    }
    if(m_autoResizeFlag&INCLUDE_GROUPBOX)
    {
        QList<QGroupBox*> _groupBoxList=m_autoResizeObj->findChildren<QGroupBox*>();
        for(QList<QGroupBox*>::iterator it=_groupBoxList.begin();it!=_groupBoxList.end();it++)
        {
            item=*it;
            tmp=item->geometry();
            tmp.setX(item->x());
            tmp.setY(item->y());
            tmp.setWidth(abs(tmp.width()));
            tmp.setHeight(abs(tmp.height()));
            resizeData.data_rect=tmp;
            resizeData.data_font=item->font();
            m_resizeMap[item]=resizeData;
        }
    }

    if(m_autoResizeFlag&INCLUDE_TABLEWIDGET)
    {
        QList<QTableWidget*> _tableWighetList=m_autoResizeObj->findChildren<QTableWidget*>();
        for(QList<QTableWidget*>::iterator it=_tableWighetList.begin();it!=_tableWighetList.end();it++)
        {
            item=*it;
            tmp=item->geometry();
            tmp.setX(item->x());
            tmp.setY(item->y());
            tmp.setWidth(abs(tmp.width()));
            tmp.setHeight(abs(tmp.height()));
            resizeData.data_rect=tmp;
            resizeData.data_font=item->font();
            m_resizeMap[item]=resizeData;

        }
    }
    for(QList<QWidget*>::iterator it=m_ignoreItem.begin();it!=m_ignoreItem.end();it++)
    {
        if(m_resizeMap.contains(*it))
            m_resizeMap.remove(*it);
    }

    m_autoResize=true;
}

float AutoResize::getHorResizeRatio()
{
    return m_horRatio;
}

float AutoResize::getVerResizeRatio()
{
    return m_verRatio;
}

float AutoResize::getFontResizeRatio()
{
    return m_fontRatio;
}

void AutoResize::calculateResizeRatio()
{
    m_horRatio=m_autoResizeObj->width()/m_baseWidth;
    m_verRatio=m_autoResizeObj->height()/m_baseHeight;
    m_fontRatio=m_horRatio<m_verRatio?m_horRatio:m_verRatio;

    //qDebug() << "m_horRatio is:" << m_horRatio;
    //qDebug() << "m_verRatio is:" << m_verRatio;
    //qDebug() << "m_fontRatio is:" << m_fontRatio;

}

void AutoResize::fontAutoResize(QWidget *obj,int fontSize)
{
    //qDebug()<<"set"<<obj<<fontSize;
    if(fontSize<=0)
        return;
    bool hasTextStyle=false;
    fontSize*=m_fontRatio;
    QString fontTextReg="font:\\s+[0-9]+pt";
    QString fontFormat="font: %1pt";
    QString fontSizeReg="[0-9]+";
    QRegExp reg=QRegExp(fontTextReg);
    QRegExp size=QRegExp(fontSizeReg);
    QString styleText=obj->styleSheet();
    QString fontText="";
    QString fontSizeText="";
    QFont changedFont;
    if(reg.indexIn(obj->styleSheet())!=-1)
    {
        fontText=reg.capturedTexts().at(0);
        if(size.indexIn(fontText)!=-1)
        {
            hasTextStyle=true;
        }
    }
    //set stylesheet to change font size
    if(hasTextStyle)
    {
        styleText.replace(reg,fontFormat.arg(fontSize));
        obj->setStyleSheet(styleText);
    }
    //set font pointsize to change font size
    else
    {
        changedFont=obj->font();
        changedFont.setPointSize(fontSize);
        obj->setFont(changedFont);
    }
}

void AutoResize::dealLayoutItems()
{
    //QString desName="layoutWidget";
    QString desName="widget";
    QString layout_ignore = "layout widget find below:\n";
    int count = 0;
    QList<QLayout*> layoutList=m_autoResizeObj->findChildren<QLayout*>();
    for(QList<QLayout*>::iterator it=layoutList.begin();it!=layoutList.end();it++)
    {
        QString objName=(*it)->parent()->objectName();
        //qDebug()<<"layout parent:"<<objName << endl;
        if(objName.contains(desName) || objName.contains("Widget")|| objName.contains("frame"))
        {
            qDebug()<<"find layoutWidget:"<<*it << endl;
            count++;
            layout_ignore += "number[" + QString::number(count) + "]:" + (*it)->objectName() + "\n";
            QWidget* layoutWidget=qobject_cast<QWidget*>((*it)->parent());
            m_otherItem.push_back(layoutWidget);
            ignoreAllChiledren(layoutWidget);
        }
    }
    //qDebug()<<layout_ignore;

}

void AutoResize::ignoreAllChiledren(QObject* obj)
{
    QList<QObject*> children=obj->children();
    static int count_ignore = 0;
    for(QList<QObject*>::iterator it=children.begin();it!=children.end();it++)
    {

        QWidget *item=qobject_cast<QWidget*>(*it);

        m_ignoreItem.push_back(item);
        AutoResizeOriginalData resizeData;
        if(!item)
            continue;
        count_ignore++;
        resizeData.data_font=item->font();
        m_fontMap[item]=resizeData;
    }
    //qDebug() << "ignore unmber is:" << QString::number(count_ignore) << endl;
}

void AutoResize::addOtherItem(QWidget *other)
{
    m_otherItem.push_back(other);
}

void AutoResize::addIgnoreItem(QWidget *ignore)
{
    m_ignoreItem.push_back(ignore);
}

void AutoResize::setAutoResizeFlag(int flag)
{
    m_autoResizeFlag=flag;
}

void AutoResize::doAutoResize()
{
    calculateResizeRatio();
    if(m_autoResize)
    {
        QMapIterator<QWidget*, AutoResizeOriginalData> _itarator(m_resizeMap);
        QFont changedFont;
        int i = 0;
        while(_itarator.hasNext())
        {
            _itarator.next();
            i++;
            QWidget* _item=_itarator.key();
            //qDebug() << "object name is:" <<_item->objectName() << endl;


            QRect tmp=_itarator.value().data_rect;
            tmp.setWidth(tmp.width()*m_horRatio);
            tmp.setHeight(tmp.height()*m_verRatio);
            QRect after=QRect(tmp.x()*m_horRatio,tmp.y()*m_verRatio,tmp.width(),tmp.height());
            //changed font
            changedFont=_itarator.value().data_font;
            fontAutoResize(_item,changedFont.pointSize());
            _item->setGeometry(after);
        }
        //qDebug() << "number is:" << i << endl;
        QMapIterator<QWidget*,AutoResizeOriginalData> _fontIt(m_fontMap);
        i = 0;
        while(_fontIt.hasNext())
        {
            _fontIt.next();


            QWidget* _item=_fontIt.key();
            i++;
            //qDebug() << "font name is:" <<_item->objectName() << endl;
              changedFont=_fontIt.value().data_font;
              fontAutoResize(_item,changedFont.pointSize());
        }
    }
}
