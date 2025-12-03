cmake_minimum_required(VERSION 3.5)

project(LangLearnApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# Qt 6 uses qt_add_executable
# Qt 5 uses add_executable

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    add_executable(LangLearnApp
        ${PROJECT_SOURCES}
    )
else()
    add_executable(LangLearnApp
        ${PROJECT_SOURCES}
    )
endif()

qt_add_resources(RESOURCES resources.qrc)

target_sources(LangLearnApp PRIVATE
    ${RESOURCES}
)

target_link_libraries(LangLearnApp PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)


set_target_properties(LangLearnApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS LangLearnApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
