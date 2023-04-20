/*************************************************************************************************
	FileName : EmailApp.h
    FileFunc : ʵ��Email��ĿӦ�ýӿ�ͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2016-12-23 11:13:15
    Descp    : ʵ��Email��ĿӦ����ں���ͷ�ļ�
    History  : None
	Other    : None
*************************************************************************************************/

#ifndef __EMAILAPP_H__
#define __EMAILAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define 	EMAILAPP_NAME				"Email����"
#define 	EMAILAPP_FUNCTION			EMAILAPP_NAME "ģ��Ӧ�����"
#define 	EMAILAPP_VERSION			"00.00.01"
#define 	EMAILAPP_AUTHOR				APP_AUTHOR
#define 	EMAILAPP_CONTACT			APP_CONTACT
#define 	EMAILAPP_DATE				"2015-09-30 10:26:10"
#define 	EMAILAPP_DESCPTION			"Email��ĿӦ�����"

/*SMTP������"��"����\r\n*/
#define 	EMAILAPP_EOF				"\r\n"		//0x0D 0x0A

/*SMTP������"��"ĩβ�������\r\n*/
#define 	EMAILAPP_EOF_NONE			""

/*SMTP����������־\r\n.\r\n*/
#define 	EMAILAPP_END				"\r\n.\r\n"		//0x0D 0x0A 0x2E 0x0D 0x0A

/*SMTP����������־(Ĭ��\t)*/
#define 	EMAILAPP_INDENT				"\t"

/*�ʼ�MIME�汾��󳤶�*/
#define		EMAILAPP_MIMEVER_MAXLEN		8

/*�ʼ����뼯��󳤶�*/
#define		EMAILAPP_CHARSET_MAXLEN		16

/*�ʼ���ַ��С����*/
#define		EMAILAPP_EMAILADDR_MINLEN	9

/*�ʼ���ַ��󳤶�*/
#define		EMAILAPP_EMAILADDR_MAXLEN	64

/*�ʼ��û�����С����*/
#define		EMAILAPP_USERNAME_MINLEN	3

/*�ʼ��û�����󳤶�*/
#define		EMAILAPP_USERNAME_MAXLEN	32

/*�ʼ��û�������󳤶�*/
#define		EMAILAPP_USERPASSWORD_MAXLEN	32

/*�ʼ�����������������С����*/
#define		EMAILAPP_HOSTDOMAINNAME_MINLEN	5

/*�ʼ�����������������󳤶�*/
#define		EMAILAPP_HOSTDOMAINNAME_MAXLEN	16

/*�ʼ�������������ַ��󳤶�*/
#define		EMAILAPP_HOSTIP_MAXLEN		15

/*�ʼ�boundary��ǩ��󳤶�*/
#define		EMAILAPP_BOUNDARY_MAXLEN	64

/*���յ��ʼ��������*/
#define		EMAILAPP_TOEMAIL_MAXNUM		50

/*���յĳ����ʼ��������*/
#define		EMAILAPP_CCEMAIL_MAXNUM		10

/*���յ������ʼ��������*/
#define		EMAILAPP_BCCEMAIL_MAXNUM	10

/*���͵��ʼ�������󳤶�*/
#define		EMAILAPP_SUBJECT_MAXLEN		256

/*���͵��ʼ������и߶���󳤶�*/
#define		EMAILAPP_TEXT_LINEHEIGHT_MAXLEN		8

/*���͵��ʼ�����������ɫ��󳤶�*/
#define		EMAILAPP_TEXT_COLOR_MAXLEN			6

/*���͵��ʼ����������С��󳤶�*/
#define		EMAILAPP_TEXT_FONTSIZE_MAXLEN		8

/*���͵��ʼ���������������󳤶�*/
#define		EMAILAPP_TEXT_FONTFAMILY_MAXLEN		32

/*���͵��ʼ�������󳤶�*/
#define		EMAILAPP_TEXT_MAXLEN		(1024*16)	//16k

/*���͵�����������󳤶�*/
#define		EMAILAPP_CONTENTTYPE_MAXLEN		128

/*���͵��ʼ������������*/
#define		EMAILAPP_ATTACHMENT_MAXNUM		10

/*���͵��ʼ������ļ�����󳤶�*/
#define		EMAILAPP_ATTACHMENTFILENAME_MAXLEN		256

/*�ʼ���������:������/������*/
typedef enum _EMAIL_CONTENTTYPE
{	
	CONTENTTYPE_TEXT_PLAIN = 0,				/*text/plain:1.txt(���ı�)*/
	CONTENTTYPE_TEXT_HTML,					/*text/html:1.htm(html�ĵ�)*/
	CONTENTTYPE_TEXT_X_C,					/*text/x-c:1.c/1.cpp/1.h(c�ĵ�)*/
	CONTENTTYPE_TEXT_X_JAVA_SOURCE,			/*text/x-java-source:1.java(java�ĵ�)*/
	CONTENTTYPE_IMAGE_GIF,					/*image/gif:1.gif(GIFͼ��)*/
	CONTENTTYPE_IMAGE_JPEG,					/*image/jpeg:1.jpeg(JPEGͼ��)*/
	CONTENTTYPE_IMAGE_PNG,					/*image/png:1.png(PNGͼ��)*/
	CONTENTTYPE_VIDEO_MPEG,					/*video/mpge:1.mpeg(MPEG����)*/
	CONTENTTYPE_APPLICATION_XHTML_XML,		/*application/xhtml+xml:1.htm(XHTML�ĵ�)*/
	CONTENTTYPE_APPLICATION_MSWORD,			/*application/msword:1.doc(Microsoft Word�ĵ�)*/
	CONTENTTYPE_APPLICATION_MSWORDX,		/*application/vnd.openxmlformats-officedocument.wordprocessingml.document:1.docx(docx�ĵ�)*/
	CONTENTTYPE_APPLICATION_MSXLS,			/*application/msxls:1.xls(xls�ĵ�)*/
	CONTENTTYPE_APPLICATION_MSXLSX,			/*application/vnd.openxmlformats-officedocument.spreadsheetml.sheet:1.xlsx(xls�ĵ�)*/
	CONTENTTYPE_APPLICATION_MSPPT,			/*application/msppt:1.ppt(ppt�ĵ�)*/
	CONTENTTYPE_APPLICATION_MSPPTX,			/*application/vnd.openxmlformats-officedocument.presentationml.presentation:1.pptx(pptx�ĵ�)*/
	CONTENTTYPE_APPLICATION_PDF,			/*application/pdf:1.pdf(PDF�ĵ�)*/
	CONTENTTYPE_APPLICATION_X_TGIF,			/*application/x-tgif:XX.obj*/
	CONTENTTYPE_APPLICATION_OCTET_STREAM,	/*application/octet-stream:323(����Ķ���������)*/
}EMAIL_CONTENTTYPE;

/*���͵��ʼ���Ϣ*/
typedef struct _FROMEMAIL_PRM{
	unsigned char ucUserPasswordFlag;									/*�ʼ��û������־:0-���� 1-����(Ĭ��)*/
	unsigned short usServerHostPort;									/*�����ʼ������������˿�(Ĭ��25)*/
	unsigned char aucFromEmail[EMAILAPP_EMAILADDR_MAXLEN+1];			/*�����ʼ���ַ:qq������Ҫ���ÿ���pop3/smtp����(qq������Ҫʹ����֤����Ϊ�����½)*/
	unsigned char aucUserName[EMAILAPP_USERNAME_MAXLEN+1];				/*�����ʼ��û���*/
	unsigned char aucUserPassword[EMAILAPP_USERPASSWORD_MAXLEN+1];		/*�����ʼ��û�����:qq������Ҫʹ����֤����Ϊ�����½*/
	unsigned char aucServerHostName[EMAILAPP_HOSTDOMAINNAME_MAXLEN+1];	/*�����ʼ���������������*/
	unsigned char aucServerHostIp[EMAILAPP_HOSTIP_MAXLEN+1];			/*�����ʼ�����������IP*/
	unsigned char aucBoundary[EMAILAPP_BOUNDARY_MAXLEN+1];				/*���͵�boundary��ǩ*/
}FROMEMAIL_PRM;

/*���յ��ʼ���ַ��Ϣ*/
typedef struct _TOEMAIL_PRM{
	unsigned char aucToEmail[EMAILAPP_EMAILADDR_MAXLEN+1];	/*���͵��ʼ���ַ*/
}TOEMAIL_PRM;

/*���յ��ʼ���*/
typedef struct _TOEMAILGROUP_PRM{
	unsigned char ucToEmailHideFlag;						/*���յ��ʼ�����Ϣ�Ƿ�����:0-������ ��0-����*/
	int iToEmailNum;										/*���յ��ʼ���Ϣ����*/
	TOEMAIL_PRM mToEmail[EMAILAPP_TOEMAIL_MAXNUM];			/*���յ��ʼ���Ϣ*/
}TOEMAILGROUP_PRM;

/*���յĳ����ʼ���*/
typedef struct _CCEMAILGROUP_PRM{
	unsigned char ucCcEmailHideFlag;						/*���յĳ����ʼ�����Ϣ�Ƿ�����:0-������ ��0-����*/
	int iCcEmailNum;										/*���յĳ����ʼ���Ϣ����*/
	TOEMAIL_PRM mCcEmail[EMAILAPP_CCEMAIL_MAXNUM];			/*���յĳ����ʼ���Ϣ*/
}CCEMAILGROUP_PRM;

/*���յ������ʼ���*/
typedef struct _BCCEMAILGROUP_PRM{
	unsigned char ucBccEmailHideFlag;						/*���յ������ʼ�����Ϣ�Ƿ�����:0-������ ��0-����*/
	int iBccEmailNum;										/*���յ������ʼ���Ϣ����*/
	TOEMAIL_PRM mBccEmail[EMAILAPP_BCCEMAIL_MAXNUM];		/*���յ������ʼ���Ϣ*/
}BCCEMAILGROUP_PRM;

/*
line-height:
���������ö�����и�,��������׶��������ڲ�����֮��ľ���;
��line-heightֻ������������,����ͼƬʱʧЧ;

color:
������������������ɫ;
������ɫ�ο�:https://blog.csdn.net/IT1039871366/article/details/46726979

font-size:������������,�����С,���õĵ�λ��px����,����%�ٷֱ�,�ƶ����õĵ�λem;
1)px���ص�λfont-size��20px��
��ʾ:��ҳ����Ĭ�ϵ������С��12px,Ҳ���������õ�����С��12px,Ĭ�϶�����12px��С��ʾ;
���Ծ������ʵ�,�����ҳ��С��12px������;
2)%�ٷֱȵ�λ�ٷֱ���Ը�Ԫ�ص�font-size��С���������С�԰ٷֱ�Ϊ��λ,��Ե��Ǹ�Ԫ��font-size��С;
3)font-size�����ϸ��������Ĵ�ϸ,ͨ��ʹ�õ�ֵ��normal��bold����ֵ�����Ӧ����400��700����ʾnormal��ʾ������
bold��ʾ�Ӵ�;bloder��ʾ���ֵ��ַ�;lighter��ʾ��ϸ���ַ�
number:100,200

font-family:����������������;
�������Ʋο�:https://www.w3school.com.cn/css/css_font.asp
���� SimSun
���� SimHei
΢���ź� Microsoft YaHei
΢�������� Microsoft JhengHei
������ NSimSun
��ϸ���� PMingLiU
ϸ���� MingLiU
�꿬�� DFKai-SB
���� FangSong
���� KaiTi
����_GB2312 FangSong_GB2312
����_GB2312 KaiTi_GB2312
���壺SimSuncss���������壨font-family����Ӣ������

Mac OS��һЩ��
����ϸ�ڣ�STHeiti Light [STXihei]
���ĺ��壺STHeiti
���Ŀ��壺STKaiti
�������壺STSong
���ķ��Σ�STFangsong
���� Pro��LiHei Pro Medium
���� Pro��LiSong Pro Light
�˿��w��BiauKai
�O�����кڣ�Apple LiGothic Medium
�O�������Σ�Apple LiSung Light

Windows��һЩ��
�¼����w��PMingLiU
�����w��MingLiU
�˿��w��DFKai-SB
���壺SimHei
�����壺NSimSun
���Σ�FangSong
���壺KaiTi
����_GB2312��FangSong_GB2312
����_GB2312��KaiTi_GB2312
΢ܛ�����w��Microsoft JhengHei
΢���ź��壺Microsoft YaHei

װOffice����������һЩ��
���飺LiSu
��Բ��YouYuan
����ϸ�ڣ�STXihei
���Ŀ��壺STKaiti
�������壺STSong
�������Σ�STZhongsong
���ķ��Σ�STFangsong
�������壺FZShuTi
����Ҧ�壺FZYaoti
���Ĳ��ƣ�STCaiyun
�������꣺STHupo
�������飺STLiti
�����п���STXingkai
������κ��STXinwei

Windowsƽ̨��Ĭ�������,�����������������;
�������峣�õ������塢΢���ź�;
Ӣ������Ƚϳ��õ���Times New Roman��Arial;
Arial��Win��Mac���е�����;
*/
/*�ʼ�����������Ϣ*/
typedef struct _TEXT_ATTR_PRM{
	//line-height:1.7;color:#538bd7;font-size:20px;font-family:Arial
	unsigned char aucLineHeight[EMAILAPP_TEXT_LINEHEIGHT_MAXLEN+1];	/*�и߶�*/
	unsigned char aucColor[EMAILAPP_TEXT_COLOR_MAXLEN+1];			/*������ɫ:https://blog.csdn.net/IT1039871366/article/details/46726979*/
	unsigned char aucFontSize[EMAILAPP_TEXT_FONTSIZE_MAXLEN+1];		/*�����С*/
	unsigned char aucFontFamily[EMAILAPP_TEXT_FONTFAMILY_MAXLEN+1];	/*��������*/
}TEXT_ATTR_PRM;

/*�ʼ�������Ϣ*/
typedef struct _EMAIL_BODY_PRM{
	unsigned char ucTextDecorationFlag;						/*�ʼ������Ƿ�����:0-������ ��0-����*/
	unsigned char ucTextBase64Flag;							/*�ʼ������Ƿ�Base64����:0-������ 1-���� ����-����*/
	unsigned char aucText[EMAILAPP_TEXT_MAXLEN+1];			/*�ʼ�����*/
	TEXT_ATTR_PRM mTextAttr;								/*�ʼ���������������Ϣ(�ʼ��������β���Ч)*/
}EMAIL_BODY_PRM;

/*���͵ĸ�����Ϣ*/
typedef struct _ATTACHMENT_PRM{
	unsigned char ucContentType;												/*��������:�ο�ö������EMAIL_CONTENTTYPE*/
	unsigned char aucContentType[EMAILAPP_CONTENTTYPE_MAXLEN+1];				/*���������ַ���:����Ч��*/
	unsigned char aucAttachmentFileName[EMAILAPP_ATTACHMENTFILENAME_MAXLEN+1];	/*ȫ·��:���͵ĸ����ļ���*/
}ATTACHMENT_PRM;

/*���͵ĸ�����*/
typedef struct _ATTACHMENTGROUP_PRM{
	unsigned char ucAttachmentFlag;							/*���͵��ʼ��Ƿ���ڸ���:0-������ ��0-����*/
	unsigned char ucAttachmentEncodeFlag;					/*���͵ĸ�����Ϣ(�總���ļ���)�Ƿ����:0-������ 1-GB2312���� 2-UTF8���� ����-GB2312����*/
	int iAttachmentNum;										/*���͵ĸ�����Ϣ����*/
	unsigned char aucBoundary[EMAILAPP_BOUNDARY_MAXLEN+1];	/*���͵ĸ���boundary��ǩ*/
	ATTACHMENT_PRM mAttachment[EMAILAPP_ATTACHMENT_MAXNUM];	/*���͵ĸ�����Ϣ*/
}ATTACHMENTGROUP_PRM;

/*�ʼ���Ϣ����*/
typedef struct _EMAIL_PRM{

	unsigned char aucMIMEVer[EMAILAPP_MIMEVER_MAXLEN+1];	/*MIME�汾:Ĭ��1.0*/
	unsigned char aucCharset[EMAILAPP_CHARSET_MAXLEN+1];	/*Ĭ�ϱ��뼯:GBK(163)/gb18030(qq)/GB2312*/
	unsigned char ucHeadEncodeFlag;							/*�ʼ�ͷ��Ϣ(���ʼ���ַ)�Ƿ����:0-������ 1-GB2312���� 2-UTF8���� ����-GB2312����*/
	FROMEMAIL_PRM mFromEmail;								/*���͵��ʼ���Ϣ*/
	TOEMAILGROUP_PRM mToEmailGroup;							/*���յ��ռ��ʼ�����Ϣ*/
	CCEMAILGROUP_PRM mCcEmailGroup;							/*���յĳ����ʼ�����Ϣ*/
	BCCEMAILGROUP_PRM mBccEmailGroup;						/*���յ������ʼ�����Ϣ*/
	unsigned char ucSubjectEncodeFlag;						/*�ʼ������Ƿ����:0-������ 1-GB2312���� 2-UTF8���� ����-GB2312����*/
	unsigned char aucSubject[EMAILAPP_SUBJECT_MAXLEN+1];	/*�ʼ�����*/
	EMAIL_BODY_PRM mBody;									/*���͵��ʼ�������Ϣ*/
	ATTACHMENTGROUP_PRM mAttachmentGroup;					/*���͵ĸ�����Ϣ*/
}EMAIL_PRM;

/***********************************************************************************************
	FuncName : EmailApp_Menu
    FuncFunc : Email��ĿӦ�ò˵�
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,���ذ���ֵ
								�� ʧ��,���س�ʱ��ȡ��
										APP_ABORT
										APP_TIMEOUT
    Author	 : Sunrier
    Date     : 2015-08-05 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif












