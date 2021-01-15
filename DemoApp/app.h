/*************************************************************************************************
	FileName : app.h
    FileFunc : ʵ��Ӧ�ýӿ�ͷ�ļ�
    Version  : V0.0.1
    Author   : Sunrier
    Date     : 2016-12-23 11:13:15
    Descp    : ʵ��Ӧ����ں���ͷ�ļ�
    History  : None
*************************************************************************************************/

#ifndef __APP_H__
#define __APP_H__

#ifdef __cplusplus
extern "C" {  
#endif


/***********************************************************************************************
	FuncName : App_GetConfigPrm
    FuncFunc : ��ȡĬ�����ò���
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_GetConfigPrm( void );

/***********************************************************************************************
	FuncName : App_InitCfg
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
unsigned char App_InitCfg( void );

/***********************************************************************************************
	FuncName : App_SetCommCfg
    FuncFunc : ������ĿĬ��ͨѶ������Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_SetCommCfg( void );

/***********************************************************************************************
	FuncName : App_GetCommCfg
    FuncFunc : ��ȡ��ĿͨѶ������Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_GetCommCfg( void );

/***********************************************************************************************
	FuncName : App_Init
    FuncFunc : ��ʼ����Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_Init( void );

/***********************************************************************************************
	FuncName : App_Help
    FuncFunc : ��������˵�
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_Help( void );

/***********************************************************************************************
	FuncName : App_DrawInterface
    FuncFunc : �����Ӧ�ý���
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_DrawInterface( void );

/***********************************************************************************************
	FuncName : App_SelectOption
    FuncFunc : Ӧ�ò˵�
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_SelectOption( void );

/***********************************************************************************************
	FuncName : App_PrintWidthHexAsc
	FuncFunc : ��������Ϣ���浽LOG��־�ļ�
	Input	 : unsigned char *	�� pucInputTitle	����ı���
			   unsigned char *	�� pucInputData		���������
			   unsigned int		�� uiInputDataLen	��������ݳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2014-12-24 12:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_PrintWidthHexAsc(unsigned char *pucInputTitle,unsigned char *pucInputData,unsigned int uiInputDataLen);

#ifdef __cplusplus   
}  

#endif

#endif







