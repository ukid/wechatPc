#pragma once
#include "OpCode.h"
#include "PJson.h"
#include "LoginInfo.h"
#include "Message.h"
#include "Package.h"

using namespace rapidjson;

// �����б�
typedef struct FriendList
{
	CHAR wxid[0x100] = { 0 };
	CHAR username[0x100] = { 0 };
	int sex = 0;  // �Ա�1=�У�2=Ů
	CHAR v1[0x256] = { 0 };
	CHAR v2[0x256] = { 0 };
	int type = 0;
	CHAR nickname[0x100] = { 0 };
	int roomType = 0;
	CHAR remark[0x128] = { 0 };
	CHAR bigHeadImgUrl[0x512] = { 0 };
	CHAR smallHeadImgUrl[0x512] = { 0 };
	CHAR roomWxidList[0xEA60] = { 0 };  // 30 x 2000 = 30���� x 2000��Ⱥ��ԱID
	int roomOwner = 0;
	CHAR roomAnnouncement[0x5120] = { 0 };
	CHAR roomAnnouncementEditor[0x100] = { 0 };
	CHAR roomAnnouncementPublishTime[0x100] = { 0 };
	int roomStatus = 0;
	int bizType = 0;
	int bizAcceptType = 0;
	CHAR bizBrandList[0xEA60] = { 0 };
	int bizBrandFlag = 0;
	CHAR bizBrandIconURL[0x512] = { 0 };
	CHAR bizExtInfo[0xEA60] = { 0 };
	CHAR extraBuf[0xEA60] = { 0 };
	int delFlag = 0;
	int verifyFlag = 0;
	int roomNotify = 0;

	FriendList *next;
} FriendList;
// ��¼����
struct LoginInfo
{
	CHAR wxid[0x100] = { 0 };  // ΢��ID
	CHAR username[0x100] = { 0 };  // ΢�ź�
	CHAR nickname[0x100] = { 0 };  // �ǳ�
	CHAR headUrl[0x256] = { 0 };  // ͷ��URL��ַ
	CHAR mobile[0x32] = { 0 };  // �ֻ�����
	CHAR email[0x32] = { 0 };  // ��Ϸ
	int sex = 0;  // �Ա�1=�У�2=Ů��0=δ֪
	CHAR nation[0x32] = { 0 };  // ����
	CHAR province[0x32] = { 0 };  // ʡ��
	CHAR city[0x32] = { 0 };  // ����
	CHAR sign[0x32] = { 0 };  // ����ǩ��
	CHAR device[0x32] = { 0 };  // ��¼���ֻ��豸
};

// ���ͻط������˵���Ϣ�ṹ��
struct WebsocketMessageStruct
{
	char msgId[0x100] = { 0 };  // ��ϢID
	int isOwner = 0;  // �Ƿ��Լ�������Ϣ��0=��1=��
	int msgType = 0;  // ��Ϣ����
	int msgSource = 0;  // ��Ϣ��Դ��0=������Ϣ��1=Ⱥ��Ϣ
	char msgSourceXml[0x2048] = { 0 };  // Ⱥ������Ϣ
	char wxid[0x100] = { 0 };  // ������΢��ID
	char roomId[0x100] = { 0 };  // ȺID
	char content[0x8092] = { 0 };  // ��Ϣ����
};


class Send
{
public:
	static void SendFriendList(FriendList *list, Package *package = NULL, int page = 1, int pageSize = 0, int total = 0);
	static void SendWxMessage(WebsocketMessageStruct *message, Package *package = NULL);
	static void SendLoginInfo(LoginInfo *info, Package *package = NULL);
	static void SendLoginStatus(int loginStatus, Package *package = NULL);
	static void SendLoginQrcode(int loginStatus, char *qrcode, Package *package = NULL);
};