QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Eclipse
TEMPLATE = app

VERSION = 1.0.0.0
QMAKE_TARGET_DESCRIPTION = Databases Course Project
QMAKE_TARGET_COPYRIGHT = Aksenovskiy Igor
QMAKE_TARGET_PRODUCT = Course Project

DESTDIR = build
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Source/About.cpp \
    Source/Connect.cpp \
    Source/Incomes.cpp \
    Source/IncomesData.cpp \
    Source/IncomesWidget.cpp \
    Source/MaterialPositionsByName.cpp \
    Source/MaterialPositionsByNameData.cpp \
    Source/DatabaseMssql.cpp \
    Source/DatabaseMssqlConnect.cpp \
    Source/DatabaseMssqlQuery.cpp \
    Source/FileSql.cpp \
    Source/IncomesInDatesData.cpp \
    Source/IncomesInDatesReport.cpp \
    Source/IncomesInDatesWidget.cpp \
    Source/Main.cpp \
    Source/MainWindow.cpp \
    Source/MaterialPositionsByNameWidget.cpp \
    Source/Materials.cpp \
    Source/MaterialsData.cpp \
    Source/MaterialsWidget.cpp \
    Source/MaterialsWithPriceOverData.cpp \
    Source/MaterialsWithPriceOverReport.cpp \
    Source/MaterialsWithPriceOverWidget.cpp \
    Source/Positions.cpp \
    Source/PositionsData.cpp \
    Source/PositionsWidget.cpp \
    Source/PrintWidget.cpp \
    Source/Producers.cpp \
    Source/ProducersData.cpp \
    Source/ProducersWidget.cpp \
    Source/Releases.cpp \
    Source/ReleasesData.cpp \
    Source/ReleasesWidget.cpp \
    Source/Responsible.cpp \
    Source/ResponsibleData.cpp \
    Source/ResponsibleWidget.cpp

HEADERS += \
    Source/About.h \
    Source/Connect.h \
    Source/DatabaseMssql.h \
    Source/FileSql.h \
    Source/Incomes.h \
    Source/IncomesInDates.h \
    Source/MainWindow.h \
    Source/MaterialPositionsByName.h \
    Source/Materials.h \
    Source/MaterialsWithPriceOver.h \
    Source/Positions.h \
    Source/PrintWidget.h \
    Source/Producers.h \
    Source/Releases.h \
    Source/Responsible.h

FORMS += \
    Interface/Incomes.ui \
    Interface/IncomesInDates.ui \
    Interface/MainWindow.ui \
    Interface/MaterialPositionsByName.ui \
    Interface/Materials.ui \
    Interface/MaterialsWithPriceOver.ui \
    Interface/Positions.ui \
    Interface/Producers.ui \
    Interface/Releases.ui \
    Interface/Responsible.ui \
    Interface/About.ui \
    Interface/Connect.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
