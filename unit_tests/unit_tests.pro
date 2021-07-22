include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    unit_test_types.h

SOURCES += \
        CalculatorTests.cpp \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../calc_lib/release/ -lcalc_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../calc_lib/debug/ -lcalc_lib
else:unix:!macx: LIBS += -L$$OUT_PWD/../calc_lib/ -lcalc_lib

INCLUDEPATH += $$PWD/../calc_lib
DEPENDPATH += $$PWD/../calc_lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../calc_lib/release/libcalc_lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../calc_lib/debug/libcalc_lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../calc_lib/release/calc_lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../calc_lib/debug/calc_lib.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../calc_lib/libcalc_lib.a
