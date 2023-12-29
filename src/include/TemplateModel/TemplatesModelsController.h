#ifndef TEMPLATESCONTOLLERROLES_H
#define TEMPLATESCONTOLLERROLES_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class TemplateInfo;

//! [0]
class TemplatesController : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(void signalProxy NOTIFY treeModelChanged)
public:
    enum TemplatesControllerRoles
    {
        TemplatesControllerRoleName = Qt::UserRole + 1,
        TemplatesControllerImagePath
    };

    explicit TemplatesController(const QString &path = "", QObject *parent = 0);
    ~TemplatesController();

    /* QAbstractItemModel interface */
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE void loadTemplateFile(QString path);
signals:
    void treeModelChanged();
private:
    QVariant newCustomType(const QString &text, int position);
    void setupModelData(const QStringList &lines, TemplateInfo *parent);
    void setupModelData(const QString &jsonContent, TemplateInfo *parent);
    void recusiveCreateObject(const QJsonValue & scenarioValue, QList<TemplateInfo*>& parents, QList<int>& indentations, int number);

    QString pathToCurrentProject = "";
    TemplateInfo *rootItem = nullptr;
    QHash<int, QByteArray> m_roleNameMapping;
};
#endif // TEMPLATESCONTOLLERROLES_H
