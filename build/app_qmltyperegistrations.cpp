/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <ChatListModel.hpp>
#include <ClientManager.hpp>
#include <ContactInfo.hpp>
#include <ContactListModel.hpp>
#include <ContactProxyList.hpp>
#include <GroupChatListModel.hpp>
#include <GroupInfo.hpp>
#include <GroupListModel.hpp>
#include <GroupMessageInfo.hpp>
#include <GroupProxyList.hpp>
#include <MediaController.hpp>
#include <MessageInfo.hpp>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_ClientApp()
{
    qmlRegisterTypesAndRevisions<ChatListModel>("ClientApp", 1);
    qmlRegisterAnonymousType<QAbstractItemModel, 254>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<ClientManager>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<ContactInfo>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<ContactListModel>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<ContactProxyList>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<GroupChatListModel>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<GroupInfo>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<GroupListModel>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<GroupMessageInfo>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<GroupProxyList>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<MediaController>("ClientApp", 1);
    qmlRegisterTypesAndRevisions<MessageInfo>("ClientApp", 1);
    QMetaType::fromType<QAbstractProxyModel *>().id();
    QMetaType::fromType<QSortFilterProxyModel *>().id();
    qmlRegisterModule("ClientApp", 1, 0);
}

static const QQmlModuleRegistration clientAppRegistration("ClientApp", qml_register_types_ClientApp);
