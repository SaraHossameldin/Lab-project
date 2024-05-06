QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    ckeckout.cpp \
    creditcardinformation.cpp \
    database.cpp \
    findproduct.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    shoppingcart.cpp \
    thankyoupage.cpp \
    userwindow.cpp

HEADERS += \
    adminwindow.h \
    ckeckout.h \
    creditcardinformation.h \
    database.h \
    findproduct.h \
    login.h \
    mainwindow.h \
    register.h \
    shoppingcart.h \
    thankyoupage.h \
    userwindow.h

FORMS += \
    adminwindow.ui \
    ckeckout.ui \
    creditcardinformation.ui \
    database.ui \
    findproduct.ui \
    login.ui \
    mainwindow.ui \
    register.ui \
    shoppingcart.ui \
    thankyoupage.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
