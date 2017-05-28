#ifndef TURNINFOCONTROLLER_H
#define TURNINFOCONTROLLER_H

#include "controller.h"

class NPC;

class TurnInfoController : public Controller
{
    Q_OBJECT
public:
    explicit TurnInfoController(QObject *parent = 0);
    ~TurnInfoController();

    void setWidgets(QWidget* turnStatContents, QWidget* turnSkillContents);

    void setNPC(NPC*);

    void toView();
    void toModel();
    void fromModel();
    void fromView();

signals:

public slots:
    void on_viewNPC(NPC*);
    void on_deleteNPC(QString);

private:
    NPC* npc;
    QWidget* uiSkills;
    QWidget* uiStats;
};

#endif // TURNINFOCONTROLLER_H