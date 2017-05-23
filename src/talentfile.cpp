#include "talentfile.h"
#include "npctemplate.h"
#include "loctemplate.h"
#include "talentdata.h"
#include "svp.h"
#include <QLinkedList>

TalentFile::TalentFile()
{
    npcTemplates = QLinkedList<NPCTemplate*>();
    locTemplates = QLinkedList<LocTemplate*>();
    players = new QLinkedList<SVP>();
    generalNotes = "";
    noteTemplate = "";
}

TalentFile::~TalentFile()
{
    foreach (NPCTemplate* npc, npcTemplates)
    {
        delete npc;
    }
    foreach (LocTemplate* loc, locTemplates)
    {
        delete loc;
    }

    delete players;
}

QLinkedList<SVP>* TalentFile::getPlayers() const
{
    return players;
}

void TalentFile::setPlayers(QLinkedList<SVP>* newPlayers)
{
    delete players;
    players = new QLinkedList<SVP>(*newPlayers);
}

NPCTemplate* TalentFile::getNPCFromName(const QString name)
{
    foreach (NPCTemplate* npc, npcTemplates)
    {
        if (npc->getName() == name)
        {
            return npc;
        }
    }
    return NULL;
}

LocTemplate* TalentFile::getLocFromName(const QString name)
{
    foreach (LocTemplate* loc, locTemplates)
    {
        if (loc->getName() == name)
        {
            return loc;
        }
    }
    return NULL;
}

void TalentFile::addNPCTemplate(NPCTemplate* npc)
{
    QString name = npc->getName();
    NPCTemplate* oldNPC = getNPCFromName(name);

    if (oldNPC != npc)
    {
        if (oldNPC)
        {
            npcTemplates.removeOne(oldNPC);
            delete oldNPC;
        }

        npcTemplates.append(npc);
    }
}

void TalentFile::addLocTemplate(LocTemplate* loc)
{
    QString name = loc->getName();
    LocTemplate* oldLoc = getLocFromName(name);

    if (oldLoc != loc)
    {
        if (oldLoc)
        {
            locTemplates.removeOne(oldLoc);
            delete oldLoc;
        }

        locTemplates.append(loc);
    }
}

QLinkedList<NPCTemplate*> TalentFile::getNPCTemplates() const
{
    return npcTemplates;
}

QLinkedList<LocTemplate*> TalentFile::getLocTemplates() const
{
    return locTemplates;
}

void TalentFile::setLocTemplates(QLinkedList<LocTemplate*> locs)
{
    locTemplates = QLinkedList<LocTemplate*>(locs);
}

void TalentFile::setNPCTemplates(QLinkedList<NPCTemplate*> npcs)
{
    npcTemplates = QLinkedList<NPCTemplate*>(npcs);
}

QString TalentFile::getNoteTemplate() const
{
    return noteTemplate;
}

void TalentFile::setNoteTemplate(QString aString)
{
    noteTemplate = aString;
}

QString TalentFile::getNotes() const
{
    return generalNotes;
}

void TalentFile::setNotes(QString aString)
{
    generalNotes = aString;
}


QDataStream& operator <<(QDataStream& out, const TalentFile& file)
{
    out << QString("TalentFile5");

    out << file.getNotes();
    out << file.getNoteTemplate();
    out << *file.getPlayers();

    out << file.getNPCTemplates().count();
    foreach (NPCTemplate* npc, file.getNPCTemplates())
    {
        out << *npc;
    }

    out << file.getLocTemplates().count();
    foreach (LocTemplate* loc, file.getLocTemplates())
    {
        out << *loc;
    }

    return out;
}

QDataStream& operator >>(QDataStream& in, TalentFile& file)
{
    QString version;
    in >> version;
    int v = TalentData::versionNumber(version, "TalentFile");

    if (v >= 1)
    {
        QString n;
        in >> n;
        file.setNotes(n);
    }
    if (v >= 2)
    {
        QString nTemp;
        in >> nTemp;
        file.setNoteTemplate(nTemp);
    }
    if (v >= 3)
    {
        QLinkedList<SVP>* p = new QLinkedList<SVP>();
        in >> *p;
        file.setPlayers(p);
    }
    if (v >= 4)
    {
        QLinkedList<NPCTemplate*> npcs = QLinkedList<NPCTemplate*>();
        int count;
        in >> count;
        for (int i = 0; i < count; i++)
        {
            NPCTemplate* npc = new NPCTemplate();
            in >> *npc;
            npcs.append(npc);
        }
        file.setNPCTemplates(npcs);
    }
    if (v >= 5)
    {
        QLinkedList<LocTemplate*> locs = QLinkedList<LocTemplate*>();
        int count;
        in >> count;
        for (int i = 0; i < count; i++)
        {
            LocTemplate* loc = new LocTemplate();
            in >> *loc;
            locs.append(loc);
        }
        file.setLocTemplates(locs);
    }

    return in;
}