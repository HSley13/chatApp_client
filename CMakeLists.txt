cmake_minimum_required(VERSION 3.30.0)
project(ClientApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Qml Multimedia WebSockets)
qt_standard_project_setup()

qt_add_executable(app WIN32 MACOSX_BUNDLE main.cpp)

target_link_libraries(app PRIVATE 
                                Qt6::Quick 
                                Qt6::Qml
                                Qt6::Multimedia
                                Qt6::WebSockets)

qt6_policy(SET QTP0001 NEW)

qt_add_qml_module(app 
                    URI ClientApp
                    VERSION 1.0

                    RESOURCE_PREFIX "/QML_modules"

                    QML_FILES
                    customModules/Main.qml
                    customModules/ChatWindow.qml
                    customModules/LoginWindow.qml 
                    customModules/SignUpWindow.qml 
                    customModules/ConversationWindow.qml 
                    customModules/InputField.qml
                    customModules/IconText.qml
                    customModules/ImageText.qml
                    customModules/ChatMainSection.qml
                    customModules/ConversationMainSection.qml

                    SOURCES
                    ChatListModel.cpp ChatListModel.h
                    ChatProtocol.cpp ChatProtocol.h
                    ClientManager.cpp ClientManager.h
                    ChatInfo.cpp ChatInfo.h
     
                    RESOURCES
                    icons/chat_icon.png
                    icons/file_icon.png
                    icons/group_icon.png 
                    icons/record_icon.png 
                    icons/send_file_icon.png
                    icons/hide_icon.png
                    icons/see_icon.png
                    icons/hi_icon.png
                    icons/phone_icon.png
                    icons/name_icon.png
                    icons/password_icon.png
                    icons/search_icon.png
                    icons/back_icon.png
                    icons/plus_icon.png
                    icons/cancel_icon.png
                    icons/menu_icon.png
                    icons/cancel_menu.png
                    icons/image.jpg
                    icons/online_icon.png
                    icons/offline_icon.png
                    icons/send_icon.png)