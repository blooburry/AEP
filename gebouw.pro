QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    codeSlot.cpp \
    deur.cpp \
    draaideur.cpp \
    drukbox.cpp \
    hallsensor.cpp \
    herkenningsslot.cpp \
    main.cpp \
    mainwindow.cpp \
    schuifdeur.cpp \
    sensor.cpp \
    sleutelSlot.cpp

HEADERS += \
    IAfdrukker.h \
    codeSlot.h \
    defines.h \
    deur.h \
    draaideur.h \
    drukbox.h \
    hallsensor.h \
    herkenningsslot.h \
    mainwindow.h \
    schuifdeur.h \
    sensor.h \
    sleutelSlot.h \
    slot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
   Gebouw.png
