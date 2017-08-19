greaterThan(QT_MAJOR_VERSION, 4)

# Project Configuration
CONFIG += console c++14 debug_and_release warn_on
TEMPLATE = app

LIB += opengl32

RESOURCES = textures.qrc

QT += core gui opengl xml

CONFIG( debug, debug|release ) {
	DESTDIR = ../bin/Debug
} else {
	DESTDIR = ../bin/Release
}
LIBPATH += $$DESTDIR 

OBJECTS_DIR = $$PWD/_objects_
MOC_DIR = $$PWD/_moc_
UI_DIR = $$PWD/_ui_
RCC_DIR = $$PWD/_rcc_

INCLUDEPATH = .. 

HEADERS += $$PWD/src/*.h
HEADERS += $$PWD/*.h
HEADERS += $$PWD/src/*.md
HEADERS += $$PWD/*.md
SOURCES += $$PWD/src/*.cpp

LIBS += common.lib opengl32.lib

# Target Output : Project File
TARGET = jalapeno
