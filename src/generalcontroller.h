#ifndef GENERALCONTROLLER_H
#define GENERALCONTROLLER_H

#include "controller.h"

class QTextEdit;

class GeneralController : public Controller
{
    Q_OBJECT
public:
    explicit GeneralController(QObject *parent = 0);

    void setWidgets(QTextEdit* generalNotes);

    void toView();
    void fromModel();
    void fromView();
    void toModel();

public slots:

signals:

private:
    QString notes;
    QTextEdit* uiNotes;
};

#endif // GENERALCONTROLLER_H
