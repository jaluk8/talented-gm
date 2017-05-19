#ifndef EDITORNPCCONTROLLER_H
#define EDITORNPCCONTROLLER_H

#include "controller.h"
#include <QString>

class NPCTemplate;
class MenuModule;

class EditorNPCController : public Controller
{
    Q_OBJECT

public:
    EditorNPCController(QObject* parent = 0);
    ~EditorNPCController();

    void draw();
    void load();
    void addHitBox(QString s = "", double v = 0);
    void makeNPC();
    void toTemplate();

signals:

public slots:
    void deleteHitBox(MenuModule*);

private:
    NPCTemplate* npcTemp;
};

#endif // EDITORNPCCONTROLLER_H