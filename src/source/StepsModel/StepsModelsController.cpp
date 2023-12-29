/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/*
    StepsModelsController.cpp

    Provides a simple tree model to show how to create and use hierarchical
    models.
*/

#include "../../include/StepsModel/StepInfo.h"
#include "../../include/StepsModel/StepsModelsController.h"

//#include "customtype.h"

#include <QStringList>
#include <QDebug>
#include <QFile>
//! [0]
StepsModelsController::StepsModelsController(const QString &path, QObject *parent)
    : QAbstractItemModel(parent)
{
    m_roleNameMapping[StepsModelsControllerRoleName] = "content";
    m_roleNameMapping[StepsModelsControllerImagePath] = "imgReference";
    if(!path.isEmpty())
    {
        loadScenarioTreeView(path);
    }
}
//! [0]

//! [1]
StepsModelsController::~StepsModelsController()
{
    delete rootItem;
}

void StepsModelsController::loadScenarioTreeView(QString path)
{
    beginResetModel();
    path.replace("file:///","");

    QString changedPath = path;
    changedPath.append("/Scenario.json");
    pathToCurrentProject = path;

    QFile file(changedPath);
    file.open(QIODevice::ReadOnly);

    if(rootItem != nullptr)
    {
        delete rootItem;
    }
    QList<QVariant> rootData;
    rootData << "content";
    rootItem = new StepInfo(rootData);
    setupModelData(file.readAll(), rootItem);
    file.close();
    endResetModel();
    emit treeModelChanged();
}
//! [1]

//! [2]
int StepsModelsController::columnCount(const QModelIndex &parent) const
{
    if(rootItem == nullptr)
        return 0;

    if (parent.isValid())
        return static_cast<StepInfo*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}
//! [2]

//! [3]
QVariant StepsModelsController::data(const QModelIndex &index, int role) const
{
    if(rootItem == nullptr)
        return QVariant();
    if (!index.isValid())
        return QVariant();

    if ( (role != StepsModelsControllerRoleName) && (role != StepsModelsControllerImagePath))
        return QVariant();

    StepInfo *item = static_cast<StepInfo*>(index.internalPointer());

    return item->data(role - Qt::UserRole - 1);
}
//! [3]

//! [4]
Qt::ItemFlags StepsModelsController::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}
//! [4]

//! [5]
QVariant StepsModelsController::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}
//! [5]

//! [6]
QModelIndex StepsModelsController::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    StepInfo *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<StepInfo*>(parent.internalPointer());

    StepInfo *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}
//! [6]

//! [7]
QModelIndex StepsModelsController::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    StepInfo *childItem = static_cast<StepInfo*>(index.internalPointer());
    StepInfo *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}
//! [7]

//! [8]
int StepsModelsController::rowCount(const QModelIndex &parent) const
{
    StepInfo *parentItem;
    if (parent.column() > 0)
        return 0;
    if(rootItem == nullptr)
        return 0;
    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<StepInfo*>(parent.internalPointer());

    return parentItem->childCount();
}
//! [8]

QHash<int, QByteArray> StepsModelsController::roleNames() const
{
    return m_roleNameMapping;
}

QVariant StepsModelsController::newCustomType(const QString &text, int position)
{
    // CustomType *t = new CustomType(this);
    // t->setText(text);
    // t->setIndentation(position);
    QVariant v;
    v.setValue(text);
    return v;
}

void StepsModelsController::recusiveCreateObject(const QJsonValue & scenarioValue, QList<StepInfo*>& parents, QList<int>& indentations, int number)
{
        QJsonObject scenarioObject = scenarioValue.toObject();
        // Konwersja obiektu na łańcuch znaków

        QString itemContent = "";
        if (scenarioObject.contains("AutomationId")) {
            QString automationId = scenarioObject["AutomationId"].toString();
            itemContent += "AutomationId:" + automationId + "\n";
        }
        if (scenarioObject.contains("ClassName")) {
            QString className = scenarioObject["ClassName"].toString();
            itemContent += "ClassName:" + className + "\n";
        }
        if (scenarioObject.contains("EventType")) {
            QString eventType = scenarioObject["EventType"].toString();
            itemContent += "EventType:" + eventType + "\n";
        }
        if (scenarioObject.contains("FrameworkId")) {
            QString frameworkId = scenarioObject["FrameworkId"].toString();
            itemContent += "FrameworkId:" + frameworkId + "\n";
        }
        if (scenarioObject.contains("ItemType")) {
            QString itemType = scenarioObject["ItemType"].toString();
            itemContent += "ItemType:" + itemType + "\n";
        }
        if (scenarioObject.contains("KeyData")) {
            QString keyData = scenarioObject["KeyData"].toString();
            itemContent += "KeyData:" + keyData + "\n";
        }
        if (scenarioObject.contains("Parent")) {
            bool hasChild = false;
            //QString parent = scenarioObject["Parent"].toString();
            if(scenarioObject["Parent"].isObject())
            {
                QJsonObject parent =  scenarioObject["Parent"].toObject();
                if(parent.count())
                {
                    hasChild = true;
                    ++number;
                }
                else
                {
                    --number;
                }

                if (number > indentations.last()) {
                    // The last child of the current parent is now the new parent
                    // unless the current parent has no children.

                    if (parents.last()->childCount() > 0) {
                        parents << parents.last()->child(parents.last()->childCount()-1);
                        indentations << number;
                    }
                } else {
                    while( (number < indentations.last()) && (parents.count() > 0)) {
                        parents.pop_back();
                        indentations.pop_back();
                    }
                }

                // Append a new item to the current parent's list of children.
                QList<QVariant> columnData;

                columnData << newCustomType(itemContent, 0);
                columnData << QVariant("");
                parents.last()->appendChild(new StepInfo(columnData, parents.last()));
                if(hasChild)
                {
                    recusiveCreateObject(scenarioObject["Parent"], parents, indentations, number);
                }
            }
        }
}

void StepsModelsController::setupModelData(const QString &jsonContent, StepInfo *parent)
{
    QList<StepInfo*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;
    //qDebug() << jsonContent;
    int number = 0;
    // Wczytywanie JSON
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonContent.toUtf8());

    // Sprawdź, czy wczytywanie się powiodło
    if (!jsonDocument.isNull()) {
        // Przetwarzanie JSON
        if (jsonDocument.isObject()) {
            QJsonObject jsonObject = jsonDocument.object();

            // Przetwarzanie obiektu JSON
            if (jsonObject.contains("Scenario") && jsonObject["Scenario"].isArray()) {
                QJsonArray scenarioArray = jsonObject["Scenario"].toArray();

                int step = 1;
                for (const QJsonValue& scenarioValue : scenarioArray) {
                    if (scenarioValue.isObject()) {
                        //indentations.push_back(1);
                        parents.last()->appendChild(new StepInfo({ "Step : " + QString::number(step), pathToCurrentProject + "/Img/" + QString::number(step)+".jpg" }, parents.last()));
                        number++;
                        indentations << number;
                        recusiveCreateObject(scenarioValue, parents, indentations, number);
                        if (number > indentations.last()) {
                            // The last child of the current parent is now the new parent
                            // unless the current parent has no children.

                            if (parents.last()->childCount() > 0) {
                                parents << parents.last()->child(parents.last()->childCount()-1);
                                indentations << number;
                            }
                        } else {
                            while( (number < indentations.last()) && (parents.count() > 0)) {
                                parents.pop_back();
                                indentations.pop_back();
                            }
                        }
                        number--;
                        step++;
                    }
            }
        } else {
            qDebug() << "Nieprawidłowy format JSON (nie jest obiektem).";
        }
    } else {
        qDebug() << "Błąd podczas wczytywania JSON.";
    }

}
    qDebug() << "End setupModelData";
}

void StepsModelsController::setupModelData(const QStringList &lines, StepInfo *parent)
{
    QList<StepInfo*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].at(position) != ' ')
                break;
            position++;
        }

        QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {
            // Read the column data from the rest of the line.
            QStringList columnStrings = lineData.split("\t", Qt::SkipEmptyParts);
            QList<QVariant> columnData;
            for (int column = 0; column < columnStrings.count(); ++column)
                columnData << newCustomType(columnStrings[column], position);

            if (position > indentations.last()) {
                // The last child of the current parent is now the new parent
                // unless the current parent has no children.

                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }

            // Append a new item to the current parent's list of children.
            parents.last()->appendChild(new StepInfo(columnData, parents.last()));
        }

        ++number;
    }
}
