/*************************************************************************************************
	FileName : FtpApp.h
    FileFunc : ʵ��FTP��ĿӦ�ýӿ�ͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2015-12-23 11:13:15
    Descp    : ʵ��FTP��ĿӦ����ں���ͷ�ļ�
    History  : None
*************************************************************************************************/

#ifndef __FTPAPP_H__
#define __FTPAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define 	FTPAPP_NAME					"FTP����"
#define 	FTPAPP_FUNCTION				FTPAPP_NAME "ģ��Ӧ�����"
#define 	FTPAPP_VERSION				"00.00.01"
#define 	FTPAPP_AUTHOR				APP_AUTHOR
#define 	FTPAPP_CONTACT				APP_CONTACT
#define 	FTPAPP_DATE					"2015-09-28 10:26:10"
#define 	FTPAPP_DESCPTION			"FTP��ĿӦ�����"


/***********************************************************************************************
	FuncName : FtpApp_Menu
    FuncFunc : FTP��ĿӦ�ò˵�
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
unsigned char FtpApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif











