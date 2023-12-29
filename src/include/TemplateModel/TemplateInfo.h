#ifndef AUDIOINFO_H
#define AUDIOINFO_H

#include <QObject>
#include <QUrl>
#include <qqml.h>

class TemplateInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit TemplateInfo(const QList<QVariant> &data, TemplateInfo *parentItem = 0);
    ~TemplateInfo();

    void appendChild(TemplateInfo *child);

    TemplateInfo *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    Q_INVOKABLE int row() const;
    TemplateInfo *parentItem();
    QString dataStr() const;

    Q_PROPERTY(QString getData READ dataStr NOTIFY dataChanged);

 signals:
     void dataChanged();
private:
    QList<TemplateInfo*> m_childItems;
    QList<QVariant> m_itemData;
    TemplateInfo *m_parentItem;
    
};

#endif // AUDIOINFO_H
