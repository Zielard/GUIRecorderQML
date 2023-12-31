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
    TemplatesController.cpp

    Provides a simple tree model to show how to create and use hierarchical
    models.
*/

#include "../../include/TemplateModel/TemplateInfo.h"
#include "../../include/TemplateModel/TemplatesModelsController.h"

//#include "customtype.h"

#include <QStringList>
#include <QDebug>
#include <QFile>
//! [0]
TemplatesController::TemplatesController(const QString &path, QObject *parent)
    : QAbstractItemModel(parent)
{
    m_roleNameMapping[TemplatesControllerRoleName] = "content";
    m_roleNameMapping[TemplatesControllerImagePath] = "imgReference";
    if(!path.isEmpty())
    {
        loadTemplateFile(path);
    }
}
//! [0]

//! [1]
TemplatesController::~TemplatesController()
{
    delete rootItem;
}

void TemplatesController::loadTemplateFile(QString path)
{
    beginResetModel();
    path.replace("file:///","");

    QString changedPath = path;
    changedPath.append("/Template.json");
    pathToCurrentProject = path;

    QFile file(changedPath);
    file.open(QIODevice::ReadOnly);

    if(rootItem != nullptr)
    {
        delete rootItem;
    }
    QList<QVariant> rootData;
    rootData << "content";
    rootItem = new TemplateInfo(rootData);
    setupModelData(file.readAll(), rootItem);
    file.close();
    endResetModel();
    emit treeModelChanged();
}
//! [1]

//! [2]
int TemplatesController::columnCount(const QModelIndex &parent) const
{
    if(rootItem == nullptr)
        return 0;

    if (parent.isValid())
        return static_cast<TemplateInfo*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}
//! [2]

//! [3]
QVariant TemplatesController::data(const QModelIndex &index, int role) const
{
    if(rootItem == nullptr)
        return QVariant();
    if (!index.isValid())
        return QVariant();

    if ( (role != TemplatesControllerRoleName) && (role != TemplatesControllerImagePath))
        return QVariant();

    TemplateInfo *item = static_cast<TemplateInfo*>(index.internalPointer());

    return item->data(role - Qt::UserRole - 1);
}
//! [3]

//! [4]
Qt::ItemFlags TemplatesController::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}
//! [4]

//! [5]
QVariant TemplatesController::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}
//! [5]

//! [6]
QModelIndex TemplatesController::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TemplateInfo *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TemplateInfo*>(parent.internalPointer());

    TemplateInfo *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}
//! [6]

//! [7]
QModelIndex TemplatesController::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TemplateInfo *childItem = static_cast<TemplateInfo*>(index.internalPointer());
    TemplateInfo *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}
//! [7]

//! [8]
int TemplatesController::rowCount(const QModelIndex &parent) const
{
    TemplateInfo *parentItem;
    if (parent.column() > 0)
        return 0;
    if(rootItem == nullptr)
        return 0;
    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TemplateInfo*>(parent.internalPointer());

    return parentItem->childCount();
}
//! [8]

QHash<int, QByteArray> TemplatesController::roleNames() const
{
    return m_roleNameMapping;
}

QVariant TemplatesController::newCustomType(const QString &text, int position)
{
    // CustomType *t = new CustomType(this);
    // t->setText(text);
    // t->setIndentation(position);
    QVariant v;
    v.setValue(text);
    return v;
}

void TemplatesController::createPrepareSubTreeView(const QJsonValue & jsonObject, QList<TemplateInfo*>& parents, QList<int>& indentations, int number)
{
    QJsonObject prepareObject = jsonObject.toObject();

    QString itemContent = "";
    if (prepareObject.contains("Enviroment variables")) {
        QString envVar = prepareObject["Enviroment variables"].toString();
        itemContent += "envVar:" + envVar + "\n";
    }
    if (prepareObject.contains("Scripts")) {
        QString scripts = prepareObject["Scripts"].toString();
        itemContent += "Scripts:" + scripts + "\n";
    }
    if (prepareObject.contains("Prepare scenario")) {
        QString preSce = prepareObject["Prepare scenario"].toString();
        itemContent += "Prepare scenario:" + preSce + "\n";
    }

    // Append a new item to the current parent's list of children.
    QList<QVariant> columnData;

    columnData << newCustomType(itemContent, 0);
    columnData << QVariant("");
    parents.last()->appendChild(new TemplateInfo(columnData, parents.last()));
}

void TemplatesController::createClearSubTreeView(const QJsonValue & jsonObject, QList<TemplateInfo*>& parents, QList<int>& indentations, int number)
{
    QJsonObject clearObject = jsonObject.toObject();

    QString itemContent = "";
    if (clearObject.contains("Enviroment variables")) {
        QString envVar = clearObject["Enviroment variables"].toString();
        itemContent += "envVar:" + envVar + "\n";
    }
    if (clearObject.contains("Scripts")) {
        QString scripts = clearObject["Scripts"].toString();
        itemContent += "Scripts:" + scripts + "\n";
    }
    if (clearObject.contains("Clear scenario")) {
        QString clearSce = clearObject["Clear scenario"].toString();
        itemContent += "Clear scenario:" + clearSce + "\n";
    }
    number++;
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
    parents.last()->appendChild(new TemplateInfo(columnData, parents.last()));

}

void TemplatesController::setupModelData(const QString &jsonContent, TemplateInfo *parent)
{
    QList<TemplateInfo*> parents;
    QList<int> indentations;
    auto root = parent;
    parents << root;
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
        if (jsonObject.contains("Prepare") && jsonObject["Prepare"].isObject()) {
            parents.last()->appendChild(new TemplateInfo({ "Prepare : " }, parents.last()));
            ++number;
            //indentations << number;
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
            //parents << parent;
            createPrepareSubTreeView(jsonObject["Prepare"], parents, indentations, number);
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
            parents << root;
        }
        if (jsonObject.contains("Clear") && jsonObject["Clear"].isObject()) {
            parents.last()->appendChild(new TemplateInfo({ "Clear : " }, parents.last()));
            ++number;
            //parents << parent;
            //indentations << number;
            createClearSubTreeView(jsonObject["Clear"], parents, indentations, number);
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
            parent = root;
        }
        else
        {
            qDebug() << "Nieprawidłowy format JSON (nie jest obiektem).";
        }
    } else {
        qDebug() << "Błąd podczas wczytywania JSON.";
    }

}
    qDebug() << "End setupModelData";
}

void TemplatesController::setupModelData(const QStringList &lines, TemplateInfo *parent)
{
    QList<TemplateInfo*> parents;
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
            parents.last()->appendChild(new TemplateInfo(columnData, parents.last()));
        }

        ++number;
    }
}
