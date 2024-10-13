cmake_minimum_required(VERSION 3.29.3)
project(ClientApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Widgets Multimedia Core5Compat WebSockets)

qt_standard_project_setup()

qt_add_executable(app src/main.cpp)

target_include_directories(app PRIVATE src/ src/contacts src/groups)

target_link_libraries(app PRIVATE Qt6::Quick Qt6::Widgets Qt6::Multimedia Qt6::Core5Compat Qt6::WebSockets)

qt6_policy(SET QTP0001 NEW)

set(QML_CUSTOMED_TYPES
    customModules/Main.qml
    customModules/LoginWindow.qml
    customModules/SignUpWindow.qml
    customModules/ForgottenPassword.qml
    customModules/ContactWindow.qml
    customModules/ContactList.qml
    customModules/ContactListDelegate.qml
    customModules/ChatWindow.qml
    customModules/ChatList.qml
    customModules/TextMessageDelegate.qml
    customModules/AudioMessageDelegate.qml
    customModules/FileMessageDelegate.qml
    customModules/GroupList.qml
    customModules/GroupListDelegate.qml
    customModules/GroupChatWindow.qml
    customModules/GroupChatList.qml
    customModules/GroupTextMessageDelegate.qml
    customModules/GroupAudioMessageDelegate.qml
    customModules/GroupFileMessageDelegate.qml
    customModules/GroupMenuPanel.qml
    customModules/InputField.qml
    customModules/IconText.qml
    customModules/MenuPanel.qml
    customModules/ListDialog.qml
    customModules/SettingWindow.qml
    customModules/RoundedImage.qml
    customModules/RoundedButton.qml)

set(CPP_FILES
    src/ClientManager.cpp
    src/ClientManager.hpp
    src/MediaController.cpp
    src/MediaController.hpp
    src/contacts/MessageInfo.cpp
    src/contacts/MessageInfo.hpp
    src/contacts/ChatListModel.cpp
    src/contacts/ChatListModel.hpp
    src/contacts/ContactInfo.cpp
    src/contacts/ContactInfo.hpp
    src/contacts/ContactListModel.cpp
    src/contacts/ContactListModel.hpp
    src/contacts/ContactProxyList.cpp
    src/contacts/ContactProxyList.hpp
    src/groups/GroupMessageInfo.cpp
    src/groups/GroupMessageInfo.hpp
    src/groups/GroupChatListModel.cpp
    src/groups/GroupChatListModel.hpp
    src/groups/GroupInfo.cpp
    src/groups/GroupInfo.hpp
    src/groups/GroupListModel.cpp
    src/groups/GroupListModel.hpp
    src/groups/GroupProxyList.cpp
    src/groups/GroupProxyList.hpp)

set(ICONS
    icons/pause_icon.png
    icons/play_icon.png
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
    icons/avengers_icon.png
    icons/justice_league_icon.png
    icons/question_icon.png
    icons/answer_icon.png
    icons/forgotten_icon.png)

qt_add_qml_module(app
  URI
  ClientApp
  VERSION
  1.0
  RESOURCE_PREFIX
  "/QML"
  QML_FILES
  ${QML_CUSTOMED_TYPES}
  SOURCES
  ${CPP_FILES}
  RESOURCES
  ${ICONS})

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -flto")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1")

  include_directories(${EMSCRIPTEN}/system/include)

  set_target_properties(app PROPERTIES LINK_FLAGS "-lidbfs.js")
endif()

set_target_properties(app PROPERTIES APPEND PROPERTY
             MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

set(android_apk_files "${CMAKE_SOURCE_DIR}/Android/AndroidManifest.xml")

set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Android")

set(ANDROID_API 21)

set(ANDROID_PERMISSIONS "INTERNET")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
