#ifndef AUDIOINFO_H
#define AUDIOINFO_H

#include <QObject>
#include <QUrl>
#include <qqml.h>

class StepInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit StepInfo(const QList<QVariant> &data, StepInfo *parentItem = 0);
    ~StepInfo();

    void appendChild(StepInfo *child);

    StepInfo *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    Q_INVOKABLE int row() const;
    StepInfo *parentItem();
    QString dataStr() const;

    Q_PROPERTY(QString getData READ dataStr NOTIFY dataChanged);

 signals:
     void dataChanged();
private:
    QList<StepInfo*> m_childItems;
    QList<QVariant> m_itemData;
    StepInfo *m_parentItem;
    
};

#endif // AUDIOINFO_H
