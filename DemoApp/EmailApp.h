/*************************************************************************************************
	FileName : EmailApp.h
    FileFunc : ʵ��Email��ĿӦ�ýӿ�ͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2016-12-23 11:13:15
    Descp    : ʵ��Email��ĿӦ����ں���ͷ�ļ�
    History  : None
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
#define 	EMAILAPP_DATE				"2015-09-28 10:26:10"
#define 	EMAILAPP_DESCPTION			"Email��ĿӦ�����"


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












