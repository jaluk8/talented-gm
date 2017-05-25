#include "npc.h"
#include "npctemplate.h"
#include "talentdata.h"
#include "hitarea.h"
#include "svp.h"

NPC::NPC()
{
    name = "Unnamed NPC";

    hitAreas = new QVector<HitArea>();

    body = 2;
    coord = 2;
    sense = 2;
    mind = 2;
    charm = 2;
    comm = 2;
}

NPC::NPC(const NPC* old)
{
    setName(old->getName());

    hitAreas = new QVector<HitArea>(*old->getHitAreas());

    body = old->body;
    coord = old->coord;
    sense = old->sense;
    mind = old->mind;
    charm = old->charm;
    comm = old->comm;
}

NPC::NPC(const NPCTemplate* npcTemp)
{
    setName(npcTemp->getName());

    hitAreas = new QVector<HitArea>();
    foreach (SVP svp, *npcTemp->getHitBoxes())
    {
        HitArea area = HitArea(svp);
        hitAreas->append(area);
    }

    body = npcTemp->body;
    coord = npcTemp->coord;
    sense = npcTemp->sense;
    mind = npcTemp->mind;
    charm = npcTemp->charm;
    comm = npcTemp->comm;
}

NPC::~NPC()
{
    delete hitAreas;
}

void NPC::setName(QString aName)
{
    name = aName;
}

QString NPC::getName() const
{
    return name;
}

void NPC::setHitAreas(QVector<HitArea>* areas)
{
    delete hitAreas;
    hitAreas = new QVector<HitArea>(*areas);
}

QVector<HitArea>* NPC::getHitAreas() const
{
    return hitAreas;
}

QDataStream& operator <<(QDataStream& out, const NPC& npc)
{
    out << QString("NPC2");

    out << npc.getName();
    out << npc.body;
    out << npc.coord;
    out << npc.sense;
    out << npc.mind;
    out << npc.charm;
    out << npc.comm;

    out << *npc.getHitAreas();

    return out;
}

QDataStream& operator >>(QDataStream& in, NPC& npc)
{
    QString version;
    in >> version;
    int v = TalentData::versionNumber(version, "NPC");

    if (v >= 1)
    {
        QString name;
        in >> name;
        npc.setName(name);

        int body;
        in >> body;
        npc.body = body;

        int coord;
        in >> coord;
        npc.coord = coord;

        double sense;
        in >> sense;
        npc.sense = sense;

        int mind;
        in >> mind;
        npc.mind = mind;

        int charm;
        in >> charm;
        npc.charm = charm;

        int comm;
        in >> comm;
        npc.comm = comm;
    }
    if (v >= 2)
    {
        QVector<HitArea>* areas = new QVector<HitArea>();
        in >> *areas;
        npc.setHitAreas(areas);
    }

    return in;
}
