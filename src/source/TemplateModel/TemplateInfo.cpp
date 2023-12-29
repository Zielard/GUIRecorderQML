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
    TemplateInfo.cpp

    A container for items of data supplied by the simple tree model.
*/

#include <QStringList>

#include "../../include/TemplateModel/TemplateInfo.h"

//! [0]
TemplateInfo::TemplateInfo(const QList<QVariant> &data, TemplateInfo *parent)
{
    m_parentItem = parent;
    m_itemData = data;
}
//! [0]

//! [1]
TemplateInfo::~TemplateInfo()
{
    qDeleteAll(m_childItems);
}
//! [1]

//! [2]
void TemplateInfo::appendChild(TemplateInfo *item)
{
    m_childItems.append(item);
}
//! [2]

//! [3]
TemplateInfo *TemplateInfo::child(int row)
{
    return m_childItems.value(row);
}
//! [3]

//! [4]
int TemplateInfo::childCount() const
{
    return m_childItems.count();
}
//! [4]

//! [5]
int TemplateInfo::columnCount() const
{
    return m_itemData.count();
}
//! [5]

//! [6]
QVariant TemplateInfo::data(int column) const
{
    return m_itemData.value(column);
}

QString TemplateInfo::dataStr() const
{
    return data(0).toString();
}
//! [6]

//! [7]
TemplateInfo *TemplateInfo::parentItem()
{
    return m_parentItem;
}
//! [7]

//! [8]
int TemplateInfo::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<TemplateInfo*>(this));

    return 0;
}
//! [8]
