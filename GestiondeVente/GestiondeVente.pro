QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp \
    stock.cpp

HEADERS += \
    client.h \
    login.h \
    mainwindow.h \
    produit.h \
    stock.h

FORMS += \
    client.ui \
    login.ui \
    mainwindow.ui \
    produit.ui \
    stock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
