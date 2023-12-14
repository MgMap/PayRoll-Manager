 cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TextInput/cursor.cpp TextInput/cursor.h TextInput/Letter.cpp TextInput/Letter.h TextInput/MultiText.cpp TextInput/MultiText.h TextInput/TextBox.cpp TextInput/TextBox.h  TextInput/Typing.cpp TextInput/Typing.h Font/Fonts.cpp Font/Fonts.h Images/Textures.cpp Images/Textures.h Helper/Position.cpp Helper/Position.h Helper/MouseEvents.cpp Helper/MouseEvents.h FileTree/FileTree.cpp FileTree/FileTree.h FileTree/FileNode.cpp FileTree/FileNode.h FileTree/FileItem.cpp FileTree/FileItem.h Helper/States.cpp Helper/States.h Helper/GUIComponents.cpp Helper/GUIComponents.h Helper/EventHandler.cpp Helper/EventHandler.h DEFINITIONS.h "Payroll Manager/Screen1.cpp" "Payroll Manager/Screen1.h" Helper/Button.cpp Helper/Button.h "Payroll Manager/Screen3.cpp" "Payroll Manager/Screen3.h" DropDownMenu/Item.cpp DropDownMenu/Item.h DropDownMenu/ItemList.cpp DropDownMenu/ItemList.h DropDownMenu/DropDownMenu.cpp DropDownMenu/DropDownMenu.h DropDownMenu/InputBox.cpp DropDownMenu/InputBox.h WordSort/Word.cpp WordSort/Word.h WordSort/WordSort.cpp WordSort/WordSort.h WordSort/FileReader.cpp WordSort/FileReader.h WordSort/Heap.cpp WordSort/Heap.h "Payroll Manager/DataReader.cpp" "Payroll Manager/DataReader.h" "Payroll Manager/employeeData.cpp" "Payroll Manager/employeeData.h" "Payroll Manager/dataSort.cpp" "Payroll Manager/dataSort.h" "Payroll Manager/Screen2.cpp" "Payroll Manager/Screen2.h" "Payroll Manager/Interface.cpp" "Payroll Manager/Interface.h")

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()