cmake_minimum_required(VERSION 3.30.0)
project(ClientApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia Core5Compat)
qt_standard_project_setup()

qt_add_executable(app WIN32 MACOSX_BUNDLE main.cpp)

target_link_libraries(app PRIVATE 
                                Qt6::Quick 
                                Qt6::Multimedia
                                Qt6::Core5Compat)

qt6_policy(SET QTP0001 NEW)

qt_add_qml_module(app 
                    URI ClientApp
                    VERSION 1.0

                    RESOURCE_PREFIX "/QML"

                    QML_FILES
                    customModules/Main.qml
                    customModules/LoginWindow.qml 
                    customModules/SignUpWindow.qml 
                    customModules/ChatWindow.qml
                    customModules/ChatList.qml
                    customModules/ChatListDelegate.qml
                    customModules/ContactWindow.qml
                    customModules/ContactList.qml
                    customModules/ContactListDelegate.qml
                    customModules/InputField.qml
                    customModules/IconText.qml
                    customModules/MenuPanel.qml
                    customModules/ListDialog.qml
                    customModules/SettingWindow.qml
                    customModules/RoundedImage.qml
                    customModules/GroupList.qml
                    customModules/RoundedButton.qml
                    customModules/GroupChatWindow.qml
                    customModules/GroupListDelegate.qml
                    customModules/GroupChatList.qml
                    customModules/GroupChatListDelegate.qml

                    SOURCES
                    ChatProtocol.cpp ChatProtocol.h
                    ClientManager.cpp ClientManager.h
                    AudioController.cpp AudioController.h

                    MessageInfo.cpp MessageInfo.h
                    ChatListModel.cpp ChatListModel.h
                    ContactInfo.cpp ContactInfo.h
                    ContactListModel.cpp ContactListModel.h
                    ContactProxyList.cpp ContactProxyList.h

                    GroupChatListModel.cpp GroupChatListModel.h
                    GroupMessageInfo.cpp GroupMessageInfo.h
                    GroupInfo.cpp GroupInfo.h
                    GroupListModel.cpp GroupListModel.h
                    GroupProxyList.cpp GroupProxyList.h

                    RESOURCES
                    icons/chat_icon.png
                    icons/file_icon.png
                    icons/group_icon.png 
                    icons/voice_icon.png 
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
                    icons/online_icon.png
                    icons/offline_icon.png
                    icons/send_icon.png
                    icons/batman_icon.png
                    icons/batman_icon1.png
                    icons/ironman_icon.png
                    icons/superman_icon.png
                    icons/captain_icon.png
                    icons/settings_icon.png
                    icons/save_icon.png
                    icons/delete_icon.png
                    icons/logout_icon.png
                    icons/upload_icon.png
                    )

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -flto")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1")
endif()