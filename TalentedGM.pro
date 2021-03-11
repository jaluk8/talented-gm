#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T13:01:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TalentedGM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += src/main.cpp\
    src/controllers/controller.cpp \
    src/controllers/editorloccontroller.cpp \
    src/controllers/editornpccontroller.cpp \
    src/controllers/filecontroller.cpp \
    src/controllers/generalcontroller.cpp \
    src/controllers/hashcontroller.cpp \
    src/controllers/maincontroller.cpp \
    src/controllers/temploccontroller.cpp \
    src/controllers/tempnotescontroller.cpp \
    src/controllers/tempnpccontroller.cpp \
    src/controllers/tempplayercontroller.cpp \
    src/controllers/turncontroller.cpp \
    src/controllers/turninfocontroller.cpp \
    src/controllers/turninitcontroller.cpp \
    src/controllers/turnloccontroller.cpp \
    src/controllers/turnnotescontroller.cpp \
    src/models/hitarea.cpp \
    src/models/initiativeact.cpp \
    src/models/location.cpp \
    src/models/npc.cpp \
    src/models/npctemplate.cpp \
    src/models/skill.cpp \
    src/models/svp.cpp \
    src/models/talentdata.cpp \
    src/models/talentfile.cpp \
    src/models/turn.cpp \
    src/views/initmodule.cpp \
    src/models/loctemplate.cpp \
    src/views/mainwindow.cpp \
    src/views/menumodule.cpp \
    src/views/module.cpp \
    src/views/npcmenumodule.cpp \
    src/views/skillmenumodule.cpp \
    src/views/svpmenumodule.cpp

HEADERS  += \
    src/controllers/editorloccontroller.h \
    src/controllers/editornpccontroller.h \
    src/controllers/filecontroller.h \
    src/controllers/generalcontroller.h \
    src/controllers/hashcontroller.h \
    src/controllers/maincontroller.h \
    src/controllers/temploccontroller.h \
    src/controllers/tempnotescontroller.h \
    src/controllers/tempnpccontroller.h \
    src/controllers/tempplayercontroller.h \
    src/controllers/turncontroller.h \
    src/controllers/turninfocontroller.h \
    src/controllers/turninitcontroller.h \
    src/controllers/turnloccontroller.h \
    src/controllers/turnnotescontroller.h \
    src/controllers/controller.h \
    src/models/hitarea.h \
    src/models/initiativeact.h \
    src/models/location.h \
    src/models/loctemplate.h \
    src/models/npc.h \
    src/models/npctemplate.h \
    src/models/skill.h \
    src/models/svp.h \
    src/models/talentdata.h \
    src/models/talentfile.h \
    src/models/turn.h \
    src/views/initmodule.h \
    src/views/mainwindow.h \
    src/views/menumodule.h \
    src/views/module.h \
    src/views/npcmenumodule.h \
    src/views/skillmenumodule.h \
    src/views/svpmenumodule.h

FORMS    += src/views/mainwindow.ui

RESOURCES += \
    res/default.qrc
