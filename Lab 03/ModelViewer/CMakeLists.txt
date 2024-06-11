cmake_minimum_required(VERSION 3.5)

project(ModelViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_OSX_DEPLOYMENT_TARGET "13.3")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/Users/fakejutsu/DeveloperTools/Qt/6.7.0/macos/lib/cmake")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/")

find_package(Boost)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

find_package(glm CONFIG REQUIRED)

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
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Factory)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Managers)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Commands)
include_all_directories(${CMAKE_CURRENT_SOURCE_DIR}/Adapters)
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
        Scene/scene.h Scene/scene.cpp
        Primitives/Point3d/point3d.h
        Primitives/Point3d/point3d.cpp
        Scene/Camera/TraceCamera/TraceCamera.cpp
        Scene/Camera/TraceCamera/TraceCamera.h
        Commands/SceneCommand/SceneTextListCommand/SceneTextListCommand.cpp
        Commands/SceneCommand/SceneTextListCommand/SceneTextListCommand.h
        Adapters/RotateTraceCameraAdapter/RotateTraceCameraAdapter.cpp
        Adapters/RotateTraceCameraAdapter/RotateTraceCameraAdapter.h
        Visitors/TransformVisitor/TransformVisitor.cpp
        Visitors/TransformVisitor/TransformVisitor.h
        Primitives/Transformation/BaseTransformation.cpp
        Primitives/Transformation/BaseTransformation.h
        Primitives/Transformation/Scale/Scale.cpp
        Primitives/Transformation/Scale/Scale.h
        Primitives/Transformation/Transform/Transform.cpp
        Primitives/Transformation/Transform/Transform.h
        Primitives/Transformation/Rotate/Rotate.cpp
        Primitives/Transformation/Rotate/Rotate.h
        Primitives/Transformation/TransformationData.cpp
        Primitives/Transformation/TransformationData.h
        Model/CarcassEdgesDataImplementor.cpp
        Model/CarcassEdgesDataImplementor.h
        Adapters/ModelObjectEntityAdapter.cpp
        Adapters/ModelObjectEntityAdapter.h
        Builders/ModelDirectors/CarcassModelDirector.cpp
        Builders/ModelDirectors/CarcassModelDirector.h
        Builders/ModelBuilders/CarcassModelBuilder.cpp
        Builders/ModelBuilders/CarcassModelBuilder.h
        Builders/ModelBuilders/CarcassEdgesModelBuilder.cpp
        Builders/ModelBuilders/CarcassEdgesModelBuilder.h
        Builders/TextModelSource.cpp
        Builders/TextEdgesModelSource.h
        Builders/ModelDirectors/CarcassModelDirector.cpp
        Builders/ModelDirectors/CarcassModelDirector.h
        Commands/SceneCommand/InstallGraphicSceneCommand/InstallGraphicSceneCommand.cpp
        Commands/SceneCommand/InstallGraphicSceneCommand/InstallGraphicSceneCommand.h
        Adapters/DrawSceneAdapter/QtSceneAdapter.cpp
        Adapters/DrawSceneAdapter/QtSceneAdapter.h
        Primitives/Point2d/Point2d.h
        Primitives/Transformation/TransformHelper.cpp
        Primitives/Transformation/TransformHelper.h
        Visitors/ModelEntityVisitors/ModelEntityVisitorBase.cpp
        Visitors/ModelEntityVisitors/ModelEntityVisitorBase.h
        Visitors/ModelEntityVisitors/ModelEntityDrawVisitor.cpp
        Visitors/ModelEntityVisitors/ModelEntityDrawVisitor.h
        Builders/Solutions/CarcassSolution.cpp
        Builders/Solutions/CarcassCreatorSolution.h
        Facade/QtMiddlewareFacade.cpp
        Facade/QtMiddlewareFacade.h
        Commands/CameraCommand/SetNewMainCamera/SetNewMainCameraCommand.cpp
        Commands/CameraCommand/SetNewMainCamera/SetNewMainCameraCommand.h
        Commands/SceneCommand/DeleteObjectCommand/DeleteObjectCommand.cpp
        Commands/SceneCommand/DeleteObjectCommand/DeleteObjectCommand.h
        Adapters/DrawSceneAdapter/SceneAdapterFactory.cpp
        Adapters/DrawSceneAdapter/SceneAdapterFactory.h
        Factory/uifactorybase.h
        Factory/UIFactorySolution/uifactorysolution.h
        Factory/uicreator.h
        Factory/UIQtFactory/RefDrawSceneCreator.h
        Adapters/DrawSceneAdapter/drawsceneadapter.cpp
        Adapters/DrawSceneAdapter/drawsceneadapter.h
        Scene/SceneObject/SceneObjectMemento.cpp
        Scene/SceneObject/SceneObjectMemento.h
        Managers/HistoryManager/HistoryManager.cpp
        Managers/HistoryManager/HistoryManager.h
        Scene/ExceptionBase/BaseException.cpp
        Scene/ExceptionBase/BaseException.h
        Scene/ExceptionBase/NotFoundItemScene.h
        Builders/CarcassModelCreator.cpp
        Builders/CarcassModelCreator.h
        Builders/ModelDirectors/CarcassEdgesModelDirector.cpp
        Builders/ModelDirectors/CarcassEdgesModelDirector.h
        Scene/BaseScene/BaseSceneIterator/basesceneiterator.h
        Scene/BaseScene/BaseSceneIterator/basesceneiterator.cpp
        Managers/DependencyManager/DependencyManager.cpp
        Managers/DependencyManager/DependencyManager.h
        Builders/ModelSourceCreator.cpp
        Builders/ModelSourceCreator.h
        Adapters/DrawSceneAdapter/SceneAdapterCreator.cpp
        Adapters/DrawSceneAdapter/SceneAdapterCreator.h
        Builders/ModelBuilders/CarcassDotEdgesModelBuilder.cpp
        Builders/ModelBuilders/CarcassDotEdgesModelBuilder.h
        Model/CarcassEdgesDotImplementor.cpp
        Model/CarcassEdgesDotImplementor.h
        Builders/TextDotEdgesModelSource.cpp
        Builders/TextDotEdgesModelSource.h
        Builders/ModelDirectors/CarcassDotEdgesModelDirector.cpp
        Builders/ModelDirectors/CarcassDotEdgesModelDirector.h
        Scene/SceneObject/CarcassObject.cpp
        Scene/SceneObject/CarcassObject.h
        Scene/ModelObjectCreator.cpp
        Scene/ModelObjectCreator.h
        Scene/ModelObjectFactory.cpp
        Scene/ModelObjectFactory.h
        Builders/FileReader.cpp
        Builders/FileReader.h
        Builders/SourceCreator.cpp
        Builders/SourceCreator.h
        Builders/SourceFactory.cpp
        Builders/SourceFactory.h
        Builders/FileReaderCreator.cpp
        Builders/FileReaderCreator.h
        Scene/Camera/CameraCreator.cpp
        Scene/Camera/CameraCreator.h
        Scene/CompositeSceneObject/CompositeCreator.cpp
        Scene/CompositeSceneObject/CompositeCreator.h
        Scene/CompositeSceneObject/SimpleCompositeObject.cpp
        Scene/CompositeSceneObject/SimpleCompositeObject.h
        Commands/SceneCommand/GroupModelCommand/GroupModelCommand.cpp
        Commands/SceneCommand/GroupModelCommand/GroupModelCommand.h
)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ModelViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Scene/SceneObject/sceneobject.h Scene/SceneObject/sceneobject.cpp
        Scene/scene.h Scene/scene.cpp
        Primitives/Point3d/point3d.h Primitives/Point3d/point3d.cpp
        Primitives/EdgeData/edgedata.h Primitives/EdgeData/edgedata.cpp
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
            Adapters/DrawSceneAdapter/drawsceneinneradapter.h Adapters/DrawSceneAdapter/drawsceneinnteradapter.cpp
        Adapters/FileLoaderAdapter/fileloaderadapter.h Adapters/FileLoaderAdapter/fileloaderadapter.cpp
        Visitors/visitorbase.h Visitors/visitorbase.cpp
        Visitors/DrawVisitor/drawvisitor.h Visitors/DrawVisitor/drawvisitor.cpp
        Scene/VisibleSceneObject/ModelObject/modelobject.h Scene/VisibleSceneObject/ModelObject/modelobject.cpp
        Managers/TransformManager/transformmanager.h Managers/TransformManager/transformmanager.cpp
        Commands/CameraCommand/RotateCameraCommand/rotatecameracommand.h Commands/CameraCommand/RotateCameraCommand/rotatecameracommand.cpp
        Commands/ModelCommand/AddModelCommand/addmodelcommand.h Commands/ModelCommand/AddModelCommand/addmodelcommand.cpp
            Scene/Camera/TraceCamera/TraceCamera.cpp
            Scene/Camera/TraceCamera/TraceCamera.h
            Adapters/RotateTraceCameraAdapter/RotateTraceCameraAdapter.cpp
            Adapters/RotateTraceCameraAdapter/RotateTraceCameraAdapter.h
            Scene/Camera/TraceCamera/TraceCamera.cpp
            Scene/Camera/TraceCamera/TraceCamera.h
            Commands/SceneCommand/SceneTextListCommand/SceneTextListCommand.cpp
            Commands/SceneCommand/SceneTextListCommand/SceneTextListCommand.h
            Adapters/TransformationMatrix/TransformationMatrix.cpp
            Adapters/TransformationMatrix/TransformationMatrix.h
            Visitors/TransformVisitor/TransformVisitor.cpp
            Visitors/TransformVisitor/TransformVisitor.h
            Primitives/Transformation/Scale/Scale.cpp
            Primitives/Transformation/Scale/Scale.h
            Primitives/Transformation/Rotate/Rotate.cpp
            Primitives/Transformation/Rotate/Rotate.h
            Builders/AbsModelSource/AbsCorrectModelSource.cpp
            Builders/AbsModelSource/AbsCorrectModelSource.h
            Model/ModelAbstraction.h
            Model/CarcassModelEntity.cpp
            Model/CarcassModelEntity.h
            Model/CarcassModelImplementor.cpp
            Model/CarcassModelImplementor.h
            Model/CarcassEdgesDataImplementor.cpp
            Model/CarcassEdgesDataImplementor.h

            Builders/ModelBuilders/CarcassEdgesModelBuilder.cpp
            Builders/ModelBuilders/CarcassEdgesModelBuilder.h
            Builders/TextModelSource.cpp
            Builders/TextEdgesModelSource.h
            Builders/ModelDirectors/CarcassModelDirector.cpp
            Builders/ModelDirectors/CarcassModelDirector.h

            Commands/SceneCommand/InstallGraphicSceneCommand/InstallGraphicSceneCommand.cpp
            Commands/SceneCommand/InstallGraphicSceneCommand/InstallGraphicSceneCommand.h
            Adapters/DrawSceneAdapter/QtSceneAdapter.cpp
            Adapters/DrawSceneAdapter/QtSceneAdapter.h
            Primitives/Point2d/Point2d.h
            Primitives/Transformation/TransformHelper.cpp
            Primitives/Transformation/TransformHelper.h
            Visitors/ModelEntityVisitors/ModelEntityVisitorBase.cpp
            Visitors/ModelEntityVisitors/ModelEntityVisitorBase.h
            Builders/Solutions/CarcassSolution.cpp
            Builders/Solutions/CarcassCreatorSolution.h
            Facade/QtMiddlewareFacade.cpp
            Facade/QtMiddlewareFacade.h
            Commands/CameraCommand/SetNewMainCamera/SetNewMainCameraCommand.cpp
            Commands/CameraCommand/SetNewMainCamera/SetNewMainCameraCommand.h
            Commands/SceneCommand/DeleteObjectCommand/DeleteObjectCommand.cpp
            Commands/SceneCommand/DeleteObjectCommand/DeleteObjectCommand.h
            Adapters/DrawSceneAdapter/SceneAdapterFactory.cpp
            Adapters/DrawSceneAdapter/SceneAdapterFactory.h
            Factory/uifactorybase.h
            Factory/UIFactorySolution/uifactorysolution.h
            Factory/uicreator.h
            Factory/UIQtFactory/RefDrawSceneCreator.h
            Adapters/DrawSceneAdapter/drawsceneadapter.cpp
            Adapters/DrawSceneAdapter/drawsceneadapter.h
            Scene/SceneObject/SceneObjectMemento.cpp
            Scene/SceneObject/SceneObjectMemento.h
            Managers/HistoryManager/HistoryManager.cpp
            Managers/HistoryManager/HistoryManager.h
            Scene/ExceptionBase/BaseException.cpp
            Scene/ExceptionBase/BaseException.h
            Scene/ExceptionBase/NotFoundItemScene.h
            Builders/CarcassModelCreator.cpp
            Builders/CarcassModelCreator.h
            Builders/ModelDirectors/CarcassEdgesModelDirector.cpp
            Builders/ModelDirectors/CarcassEdgesModelDirector.h
            Scene/BaseScene/BaseSceneIterator/basesceneiterator.h
            Scene/BaseScene/BaseSceneIterator/basesceneiterator.cpp
            Managers/DependencyManager/DependencyManager.cpp
            Managers/DependencyManager/DependencyManager.h
            Builders/ModelSourceCreator.cpp
            Builders/ModelSourceCreator.h
            Adapters/DrawSceneAdapter/SceneAdapterCreator.cpp
            Adapters/DrawSceneAdapter/SceneAdapterCreator.h
            Builders/ModelBuilders/CarcassDotEdgesModelBuilder.cpp
            Builders/ModelBuilders/CarcassDotEdgesModelBuilder.h
            Model/CarcassEdgesDotImplementor.cpp
            Model/CarcassEdgesDotImplementor.h
            Builders/TextDotEdgesModelSource.cpp
            Builders/TextDotEdgesModelSource.h
            Builders/ModelDirectors/CarcassDotEdgesModelDirector.cpp
            Builders/ModelDirectors/CarcassDotEdgesModelDirector.h
            Scene/SceneObject/CarcassObject.cpp
            Scene/SceneObject/CarcassObject.h
            Scene/ModelObjectCreator.cpp
            Scene/ModelObjectCreator.h
            Scene/ModelObjectFactory.cpp
            Scene/ModelObjectFactory.h
            Builders/FileReader.cpp
            Builders/FileReader.h
            Builders/SourceCreator.cpp
            Builders/SourceCreator.h
            Builders/SourceFactory.cpp
            Builders/SourceFactory.h
            Builders/FileReaderCreator.cpp
            Builders/FileReaderCreator.h
            Scene/Camera/CameraCreator.cpp
            Scene/Camera/CameraCreator.h
            Scene/CompositeSceneObject/CompositeCreator.cpp
            Scene/CompositeSceneObject/CompositeCreator.h
            Scene/CompositeSceneObject/SimpleCompositeObject.cpp
            Scene/CompositeSceneObject/SimpleCompositeObject.h
            Commands/SceneCommand/GroupModelCommand/GroupModelCommand.cpp
            Commands/SceneCommand/GroupModelCommand/GroupModelCommand.h


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

target_link_libraries(ModelViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets glm::glm)

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
