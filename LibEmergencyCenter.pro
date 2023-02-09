QT -= gui

TEMPLATE = lib
DEFINES += LIBEMERGENCYCENTER_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    libemergencycenter.cpp \
    Alarm.cpp \
    Component.cpp \
    EmergencyCenter.cpp \
    GasSensor.cpp \
    Location.cpp \
    activation.cpp \
    mail.cpp \
    MotionSensor.cpp \
    Sensor.cpp \
    SmokeSensor.cpp \

HEADERS += \
    LibEmergencyCenter_global.h \
    libemergencycenter.h \
    Alarm.h \
    Component.h \
    EmergencyCenter.h \
    GasSensor.h \
    Location.h \
    activation.h \
    mail.h \
    MotionSensor.h \
    Sensor.h \
    SmokeSensor.h \
    strategy.h\

# Default rules for deployment.
unix {
    target.path = /home/louise/Media_Processing_Labs
}
!isEmpty(target.path): INSTALLS += target
