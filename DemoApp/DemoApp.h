/*************************************************************************************************
	FileName : demoapp.h
    FileFunc : ʵ��demoӦ�ýӿ�ͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2013-08-05 18:13:15
    Descp    : ʵ��demoӦ����ں���ͷ�ļ�
    History  : None
	Other    : None
*************************************************************************************************/

#ifndef __DEMOAPP_H__
#define __DEMOAPP_H__

#ifdef __cplusplus
extern "C" {  
#endif


/*DEMOӦ�������Ϣ*/
#define		DEMOAPP_APPNAME   			"DEMOAPP"					/*Ӧ����*/
#define		DEMOAPP_APPCOMMSECNAME		"COMM"						/*Ӧ��ͨѶ��������*/
#define 	DEMOAPP_DEFAULTCONFIGPATH	".\\CONFIG\\"				/*�����ļ�Ĭ��·��*/
#define 	DEMOAPP_CONFIGFILENAME		DEMOAPP_APPNAME ".ini"		/*Ӧ�������ļ���*/


#define 	DEMOAPP_NAME				GLOBAL_APPNAME
#define 	DEMOAPP_FUNCTION			GLOBAL_APPNAME "Ӧ�����"
#define 	DEMOAPP_VERSION				"00.00.01"
#define 	DEMOAPP_AUTHOR				"Sunrier"
#define 	DEMOAPP_CONTACT				"Sunrier@163.com"
#define 	DEMOAPP_DATE				"2013-08-15 18:26:10"
#define 	DEMOAPP_DESCPTION			"Demo��ĿӦ�����"


/***********************************************************************************************
	FuncName : DemoApp_InitTranCfg
    FuncFunc : ��ʼ�������ļ���Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2013-08-05 18:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_InitTranCfg( void );

/***********************************************************************************************
	FuncName : DemoApp_Init
    FuncFunc : DemoӦ�ó�ʼ��
	Input	 : void *			�� pDummy	����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2013-08-05 18:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_Init(void *pDummy);

/***********************************************************************************************
	FuncName : DemoApp_Menu
    FuncFunc : Demo��ĿӦ�ò˵�
	Input	 : void *	�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,���ذ���ֵ
								�� ʧ��,���س�ʱ��ȡ��
										APP_ABORT
										APP_TIMEOUT
    Author	 : Sunrier
    Date     : 2013-08-05 18:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char DemoApp_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif









