QT += quick qml network sql multimedia
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    connection.cpp \
    dbtoaccess.cpp \
    incident.cpp \
    customcamera.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    connection.h \
    dbtoaccess.h \
    incident.h \
    customcamera.h
 #   ../library/Ekylib/ekylib.h

#linux:!android {
 #   message("* Using settings for Unix/Linux.")
#    INCLUDEPATH += "/home/clement/ekylibre/qt/library/Ekylib"
#    LIBS += "/home/clement/ekylibre/qt/library/Ekylib-Desktop_Release/libEkylib.a"
#}
#
#android {
#    message("* Using settings for Android.")
#    INCLUDEPATH += "/home/clement/ekylibre/qt/library/Ekylib"
#    LIBS += "/home/clement/ekylibre/qt/library/Ekylib-Android_armeabi_v7a_Release/libEkylib.a"
#}
