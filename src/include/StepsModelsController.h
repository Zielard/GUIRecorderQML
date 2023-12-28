#ifndef STEPSMODELSCONTROLLERROLES_H
#define STEPSMODELSCONTROLLERROLES_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class StepInfo;

//! [0]
class StepsModelsController : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(void signalProxy NOTIFY treeModelChanged)
public:
    enum StepsModelsControllerRoles
    {
        StepsModelsControllerRoleName = Qt::UserRole + 1,
        StepsModelsControllerImagePath
    };

    explicit StepsModelsController(const QString &path = "", QObject *parent = 0);
    ~StepsModelsController();

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
    Q_INVOKABLE void loadScenarioTreeView(QString path);
signals:
    void treeModelChanged();
private:
    QVariant newCustomType(const QString &text, int position);
    void setupModelData(const QStringList &lines, StepInfo *parent);
    void setupModelData(const QString &jsonContent, StepInfo *parent);
    void recusiveCreateObject(const QJsonValue & scenarioValue, QList<StepInfo*>& parents, QList<int>& indentations, int number);

    QString pathToCurrentProject = "";
    StepInfo *rootItem = nullptr;
    QHash<int, QByteArray> m_roleNameMapping;
};
#endif // STEPSMODELSCONTROLLERROLES_H
