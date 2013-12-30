project(Breakout)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Breakout_SRCS ball.cpp brick.cpp paddle.cpp Breakout.cpp main.cpp)
qt4_automoc(${Breakout_SRCS})
add_executable(Breakout ${Breakout_SRCS})
target_link_libraries(Breakout ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
