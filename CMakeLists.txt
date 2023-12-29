CMAKE_MINIMUM_REQUIRED(VERSION 3.21.1)

PROJECT(GUIRecorder LANGUAGES CXX)

FIND_PACKAGE(Qt6 6.6.0 REQUIRED COMPONENTS Core Gui Qml Quick Widgets QuickControls2)

#FOR QT
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CONFIGURATION_TYPES Debug;Release)

#QT STAFF
qt6_standard_project_setup()

qt6_add_executable(GUIRecorder
    src/source/main.cpp
    src/source/InitExtendLibs.cpp

    src/include/StepsModel/StepsModelsController.h
    src/include/StepsModel/StepInfo.h

    src/source/StepsModel/StepsModelsController.cpp
    src/source/StepsModel/StepInfo.cpp

    src/include/TemplateModel/TemplatesModelsController.h
    src/include/TemplateModel/TemplateInfo.h

    src/source/TemplateModel/TemplatesModelsController.cpp
    src/source/TemplateModel/TemplateInfo.cpp

    #External
    src/include/DllLoader.h
    src/include/InitExtendLibs.h


    src/externalLibs/API/IGUIRecorderCore.h
    src/externalLibs/API/IGUIRecorderReportGen.h
    src/externalLibs/API/IParentInfo.h
    src/externalLibs/API/IPlayer.h
    src/externalLibs/API/IRecorder.h
    src/externalLibs/API/IScenario.h
    src/externalLibs/API/IStep.h
)

qt6_add_resources(GUIRecorder "configuration"
    PREFIX "/"
    FILES
        src/qtquickcontrols2.conf
        src/qml/main.qml
        src/qml/MainMenuBar.qml
        src/qml/FooterOutput.qml
        src/qml/content/ViewTab/ViewTab.qml
        src/qml/content/ViewTab/TreeViewTemplate.qml
        src/qml/content/ViewTab/TreeViewStepsList/TreeViewStepsList.qml
        src/qml/content/ViewTab/TreeViewStepsList/TreeDelegate.qml
        src/source/TemplateModel/default.txt

        #Logger
        src/js/qmlfooterlog.js
)

TARGET_LINK_LIBRARIES(GUIRecorder PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Widgets
    Qt6::QuickControls2
)
