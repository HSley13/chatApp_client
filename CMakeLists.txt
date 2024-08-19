cmake_minimum_required(VERSION 3.30.0)
project(ClientApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Widgets Multimedia Core5Compat WebSockets)
qt_standard_project_setup()

qt_add_executable(app WIN32 MACOSX_BUNDLE src/main.cpp src/FileWatcher.cpp)

target_include_directories(app PRIVATE src/ 
                                        src/contacts
                                        src/groups)
target_link_libraries(app PRIVATE 
                                Qt6::Quick
                                Qt6::Widgets 
                                Qt6::Multimedia
                                Qt6::Core5Compat
                                Qt6::WebSockets)

qt6_policy(SET QTP0001 NEW)

file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp src/*.h)
file(GLOB QML_CUSTOMED_TYPES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} customModules/)
file(GLOB ICONS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} icons/*.png)

qt_add_qml_module(app 
                    URI ClientApp
                    VERSION 1.0

                    RESOURCE_PREFIX "/QML"

                    QML_FILES
                    ${QML_CUSTOMED_TYPES}

                    SOURCES
                    ${CPP_FILES}

                    RESOURCES
                    ${ICONS}
                )

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -flto")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1")

    include_directories(${EMSCRIPTEN}/system/include)
    set_target_properties(app PROPERTIES LINK_FLAGS "-lidbfs.js")
endif()

if (APPLE)
    set(MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
    set_target_properties(app PROPERTIES
                            MACOSX_BUNDLE_INFO_PLIST ${MACOSX_BUNDLE_INFO_PLIST}
                         )
endif()
