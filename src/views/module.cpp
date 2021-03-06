#include "module.h"
#include <QHBoxLayout>
#include <QString>
#include <QStyle>

Module::Module(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    sortID = "";
    sort = false;
}

Module::~Module()
{
    delete layout;
}

void Module::setSortID(QString anID)
{
    sortID = anID.toLower();
    sort = true;
}

QString Module::getSortID()
{
    return sortID;
}

bool Module::needsSort()
{
    return sort;
}

void Module::on_update()
{
    emit viewUpdate();
}
