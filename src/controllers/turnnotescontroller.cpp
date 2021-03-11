#include "turnnotescontroller.h"
#include "../models/talentdata.h"
#include "../models/talentfile.h"
#include "../models/turn.h"
#include <QTextEdit>

TurnNotesController::TurnNotesController(QObject* parent) : Controller(parent)
{
    notes = "";
}

void TurnNotesController::setWidgets(QTextEdit* turnNotes)
{
    uiNotes = turnNotes;

    view.append(uiNotes);

    connect(uiNotes, SIGNAL(textChanged()), this, SLOT(on_viewUpdate()));
}

void TurnNotesController::toView()
{
    uiNotes->setText(notes);
}

void TurnNotesController::toModel()
{
    TalentData::lockTalentFile()->currentTurn()->setNotes(notes);
    TalentData::unlockTalentFile();
}

void TurnNotesController::fromModel()
{
    notes = TalentData::lockTalentFile()->currentTurn()->getNotes();
    TalentData::unlockTalentFile();
}

void TurnNotesController::fromView()
{
    notes = uiNotes->toPlainText();
}
