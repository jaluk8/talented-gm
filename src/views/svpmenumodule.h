#ifndef SVPMENUMODULE_H
#define SVPMENUMODULE_H

#include "menumodule.h"

class SVP;
class QHBoxLayout;
class QDoubleSpinBox;
class QLineEdit;

class SVPMenuModule : public MenuModule
{
public:
    SVPMenuModule(QWidget* parent = 0);
    ~SVPMenuModule();

    void addWidgets();

    SVP getValue();
    void setValue(SVP);

    QDoubleSpinBox* getSpin();
    QLineEdit* getEdit();

    void setDecimals(int);

private:
    QDoubleSpinBox* spin;
    QLineEdit* edit;
};

#endif // MENUMODULE_H
