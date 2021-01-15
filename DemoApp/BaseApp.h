/*************************************************************************************************
	FileName : BaseApp.h
    FileFunc : ʵ�ֻ�����ĿӦ�ýӿ�ͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2013-06-28 18:26:10
    Descp    : ʵ�ֻ�����ĿӦ����ں���ͷ�ļ�
    History  : None
*************************************************************************************************/

#ifndef __BASEAPP_H__
#define __BASEAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


#define 	BASEAPP_NAME				"��������"
#define 	BASEAPP_FUNCTION			BASEAPP_NAME "ģ��Ӧ�����"
#define 	BASEAPP_VERSION				"00.00.01"
#define 	BASEAPP_AUTHOR				APP_AUTHOR
#define 	BASEAPP_CONTACT				APP_CONTACT
#define 	BASEAPP_DATE				"2013-06-28 18:26:10"
#define 	BASEAPP_DESCPTION			"������ĿӦ�����"


/***********************************************************************************************
	FuncName : BaseApp_Menu
    FuncFunc : ������ĿӦ�ò˵�
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,���ذ���ֵ
								�� ʧ��,���س�ʱ��ȡ��
										APP_ABORT
										APP_TIMEOUT
    Author	 : Sunrier
    Date     : 2013-06-28 18:26:10
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char BaseApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif












