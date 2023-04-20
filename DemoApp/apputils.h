/*************************************************************************************************
	FileName : apputils.h
	FileFunc : ʵ��Ӧ��ʵ�ú����ӿ�ͷ�ļ�
    Version  : V0.0.1
	Author   : Sunrier
	Date     : 2015-12-25 19:13:15
	Descp    : ʵ��Ӧ��ʵ�ú����ӿ�
    History  : None
	Other    : None
*************************************************************************************************/

#ifndef __APPUTILS_H__
#define __APPUTILS_H__

#ifdef __cplusplus
extern "C" {  
#endif


/*�豸�¼�*/
typedef enum
{
	DEV_CARD = 1,
	
}enumDeviceEvent;


typedef enum
{
	MENUOPT_1LINE2MENU    		= 0x0001,   /*һ�������˵�,����һ��һ���˵�*/
	MENUOPT_NOI_NVERT_TITLE  	= 0x0002,   /*���ⲻ����*/
	MENUOPT_AUTOCHECKLEN  		= 0x0004,   /*���˵�����,���ڶ��еĳ�������,����һ����ʾ,����һ��һ���˵�*/
	MENUOPT_INORDER       		= 0x0008,   /*������˵�˳������,�����1��ʼ*/
	MENUOPT_UP_DOWN_ARROW 		= 0x0010,   /*�Ƿ���ʾ��ҳ��ͷ*/
	MENUOPT_EXEC_FUNC     		= 0x0020,   /*�Ƿ�ִ�����̺���*/
	MENUOPT_RETURN        		= 0x0040,   /*ѡ�в˵�ִ���꺯���Ժ�ֱ���˳��˵�,�����˻ص���ǰ�˵�����*/
	MENUOPT_ENTER_RETURN  		= 0x0080,   /*��ȷ�����˳��˵�*/
}AppUtils_MenuOption;



typedef struct
{
	//unsigned char ( *EnableFunc )( void );	/* =1:��ʾ, =0:����ʾ*/
	unsigned char ucReturnIndex;            	/*ѡ�����Ժ󷵻�ֵ*/
	unsigned char *pucMenuTitle;          		/*�˵�����*/
	unsigned char (*Func)(void *Parameter); 	/*ѡ�к�ִ�к���*/
	void *Parameter;                			/*�������*/
}AppUtils_MenuItem;

/***********************************************************************************************
	FuncName : AppUtils_Restart
	FuncFunc : ����Ӧ��
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Restart( void );

/***********************************************************************************************
	FuncName : AppUtils_Cls
	FuncFunc : ����
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Cls( void );

/***********************************************************************************************
	FuncName : AppUtils_ClearLine
	FuncFunc : �����ǰ��Ļ��Ϣ
	Input	 : unsigned char �� ucLineNo	�ӵڼ��п�ʼ����
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ClearLine(unsigned char ucLineNo);

/***********************************************************************************************
	FuncName : AppUtils_ClearLines
	FuncFunc : �����ǰ��Ļ��Ϣ
	Input	 : unsigned char	�� ucLineNo		�ӵڼ��п�ʼ����
			   unsigned char	�� ucEndLineNo	�ӵڼ��н�������
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ClearLines(unsigned char ucLineNo,unsigned char ucEndLineNo);

/***********************************************************************************************
	FuncName : AppUtils_UserClear
	FuncFunc : ����
	Input	 : unsigned char	�� ucLineNo	�ӵڼ��п�ʼ����
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_UserClear(unsigned char ucLineNo);

/***********************************************************************************************
	FuncName : AppUtils_CStrlcpy
	FuncFunc : �������ܽضϺ���
	Input	 : const unsigned char *	�� pucSrc	Դ��
               int 						�� iLen		��ȡ�ĳ���,ֻ�������iLen-1���ֽڲ���󸽼�0x00
	Output	 : unsigned char *			�� pucDest  Ŀ�괮,�����ѿ������ַ���, ������NULL 
	Return	 : int						�� �����ѿ������ַ���
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : pucDest �� pucSrcָ�벻���ص�
	History  : None
	Other    : None
*************************************************************************************************/
int AppUtils_CStrlcpy(unsigned char *pucDest,const unsigned char *pucSrc,int iLen);

/***********************************************************************************************
	FuncName : AppUtils_DisplayChar
	FuncFunc : ��ʾһ���ַ���ʾ��Ϣ
	Input	 : unsigned char 	�� ucChar	�����һ���ַ���ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayChar(unsigned char ucChar,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DisplayInfo
	FuncFunc : ��ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayInfo(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DisplayCenter
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
               BOOL			 	�� bInvertFlag	�Ƿ��� TRUE-�� FALSE-��
	Output	 : None
	Return	 : unsigned char	�� ������һ����ʾ����
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayCenter(unsigned char *pucInputData,unsigned char ucStartLine,BOOL bInvertFlag);

/***********************************************************************************************
	FuncName : AppUtils_DisplayTitle
	FuncFunc : ������ʾ����
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayTitle(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_DisplayLeft
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
	Output	 : None
	Return	 : unsigned char	�� unsigned char	�� ������һ����ʾ����
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayLeft(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DisplayRight
	FuncFunc : ������ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
               unsigned char 	�� ucStartLine	��ʼ��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayRight(unsigned char *pucInputData,unsigned char ucStartLine);

/***********************************************************************************************
	FuncName : AppUtils_DispEnglish
	FuncFunc : ��ʾӢ����Ϣ��Ŀ��λ��
	Input	 : unsigned char *	�� pucInputData		�������ʾ��Ӣ����Ϣ
               unsigned int 	�� uiStartX			��ʼ����X-������
               unsigned int 	�� uiStartY			��ʼ����Y-������
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_DispEnglish(unsigned char *pucInputData,unsigned int uiStartX,unsigned int uiStartY);

/***********************************************************************************************
	FuncName : AppUtils_DispChinese
	FuncFunc : ��ʾ������Ϣ��Ŀ��λ��
	Input	 : unsigned char *	�� pucInputData		�������ʾ��������Ϣ
               unsigned int 	�� uiStartX			��ʼ����X-������
               unsigned int 	�� uiStartY			��ʼ����Y-������
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_DispChinese(unsigned char *pucInputData,unsigned int uiStartX,unsigned int uiStartY);

/***********************************************************************************************
	FuncName : AppUtils_DispStrByColor
	FuncFunc : ��ʾ��Ϣ��Ŀ��λ��
	Input	 : unsigned char *	�� pucInputData		�������ʾ��Ϣ
               unsigned int 	�� uiStartX			��ʼ����X-������
               unsigned int 	�� uiStartY			��ʼ����Y-������
               unsigned int 	�� uiFontSize		�����С
               unsigned long 	�� ulRGBFontColor	������ɫ
               unsigned long 	�� ulRGBBGColor		����ɫ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DispStrByColor(unsigned char *pucInputData,unsigned int uiStartX,unsigned int uiStartY,unsigned int uiFontSize,unsigned long ulRGBFontColor,unsigned long ulRGBBGColor);

/***********************************************************************************************
	FuncName : AppUtils_DisplayText
	FuncFunc : ��ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
			   unsigned char 	�� ucStartLine	��ʼ��
			   unsigned	char	�� ucDispMode	��ʾ��ʽ:0-����� 1-�Ҷ��� 2-����
               unsigned	char	�� ucInvertFlag	�Ƿ��� TRUE-�� FALSE-��
               unsigned	char	�� ucInvertColor������ɫ:����λ����ǰ��ɫ:����|��|��|��,����λ�����Ʊ���ɫ:����|��|��|��
               unsigned char 	�� ucCRFlag		�Ƿ��Զ����� 0-�� 1-��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayText(unsigned char *pucInputData,unsigned char ucStartLine,unsigned char ucDispMode,unsigned char ucInvertFlag,unsigned char ucInvertColor,unsigned char ucCRFlag);

/***********************************************************************************************
	FuncName : AppUtils_FlushKbd
	FuncFunc : ���������������Ϣ
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_FlushKbd( void );

/***********************************************************************************************
	FuncName : AppUtils_FlushCard
	FuncFunc : ������ۻ�������Ϣ
	Input	 : None
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_FlushCard( void );

/***********************************************************************************************
	FuncName : AppUtils_SetTimeOut
	FuncFunc : ���ó�ʱʱ��
	Input	 : unsigned long	�� uiTimeout	�������õĳ�ʱʱ��(S)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-12-23 10:01:12
	Descp    : ��
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_SetTimeOut(unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetTimeOut
	FuncFunc : ��ȡ��ʱʱ��
	Input	 : None
	Output	 : unsigned int	*	�� puiTimeout	������õĳ�ʱʱ��(S)
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-12-23 10:01:12
	Descp    : ��
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTimeOut(unsigned int *puiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_WaitKey
	FuncFunc : �ȴ�����
	Input	 : unsigned long	�� ulTimeout		���볬ʱʱ��(��)
	Output	 : None
	Return	 : unsigned char *	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_WaitKey(unsigned long ulTimeout);

/***********************************************************************************************
	FuncName : AppUtils_WaitKeyMill
	FuncFunc : �ȴ�����
	Input	 : unsigned long	�� ulTimeout	���볬ʱʱ��(����)
	Output	 : None
	Return	 : unsigned char *	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_WaitKeyMill(unsigned long ulTimeout);

/***********************************************************************************************
	FuncName : AppUtils_Delay
	FuncFunc : �ȴ���ʱ
	Input	 : unsigned long	�� ulMSec	���볬ʱʱ��(����)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Delay(unsigned long ulMSec);

/***********************************************************************************************
	FuncName : AppUtils_MillSec
	FuncFunc : ��ȡ��ǰ�ĺ�����
	Input	 : None
	Output	 : None
	Return	 : unsigned long	�� ulMillSec	��������ĺ�����
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned long AppUtils_MillSec( void );

/***********************************************************************************************
	FuncName : AppUtils_Printf
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : char *			�� pFmt			��ʽ���ַ���
	Output	 : None
 	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Printf(char *pFmt,...);

/***********************************************************************************************
	FuncName : AppUtils_Warning
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
	Output	 : None
	Return	 : unsigned char *	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : Ĭ��5��
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Warning(unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_WarningEx
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : unsigned char *	�� pucInputData	�������ʾ��Ϣ
		       unsigned long	�� ulTimeout	���볬ʱʱ��(��)
	Output	 : None
	Return	 : unsigned char *	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_WarningEx(unsigned char *pucInputData,unsigned long ulTimeout);

/***********************************************************************************************
	FuncName : AppUtils_FormatWarning
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : char *			�� pFmt			��ʽ���ַ���
	Output	 : None
	Return	 : unsigned char 	�� ucKey		�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_FormatWarning(char *pFmt,...);

/***********************************************************************************************
	FuncName : AppUtils_FormatWarningEx
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : unsigned char    �� ucTimerFlag	    �����Ƿ�֧�ֳ�ʱ 0-��֧�� 1-֧��
			   unsigned long	�� ulInputSeconds	�������õĳ�ʱʱ��(S)
	           char *			�� pFmt				��ʽ���ַ���
	Output	 : None
	Return	 : unsigned char 	�� ucKey			�����ȡ�İ���ֵ	0x00-��ʾ��ʱ
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : ��֧�ֳ�ʱ
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_FormatWarningEx(unsigned char ucTimerFlag,unsigned long ulInputSeconds,char *pFmt,...);

/***********************************************************************************************
	FuncName : AppUtils_FormatDisp
	FuncFunc : ��ʾ��ʾ��Ϣ
	Input	 : char *			�� pFmt			��ʽ���ַ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : �Զ�����
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_FormatDisp(char *pFmt,...);

/***********************************************************************************************
	FuncName 	: AppUtils_DisplayAscData
	FuncFunc 	: ��ʾ������־����Ļ
    Input	 	: unsigned char *	��	pucInputTitle 	��ʾ��־����
    			  unsigned char *	��	pucInputData	��ʾ��������
	Output	 	: None
	Return	 	: unsigned char		�� �ɹ�,����APPUTILS_SUCCESS
									�� ʧ��,����APPUTILS_FAILURE
	Author		: Sunrier
	Date     	: 2013-12-24 19:13:21
	Descp    	: None
	History  	: None
	Other    	: None
*************************************************************************************************/
unsigned char AppUtils_DisplayAscData(unsigned char *pucInputTitle,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_DisplayHexData
	FuncFunc : 16���Ʒ�ʽ��ʾ���ݵ�����
	Input	 : unsigned char *	�� pucInputTitle	����ı���
			   unsigned char *	�� pucInputData		���������
			   unsigned int		�� uiInputDataLen	��������ݳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayHexData(unsigned char *pucInputTitle,unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_SetStatus
	FuncFunc : ����ĳ��״̬λ
	Input	 : unsigned char *	�� pucStatusSetted 	��������
		       unsigned char 	�� ucStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : unsigned char *	�� pucStatusSetted 	�������
	Return	 : unsigned char	�� �ɹ�����TOOL_OK(0x00)
								�� ʧ�ܷ���TOOL_FAIL(0x01)
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : ��2012
	History  : �ֽ�
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_SetStatus(unsigned char *pucStatusSetted,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_ResetStatus
	FuncFunc : ��λĳ��״̬λ
	Input	 : unsigned char *	�� pucStatusSetted 	��������
		       unsigned char 	�� ucStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : unsigned char *	�� pucStatusSetted 	�������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : ��2012
	History  : �ֽ�
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ResetStatus(unsigned char *pucStatusSetted,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_ResetUsStatus
	FuncFunc : ��λĳ��״̬λ
	Input	 : unsigned short *	�� pusStatusSetted 	��������
		       unsigned short 	�� usStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : unsigned short *	�� pusStatusSetted 	�������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : ��2012
	History  : ����������
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ResetUsStatus(unsigned short *pusStatusSetted,unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_CheckStatus
	FuncFunc : ���ĳ��״̬λ��ֵ�Ƿ���ͬ
	Input	 : unsigned char	�� ucStatusChecked 		��������
		       unsigned char 	�� ucStatusFlag 		����ĳ��λ��״ֵ̬
	Output	 : None
	Return	 : unsigned char	�� ��ͬ����APPUTILS_SUCCESS(0x00)
								�� ����ͬ����APPUTILS_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : ��2012
	History  : �ֽ�
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckStatus(unsigned char ucStatusChecked,unsigned char ucStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_CheckUshortStatus
	FuncFunc : ���ĳ��״̬λ��ֵ�Ƿ���ͬ
	Input	 : unsigned short	�� usStatusChecked 	��������
		       unsigned short 	�� usStatusFlag 	����ĳ��λ��״ֵ̬
	Output	 : None
	Return	 : unsigned char	�� ��ͬ����APPUTILS_SUCCESS(0x00)
								�� ����ͬ����APPUTILS_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2013-04-21 19:00:55
	Descp    : ��2012
	History  : ������
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckUshortStatus(unsigned short usStatusChecked,unsigned short usStatusFlag);

/***********************************************************************************************
	FuncName : AppUtils_IsNullData
	FuncFunc : �ж����������Ƿ�Ϊ��
	Input	 : unsigned char *	�� pucInputData		��������
			   unsigned int *	�� uiInputDataLen	�������ݵĳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS 	��ʾΪ��
								�� ʧ��,����APPUTILS_FAILURE	��ʾ��Ϊ��
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsNullData(unsigned char *pucInputData,unsigned int uiInputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_GetSysDateTime
	FuncFunc : ��ȡϵͳ��ǰ����ʱ��
	Input	 : None
	Output	 : unsigned int *	�� pucOutputData	�����ϵͳ����
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetSysDateTime(unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetTerminalType
	FuncFunc : ��ȡ�ն�����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,���ض�Ӧ����,��ϸ��enumTerminalType����
								�� ʧ��,����0x00
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTerminalType( void );

/***********************************************************************************************
	FuncName : AppUtils_GetTermModuleName
	FuncFunc : ��ȡ�ն�ģ������
	Input	 : None
	Output	 : unsigned char *	�� pucOutputData	�ն�ģ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTermModuleName(unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetTermLicense
	FuncFunc : ��ȡ�ն�������֤���
	Input	 : None
	Output	 : unsigned char *	�� pucOutputData	�ն�������֤���
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTermLicense(unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetSerialNo
	FuncFunc : ��ȡ�ն����к�
	Input	 : None
	Output	 : unsigned char *	�� pucOutputSerialNo	�ն����к�
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetSerialNo(unsigned char *pucOutputSerialNo);

/***********************************************************************************************
	FuncName : AppUtils_GetTusn
	FuncFunc : ��ȡ�ն˳������к�
	Input	 : None
	Output	 : unsigned char *	�� pucOutputTusn		�ն˳������к�
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : ����Ψһ��ʶ
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTusn(unsigned char *pucOutputTusn);

/***********************************************************************************************
	FuncName : AppUtils_GetRows
	FuncFunc : ��ȡ�û����������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	����������
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRows( void );

/***********************************************************************************************
	FuncName : AppUtils_GetColumns
	FuncFunc : ��ȡ�û����������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	����������
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetColumns( void );

/***********************************************************************************************
	FuncName : AppUtils_IsBigScreen
	FuncFunc : �Ƿ��Ǵ���Ļ����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsBigScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsTouchScreen
	FuncFunc : �Ƿ��Ǵ�����Ļ����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsTouchScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsRotatedScreen
	FuncFunc : �Ƿ��ǿ�������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsRotatedScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsColorScreen
	FuncFunc : �Ƿ��ǲ�������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsColorScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsAlphaScreen
	FuncFunc : �Ƿ���֧��ALPHA���Ļ���
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsAlphaScreen( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInPinpad
	FuncFunc : �Ƿ�ֻ֧�������������
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInPinpad( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInCtls
	FuncFunc : �Ƿ�ֻ֧������CTLS
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInCtls( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInSignature
	FuncFunc : �Ƿ�ֻ֧������ǩ����
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInSignature( void );

/***********************************************************************************************
	FuncName : AppUtils_IsOnlyBuiltInBarCode
	FuncFunc : �Ƿ�ֻ֧������ɨ��ǹ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsOnlyBuiltInBarCode( void );

/***********************************************************************************************
	FuncName : AppUtils_IsMobileDevice
	FuncFunc : �Ƿ����ƶ��豸
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsMobileDevice( void );

/***********************************************************************************************
	FuncName : AppUtils_IsBatteryTerminal
	FuncFunc : �Ƿ��ǽ����ն�
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� ��,����APPUTILS_SUCCESS
								�� ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsBatteryTerminal( void );

/***********************************************************************************************
	FuncName : AppUtils_YesOrNo
	FuncFunc : ��ʾ�Ƿ��޸������Ϣ
	Input	 : unsigned char  * �� pucMsg1,������ʾ����Ϣ1
	           unsigned char  * �� pucMsg2,������ʾ����Ϣ2
	           unsigned char   ��  ucInputDispFlag,������Ϣ�Ƿ���ʾ��־:0-����ʾ 1-��ʾ
	           unsigned char  *	�� puiOutputData,�����ԭ���ݵ�ֵ
	Output	 : unsigned char  *	�� puiOutputData,����޸ĺ������ֵ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_YesOrNo(unsigned char *pucMsg1,unsigned char *pucMsg2,unsigned char ucInputDispFlag,unsigned int *puiOutputData);

/***********************************************************************************************
	FuncName : AppUtils_YesNoConfirm
	FuncFunc : ��ʾ�Ƿ�ȷ�������Ϣ
	Input	 : unsigned char  * �� pucTitle,�������ʾ����
			   unsigned char  * �� pucMsg1,������ʾ����Ϣ1
	           unsigned char  * �� pucMsg2,������ʾ����Ϣ2
	           unsigned char  *	�� pucPromptMsg,�������ʾ��Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_YesNoConfirm(unsigned char *pucTitle,unsigned char *pucMsg1,unsigned char *pucMsg2,unsigned char *pucPromptMsg);

/***********************************************************************************************
	FuncName : AppUtils_GetText
	FuncFunc : ����һ����Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
	           unsigned char *	�� pucMsgPrompt		������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned char	�� ucMaskChr		�������Ϣ�Ƿ����� 0-������ ��0-����
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
								�� ��ʱ,����APPUTILS_TIMEOUT
								�� �û�ȡ��,����APPUTILS_ESC(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : ����һ��������Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetText(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucMaskChr,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetTextEx
	FuncFunc : ����һ����Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
	           unsigned char *	�� pucMsgPrompt		������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned char	�� ucMaskChr		�������Ϣ�Ƿ����� 0-������ ��0-����
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��(S)
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	Return	 : int				�� �ɹ�,�������ݵĳ���
					 			�� ʧ��,-1��ʱ
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : ����һ��������Ϣ,���������ֺ���ĸ�Լ�����ʾ�ַ����
	History  : None
	Other    : None
*************************************************************************************************/
int AppUtils_GetTextEx(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucMaskChr,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetNum
	FuncFunc : ����һ����Ϣ,ֻ�������ַ����
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
	           unsigned char *	�� pucMsgPrompt		������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
								�� ��ʱ,����APPUTILS_TIMEOUT
								�� �û�ȡ��,����APPUTILS_ESC(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : ����һ��������Ϣ,ֻ�������ַ����
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetNum(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_GetPassWord
	FuncFunc : ����һ��������Ϣ,�������Ϣ����
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
	           unsigned char *	�� pucMsgPrompt		������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned char	�� ucDispMode		����Ķ��뷽ʽ:0x00-���������ʾ(Ĭ�Ϸ�ʽ) 0x01-���Ҷ�����ʾ
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,����APPUTILS_FAILURE
								�� ��ʱ,����APPUTILS_TIMEOUT
								�� �û�ȡ��,����APPUTILS_ESC(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetPassWord(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode);

/***********************************************************************************************
	FuncName : AppUtils_GetPassWordEx
	FuncFunc : ����һ��������Ϣ,�������Ϣ����
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
	           unsigned char *	�� pucMsgPrompt		������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned char	�� ucDispMode		����Ķ��뷽ʽ:0x00-���������ʾ(Ĭ�Ϸ�ʽ) 0x01-���Ҷ�����ʾ
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
					 			�� ��ʱ,����APPUTILS_TIMEOUT
								�� �û�ȡ��,����APPUTILS_ESC(ESC��)
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetPassWordEx(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned char ucDispMode);

/***********************************************************************************************
	FuncName : AppUtils_GetAmout
	FuncFunc : ��������Ϣ,ֻ�������ַ����
	Input	 : unsigned char 	�� ucStartLine			�������ʼ����
	           unsigned char *	�� pucMsgPrompt			������ʾ�ı���
	           unsigned char 	�� ucNegativeFlag		������������־
	           unsigned char *	�� pucCurrencyName		����Ļ�������
			   unsigned char	�� ucZeroAmtAllowFlag	������Ƿ���Խ��Ϊ0��־ TRUE-����Ϊȫ0 ����-������
	Output	 : unsigned char *	�� pucOutputData		�������Ľ����Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-09 19:00:55
	Descp    : ����һ�������Ϣ,ֻ�������ַ����
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetAmout(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char ucNegativeFlag,unsigned char *pucCurrencyName,unsigned char ucZeroAmtAllowFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_GetIpAddress
	FuncFunc : ����IP��ַ��Ϣ
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
	           unsigned char *	�� pucMsgPrompt		������ʾ�ı���
	           unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputIP		���IP��ַ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : ����IP��ַ�����ַ�����������#�ż���������'.',���Խ��ܵ��ַ���Ϊ16�ֽ�(��NULL),
	           �ڵڶ�����ʾMsg�е���ʾ��Ϣ����������ʾ������IP��ַ
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetIpAddress(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned int uiTimeout,unsigned char *pucOutputIP);

/***********************************************************************************************
	FuncName : AppUtils_GetBcd
	FuncFunc : ����һ��BCD���ʽ����Ϣ
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
			   unsigned char *	�� pucInputTitle	������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	           unsigned int *	�� puiOutputDataLen	���������Ϣ����
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��BCD���ʽ����Ϣ,��'0'��'9'����'A'��'F'�ַ����
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetBcd(unsigned char ucStartLine,unsigned char *pucInputTitle,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_GetCn
	FuncFunc : ����һ����Ϣ,���������ֺ���ĸ�Լ�����ʾ�����ַ����
	Input	 : unsigned char 	�� ucStartLine		�������ʼ����
			   unsigned char *	�� pucMsgPrompt		������ʾ�ı���
			   unsigned int		�� uiMinLen			�������Ϣ��С����(���Ϊ0,����Ϊ��)
			   unsigned int		�� uiMaxLen			�������Ϣ��󳤶�
			   unsigned int		�� uiTimeout		����ĳ�ʱʱ��
	Output	 : unsigned char *	�� pucOutputData	���������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-09 19:10:22
	Descp    : ����һ��������Ϣ,���������ֺ���ĸ�Լ�����ʾ�����ַ����
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetCn(unsigned char ucStartLine,unsigned char *pucMsgPrompt,unsigned char *pucOutputData,unsigned int uiMinLen,unsigned int uiMaxLen,unsigned int uiTimeout);

/***********************************************************************************************
	FuncName : AppUtils_IsExistFile
	FuncFunc : ����ļ��Ƿ����
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
			   unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned char    �� ucNullFlag  			�����ļ������Ƿ����Ϊ�� 0-������Ϊ�� 1���0-����Ϊ��  
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_IsExistFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char ucNullFlag);

/***********************************************************************************************
	FuncName : AppUtils_CreateFile
	FuncFunc : �����ļ�
	Input	 : unsigned char *	�� pucInputFilePathName	���봴�����ļ�·��
		       unsigned char *	�� pucInputFileName		���봴�����ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS(0x00)
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2013-12-24 19:00:55
	Descp    : ����ļ��Ƿ����,��������ھʹ����ļ�
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CreateFile(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName);

/***********************************************************************************************
	FuncName : AppUtils_RemoveDir
	FuncFunc : ɾ��ָ���ļ�
	Input	 : unsigned char *	�� pucInputDelFilePath	����ɾ�����ļ�Ŀ¼·��
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_RemoveDir(unsigned char *pucInputDelFilePath);

/***********************************************************************************************
	FuncName : AppUtils_RemoveFile
	FuncFunc : ɾ��ָ���ļ�
	Input	 : unsigned char *	�� pucInputDelFilePath	����ɾ�����ļ�Ŀ¼·��
			   unsigned char *	�� pucInputDelFileName	����ɾ�����ļ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_RemoveFile(unsigned char *pucInputDelFilePath,unsigned char *pucInputDelFileName);

/***********************************************************************************************
	FuncName : AppUtils_AppendInfoToFile
	FuncFunc : ����Ϣ���ַ�����ʮ�����Ƹ�ʽ���浽�ļ�
	Input	 : unsigned char	�� ucInputSystemFlag	�����ϵͳ��ʽ:0-Windows���з�(0x0D 0x0A)	����-Linux/Unix,���з�(0x0A)
	           unsigned char	�� ucInputFileModeFlag	����ı����ļ�ģʽ:0-׷��	����-����
			   unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
			   unsigned char *	�� pucInputFileName		���뱣����ļ���
			   unsigned char    �� ucFileFlag			���뱣���ļ����ӱ�־
			   											0x00-�޸�����Ϣ
			   											ucFileFlag&0x01-������ļ����������ں�׺
			   											ucFileFlag&0x02-������ļ���Ϣ��������ʱ����Ϣ
			   											ucFileFlag&0x04-������ļ���Ϣ������������ݳ���
			   unsigned char    �� ucCRFlag				�����ʽ���б�־
			                                            ucCRFlag 0x00-������ 
										    	        ucCRFlag&0x01-д�ļ���Ϣ֮ǰ�Ȼ��� 
										    	        ucCRFlag&0x02-���ڱ���ʱ���� 
										    		    ucCRFlag&0x04-д�ļ���Ϣ�껻��
										    		    ucCRFlag&0x08-�����ļ�ĩβ׷�ӷָ���
		       unsigned char *	�� pucTitle				���������Ϣ
			   unsigned char *	�� pucInputData			��������
		       unsigned int		�� uiInputDataLen		�������ݳ���
		       unsigned char	�� ucFormatFlag  		�洢���ݵĸ�ʽ 0-ASC 1-HEX 2-HEX��ASC 3-ֻ��ʾ����ʾ�ַ� ����ֵ-ASC
		       unsigned int		�� uiLineMaxNum			����ÿ����ʾ������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����TOOL_SUCCESS(0x00)
					 			�� ʧ��,������Ӧ������Ϣ(0x01��������0)
	Author	 : Sunrier
	Date     : 2013-05-03 19:00:55
	Descp    : ��:ucCRFlag=0x06-д�ļ���Ϣ֮ǰ�Ȼ��к�д�ļ���Ϣ�궼����,һ����󳤶�4096
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AppendInfoToFile(unsigned char ucInputSystemFlag,unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,
						unsigned char ucFileFlag,unsigned char ucCRFlag,unsigned char *pucTitle,
						unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucFormatFlag,unsigned int uiMaxLineNum);

/***********************************************************************************************
	FuncName : AppUtils_GetNumberOfRecords
	FuncFunc : ��ȡ�ļ���¼��
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
	           unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				�����ļ���¼�Ĵ�С
	Output	 : unsigned long *	�� pulRecordNumber		����ļ���¼��
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetNumberOfRecords(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long *pulRecordNumber);

/***********************************************************************************************
	FuncName : AppUtils_GetRecordByIndex
	FuncFunc : ������ؽ��׼�¼������ȡ��¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
	           unsigned char *	�� pucInputFileName		������ļ���
			   unsigned int		�� uiRecordLength		�����¼��С
			   unsigned int		�� uiRecordIndex		�����¼����
	Output	 : unsigned char *	�� pucRecord			������׼�¼
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucRecord,unsigned int uiRecordLength,unsigned int uiRecordIndex);

/***********************************************************************************************
	FuncName : AppUtils_GetTransRecByIdx
	FuncFunc : ����������ȡ���׼�¼
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				�����¼��С
			   unsigned int		�� uiRecordIndex		�����¼����
	Output	 : void *			�� pRecord				������׼�¼
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-09-19 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetTransRecByIdx(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,void *pRecord,unsigned int uiRecordIndex);

/***********************************************************************************************
	FuncName : AppUtils_UpdateRecordByIndex
	FuncFunc : ����ָ���������ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
	           unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned char *	�� pucInputData			������µ�ĳ��������¼��Ϣ
		       unsigned long    �� ulSize  				���뱣���������Ϣ��С
		       unsigned long   	�� ulIndex  				������µ��ļ���¼������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_UpdateRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : AppUtils_GetRecord
	FuncFunc : ����ָ�����ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
	           unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				���뱣���������Ϣ��С
		       DBInfor *    	�� pDBInfor  			�����������ļ���¼��Ϣ       
	Output	 : unsigned char *	�� pucOutputData			�����ȡ��ĳ��������¼��Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : ������ؽ��׼�¼��Ϣ��ȡ������¼��Ϣ
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_AppendFileRecord
	FuncFunc : ׷���ļ���¼
	Input	 : unsigned char	�� ucInputFileModeFlag	����ı����ļ�ģʽ			0-׷��	����-����
	           unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
		       unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned char *	�� pucInputData			���뱣���������Ϣ
		       unsigned long    �� ulSize  				���뱣���������Ϣ��С
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AppendFileRecord(unsigned char ucInputFileModeFlag,unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize);

/***********************************************************************************************
	FuncName : AppUtils_AppendRecord
	FuncFunc : ׷�Ӽ�¼
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
	           unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned char *	�� pucInputData			���뱣���������Ϣ
		       unsigned long    �� ulSize  				���뱣���������Ϣ��С
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AppendRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputData,unsigned long ulSize);

/***********************************************************************************************
	FuncName : AppUtils_UpdateRecord
	FuncFunc : ����ָ�����ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
	           unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				���뱣���������Ϣ��С
		       DBInfor *    	�� pDBInfor  			�����������ļ���¼��Ϣ
		       unsigned char *	�� pucInputData			������µ�ĳ��������¼��Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : ֻ����ָ���ļ���¼��Ϣ,������ָ���ļ���ϢҲ��׷��
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_UpdateRecord(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,DBInfor *pDBInfor,unsigned char *pucInputData);

/***********************************************************************************************
	FuncName : AppUtils_DeleteRecordByIndex
	FuncFunc : ɾ��ָ���������ļ���¼��Ϣ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
	           unsigned char *	�� pucInputFileName		���뱣����ļ���
		       unsigned long    �� ulSize  				���뱣���������Ϣ��С
		       unsigned long   	�� ulIndex  			����ɾ�����ļ���¼������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-24 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DeleteRecordByIndex(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned long ulSize,unsigned long ulIndex);

/***********************************************************************************************
	FuncName : AppUtils_GetClock
	FuncFunc : ��ȡ����ʱ��
	Input	 : None
	Output	 : unsigned char *	�� pucClockData	���������ʱ����ϢYYYYMMDDHHMMSS
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : ����ʱ����ַ��� YYYYMMDDHHMMSS
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetClock(unsigned char *pucClockData);

/***********************************************************************************************
	FuncName : AppUtils_Asc2Bcd
	FuncFunc : Asc��ת����Bcd��
	Input	 : unsigned char *	�� pucAscBuf	�����ASCII��
			   unsigned int		�� iAscLength	�����ASCII�볤��
	Output	 : unsigned char *	�� pucBcdBuf	�����BCD��
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Asc2Bcd(unsigned char *pucAscBuf,unsigned char *pucBcdBuf,unsigned int uiAscLength);

/***********************************************************************************************
	FuncName : AppUtils_Bcd2Asc
	FuncFunc : Bcd��ת����Asc��
	Input	 : unsigned char *	�� pucBcdBuf	�����BCD��
			   unsigned int		�� uiAscLength	�����ASCII�볤��
	Output	 : unsigned char *	�� pucAscBuf	�����ASCII��
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_Bcd2Asc(unsigned char *pucBcdBuf, unsigned char *pucAscBuf,unsigned int uiAscLength);

/***********************************************************************************************
	FuncName : AppUtils_DeleteTrail
	FuncFunc : ȥ��ĳ���ַ���β�������ַ�
	Input	 : unsigned char 	�� ucDeleteLetter	ȥ�����ַ�
			   unsigned char *	�� pucString		������ַ���
	Output	 : unsigned char *	�� pucString		������ַ�
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DeleteTrail(unsigned char ucDeleteLetter,unsigned char *pucString);

/***********************************************************************************************
	FuncName : AppUtils_AmountCmp
	FuncFunc : �Ƚ������ַ������
	Input	 : unsigned char *	�� pucAmount1	�����ַ������1
			   unsigned char *	�� pucAmount2	�����ַ������2
	Output	 : None
	Return	 : int				�� 0:pucAmount1==pucAmount2
								�� >0:pucAmount1>pucAmount2
								�� <0:pucAmount1<pucAmount2
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
int AppUtils_AmountCmp(unsigned char *pucAmount1,unsigned char *pucAmount2);

/***********************************************************************************************
	FuncName : AppUtils_AddAmountPoint
	FuncFunc : ���ַ������ĩβ���С����
	Input	 : unsigned char *	�� pucInputData		�����ַ������
	           unsigned char 	�� ucTrimZeroFlag	����ĩβ0�Ƿ�ȥ����־:0-��ȥ�� 1-ȥ��
	Output	 : unsigned char *	�� pucOutputData	�������С������ַ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : ��:pucInputData=2000068,ucTrimZeroFlag=0,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=0,pucOutputData=200006.80
	              pucInputData=2000068,ucTrimZeroFlag=1,pucOutputData=20000.68;pucInputData=20000680,ucTrimZeroFlag=1,pucOutputData=200006.8
*************************************************************************************************/
unsigned char AppUtils_AddAmountPoint(unsigned char *pucInputData,unsigned char ucTrimZeroFlag,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_TrimAmountPoint
	FuncFunc : ȥ���ַ������С����
	Input	 : unsigned char *	�� pucInputData		�������С������ַ������
	Output	 : unsigned char *	�� pucOutputData	������ַ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : ��:pucInputData=20000.68,pucOutputData=2000068;pucInputData=200006.8,pucOutputData=20000680
*************************************************************************************************/
unsigned char AppUtils_TrimAmountPoint(unsigned char *pucInputData,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_AmountAdd
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucAdd1		�����ַ������1
			   unsigned char *	�� pucAdd2		�����ַ������2
			   unsigned char 	�� ucMaxLen		�����ַ��������󳤶�(��ucMaxLen=0ʱ,Ĭ��ucMaxLen;����Ϊ0<ucMaxLen<=50)
	Output	 : unsigned char *	�� pucResult	�������Ӻ���ַ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 + pucSub2
	History  : None
	Other    : ��:100+203=303
*************************************************************************************************/
unsigned char AppUtils_AmountAdd(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountAddEx
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucAdd1		�����ַ������1
			   unsigned char *	�� pucAdd2		�����ַ������2
			   unsigned char 	�� ucMaxLen		�����ַ��������󳤶�(��ucMaxLen=0ʱ,Ĭ��ucMaxLen;����Ϊ0<ucMaxLen<=50)
	Output	 : unsigned char *	�� pucResult	�������Ӻ���ַ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 + pucSub2
	History  : None
	Other    : ��:1.00+2.03=3.03
*************************************************************************************************/
unsigned char AppUtils_AmountAddEx(unsigned char *pucAdd1,unsigned char *pucAdd2,unsigned char ucMaxLen,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountSub
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucSub1		�����ַ������1
			   unsigned char *	�� pucSub2		�����ַ������2
	Output	 : unsigned char *	�� pucResult	������������ַ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 - pucSub2
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AmountSub(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountSubEx
	FuncFunc : �����ַ����ַ�������
	Input	 : unsigned char *	�� pucSub1		�����ַ������1
			   unsigned char *	�� pucSub2		�����ַ������2
	Output	 : unsigned char *	�� pucResult	������������ַ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,����APPUTILS_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : pucResult = pucSub1 - pucSub2
	History  : None
	Other    : ��:3.00+2.03=0.97
*************************************************************************************************/
unsigned char AppUtils_AmountSubEx(unsigned char *pucSub1,unsigned char *pucSub2,unsigned char *pucResult);

/***********************************************************************************************
	FuncName : AppUtils_AmountAscToString
	FuncFunc : ��һ���ַ���ת��Ϊ�ַ������
	Input	 : unsigned char *	�� pucInputAmount	������ַ������(ASC��ʽ,��󳤶�12λ)
			   unsigned char *	�� pucCurrencyName	�����������
			   unsigned char 	�� ucNegativeFlag	����Ľ��������־ '-'��'D'��ʾ����;������־Ϊ����
	Output	 : unsigned char *	�� pucOutputAmount	����ַ������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : ������000000012030,Ϊ����־����120.30
    		   ������000000012030,Ϊ����־����-120.30
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AmountAscToString(unsigned char *pucInputAmount,unsigned char *pucCurrencyName,unsigned char ucNegativeFlag,unsigned char *pucOutputAmount);

/***********************************************************************************************
	FuncName : AppUtils_AmountAscToLong
	FuncFunc : ��һ���ַ������ת��Ϊ�������
	Input	 : unsigned char *	�� pucInputAmount	������ַ������(ASC��ʽ,��󳤶�12λ)
	Output	 : unsigned long *	�� pulOutputAmount	����������
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : ������000000012030,Ϊ����־����120.30
    		   ������000000012030,Ϊ����־����-120.30
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_AmountAscToLong(unsigned char *pucInputAmount,unsigned long *pulOutputAmount);

/***********************************************************************************************
	FuncName : AppUtils_Beep
	FuncFunc : ����
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Beep( void );

/***********************************************************************************************
	FuncName : AppUtils_NormalBeep
	FuncFunc : ��������
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_NormalBeep( void );

/***********************************************************************************************
	FuncName : AppUtils_ErrorBeep
	FuncFunc : ������ʾ����
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ErrorBeep( void );

/***********************************************************************************************
	FuncName : AppUtils_ErrorSound
	FuncFunc : ���󱨾�
	Input	 : None
	Output	 : None
	Return	 : void
	Author	 : Sunrier
	Date     : 2015-12-23 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_ErrorSound( void );

/***********************************************************************************************
	FuncName : AppUtils_BeepEx
	FuncFunc : ����
	Input	 : unsigned	int 	�� uiFreq,���뷢��Ƶ��
			   unsigned	long 	�� ulMillSec,���뷢��ʱ����(MS)
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-08-05 19:12:55
	Descp    : ����
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_BeepEx(unsigned int uiFreq,unsigned long ulMillSec);

/***********************************************************************************************
	FuncName : AppUtils_Window
	FuncFunc : ���»���
	Input	 : unsigned int 	�� uiStartX			��ʼ����X-������
               unsigned int 	�� uiStartY			��ʼ����Y-������
               unsigned int 	�� uiEndX			��������X-������
               unsigned int 	�� uiEndY			��������Y-������
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_Window(unsigned int uiStartX,unsigned int uiStartY,unsigned int uiEndX,unsigned int uiEndY);

/***********************************************************************************************
	FuncName : AppUtils_SetFontSize
	FuncFunc : ���������С
	Input	 : unsigned int 	�� uiFontSize	�����С
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_SetFontSize(unsigned int uiFontSize);

/***********************************************************************************************
	FuncName : AppUtils_SetFontFile
	FuncFunc : ���������ļ�
	Input	 : const unsigned char *	�� pucFontFileName	�����ļ���
	Output	 : None
	Return	 : None
	Author	 : Sunrier
	Date     : 2015-12-26 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
void AppUtils_SetFontFile(const unsigned char *pucFontFileName);

/***********************************************************************************************
	FuncName : AppUtils_GetFileString
	FuncFunc : ��ȡ�����ļ����ַ�����ֵ
	Input	 : unsigned char *	�� pucInputFilePathName	���뱣����ļ�·��
			   unsigned char *	�� pucInputFileName		�����ļ���
			   unsigned char *	�� pucInputSectionName	����Ľ���
			   unsigned char *	�� pucInputKeyName		�������
	Output	 : unsigned char *	�� pucOutputKeyValue	����ļ�ֵ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetFileString(unsigned char *pucInputFilePathName,unsigned char *pucInputFileName,unsigned char *pucInputSectionName,unsigned char *pucInputKeyName,unsigned char *pucOutputKeyValue);

/***********************************************************************************************
	FuncName : AppUtils_UpdateDateTime
	FuncFunc : ��ȡ�����ļ����ַ�����ֵ
	Input	 : unsigned char *	�� pNewDate		���������YYYYMMDD
			   unsigned char *	�� pNewTime		�����ʱ��HHMMSS
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_UpdateDateTime(char *pNewDate, char *pNewTime);

/***********************************************************************************************
	FuncName : AppUtils_CheckDateFormatValid
	FuncFunc : ������ڸ�ʽ�Ƿ�Ϸ�(�����������)
	Input	 : unsigned char *	�� pucInputDate ��������(��ʽ:MMDD)
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
								�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-04-21 19:00:55
	Descp    : MMDD��0213
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckDateFormatValid(unsigned char *pucInputDate);

/***********************************************************************************************
	FuncName : AppUtils_ConvertTransDateTime
	FuncFunc : �ѽ�������ʱ��ת��Ϊ�ַ�����ʽ(YYYYMMDD HH:MM:SS)
	Input	 : unsigned char *	�� pucInputDate		�������� YYYYMMDD(BCD)
	           unsigned char *	�� pucInputTime		����ʱ�� HHMMSS(BCD)
	Output	 : unsigned char *	�� pucOutputData	������ַ�������ʱ����Ϣ
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,������Ӧ������Ϣ
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : YYYYMMDD HH:MM:SS
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ConvertTransDateTime(unsigned char *pucInputDate,unsigned char *pucInputTime,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_ConvertPanByMask
	FuncFunc : �����������ο���
	Input	 : unsigned char *	�� pucInputPAN		���뿨��
	           unsigned char	�� ucPanLen			���뿨�ų���
	Output	 : unsigned char *	�� pucOutputData	������κ�Ŀ���
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
	Date     : 2015-07-28 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ConvertPanByMask(unsigned char *pucInputPAN,unsigned char ucPanLen,unsigned char *pucOutputData);

/***********************************************************************************************
	FuncName : AppUtils_CheckEvent
	FuncFunc : ��鵱ǰ�¼��Ƿ�֧��
	Input	 : enumDeviceEvent 	�� eEvent	������ĵ�ǰ�¼�
	Output	 : None
	Return	 : unsigned char	�� ֧��,����APPUTILS_SUCCESS
					 			�� ��֧��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
    Date     : 2015-07-28 19:00:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_CheckEvent(enumDeviceEvent eEvent);

/***********************************************************************************************
	FuncName : AppUtils_ReadTrackEvent
	FuncFunc : ��ȡ�ŵ��¼���Ϣ
	Input	 : unsigned int 	�� uiMaxLen					����ŵ���Ϣ��󳤶�
	Output	 : unsigned char *	�� pucOutputData			����ŵ���Ϣ
			   unsigned int *	�� puiOutputDataLen			����ŵ���Ϣ����
	Return	 : unsigned char	�� �ɹ�,����APPUTILS_SUCCESS
					 			�� ʧ��,���ط�APPUTILS_SUCCESS
	Author	 : Sunrier
    Date     : 2015-07-28 19:00:55
    Descp    : �ŵ���Ϣ:�ŵ�1+�ŵ�2+�ŵ�3
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_ReadTrackEvent(unsigned int uiMaxLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_DisplayMenu
	FuncFunc : ��ʾ�˵�
	Input	 : unsigned char 				�� ucStartLine			��ʾ����ʼ��
			   unsigned char *				�� pucMenuTitle			�˵�����
			   unsigned char 				�� ucMenuOption			�˵�����״̬
			   unsigned char 				�� ucMenuItemMaxCnt		�û��˵�ѡ�����
			   AppUtils_MenuItem * 			�� UserMenuItem			�û��˵�ѡ��
			   unsigned int 				�� uiMenuTimeout			��ʱʱ��
			   unsigned char (*)(void) * 	�� CallFunc				�˵�ִ�����Ļص�����
	Output	 : None
	Return	 : unsigned char				�� �ɹ�,���ذ���ֵ
											�� ʧ��,���س�ʱ(0x03)��ȡ��(0x02)
	Author	 : Sunrier
	Date     : 2013-08-05 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_DisplayMenu(unsigned char ucStartLine,unsigned char *pucMenuTitle,unsigned char ucMenuOption,unsigned char ucMenuItemMaxCnt,AppUtils_MenuItem UserMenuItem[],unsigned int uiMenuTimeout,unsigned char (*CallFunc)(void));

/***********************************************************************************************
	FuncName : AppUtils_VerifyManage
	FuncFunc : Ȩ�޹���
	Input	 : unsigned char *	�� pucInputData		��֤����
			   unsigned char *	�� uiInputDataLen	��֤���ݳ���
			   unsigned char 	�� ucVerifyLevel	��֤�ȼ�:0x00-�߼� 	 0x01-һ��   0x02-���� 
			   												 0x03-���� 	 0x04-�ļ�   0x05-�弶
			   												 0x06-��֤�� 0x07-Ȩ�޼� 0x08-����
	Output	 : None
	Return	 : unsigned	char 	�� �ɹ�,����APPUTILS_SUCCESS(0x00)
								�� ʧ��,����APPUTILS_FAILURE(0x01)
	Author	 : Sunrier
	Date     : 2011-04-21 19:10:22
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_VerifyManage(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char ucVerifyLevel);

/***********************************************************************************************
	FuncName : AppUtils_GetRevisionInfo
	FuncFunc : ��ȡ��汾�޶���Ϣ
	Input	 : unsigned int *	�� puiOutputDataLen	�����޶���Ϣ�����洢����
	Output	 : unsigned char *	�� pucOutputData	����޶���Ϣ
	           unsigned int *	�� puiOutputDataLen	����޶���Ϣ�ĳ���
	Return	 : unsigned	char 	�� �ɹ�,����APPUTILS_SUCCESS(0x00)
								�� ʧ��,����APPUTILS_FAILURE(0x01)
								�� ʧ��,����APPUTILS_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2012-06-05 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetRevisionInfo(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

/***********************************************************************************************
	FuncName : AppUtils_GetLibVersion
	FuncFunc : ��ȡ��汾
	Input	 : unsigned int *	�� puiOutputDataLen	�����汾�����洢����
	Output	 : unsigned char *	�� pucOutputData	�����ǰ��汾
	           unsigned int *	�� puiOutputDataLen	�����汾�����洢����
	Return	 : unsigned	char 	�� �ɹ�,����APPUTILS_SUCCESS(0x00)
								�� ʧ��,����APPUTILS_FAILURE(0x01)
								�� ʧ��,����APPUTILS_PARAMERROR(0x05)
	Author	 : Sunrier
	Date     : 2012-06-05 19:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char AppUtils_GetLibVersion(unsigned char *pucOutputData,unsigned int *puiOutputDataLen);

#ifdef __cplusplus   
}  

#endif

#endif





