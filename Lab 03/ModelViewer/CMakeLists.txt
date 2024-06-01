cmake_minimum_required(VERSION 3.5)

project(ModelViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_OSX_DEPLOYMENT_TARGET "13.0")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/Users/fakejutsu/DeveloperTools/Qt/6.7.0/macos/lib/cmake")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

macro(include_all_directories dir)
  include_directories(${dir})
  file(GLOB children RELATIVE ${dir} ${dir}/*)
  foreach(child ${children})
    if(IS_DIRECTORY ${dir}/${child})
      include_all_directories(${dir}/${child})
      include_directories(${dir}/${child})
    endif()
  endforeach()
endmacro()

include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Primitives)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Model)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Scene)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Managers)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Commands)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Adapters)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Factory)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Visitors)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Builders)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Scene/SceneObject/sceneobject.h
        Scene/SceneObject/sceneobject.cpp
        Scene/scene.h Scene/scene.cpp
        Primitives/Matrix/TransformMatrix/transformmatrix.h
        Primitives/Matrix/TransformMatrix/transformmatrix.cpp
        Primitives/Point3d/point3d.h
        Primitives/Point3d/point3d.cpp
        Scene/Camera/TraceCamera/TraceCamera.cpp
        Scene/Camera/TraceCamera/TraceCamera.h
)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ModelViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Scene/SceneObject/sceneobject.h Scene/SceneObject/sceneobject.cpp
        Scene/scene.h Scene/scene.cpp
        Primitives/Matrix/TransformMatrix/transformmatrix.h Primitives/Matrix/TransformMatrix/transformmatrix.cpp
        Primitives/Point3d/point3d.h Primitives/Point3d/point3d.cpp
        Primitives/Matrix/matrixbase.h Primitives/Matrix/matrixbase.cpp
        Primitives/EdgeData/edgedata.h Primitives/EdgeData/edgedata.cpp
        Model/CarcasEdgesModel/ModelEdgesData/modeledgesdata.h Model/CarcasEdgesModel/ModelEdgesData/modeledgesdata.cpp
        Model/Base/ModelDataBase/modeldatabase.h Model/Base/ModelDataBase/modeldatabase.cpp
        Model/Base/EdgeDataIterator/edgedataiterator.h Model/Base/EdgeDataIterator/edgedataiterator.cpp
        Scene/VisibleSceneObject/visiblesceneobject.h Scene/VisibleSceneObject/visiblesceneobject.cpp
        Scene/InvisibleSceneObject/invisiblesceneobject.h Scene/InvisibleSceneObject/invisiblesceneobject.cpp
        Scene/CompositeSceneObject/compositesceneobject.h Scene/CompositeSceneObject/compositesceneobject.cpp
        Scene/Camera/cameraobject.h Scene/Camera/cameraobject.cpp
        Scene/SceneObject/sceneobject.h Scene/SceneObject/sceneobject.cpp
        Managers/basemanager.h Managers/basemanager.cpp
        Managers/SceneManager/scenemanager.h Managers/SceneManager/scenemanager.cpp
        Managers/DrawManager/drawmanager.h Managers/DrawManager/drawmanager.cpp
        Managers/ManagerSolution/managersolution.h Managers/ManagerSolution/managersolution.cpp
        Managers/ManagerCreator/managercreator.h Managers/ManagerCreator/managercreator.cpp
        Managers/LoadManager/loadmanager.h Managers/LoadManager/loadmanager.cpp
        Commands/basecommand.h Commands/basecommand.cpp
        Commands/ModelCommand/modelcommand.h Commands/ModelCommand/modelcommand.cpp
        Commands/ModelCommand/RotateModelCommand/rotatemodelcommand.h Commands/ModelCommand/RotateModelCommand/rotatemodelcommand.cpp
        Commands/ModelCommand/ScaleModelCommand/scalemodelcommand.h Commands/ModelCommand/ScaleModelCommand/scalemodelcommand.cpp
        Commands/ModelCommand/MoveModelCommand/movemodelcommand.h Commands/ModelCommand/MoveModelCommand/movemodelcommand.cpp
        Facade/facade.h Facade/facade.cpp
        Commands/CameraCommand/cameracommand.h Commands/CameraCommand/cameracommand.cpp
        Commands/CameraCommand/MoveCameraCommand/movecameracommand.h Commands/CameraCommand/MoveCameraCommand/movecameracommand.cpp
        Commands/CameraCommand/AddCameraCommand/addcameracommand.h Commands/CameraCommand/AddCameraCommand/addcameracommand.cpp
        Commands/CameraCommand/DeleteCameraCommand/deletecameracommand.h Commands/CameraCommand/DeleteCameraCommand/deletecameracommand.cpp
        Commands/CameraCommand/MoveCameraCommand/movecameracommand.h Commands/CameraCommand/MoveCameraCommand/movecameracommand.cpp
        Commands/SceneCommand/scenecommand.h Commands/SceneCommand/scenecommand.cpp
        Commands/SceneCommand/RedrawSceneCommand/redrawscenecommand.h Commands/SceneCommand/RedrawSceneCommand/redrawscenecommand.cpp
        Commands/SceneCommand/ClearSceneCommand/clearscenecommand.h Commands/SceneCommand/ClearSceneCommand/clearscenecommand.cpp
        Commands/UndoCommand/undocommand.h Commands/UndoCommand/undocommand.cpp
        Adapters/PenAdapter/penadapter.h Adapters/PenAdapter/penadapter.cpp
        Adapters/DrawSceneAdapter/drawsceneadapter.h Adapters/DrawSceneAdapter/drawsceneadapter.cpp
        Adapters/FileLoaderAdapter/fileloaderadapter.h Adapters/FileLoaderAdapter/fileloaderadapter.cpp
        Factory/uicreator.h Factory/uicreator.cpp
        Factory/uifactorybase.h Factory/uifactorybase.cpp
        Factory/UIQtFactory/uiqtfactory.h Factory/UIQtFactory/uiqtfactory.cpp
        Visitors/visitorbase.h Visitors/visitorbase.cpp
        Visitors/DrawVisitor/drawvisitor.h Visitors/DrawVisitor/drawvisitor.cpp
        Scene/VisibleSceneObject/ModelObject/modelobject.h Scene/VisibleSceneObject/ModelObject/modelobject.cpp
        Builders/ModelCreator/modelcreator.h Builders/ModelCreator/modelcreator.cpp
        Builders/ModelDirector/modeldirector.h Builders/ModelDirector/modeldirector.cpp
        Builders/ModelDirector/EdgesModelDirector/edgesmodeldirector.h Builders/ModelDirector/EdgesModelDirector/edgesmodeldirector.cpp
        Managers/TransformManager/transformmanager.h Managers/TransformManager/transformmanager.cpp
        Commands/CameraCommand/RotateCameraCommand/rotatecameracommand.h Commands/CameraCommand/RotateCameraCommand/rotatecameracommand.cpp
        Commands/ModelCommand/AddModelCommand/addmodelcommand.h Commands/ModelCommand/AddModelCommand/addmodelcommand.cpp
        Builders/ModelCreatorSolution/modelcreatorsolution.h Builders/ModelCreatorSolution/modelcreatorsolution.cpp
        Factory/UIFactorySolution/uifactorysolution.h Factory/UIFactorySolution/uifactorysolution.cpp
        Builders/Reader/filereader.h Builders/Reader/filereader.cpp
            Scene/Camera/TraceCamera/TraceCamera.cpp
            Scene/Camera/TraceCamera/TraceCamera.h


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ModelViewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ModelViewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ModelViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ModelViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ModelViewer)
endif()
set_target_properties(ModelViewer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)




include(GNUInstallDirs)
install(TARGETS ModelViewer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ModelViewer)
endif()
