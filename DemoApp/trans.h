/*************************************************************************************************
	FileName : trans.h
    FileFunc : ʵ����ĿӦ�ò��Խӿ�ͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2015-12-23 11:13:15
    Descp    : ʵ����ĿӦ�ò��Խӿں���
    History  : None
*************************************************************************************************/

#ifndef __TRANS_H__
#define __TRANS_H__

#ifdef __cplusplus
extern "C" {  
#endif


/***********************************************************************************************
	FuncName : Trans_InitConfig
    FuncFunc : ��ʼ�������ļ���Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2013-08-05 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_InitConfig( void );

/***********************************************************************************************
	FuncName : Trans_GetCfgInfor
    FuncFunc : ��ȡ������Ŀ������Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2015-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_GetCfgInfor( void );

/***********************************************************************************************
	FuncName : Trans_DisplayTransName
	FuncFunc : ��ʾ��������
	Input	 : unsigned char	�� ucTransType			��������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-08-05 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_DisplayTransName(unsigned char ucTransType);

/***********************************************************************************************
	FuncName : Trans_EchoTesting
	FuncFunc : ������Խ���
	Input	 : void *	�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_EchoTesting(void *pDummy);

/***********************************************************************************************
	FuncName : Trans_Help
    FuncFunc : ��������˵�
	Input	 : void *			�� pDummy	����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2015-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_Help(void *pDummy);

/***********************************************************************************************
	FuncName : Trans_Menu
    FuncFunc : ����Ӧ�ò˵�
	Input	 : void *	�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,���ذ���ֵ
								�� ʧ��,���س�ʱ��ȡ��
											BANK_ABORT
											BANK_TIMEOUT
    Author	 : Sunrier
    Date     : 2015-08-05 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_Menu(void *pDummy);


#ifdef __cplusplus   
}  

#endif

#endif








