greaterThan(QT_MAJOR_VERSION, 4)

# Project Configuration
CONFIG += staticlib c++14 debug_and_release warn_on
TEMPLATE = lib

CONFIG( debug, debug|release ) {
	DESTDIR = ../bin/Debug
} else {
	DESTDIR = ../bin/Release
}

OBJECTS_DIR = $$PWD/_objects_
MOC_DIR = $$PWD/_moc_
UI_DIR = $$PWD/_ui_
RCC_DIR = $$PWD/_rcc_

INCLUDEPATH = .. 

HEADERS += $$PWD/src/*.h
HEADERS += $$PWD/*.h
HEADERS += $$PWD/src/*.md
HEADERS += $$PWD/*.md
HEADERS += $$PWD/*.pro
SOURCES += $$PWD/src/*.cpp

# Target Output : Project File
TARGET = common
