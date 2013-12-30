project(dock)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(dock_SRCS mainwindow.cpp main.cpp)
qt4_automoc(${dock_SRCS})
add_executable(dock ${dock_SRCS})
target_link_libraries(dock ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
