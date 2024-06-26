QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chathome.cpp \
    labelmenu.cpp \
    main.cpp \
    taqikema.cpp \
    widget.cpp

HEADERS += \
    chathome.h \
    labelmenu.h \
    taqikema.h \
    widget.h

FORMS += \
    chathome.ui \
    taqikema.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    allResource.qrc

DISTFILES += \
    lib/R.png \
    lib/Taqikema.gif \
    lib/WhiteBackground.jpg \
    lib/bg1.jpg \
    lib/bg2.jpg \
    lib/bg3.jpg \
    lib/close.png \
    lib/head.jpg \
    lib/head.png \
    lib/head2.png \
    lib/head3.png \
    lib/hello.gif \
    lib/hide.png \
    lib/id.png \
    lib/shezhang.png \
    lib/shuaidao.png \
    lib/suo.png
