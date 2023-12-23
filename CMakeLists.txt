CMAKE_MINIMUM_REQUIRED(VERSION 3.21.1)

PROJECT(GUIRecorder LANGUAGES CXX)

FIND_PACKAGE(Qt6 6.6.1 REQUIRED COMPONENTS Core Gui Qml Quick Widgets QuickControls2)

#FOR QT
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CONFIGURATION_TYPES Debug;Release)

#QT STAFF
qt6_standard_project_setup()

qt6_add_executable(GUIRecorder
    src/source/main.cpp

    src/include/StepsModelsController.h
    src/include/StepInfo.h

    src/source/TreeModel/StepsModelsController.cpp
    src/source/TreeModel/StepInfo.cpp
)

qt6_add_resources(GUIRecorder "configuration"
    PREFIX "/"
    FILES
        src/qtquickcontrols2.conf
        src/qml/main.qml
        src/qml/content/RecorderTab/RecorderTab.qml
        src/qml/content/RecorderTab/LogOutput.qml
        src/qml/content/RecorderTab/TreeViewStepsList/TreeViewStepsList.qml
        src/qml/content/RecorderTab/TreeViewStepsList/TreeDelegate.qml
        src/source/TreeModel/default.txt
)

TARGET_LINK_LIBRARIES(GUIRecorder PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Widgets
    Qt6::QuickControls2
)
