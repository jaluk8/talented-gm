#include "svpmenumodule.h"
#include "svp.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

SVPMenuModule::SVPMenuModule(QWidget* parent) : MenuModule(parent)
{
    spin = new QDoubleSpinBox();
    edit = new QLineEdit();

    spin->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    edit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    setDecimals(0);
    spin->setValue(1);
}

void SVPMenuModule::addWidgets()
{
    layout->addWidget(spin);
    layout->addWidget(edit);
    layout->addWidget(getDeleteButton());
}

SVPMenuModule::~SVPMenuModule()
{
    delete spin;
    delete edit;
}

void SVPMenuModule::setDecimals(int d)
{
    spin->setDecimals(d);
}

SVP SVPMenuModule::getValue()
{
    double v = spin->value();
    QString s = edit->text();
    SVP svp(s, v);
    return svp;
}

void SVPMenuModule::setValue(SVP svp)
{
    spin->setValue(svp.getValue());
    edit->setText(svp.getString());
}

QDoubleSpinBox* SVPMenuModule::getSpin()
{
    return spin;
}

QLineEdit* SVPMenuModule::getEdit()
{
    return edit;
}
