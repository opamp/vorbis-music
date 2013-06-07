FIND_PACKAGE(Qt5Widgets REQUIRED)
MESSAGE(STATUS "Qt5 --> ${Qt5Widgets_VERSION_STRING}") 
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES(/usr/include /usr/local/include)
LINK_DIRECTORIES(/usr/lib /usr/local/lib)

SET(BINARY_NAME "vorbis-music")


SET(MSRC
	${SRC_DIR}/main.cpp
	${SRC_DIR}/MainWindow.cpp
	${SRC_DIR}/MainWidget.cpp
	${SRC_DIR}/playVorbis.cpp
	)

#QT5_ADD_RESOURCES(QRC ${SRC_DIR}/main.qrc)

SET(SRCS ${MSRC}) #${SRC})

ADD_EXECUTABLE(${BINARY_NAME} ${SRCS})
QT5_USE_MODULES(${BINARY_NAME} Widgets Multimedia)
TARGET_LINK_LIBRARIES(${BINARY_NAME} vorbis vorbisfile)
