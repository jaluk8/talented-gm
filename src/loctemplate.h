#ifndef LOCATIONTEMPLATE_H
#define LOCATIONTEMPLATE_H

#include <QString>
#include <QLinkedList>

class NPCTemplate;

class LocTemplate
{
public:
    LocTemplate();
    LocTemplate(const LocTemplate*);

    int minions1;
    int minions2;

    QString getName() const;
    void setName(QString);
    QString getDescription() const;
    void setDescription(QString);

    QLinkedList<NPCTemplate*>& NPCs();
    const QLinkedList<NPCTemplate*>& getNPCs() const;

    void addNPC(NPCTemplate*);
    void removeNPC(NPCTemplate*);

private:
    QString name;
    QString description;
    QLinkedList<NPCTemplate*> npcs;

    static QString randName();
};

QDataStream& operator <<(QDataStream&, const LocTemplate&);
QDataStream& operator >>(QDataStream&, LocTemplate&);

#endif // LOCATIONTEMPLATE_H
