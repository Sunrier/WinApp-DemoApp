/*************************************************************************************************
	FileName : EmailApp.c
    FileFunc : ʵ���ʼ���ĿӦ�ýӿ�
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2017-06-08 11:13:15
	Descp    : ʵ���ʼ���ĿӦ�ýӿں���
    History  : None
	Other    : None
*************************************************************************************************/
#include "define.h"




/***********************************************************************************************
	FuncName : EmailApp_InitComm
    FuncFunc : ��ʼ�����������ͨѶ��Ϣ
	Input	 : void *			�� pDummy,����	
	           unsigned char *	�� pucEmailFromMail,�����ʼ��ĵ�ַ
	           unsigned short 	�� usEmailServerPort,�ʼ����ͷ����������Ķ˿�
	Output	 : unsigned char *	�� pucEmailUserName,�û���
	           unsigned char *	�� pucEmailServerHostName,�ʼ����ͷ�������������
	           unsigned char *	�� pucEmailServerIP,�ʼ����ͷ�����������IP	           
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : Ŀǰ֧��163��qq����
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_InitComm(void *pDummy,unsigned char *pucEmailFromMail,unsigned short usEmailServerPort,unsigned char *pucEmailUserName,unsigned char *pucEmailServerHostName,unsigned char *pucEmailServerIP)
{
	unsigned char ucRetCode = 0;
	int iI = 0,iJ = 0,iLen = 0;
	unsigned char aucTmpBuf[256+1];
	unsigned char aucDomainName[128];
	unsigned char aucEmailSmtp[16];
	unsigned char aucEmailServerIP[16];
	unsigned char aucEmailServerDomain[128];
	//unsigned short usEmailServerPort = 25;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_InitComm");
	
	if( (NULL==pucEmailFromMail) || (strlen(pucEmailFromMail)<9) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	if( !usEmailServerPort>0 )
	{
		usEmailServerPort = 25;
	}

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = Tool_Strrchr(pucEmailFromMail,'@',0x03,aucTmpBuf);
	if( ucRetCode || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Get Email user name fail!");
		return APP_FAILURE;
	}
	strcpy(pucEmailUserName,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = Tool_Strrchr(pucEmailFromMail,'@',0x00,aucTmpBuf);
	if( ucRetCode || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Get Email server domain name fail!");
		return APP_FAILURE;
	}

	memset(aucEmailSmtp,0,sizeof(aucEmailSmtp));
	memset(aucEmailServerDomain,0,sizeof(aucEmailServerDomain));
	iLen = strlen(aucTmpBuf);
	if( (iLen<=1) || ('@'!=aucTmpBuf[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param,pucEmailFromMail[%s]!",pucEmailFromMail);
		return APP_FAILURE;
	}

	iJ = 0;
	memset(aucDomainName,0,sizeof(aucDomainName));
	for(iI=1; iI<iLen; iI++)
	{
		if( '.'==aucTmpBuf[iI] )
		{
			break;
		}
		aucDomainName[iJ] = aucTmpBuf[iI];
		++iJ;
	}

	if( iJ<=0 )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param,pucEmailFromMail[%s]!",pucEmailFromMail);
		return APP_FAILURE;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucDomainName[%s]!",aucDomainName);

	sprintf(aucEmailSmtp,"smtp.%s.com",aucDomainName);
	sprintf(aucEmailServerDomain,"https://smtp.%s.com",aucDomainName);
	sprintf(pucEmailServerHostName,"%s.com",aucDomainName);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucEmailSmtp[%s],aucEmailServerDomain[%s],pucEmailServerHostName[%s]!",aucEmailSmtp,aucEmailServerDomain,pucEmailServerHostName);
	
	ucRetCode = Comm_GetInfoFromUrl(aucEmailServerDomain,1,aucEmailServerIP,NULL,NULL,NULL);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_GetInfoFromURL [ucRetCode=0x%02X,aucEmailServerDomain=%s]!",ucRetCode,aucEmailServerDomain);
		return ucRetCode;
	}

	if( NULL!=pucEmailServerIP )
	{
		strcpy(pucEmailServerIP,aucEmailServerIP);
	}

	if( (void*)1!=pDummy )
	{
		AppUtils_DisplayLeft("ͨѶ��ʼ��...\n",LINE2);
		AppUtils_DisplayLeft("���Ժ�...\n",LINE3);
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter Comm_InitComm!");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_InitComm [CommPort=COM%d,BaudRate=%d]!",g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate);
	
	ucRetCode = Comm_InitComm(g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate,g_mTermCfg.usRS232Timeout);	
	if( APP_SUCCESS==ucRetCode )
	{
		#if 1
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter Comm_InitSock!");
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_InitSock [BakCommFlag=%d,TCPIP1=%s,TCPHostPort1=%d,TCPIP2=%s,TCPHostPort2=%d,SelfHttpProtocolFlag=%d,HttpURL=%s,HttpRequestWayFlag=%d,TCPServerIP=%s,TCPServerPort=%d,TcpServerBlockTimeout=%d]!",
							g_mTermCfg.ucBakCommFlag,aucEmailServerIP,usEmailServerPort,
							aucEmailServerIP,usEmailServerPort,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
		//ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
		#endif
		ucRetCode = Comm_InitSock(aucEmailServerIP,usEmailServerPort,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,0,NULL,g_mTermCfg.ucRequestWayFlag,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : EmailApp_Init
    FuncFunc : �����ʼ��
	Input	 : void *			�� pDummy,����
	           unsigned char *	�� pucEmailFromMail,�����ʼ��ĵ�ַ
	           unsigned short 	�� usEmailServerPort,�ʼ����ͷ����������Ķ˿�
	Output	 : unsigned char *	�� pucEmailUserName,�û���
	           unsigned char *	�� pucEmailServerHostName,�ʼ����ͷ�������������
	           unsigned char *	�� pucEmailServerIP,�ʼ����ͷ�����������IP
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Init(void *pDummy,unsigned char *pucEmailFromMail,unsigned short usEmailServerPort,unsigned char *pucEmailUserName,unsigned char *pucEmailServerHostName,unsigned char *pucEmailServerIP)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,3,DEBUG,"Enter EmailApp_Init!");
	
	ucRetCode = EmailApp_InitComm(pDummy,pucEmailFromMail,usEmailServerPort,pucEmailUserName,pucEmailServerHostName,pucEmailServerIP);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : EmailApp_SetBodyTextAttr
    FuncFunc : �����ʼ�����������Ϣ
	Input	 : TEXT_ATTR_PRM *	�� pTextAttr,�����ʼ�����������Ϣ
	Output	 : TEXT_ATTR_PRM *	�� pTextAttr,����ʼ�����������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetBodyTextAttr(TEXT_ATTR_PRM *pTextAttr)
{
	//unsigned char ucRetCode = APP_SUCCESS;
	
	if( NULL==pTextAttr )
	{
		return APP_PARAMERROR;
	}

	/*�и߶�*/
	strcpy(pTextAttr->aucLineHeight,"1.7");

	/*������ɫ*/
	strcpy(pTextAttr->aucColor,"#538bd7");	/*������ɫ:https://blog.csdn.net/IT1039871366/article/details/46726979*/

	/*�����С*/
	strcpy(pTextAttr->aucFontSize,"20px");

	/*��������*/
	strcpy(pTextAttr->aucFontFamily,"Arial");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetQQAutoRsp
    FuncFunc : ����QQ�����յ��ʼ����Զ��ظ���Ϣ
	Input	 : unsigned char *	�� pucServerHostName,�����ʼ����ͷ�������������(��qq.com)
	Output	 : unsigned char *	�� pucText,����ʼ�������Ϣ
	           unsigned int *	�� puiTextLen,����ʼ�������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetQQAutoRsp(unsigned char *pucServerHostName,unsigned char *pucText,unsigned int *puiTextLen)
{
	//unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiDataLen = 0,uiSendLen = 0;
	unsigned char aucData[APP_MAXCOMMBUF/2+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	
	if( (NULL==pucText) || (NULL==puiTextLen) || memcmp(pucServerHostName,"qq",2) )
	{
		return APP_PARAMERROR;
	}
	
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));

	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"<div>�����ʼ��󣬻����ϻظ���лл��</div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"<div>&nbsp;</div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"<div>&nbsp;���쿪��!<img src=\"http://cache.soso.com/img/img/e113.gif\"/></div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	*puiTextLen = uiSendLen;
	memcpy(pucText,aucSendBuf,uiSendLen);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetDefAutoRsp
    FuncFunc : ���������յ��ʼ����Զ��ظ���Ϣ
	Input	 : unsigned char *	�� pucServerHostName,�����ʼ����ͷ�������������(��qq.com)
	Output	 : unsigned char *	�� pucText,����ʼ�������Ϣ
	           unsigned int *	�� puiTextLen,����ʼ�������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetDefAutoRsp(unsigned char *pucServerHostName,unsigned char *pucText,unsigned int *puiTextLen)
{
	//unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiDataLen = 0,uiSendLen = 0;
	unsigned char aucData[APP_MAXCOMMBUF/2+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	
	if( (NULL==pucText) || (NULL==puiTextLen) )
	{
		return APP_PARAMERROR;
	}
	
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));

	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"<div>�����ʼ��󣬻����ϻظ���лл��</div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;
	
	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"<div>&nbsp;</div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"<div>&nbsp;���쿪��!</div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	*puiTextLen = uiSendLen;
	memcpy(pucText,aucSendBuf,uiSendLen);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetAutoRsp
    FuncFunc : �����յ��ʼ����Զ��ظ���Ϣ
	Input	 : unsigned char *	�� pucServerHostName,�����ʼ����ͷ�������������(��qq.com)
	Output	 : unsigned char *	�� pucText,����ʼ�������Ϣ
	           unsigned int *	�� puiTextLen,����ʼ�������Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetAutoRsp(unsigned char *pucServerHostName,unsigned char *pucText,unsigned int *puiTextLen)
{
	unsigned char ucRetCode = APP_SUCCESS;

	if( (NULL==pucText) || (NULL==puiTextLen) )
	{
		return APP_PARAMERROR;
	}

	if( !memcmp(pucServerHostName,"qq",2) )
	{
		ucRetCode = EmailApp_SetQQAutoRsp(pucServerHostName,pucText,puiTextLen);
	}
	else
	{
		ucRetCode = EmailApp_SetDefAutoRsp(pucServerHostName,pucText,puiTextLen);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : EmailApp_GetBoundary
    FuncFunc : ��ȡ�ʼ����͵�boundary��ǩ
	Input	 : unsigned char *	�� pucFromEmail,���뷢���ʼ���ַ
	           unsigned int *	�� puiOutputDataLen,���뻺������󳤶�
	Output	 : unsigned char *	�� pucOutputData,���boundary��ǩ
	           unsigned int *	�� puiOutputDataLen,���boundary��ǩ����
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_GetBoundary(unsigned char *pucFromEmail,unsigned char *pucOutputData,unsigned int *puiOutputDataLen)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiBoundaryLen = 0,uiMaxBoundaryLen = 0;
	unsigned int uiResultLen = 0,uiResultHexLen = 0;
	unsigned char aucBoundary[64+1];
	unsigned char aucTmpBuf[128+1];
	unsigned char aucResult[256+1],aucRandResult[256+1],aucBeforeResult[256+1],aucResultHex[128+1];
	long lSeconds = 0;
	unsigned int uiRand = 0;
	unsigned long ulMSeconds = 0;
	UINT64 ui64Data = 0;

	if( (NULL==pucFromEmail) || (strlen(pucFromEmail)<4) )
	{
		return APP_PARAMERROR;
	}

	if( (NULL==pucOutputData) || (NULL==puiOutputDataLen) || (!*puiOutputDataLen) )
	{
		return APP_PARAMERROR;
	}
	
	uiMaxBoundaryLen = *puiOutputDataLen;

	memset(aucTmpBuf, 0, sizeof(aucTmpBuf));
	lSeconds = 0;
	Tool_GetCurrentSeconds(&lSeconds);
	ulMSeconds = 0;
	Tool_GetCurrentMillSeconds(&ulMSeconds);	
	memset(aucBoundary, 0, sizeof(aucBoundary));
	//_NextPart_642A3313_1159F340_5D43D7BD
	if( (strlen(pucFromEmail)>6) && !memcmp(pucFromEmail+strlen(pucFromEmail)-6,"qq.com",6))
	{
		ui64Data = lSeconds;
		uiResultHexLen = 0;
		memset(aucResultHex,0,sizeof(aucResultHex));
		uiResultHexLen = 8;
		Tool_Uint64ToHexEx(ui64Data,aucResultHex,&uiResultHexLen);
		uiResultLen = uiResultHexLen * 2;
		memset(aucResult,0,sizeof(aucResult));
		Tool_HexToAsc(aucResultHex, uiResultLen, aucResult);
		
		if( !g_mApp.ulSystemNo )
		{
			uiRand = 0;
			Tool_RandInt(1,10,10000,&uiRand);
			ui64Data = 259163664 - uiRand;
		}
		else
		{
			ui64Data = 259163664 + g_mApp.ulSystemNo;
		}
		uiResultHexLen = 0;
		memset(aucResultHex,0,sizeof(aucResultHex));
		uiResultHexLen = 8;
		Tool_Uint64ToHexEx(ui64Data,aucResultHex,&uiResultHexLen);
		uiResultLen = uiResultHexLen * 2;
		memset(aucRandResult,0,sizeof(aucRandResult));
		Tool_HexToAsc(aucResultHex, uiResultLen, aucRandResult);
		
		ui64Data = lSeconds - 3*365*24*60*60 + g_mApp.ulSystemNo;
		uiResultHexLen = 0;
		memset(aucResultHex, 0, sizeof(aucResultHex));
		uiResultHexLen = 8;
		Tool_Uint64ToHexEx(ui64Data,aucResultHex,&uiResultHexLen);
		uiResultLen = uiResultHexLen * 2;
		memset(aucBeforeResult,0,sizeof(aucBeforeResult));
		Tool_HexToAsc(aucResultHex, uiResultLen, aucBeforeResult);		
		sprintf(aucBoundary,"----=_NextPart_%s_%s_%s",aucResult,aucRandResult,aucBeforeResult);
	}
	else
	{
		sprintf(aucBoundary,"----=_Part_%d_%ld.%I64d",g_mApp.ulSystemNo,lSeconds,ulMSeconds);
	}
	uiBoundaryLen = strlen(aucBoundary);
	
	App_AddSystemNo();

	if( uiBoundaryLen>uiMaxBoundaryLen )
	{
		return APP_PARAMERROR;
	}

	strcpy(pucOutputData,aucBoundary);
	*puiOutputDataLen = uiBoundaryLen;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucBoundary[%s]!",aucBoundary);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_InitMail
    FuncFunc : ��ʼ���ʼ���Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_InitMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;	
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_InitMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	/*�ʼ��˿ں�Ĭ��25*/
	pEmailInfo->mFromEmail.usServerHostPort = 25;

	/*MIME�汾:Ĭ��1.0*/
	strcpy(pEmailInfo->aucMIMEVer,"1.0");

	/*Ĭ�ϱ��뼯:GBK(163)/gb18030(qq)/GB2312*/
	strcpy(pEmailInfo->aucCharset,"GBK");

	/*�ʼ�ͷ��Ϣ(���ʼ���ַ)�Ƿ����:0-������ 1-GB2312���� 2-UTF8���� ����-GB2312����*/
	pEmailInfo->ucHeadEncodeFlag = 1;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucFromEmail[%s]!",pEmailInfo->mFromEmail.aucFromEmail);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetFromMail
    FuncFunc : �����ʼ����ͷ���Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetFromMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;	
	unsigned char aucInputBuf[128+1];
	unsigned char aucDispTitle[128+1] = {0};
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetFromMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"�����뷢���ʼ���ַ:",aucInputBuf,7,32,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ���ַʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	Tool_StrTrim(aucInputBuf,4);
	Tool_StrLowerCase(aucInputBuf);
	strcpy(pEmailInfo->mFromEmail.aucFromEmail,aucInputBuf);

	memset(aucDispTitle,0,sizeof(aucDispTitle));
	if( !memcmp(aucInputBuf+strlen(aucInputBuf)-6,"qq.com",6) )
	{
		strcpy(aucDispTitle,"�����뷢���ʼ���֤��:");
	}
	else
	{
		strcpy(aucDispTitle,"�����뷢���ʼ�����:");
	}
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetPassWordEx(LINE2,aucDispTitle,aucInputBuf,4,32,0);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetPassWordEx fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ�����ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(pEmailInfo->mFromEmail.aucUserPassword,aucInputBuf);
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucFromEmail[%s]!",pEmailInfo->mFromEmail.aucFromEmail);
	
	return APP_SUCCESS;
}


/***********************************************************************************************
	FuncName : EmailApp_DispFromMail
    FuncFunc : ��ʾ���͵��ʼ���Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_DispFromMail(EMAIL_PRM *pEmailInfo)
{
	//unsigned char ucRetCode = APP_SUCCESS;
	//unsigned char aucTmpBuf[128+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_DispFromMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucFromEmail[%s]!",pEmailInfo->mFromEmail.aucFromEmail);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_DispToMail
    FuncFunc : ��ʾ�ʼ����յ��ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_DispToMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	int iI = 0,iToEmailNum = 0;
	//unsigned char aucTmpBuf[128+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_DispToMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iToEmailNum[%d]!",pEmailInfo->mToEmailGroup.iToEmailNum);

	iToEmailNum = pEmailInfo->mToEmailGroup.iToEmailNum;
	for(iI=0; iI<iToEmailNum; iI++)
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucToEmail[%s] of [%d/%d]!",pEmailInfo->mToEmailGroup.mToEmail[iI].aucToEmail,iI+1,iToEmailNum);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_DispCcMail
    FuncFunc : ��ʾ�ʼ����յĳ����ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_DispCcMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	int iI = 0,iCcEmailNum = 0;
	//unsigned char aucTmpBuf[128+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_DispCcMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iCcEmailNum[%d]!",pEmailInfo->mCcEmailGroup.iCcEmailNum);

	iCcEmailNum = pEmailInfo->mCcEmailGroup.iCcEmailNum;
	for(iI=0; iI<iCcEmailNum; iI++)
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucCcEmail[%s] of [%d/%d]!",pEmailInfo->mCcEmailGroup.mCcEmail[iI].aucToEmail,iI+1,iCcEmailNum);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_DispBccMail
    FuncFunc : ��ʾ�ʼ����յ������ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_DispBccMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	int iI = 0,iBccEmailNum = 0;
	//unsigned char aucTmpBuf[128+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_DispBccMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iBccEmailNum[%d]!",pEmailInfo->mBccEmailGroup.iBccEmailNum);

	iBccEmailNum = pEmailInfo->mBccEmailGroup.iBccEmailNum;
	for(iI=0; iI<iBccEmailNum; iI++)
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucBccEmail[%s] of [%d/%d]!",pEmailInfo->mBccEmailGroup.mBccEmail[iI].aucToEmail,iI+1,iBccEmailNum);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_DispMail
    FuncFunc : ��ʾ�ʼ����յ��ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_DispMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_DispMail!");

	ucRetCode = EmailApp_DispFromMail(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_DispFromMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_DispToMail(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_DispToMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	ucRetCode = EmailApp_DispCcMail(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_DispCcMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	ucRetCode = EmailApp_DispBccMail(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_DispBccMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetToMail
    FuncFunc : �����ʼ����յ��ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetToMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	int iI = 0,iJ = 0,iK = 0,iToEmailNum = 0;
	int iLen = 0;
	int iCurIndex = 0;
	unsigned char aucTmpBuf[128+1];
	unsigned char aucInputBuf[1024+1];
	TOEMAIL_PRM mToEmail[] = { 0 };
	

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetToMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	/*����Ĭ���ʼ����յ��ʼ�����Ϣ*/
	iToEmailNum = sizeof(mToEmail)/sizeof(TOEMAIL_PRM);
	pEmailInfo->mToEmailGroup.ucToEmailHideFlag = 1;
	for(iI=0; iI<iToEmailNum; iI++)
	{
		if( !strlen(mToEmail[iI].aucToEmail) )
		{
			break;
		}

		if( iI>=EMAILAPP_TOEMAIL_MAXNUM )
		{
			break;
		}
		
		strcat(pEmailInfo->mToEmailGroup.mToEmail[iI].aucToEmail,mToEmail[iI].aucToEmail);
	}
	pEmailInfo->mToEmailGroup.iToEmailNum = iI;

	/*����������ʼ����յ��ʼ�����Ϣ*/
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"����������ʼ���ַ(����ʼ��ֺ�����):",aucInputBuf,7,1024,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText ToEmail fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ���ַʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	iCurIndex = pEmailInfo->mToEmailGroup.iToEmailNum;
	iLen = strlen(aucInputBuf);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iLen[%d],aucInputBuf[%s]!",iLen,aucInputBuf);
	for(iI=0; iI<iLen; iI++)
	{	
		iK = 0;
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		for(iJ=iI; iJ<iLen; iJ++)
		{
			if( (';'==aucInputBuf[iJ]) || ('|'==aucInputBuf[iJ])  || (','==aucInputBuf[iJ]) )
			{
				break;
			}
			aucTmpBuf[iK] = aucInputBuf[iJ];
			++iK;
		}

		if( iK>0 )
		{
			Tool_StrTrim(aucInputBuf,4);
			if( strlen(aucInputBuf) )
			{
				Tool_StrLowerCase(aucInputBuf);
				if( iCurIndex>=EMAILAPP_TOEMAIL_MAXNUM )
				{
					Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iToEmailNum[%d] has been reached max[%d]!",iCurIndex,EMAILAPP_TOEMAIL_MAXNUM);
					return APP_FAILURE;
				}
				
				strcat(pEmailInfo->mToEmailGroup.mToEmail[iCurIndex].aucToEmail,aucTmpBuf);
				++iCurIndex;
			}
			
			iI = iJ - 1;
		}
	}
	pEmailInfo->mToEmailGroup.iToEmailNum = iCurIndex;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iToEmailNum[%d]!",pEmailInfo->mToEmailGroup.iToEmailNum);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetCcMail
    FuncFunc : �����ʼ����͵��ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetCcMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	int iI = 0,iJ = 0,iK = 0;
	int iInputFlag = 0;
	int iLen = 0;
	int iCurIndex = 0,iCcEmailNum = 0;
	unsigned char aucTmpBuf[128+1];
	unsigned char aucInputBuf[1024+1];
	TOEMAIL_PRM mCcEmail[] = {0};
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetCcMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	/*����Ĭ���ʼ����͵��ʼ�����Ϣ*/
	iCcEmailNum = sizeof(mCcEmail)/sizeof(TOEMAIL_PRM);
	pEmailInfo->mCcEmailGroup.ucCcEmailHideFlag = 1;
	for(iI=0; iI<iCcEmailNum; iI++)
	{
		if( !strlen(mCcEmail[iI].aucToEmail) )
		{
			break;
		}

		if( iI>=EMAILAPP_CCEMAIL_MAXNUM )
		{
			break;
		}
		
		strcat(pEmailInfo->mCcEmailGroup.mCcEmail[iI].aucToEmail,mCcEmail[iI].aucToEmail);
	}
	pEmailInfo->mCcEmailGroup.iCcEmailNum = iI;

	/*�Ƿ������ʼ����͵��ʼ�����Ϣ*/
	iInputFlag = 0;
	ucRetCode = AppUtils_YesOrNo("\n�������Ƿ����ʼ�:","0-������ 1-����",0,&iInputFlag);
	if( APP_SUCCESS!=ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_YesOrNo Cc fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�Ƿ����ʼ�ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	if( !iInputFlag )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iCcEmailNum[%d]!",pEmailInfo->mCcEmailGroup.iCcEmailNum);
		return APP_SUCCESS;
	}

	/*����������ʼ����͵��ʼ�����Ϣ*/
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"�����볭���ʼ���ַ(��������ʼ��ֺ�����):",aucInputBuf,7,1024,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText CcEmail fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ���ַʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	iCurIndex = pEmailInfo->mCcEmailGroup.iCcEmailNum;
	iLen = strlen(aucInputBuf);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iLen[%d],aucInputBuf[%s]!",iLen,aucInputBuf);
	for(iI=0; iI<iLen; iI++)
	{	
		iK = 0;
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		for(iJ=iI; iJ<iLen; iJ++)
		{
			if( (';'==aucInputBuf[iJ]) || ('|'==aucInputBuf[iJ])  || (','==aucInputBuf[iJ]) )
			{
				break;
			}
			aucTmpBuf[iK] = aucInputBuf[iJ];
			++iK;
		}

		if( iK>0 )
		{
			Tool_StrTrim(aucInputBuf,4);
			if( strlen(aucInputBuf) )
			{
				Tool_StrLowerCase(aucInputBuf);
				if( iCurIndex>=EMAILAPP_CCEMAIL_MAXNUM )
				{
					Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iCcEmailNum[%d] has been reached max[%d]!",iCurIndex,EMAILAPP_CCEMAIL_MAXNUM);
					return APP_FAILURE;
				}
				
				strcat(pEmailInfo->mCcEmailGroup.mCcEmail[iCurIndex].aucToEmail,aucTmpBuf);
				++iCurIndex;
			}
			
			iI = iJ - 1;
		}
	}
	pEmailInfo->mCcEmailGroup.iCcEmailNum = iCurIndex;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iCcEmailNum[%d]!",pEmailInfo->mCcEmailGroup.iCcEmailNum);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetBccMail
    FuncFunc : �����ʼ����͵��ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetBccMail(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	int iI = 0,iJ = 0,iK = 0;
	int iInputFlag = 0;
	int iLen = 0;
	int iCurIndex = 0,iBccEmailNum = 0;
	unsigned char aucTmpBuf[128+1];
	unsigned char aucInputBuf[1024+1];
	TOEMAIL_PRM mBccEmail[] = { 0 };
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetBccMail!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	/*����Ĭ���ʼ����͵��ʼ�����Ϣ*/
	iBccEmailNum = sizeof(mBccEmail)/sizeof(TOEMAIL_PRM);
	pEmailInfo->mBccEmailGroup.ucBccEmailHideFlag = 0;
	for(iI=0; iI<iBccEmailNum; iI++)
	{
		if( !strlen(mBccEmail[iI].aucToEmail) )
		{
			break;
		}

		if( iI>=EMAILAPP_BCCEMAIL_MAXNUM )
		{
			break;
		}
		
		strcat(pEmailInfo->mBccEmailGroup.mBccEmail[iI].aucToEmail,mBccEmail[iI].aucToEmail);
	}
	pEmailInfo->mBccEmailGroup.iBccEmailNum = iI;

	/*�Ƿ������ʼ����͵��ʼ�����Ϣ*/
	iInputFlag = 0;
	ucRetCode = AppUtils_YesOrNo("\n�������Ƿ������ʼ�:","0-������ 1-����",0,&iInputFlag);
	if( APP_SUCCESS!=ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_YesOrNo Bcc fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�Ƿ������ʼ�ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	if( !iInputFlag )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iBccEmailNum[%d]!",pEmailInfo->mBccEmailGroup.iBccEmailNum);
		return APP_SUCCESS;
	}
	
	/*����������ʼ����͵��ʼ�����Ϣ*/
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"�����������ʼ���ַ(��������ʼ��ֺ�����):",aucInputBuf,7,1024,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText BccEmail fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ���ַʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	
	iCurIndex = pEmailInfo->mBccEmailGroup.iBccEmailNum;
	iLen = strlen(aucInputBuf);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iLen[%d],aucInputBuf[%s]!",iLen,aucInputBuf);
	for(iI=0; iI<iLen; iI++)
	{	
		iK = 0;
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		for(iJ=iI; iJ<iLen; iJ++)
		{
			if( (';'==aucInputBuf[iJ]) || ('|'==aucInputBuf[iJ])  || (','==aucInputBuf[iJ]) )
			{
				break;
			}
			aucTmpBuf[iK] = aucInputBuf[iJ];
			++iK;
		}

		if( iK>0 )
		{
			Tool_StrTrim(aucInputBuf,4);
			if( strlen(aucInputBuf) )
			{
				Tool_StrLowerCase(aucInputBuf);
				if( iCurIndex>=EMAILAPP_BCCEMAIL_MAXNUM )
				{
					Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iBccEmailNum[%d] has been reached max[%d]!",iCurIndex,EMAILAPP_BCCEMAIL_MAXNUM);
					return APP_FAILURE;
				}
				
				strcat(pEmailInfo->mBccEmailGroup.mBccEmail[iCurIndex].aucToEmail,aucTmpBuf);
				++iCurIndex;
			}
			
			iI = iJ - 1;
		}
	}
	pEmailInfo->mBccEmailGroup.iBccEmailNum = iCurIndex;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iBccEmailNum[%d]!",pEmailInfo->mBccEmailGroup.iBccEmailNum);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetMailSubject
    FuncFunc : �����ʼ����͵��ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetMailSubject(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char aucInputBuf[1024+1];
	unsigned char aucSubject[EMAILAPP_SUBJECT_MAXLEN+1] = "Hello Mail Test";
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetMailSubject!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"�������ʼ�����:",aucInputBuf,2,EMAILAPP_SUBJECT_MAXLEN,0,60);
	//ucRetCode = AppUtils_GetCN(LINE2,"�������ʼ�����:",aucInputBuf,2,EMAILAPP_SUBJECT_MAXLEN,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�ʼ�����ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(pEmailInfo->aucSubject,aucInputBuf);

	pEmailInfo->ucSubjectEncodeFlag = 1;
	if( !strlen(pEmailInfo->aucSubject) )
	{
		strcpy(pEmailInfo->aucSubject,aucSubject);
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucSubject[%s]!",pEmailInfo->aucSubject);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetMailText
    FuncFunc : �����ʼ��ı���Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetMailText(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char aucInputBuf[1024+1];
	unsigned char aucText[256+1] = "Hello World";
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetMailText!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"�������ʼ��ı�:",aucInputBuf,2,1024,0,60);
	//ucRetCode = AppUtils_GetCN(LINE2,"�������ʼ��ı�:",aucInputBuf,2,1024,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�ʼ��ı�ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	
	if( !strlen(pEmailInfo->mBody.aucText) )
	{
		strcpy(pEmailInfo->mBody.aucText,aucText);
	}

	/*�ʼ������Ƿ�����:0-������ ��0-����*/
	pEmailInfo->mBody.ucTextDecorationFlag = 0;
	if( pEmailInfo->mBody.ucTextDecorationFlag )
	{
		EmailApp_SetBodyTextAttr(&pEmailInfo->mBody.mTextAttr);
	}
	
	/*�ʼ������Ƿ�Base64����:0-������ 1-����*/
	pEmailInfo->mBody.ucTextBase64Flag = 1;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucText[%s]!",pEmailInfo->mBody.aucText);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetMailAttachment
    FuncFunc : �����ʼ����͵��ʼ�����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetMailAttachment(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiBoundaryLen = 0;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetMailAttachment!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	pEmailInfo->mAttachmentGroup.iAttachmentNum = 0;
	#if 0
	strcpy(pEmailInfo->mAttachmentGroup.mAttachment[pEmailInfo->mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\1.txt");
	++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	strcpy(pEmailInfo->mAttachmentGroup.mAttachment[pEmailInfo->mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\����2.docx");
	++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	strcpy(pEmailInfo->mAttachmentGroup.mAttachment[pEmailInfo->mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\����3.pdf");
	++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	strcpy(pEmailInfo->mAttachmentGroup.mAttachment[pEmailInfo->mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\����2.txt");
	++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	#else
	//strcpy(pEmailInfo->mAttachmentGroup.mAttachment[mEmailInfo.mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\����2.txt");
	//++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	#endif
	
	if( pEmailInfo->mAttachmentGroup.iAttachmentNum )
	{
		pEmailInfo->mAttachmentGroup.ucAttachmentFlag = 1;
		pEmailInfo->mAttachmentGroup.ucAttachmentEncodeFlag = 1;
		uiBoundaryLen = sizeof(pEmailInfo->mAttachmentGroup.aucBoundary);
		ucRetCode = EmailApp_GetBoundary(pEmailInfo->mFromEmail.aucFromEmail,pEmailInfo->mAttachmentGroup.aucBoundary,&uiBoundaryLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBoundary Attachment fail,ucRetCode[0x%02X]!",ucRetCode);
			return APP_PARAMERROR;
		}

		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Attachment aucBoundary[%s]!",pEmailInfo->mAttachmentGroup.aucBoundary);
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iAttachmentNum[%d]!",pEmailInfo->mAttachmentGroup.iAttachmentNum);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetMailBoundary
    FuncFunc : �����ʼ���ǩ��Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetMailBoundary(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiBoundaryLen = 0;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetMailBoundary!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	uiBoundaryLen = sizeof(pEmailInfo->mFromEmail.aucBoundary);
	ucRetCode = EmailApp_GetBoundary(pEmailInfo->mFromEmail.aucFromEmail,pEmailInfo->mFromEmail.aucBoundary,&uiBoundaryLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBoundary fail,ucRetCode[0x%02X]!",ucRetCode);
		return APP_PARAMERROR;
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucBoundary[%s]!",pEmailInfo->mFromEmail.aucBoundary);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_GetBase64
    FuncFunc : ��ȡ�������Ϣ
	Input	 : unsigned char 	�� ucEncodeFlag,������Ϣ�Ƿ����:0-������ 1-GB2312���� 2-UTF8���� ����-GB2312����
	           unsigned char *	�� pucCharset,��������ַ���
			   unsigned char *	�� pucInputData,��������
			   int 				�� iInputDataLen,�������ݵĳ���
	           unsigned int *	�� puiOutputDataLen,���뻺������󳤶�
	Output	 : unsigned char *	�� pucOutputData,����������Ϣ
	           unsigned int *	�� puiOutputDataLen,����������Ϣ�ĳ���
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ��������Ϣ�����˱���˵��
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_GetBase64(unsigned char ucEncodeFlag,unsigned char *pucCharset,unsigned char *pucInputData,int iInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiDataLen = 0,uiBase64DataLen = 0,uiMaxLen = 0;
	unsigned char aucData[APP_MAXCOMMBUF+1];
	unsigned char aucBase64Data[APP_MAXCOMMBUF+1];
	//unsigned char aucTmpBuf[128+1];
	
	if( (NULL==pucCharset) ||  (NULL==pucInputData) || (!iInputDataLen) )
	{
		return APP_PARAMERROR;
	}
	
	if( (NULL==pucOutputData) || (NULL==puiOutputDataLen) || (!*puiOutputDataLen) )
	{
		return APP_PARAMERROR;
	}

	uiMaxLen = *puiOutputDataLen;
	if( (int)uiMaxLen<iInputDataLen )
	{
		return APP_PARAMERROR;
	}

	if( !ucEncodeFlag )
	{
		strcpy(pucOutputData,pucInputData);
		*puiOutputDataLen = iInputDataLen;
		return APP_SUCCESS;
	}

	if( 2==ucEncodeFlag )
	{
		uiBase64DataLen = sizeof(aucBase64Data);
		memset(aucBase64Data,0,sizeof(aucBase64Data));
		ucRetCode = Tool_Base64Encode(pucInputData,iInputDataLen,0x00,aucBase64Data,&uiBase64DataLen);
		if( ucRetCode )
		{	
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Tool_Base64Encode fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("UTF8��������ʧ��");
			return ucRetCode;
		}		
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"=?UTF-8?B?%s?=",aucBase64Data);
		uiDataLen = strlen(aucData);
	}
	else
	{
		uiBase64DataLen = 0;
		memset(aucBase64Data,0,sizeof(aucBase64Data));
		ucRetCode = Tool_Base64Encrypt(pucInputData,iInputDataLen,0x00,aucBase64Data,&uiBase64DataLen);
		if( ucRetCode )
		{	
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Tool_Base64Encrypt fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("GB2312��������ʧ��");
			return ucRetCode;
		}		
		memset(aucData,0,sizeof(aucData));
		//sprintf(aucData,"=?GBK?B?%s?=",aucBase64Data);
		sprintf(aucData,"=?%s?B?%s?=",pucCharset,aucBase64Data);
		uiDataLen = strlen(aucData);
	}
	
	if( uiDataLen>uiMaxLen )
	{
		return APP_PARAMERROR;
	}
	
	strcpy(pucOutputData,aucData);
	*puiOutputDataLen = uiDataLen;
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_GetAttachmentContentType
    FuncFunc : ��ȡ�ʼ���������������
	Input	 : unsigned char *	�� pucServerHostName,�����ʼ����ͷ�������������(��qq.com)
			   unsigned char *	�� pucFileName,���븽���ļ���
	           unsigned int		�� uiContentTypeMaxSize,�������������ַ�����󻺳����ռ�
	Output	 : unsigned char *	�� pucContentType,�����������
	           unsigned char *	�� pucContentTypeStr,������������ַ���
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_GetAttachmentContentType(unsigned char *pucServerHostName,unsigned char *pucFileName,unsigned char *pucContentType,unsigned char *pucContentTypeStr,unsigned int uiContentTypeMaxSize)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char aucFileName[256+1],aucSuffix[256+1];
	unsigned char aucTmpBuf[256+1];
	
	if( (NULL==pucServerHostName) || (NULL==pucContentType) || (NULL==pucContentType) || (!uiContentTypeMaxSize) )
	{
		return APP_PARAMERROR;
	}
	
	//Content-Type���������ĵ����ͣ�����ʵ������ͨ�������ʶ��֪����������ʲô���͵��ļ������磺
	//text/plain ��ʾ�����޸�ʽ���ı�����;
	//text/html ��ʾ�� Html �ĵ�;
	//image/gif ��ʾ���� gif ��ʽ��ͼƬ�ȵ�
	//Content-Type���ǡ�������/�����͡�����ʽ
	/*
	�ʼ����������ͷ�Ϊ���֣��ֱ���:�ı�(Text)�����ĵ�(mulipart)����Ϣ(Message)��ͼ��(Image)����Ƶ(audio)����Ƶ(Video)��Ӧ��(Application)��
	�ı�(Text)����������Ϣ��������������ʶ�ǡ�Plain������û�и�ʽ���ı���������Ҫ֧��ָ�����ַ���������ı���Ϣ����Ҫ�����������ı��������ڶ���Ϣ�ı���������Ӧ�����ִ���������������ı�����ۣ����ı������ݼ����������κ��������������Ͱ����κοɶ������ִ����ʽ
	���ĵ�(mulipart) ���������ж����������͵Ķ�����֡����ж�����4����ԭʼ�������ͣ�mixed(��������), alternative(���пɹ�ѡ��Ķ����ʽ), parallel(ͬʱ�����Ĳ���), digest(������Ϣ�͵Ķಿ����).
	��Ϣ(Message) �Cδ��װ����Ϣ�������͵���Ϣ�屾���ֻ�ȫ������RFC822��ʽ�����������ǡ� rfc822������partial����ʾ�ֲ���Ϣ�������ʼ������пɷֿ���С���External-body����ʾ��չ���ʼ���
	ͼ��(Image) �C��Ҫ����ʵ�豸��������Ҫ������Ӧ�ù㷺��ͼ�θ�ʽ��jpeg, gif��
	��Ƶ(audio) �C�������ࡱbasic��,��Ҫ��Ƶ����豸��
	��Ƶ(Video) �C�������ס�mpeg��,��Ҫ��Ƶ��ʾ�豸��
	Ӧ��(Application) �C�����������ݣ��޷������Ķ��������ݡ��������ࡱoctet-stream�������ڲ��ɽ����Ķ��������������Ϊ�û��ṩ����Ϣд���ļ��ķ�������PostScript����ʾ����ű��ĵ���
	*/
	memset(aucFileName,0,sizeof(aucFileName));
	strcpy(aucFileName,pucFileName);
	if( !strlen(aucFileName) )
	{
		return APP_PARAMERROR;
	}
	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	memset(aucSuffix,0,sizeof(aucSuffix));
	ucRetCode = Tool_GetFileNameSuffix(aucFileName,aucSuffix);
	if( ucRetCode )
	{
		*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
		strcpy(aucTmpBuf,"application/octet-stream");
		if( strlen(aucTmpBuf)>uiContentTypeMaxSize )
		{
			return APP_PARAMERROR;
		}
		strcpy(pucContentTypeStr,aucTmpBuf);
		return APP_SUCCESS;
	}

	Tool_StrLowerCase(aucSuffix);
	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	if( !memcmp(aucSuffix,".txt",4) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_TEXT_PLAIN;
			strcpy(aucTmpBuf,"text/plain");
		}
	}
	else if( !memcmp(aucSuffix,".htm",4) || !memcmp(aucSuffix,".html",5) )
	{
		*pucContentType = CONTENTTYPE_TEXT_HTML;
		strcpy(aucTmpBuf,"text/html");
	}
	#if 0
	else if( !memcmp(aucSuffix,".c",2) || !memcmp(aucSuffix,".h",2) || !memcmp(aucSuffix,".cpp",4) )
	{
		*pucContentType = CONTENTTYPE_TEXT_X_C;
		strcpy(aucTmpBuf,"text/x-c");
	}
	else if( !memcmp(aucSuffix,".java",5) || !memcmp(aucSuffix,".class",6) )
	{
		*pucContentType = CONTENTTYPE_TEXT_X_JAVA_SOURCE;
		strcpy(aucTmpBuf,"text/x-java-source");
	}
	#endif
	else if( !memcmp(aucSuffix,".gif",4) )
	{
		*pucContentType = CONTENTTYPE_IMAGE_GIF;
		strcpy(aucTmpBuf,"image/gif");
	}
	else if( !memcmp(aucSuffix,".jpeg",5) || !memcmp(aucSuffix,".jpg",4) )
	{
		*pucContentType = CONTENTTYPE_IMAGE_JPEG;
		strcpy(aucTmpBuf,"image/jpeg");
	}
	else if( !memcmp(aucSuffix,".png",4) )
	{
		*pucContentType = CONTENTTYPE_IMAGE_PNG;
		strcpy(aucTmpBuf,"image/png");
	}
	else if( !memcmp(aucSuffix,".mpeg",5) || !memcmp(aucSuffix,".mpg",4) )
	{
		*pucContentType = CONTENTTYPE_VIDEO_MPEG;
		strcpy(aucTmpBuf,"video/mpge");
	}
	else if( !memcmp(aucSuffix,".xhtml",6) || !memcmp(aucSuffix,".xml",4) )
	{
		*pucContentType = CONTENTTYPE_APPLICATION_XHTML_XML;
		strcpy(aucTmpBuf,"application/xhtml+xml");
	}
	else if( !memcmp(aucSuffix,".doc",4) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_MSWORD;
			strcpy(aucTmpBuf,"application/msword");
		}
	}
	else if( !memcmp(aucSuffix,".docx",5) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_MSWORDX;
			strcpy(aucTmpBuf,"application/vnd.openxmlformats-officedocument.wordprocessingml.document");
		}
	}
	else if( !memcmp(aucSuffix,".xls",4) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_MSXLS;
			strcpy(aucTmpBuf,"application/msxls");
		}
	}
	else if( !memcmp(aucSuffix,".xlsx",5) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_MSXLSX;
			strcpy(aucTmpBuf,"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
		}
	}
	else if( !memcmp(aucSuffix,".ppt",4) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_MSPPT;
			strcpy(aucTmpBuf,"application/msppt");
		}
	}
	else if( !memcmp(aucSuffix,".pptx",5) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_MSPPTX;
			strcpy(aucTmpBuf,"application/vnd.openxmlformats-officedocument.presentationml.presentation");
		}
	}
	else if( !memcmp(aucSuffix,".pdf",4) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_PDF;
			strcpy(aucTmpBuf,"application/pdf");
		}
	}
	else if( !memcmp(aucSuffix,".obj",4) )
	{
		if( !memcmp(pucServerHostName,"qq",2) )
		{
			*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
			strcpy(aucTmpBuf,"application/octet-stream");
		}
		else
		{
			*pucContentType = CONTENTTYPE_APPLICATION_X_TGIF;
			strcpy(aucTmpBuf,"application/x-tgif");
		}
	}
	else
	{
		*pucContentType = CONTENTTYPE_APPLICATION_OCTET_STREAM;
		strcpy(aucTmpBuf,"application/octet-stream");
	}

	if( strlen(aucTmpBuf)>uiContentTypeMaxSize )
	{
		return APP_PARAMERROR;
	}
	strcpy(pucContentTypeStr,aucTmpBuf);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_GetResponse
    FuncFunc : ��ȡ�ʼ�������������Ϣ
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
unsigned char EmailApp_GetResponse( void )
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiRecvLen = 0;
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];	
	
	/*�������ݰ�-�ȴ��ʼ�������������Ϣ*/
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf,&uiRecvLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	if( !memcmp(aucRecvBuf,"211",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"ϵͳ״̬��ϵͳ������Ӧ!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"214",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"������Ϣ!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"220",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�������!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"221",3) )
	{
		/*QUIT��������󷵻�*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"����رմ����ŵ�!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"235",3) )
	{
		/*AUTH LOGIN���������,�������û�������󷵻�*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�û���֤�ɹ�!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"250",3) )
	{
		/*EHLO/MAIL FROM/RCPT TO/\r\n.\r\n/����������󷵻�*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Ҫ����ʼ��������!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"251",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�û��Ǳ���,��ת����!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"334",3) )
	{
		/*AUTH LOGIN��������󷵻�:��ʾ�����û�������*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�ȴ��û�������֤��Ϣ!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"354",3) )
	{
		/*DATA��������󷵻�*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"��ʼ�ʼ�����,��.����!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"420",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"����δ����,�رմ����ŵ�(������ر�ʱ,��Ӧ�������Ϊ���κ��������Ӧ)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"421",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"����δ����,�رմ����ŵ�(������ر�ʱ,��Ӧ�������Ϊ���κ��������Ӧ)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"450",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Ҫ����ʼ�����δ���,���䲻����(����:����æ)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"451",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"����Ҫ��Ĳ���,��������г���!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"452",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"ϵͳ�洢����,Ҫ��Ĳ���δִ��");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"500",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"��ʽ����,�����ʶ��(�˴���Ҳ���������й���)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"501",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"������ʽ����!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"502",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�����ʵ��!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"503",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�������������!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"504",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�����������ʵ��!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"535",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�û���֤ʧ��!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"550",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Ҫ����ʼ�����δ���,���䲻����(����:����δ�ҵ��򲻿ɷ���)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"551",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�û��Ǳ���,�볢��!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"552",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"�����Ĵ洢����,Ҫ��Ĳ���δִ��!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"553",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"������������,Ҫ��Ĳ���δִ��(����:�����ʽ����)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"554",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"����ʧ��!");
		return APP_FAILURE;
	}
	else if( '5'==aucRecvBuf[0] )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"��֧��SMTPЭ��!");
		//AppUtils_Warning("��֧��SMTPЭ��");
		return APP_FAILURE;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_ConnectEmailHost
    FuncFunc : ����/����ʼ�������
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_ConnectEmailHost(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiRecvLen = 0;
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];	

	if( (void*)0==pDummy )
	{
		//memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
		g_mCurrTrans.ucTransType = TTYPE_TEST;

		AppUtils_UserClear(LINE1);
		Trans_DisplayTransName(g_mCurrTrans.ucTransType);
	}
	
	if( g_mTermCfg.ucSSLFlag )
	{
		g_mCurrTrans.ucCommFlag = COMM_TCP;
	}
	else
	{
		g_mCurrTrans.ucCommFlag = COMM_TCP;
	}
	
	g_mCurrTrans.ucDataFormat = COMM_FMT_NOFMT;
	//g_mCurrTrans.ucDataFormat = COMM_FMT_ASCLEN_DATA;
	if( COMM_RS232==g_mCurrTrans.ucCommFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usRS232Timeout;
	}
	else if( COMM_TCP==g_mCurrTrans.ucCommFlag )
	{
		//g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
		g_mCurrTrans.usTimeout = 20;
	}
	else if( COMM_SSL==g_mCurrTrans.ucCommFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usSSLTimeout;
	}
	else if( COMM_HTTP==g_mCurrTrans.ucCommFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}
	else if( COMM_HTTPS==g_mCurrTrans.ucCommFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usSSLTimeout;
	}
	else
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}

	if( (void*)0==pDummy )
	{
		AppUtils_DisplayLeft("�������...\n",LINE2);
	}
	
	//�������
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_CheckConnect [ucRetCode=0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	if( (void*)0==pDummy )
	{
		AppUtils_DisplayLeft("��������...\n",LINE2);
	}
	
	/*�������ݰ�-�ȴ�������������Ϣ*/
	uiRecvLen = 0;
	memset(aucRecvBuf,0,sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf,&uiRecvLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_Logon
    FuncFunc : ��½�ʼ�������
	Input	 : unsigned char *	�� pucSendMail,�����ʼ��ĵ�ַ
	           unsigned char *	�� pucEmailUserName,�û���
	           unsigned char *	�� pucEmailUserPassword,����
	           unsigned char *	�� pucEmailServerHostName,�ʼ����ͷ�������������
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Logon(unsigned char *pucSendMail,unsigned char *pucEmailUserName,unsigned char *pucEmailUserPassword,unsigned char *pucEmailServerHostName)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiDataLen = 0,uiSendLen = 0;
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned char aucEmailUserName[512];
	unsigned char aucEmailUserPassword[512];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_Logon!");
	
	if( (NULL==pucEmailUserName) || (strlen(pucEmailUserName)==0) || (NULL==pucEmailUserPassword) || (strlen(pucEmailUserPassword)==0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	uiDataLen = 0;
	memset(aucEmailUserName,0,sizeof(aucEmailUserName));
	
	Tool_Base64Encrypt(pucEmailUserName,strlen(pucEmailUserName),0x00,aucEmailUserName,&uiDataLen);
	//AppUtils_FormatDisp("pucEmailUserName[%s],%s\n",pucEmailUserName,aucEmailUserName);
	
	uiDataLen = 0;
	memset(aucEmailUserPassword,0,sizeof(aucEmailUserPassword));
	Tool_Base64Encrypt(pucEmailUserPassword,strlen(pucEmailUserPassword),0x00,aucEmailUserPassword,&uiDataLen);

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"HELO %s\r\n",pucEmailServerHostName);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,"AUTH LOGIN\r\n");
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucEmailUserName[%s],aucEmailUserPassword[%s]!",aucEmailUserName,aucEmailUserPassword);

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"%s\r\n",aucEmailUserName);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"%s\r\n",aucEmailUserPassword);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SendEnd
    FuncFunc : �����ʼ�������Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : �����ʼ�����\r\n.\r\n���ݽ������
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendEnd( void )
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiSendLen = 0;
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendEnd!");

	/*�����ʼ�����\r\n.\r\n���ݽ������*/
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,EMAILAPP_END);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendQuit
    FuncFunc : �����ʼ��˳���Ϣ
	Input	 : None
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : ������֪ͨ�ռ����ж�����
	History  : SMTPҪ����շ�����ش�OK,Ȼ���жϴ���;
			   ���յ��������ش�OKǰ,�ռ��������ж�����,��ʹ������ִ���;
			   �������ڷ����������յ�OK��ǰ,Ҳ�����ж�����;
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendQuit( void )
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiSendLen = 0;
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];


	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendQuit!");


	//��ֹ�������Ϳͻ��˵ĻỰ
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"QUIT%s",EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SetHead
    FuncFunc : �����ʼ�ͷ����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : unsigned char *	�� pucOutputData 	ͷ��Ϣ������
		       unsigned int	 *	�� puiOutputDataLen	ͷ��Ϣ���ݵĳ���
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SetHead(EMAIL_PRM *pEmailInfo,unsigned char *pucOutputData,unsigned int *puiOutputDataLen)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char ucDispFlag = 0;
	int iI = 0;
	unsigned int uiDataLen = 0,uiBase64DataLen = 0,uiSendLen = 0,uiRecvLen = 0;
	unsigned char aucToEmailBuf[APP_MAXCOMMBUF+1];
	unsigned char aucBase64Data[APP_MAXCOMMBUF+1];
	unsigned char aucData[APP_MAXCOMMBUF+1];
	unsigned char aucDate[256+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SetHead!");
	
	if( (NULL==pEmailInfo) 
		|| (NULL==pucOutputData)
		|| (NULL==puiOutputDataLen) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	/*
	To:���͸���Щ��Ҫ��Ӧ����
	Cc:���͸���Щ��Ҫ֪�������չ���ǲ���Ҫ�����ж�����
	Bcc:���͸���Щ����Ҫ֪�������ռ��˵��˻������ڴ������ʼ�����
	�����ڸ�����������ṩ��,�����ṩ���������ַ��ͷ�ʽ,
	To��Ӧ���ռ�������д��������ַ,
	Cc��Ӧ����ӳ��ͣ�
	Bcc��Ӧ���������,
	��Ȼ���зֱ���(QQ����)��Ⱥ������(���׺�����),
	���ַ��񽫶�����������������зֱ���,
	�ռ��˻������յ���ͬ���ʼ�;
	*/
	//����
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"From!");

	#if 0
	/*ע��:163����qq����ʱ,qq�������ʾ"�˵�ַδ��֤����ע��ʶ��",qq������ڼ��ܵķ�����û��ȫ�����ܱȽ�*/
	uiBase64DataLen = sizeof(aucBase64Data);
	memset(aucBase64Data,0,sizeof(aucBase64Data));
	ucRetCode = EmailApp_GetBase64(pEmailInfo->ucHeadEncodeFlag,pEmailInfo->aucCharset,pEmailInfo->mFromEmail.aucFromEmail,strlen(pEmailInfo->mFromEmail.aucFromEmail),aucBase64Data,&uiBase64DataLen);
	if( ucRetCode || !uiBase64DataLen )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBase64 aucFromEmail fail!");
		return APP_PARAMERROR;
	}
	
	if( pEmailInfo->ucHeadEncodeFlag )
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"From: \"%s\"%s",aucBase64Data,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
	}
	else
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"From: %s%s",aucBase64Data,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
	}
	#else
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"From: %s%s",pEmailInfo->mFromEmail.aucFromEmail,EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	#endif
	
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,aucData);
	uiSendLen = strlen(aucSendBuf);

	//To�ռ���(��ʾ�ռ��˵�ַ����Ϣ)
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"To!");
	if( (!pEmailInfo->mToEmailGroup.ucToEmailHideFlag) && (pEmailInfo->mToEmailGroup.iToEmailNum>0) )
	{
		memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
		for(iI=0; iI<pEmailInfo->mToEmailGroup.iToEmailNum; iI++)
		{
			strcat(aucToEmailBuf,pEmailInfo->mToEmailGroup.mToEmail[iI].aucToEmail);
			if( (iI+1)!=pEmailInfo->mToEmailGroup.iToEmailNum )
			{
				strcat(aucToEmailBuf,";");
			}
		}

		uiBase64DataLen = sizeof(aucBase64Data);
		memset(aucBase64Data,0,sizeof(aucBase64Data));
		ucRetCode = EmailApp_GetBase64(pEmailInfo->ucHeadEncodeFlag,pEmailInfo->aucCharset,aucToEmailBuf,strlen(aucToEmailBuf),aucBase64Data,&uiBase64DataLen);
		if( ucRetCode || !uiBase64DataLen )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBase64 aucToEmail fail!");
			return APP_PARAMERROR;
		}
		
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"To: %s%s",aucBase64Data,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}

	//Cc����(��ʾ�����˵�ַ����Ϣ)
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Cc!");
	if( (!pEmailInfo->mCcEmailGroup.ucCcEmailHideFlag) && (pEmailInfo->mCcEmailGroup.iCcEmailNum>0) )
	{
		memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
		for(iI=0; iI<pEmailInfo->mCcEmailGroup.iCcEmailNum; iI++)
		{
			strcat(aucToEmailBuf,pEmailInfo->mCcEmailGroup.mCcEmail[iI].aucToEmail);
			if( (iI+1)!=pEmailInfo->mCcEmailGroup.iCcEmailNum )
			{
				strcat(aucToEmailBuf,";");
			}
		}

		uiBase64DataLen = sizeof(aucBase64Data);
		memset(aucBase64Data,0,sizeof(aucBase64Data));
		ucRetCode = EmailApp_GetBase64(pEmailInfo->ucHeadEncodeFlag,pEmailInfo->aucCharset,aucToEmailBuf,strlen(aucToEmailBuf),aucBase64Data,&uiBase64DataLen);
		if( ucRetCode || !uiBase64DataLen )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBase64 aucToEmail fail!");
			return APP_PARAMERROR;
		}
		
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Cc: %s%s",aucBase64Data,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}

	//Bcc����(��ʾ�����˵�ַ����Ϣ)
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Bcc!");
	if( (!pEmailInfo->mBccEmailGroup.ucBccEmailHideFlag) && (pEmailInfo->mBccEmailGroup.iBccEmailNum>0) )
	{
		memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
		for(iI=0; iI<pEmailInfo->mBccEmailGroup.iBccEmailNum; iI++)
		{
			strcat(aucToEmailBuf,pEmailInfo->mBccEmailGroup.mBccEmail[iI].aucToEmail);
			if( (iI+1)!=pEmailInfo->mBccEmailGroup.iBccEmailNum )
			{
				strcat(aucToEmailBuf,";");
			}
		}

		uiBase64DataLen = sizeof(aucBase64Data);
		memset(aucBase64Data,0,sizeof(aucBase64Data));
		ucRetCode = EmailApp_GetBase64(pEmailInfo->ucHeadEncodeFlag,pEmailInfo->aucCharset,aucToEmailBuf,strlen(aucToEmailBuf),aucBase64Data,&uiBase64DataLen);
		if( ucRetCode || !uiBase64DataLen )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBase64 aucToEmail fail!");
			return APP_PARAMERROR;
		}
		
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Bcc: %s%s",aucBase64Data,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Subject!");
	
	/*�ʼ�����*/
	/*
	�ʼ�����
	���������ʣ�Subject: =?utf-8?B?6YKu5Lu25rWL6K+V?=
	Foxmail�� Subject: =?gbk?B?08q8/rLiytQ=?=
	�������ռ���һЩ�ⷽ���һЩ��Դ���������£�
	�ʼ��������3�Σ�=?��?=�ǿ�ʼ�ͽ�����ǣ��м���ʺ��Ǽ����
	��һ�Σ�utf-8����gbk����ʾԭ��ҳ��ı��뷽ʽ
	�ڶ��Σ�B�Ǳ�ʾ�ʼ��ı��뷽ʽΪbase64
	�����Σ�08q8/rLiytQ= ���� 6YKu5Lu25rWL6K+V ��ʾ��������ݣ����Ǿ���Base64������
	*/
	uiBase64DataLen = sizeof(aucBase64Data);
	memset(aucBase64Data,0,sizeof(aucBase64Data));
	ucRetCode = EmailApp_GetBase64(pEmailInfo->ucSubjectEncodeFlag,pEmailInfo->aucCharset,pEmailInfo->aucSubject,strlen(pEmailInfo->aucSubject),aucBase64Data,&uiBase64DataLen);
	if( ucRetCode || !uiBase64DataLen )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBase64 aucSubject fail!");
		return APP_PARAMERROR;
	}
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"Subject: %s%s",aucBase64Data,EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	if( !memcmp(pEmailInfo->mFromEmail.aucServerHostName,"qq",2) )
	{
		/*��ʾMIME�İ汾*/
		memset(aucData,0,sizeof(aucData));
		if( (NULL!=pEmailInfo->aucMIMEVer) && (strlen(pEmailInfo->aucMIMEVer)>0) )
		{
			sprintf(aucData,"MIME-Version: %s%s",pEmailInfo->aucMIMEVer,EMAILAPP_EOF);
		}
		else
		{
			sprintf(aucData,"MIME-Version: %s%s","1.0",EMAILAPP_EOF);
		}
		uiDataLen = strlen(aucData);
		
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		//�� X-��ͷ�����û�������ֶΣ��������� RFC 822 �����
		//���ñ߽�ֵ�������ʼ����ݵ� �����س�����BOUNDARY
		//                
		//	
		//Content-Type���������ĵ����ͣ�����ʵ������ͨ�������ʶ��֪����������ʲô���͵��ļ������磺
		//text/plain ��ʾ�����޸�ʽ���ı�����;
		//text/html ��ʾ�� Html �ĵ�;
		//image/gif ��ʾ���� gif ��ʽ��ͼƬ�ȵ�
		//Content-Type���ǡ�������/�����͡�����ʽ
		/*
		�ʼ����������ͷ�Ϊ���֣��ֱ���:�ı�(Text)�����ĵ�(mulipart)����Ϣ(Message)��ͼ��(Image)����Ƶ(audio)����Ƶ(Video)��Ӧ��(Application)��
		�ı�(Text)����������Ϣ��������������ʶ�ǡ�Plain������û�и�ʽ���ı���������Ҫ֧��ָ�����ַ���������ı���Ϣ����Ҫ�����������ı��������ڶ���Ϣ�ı���������Ӧ�����ִ���������������ı�����ۣ����ı������ݼ����������κ��������������Ͱ����κοɶ������ִ����ʽ
		���ĵ�(mulipart) ���������ж����������͵Ķ�����֡����ж�����4����ԭʼ�������ͣ�mixed(��������), alternative(���пɹ�ѡ��Ķ����ʽ), parallel(ͬʱ�����Ĳ���), digest(������Ϣ�͵Ķಿ����).
		��Ϣ(Message) �Cδ��װ����Ϣ�������͵���Ϣ�屾���ֻ�ȫ������RFC822��ʽ�����������ǡ� rfc822������partial����ʾ�ֲ���Ϣ�������ʼ������пɷֿ���С���External-body����ʾ��չ���ʼ���
		ͼ��(Image) �C��Ҫ����ʵ�豸��������Ҫ������Ӧ�ù㷺��ͼ�θ�ʽ��jpeg, gif��
		��Ƶ(audio) �C�������ࡱbasic��,��Ҫ��Ƶ����豸��
		��Ƶ(Video) �C�������ס�mpeg��,��Ҫ��Ƶ��ʾ�豸��
		Ӧ��(Application) �C�����������ݣ��޷������Ķ��������ݡ��������ࡱoctet-stream�������ڲ��ɽ����Ķ��������������Ϊ�û��ṩ����Ϣд���ļ��ķ�������PostScript����ʾ����ű��ĵ���
		*/
		/*
		���ڲ�������ʽ��RFC���кܶಹ��涨���е����������������
		��Ϊ��������:    
		������           ������           ����    
		text            charset         �ַ���    
		image           name            ����    
		application     name            ����    
		multipart       boundary        �߽�   
		multipart����   �ʼ��г��õ��ĸ�������:multipart��   
		multipart���ͱ�ʾ�������ɶ��������ɵģ������������˵��������Щ����֮��Ĺ�ϵ
		*/
		//multipart/mixed����˵���ʼ����а����ж�����ݣ�ÿ������֮��ʹ��boundary������ָ�����ַ��ı���Ϊ�ָ���ʶ��
		/*
		�ʼ�������ʼ������ݣ������������ʼ�ͷ�ġ�Content-Type�����塣�����������text/plain(���ı�)��text/html(���ı�)���ʼ��屻��Ϊ����Σ�ÿ�����ְ�����ͷ�Ͷ��������֣���������֮��Ҳ�Կ��зָ���������multipart���������֣� multipart/mixed, multipart/related��multipart/alternative��
		1.multipart/alternative����
			MIME�ʼ����Դ��ͳ��ı����ݣ������ڼ����ԵĿ��ǣ�һ���ڷ��ͳ��ı���ʽ���ݵ�ͬʱ��ͬʱ����һ�����ı����ݵĸ���������ʼ���ͬʱ���ڴ��ı��ͳ��ı����ݣ����ʼ���Ҫ��Content-Type���ж���multipart/alternative���ͣ��ʼ�ͨ����boundary�еķֶα�ʶ�����ı������ı����ʼ����������ݷֳɲ�ͬ�ĶΡ�������ʽ���£� Content-Type�� multipart/alternative;                boundary=��{�ֶα�ʶ}��
		2.multipart/mixed����
			���һ���ʼ��к��и��������ʼ���Content-Type���б��붨��multipart/mixed���ͣ��ʼ�ͨ��multipart/mixed�����ж����boundary��ʶ����������ͬ�ʼ��������ݷֳɲ�ͬ�ĶΡ�������ʽ���£� Content-Type�� multipart/mixed;                boundary=��{�ֶα�ʶ}��
		3.multipart/related����
			MIME�ʼ��г��˿���Я�����ָ����⣬�����Խ�������������Ƕ��Դ�ķ�ʽ�洢���ʼ��С����������ڷ���html��ʽ���ʼ�����ʱ������ʹ��ͼ����Ϊ html�ı�����html�ı��ᱻ�洢��alternative���У�����Ϊ������ͼ�����洢��multipart/related���Ͷ���Ķ��С�������ʽ���£� Content-Type�� multipart/related;                  type=��multipart/alternative��;                  boundary=��{�ֶα�ʶ}��
			˵��:��Ƕ��ԴҲ��MIME��һ������㣬����ʹ�ʼ����ݱ���������á��ḻ��ʡ������ʼ���multipart/related����ڶ���һЩ�����Ĺ�����ͼƬ����������������CSS��ʽ�ͽű��ĶΡ�ͨ����HTML�����ڣ�ʹ�ó�����������Ƕ��Դ����ϵ��
		4.multipart���͵�boundary����
			multipart���������ж������˸��Ե�boundary���ԣ��ʼ�ʹ����Щboundary�ж�����ַ�����Ϊ��ʶ�����ʼ����ݷֳɲ�ͬ�ĶΣ������ڵ�ÿ���Ӷ��ԡ��C��+boundary�п�ʼ���������ԡ��C��+boundary+���C���н�������ͬ��֮���ÿ��зָ�

		����֮��Ĳ�ι�ϵ�ɹ���Ϊ��ͼ��ʾ��      
		+------------------------- multipart/mixed ----------------------------+      
		|                                                                       |      
		|   +----------------- multipart/related ------------------+             |      
		|   |                                                       |             |      
		|   |   +----- multipart/alternative ------+   +----------+   |   +------+   |      
		|   |   |                                   |   | ��Ƕ��Դ   |   |   | ���� |   |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |   | ���ı����� |   | ���ı����� |   |                 |              |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |                                   |   | ��Ƕ��Դ   |   |   | ���� |   |      
		|   |   +----------------------------------+   +----------+   |   +------+   |      
		|   |                                                       |             |      
		|   +------------------------------------------------------+             |      
		|                                                                       |      
		+----------------------------------------------------------------------+    
		���Կ�����������ʼ���Ҫ��Ӹ��������붨��multipart/mixed�Σ�
		���������Ƕ��Դ������Ҫ����multipart/related�Σ�
		������ı��볬�ı����棬����Ҫ����multipart/alternative�Ρ�ʲô�ǡ����١����ٸ�����˵��
		���ֻ�д��ı��볬�ı����ģ���ô���ʼ�ͷ�н��������󻯣�����Ϊmultipart/related������multipart/mixed���������;

		��Щ�����������ǿ���Ƕ��ʹ�õģ�����˵һ�����и������ʼ���ͬʱ��html��text���ָ�ʽ�����ģ����ʼ��Ľṹ�ǣ�����
		Content-Type: multipart/mixed����
		����һ������
		Content Type : multipart/alternative������
		Text ���ģ�����
		Html ��ʽ�����ġ�����
		���ֶ�������
		��������
		�ʼ�������������
		���ڸ��������ɶ��������ɣ���ˣ���Ҫһ���ָ������ָ��������֣������������ʼ�Դ�ļ��е�boundary�������ģ�
		����ÿһ��Contect type :multipart/* �����ݣ���������ôһ��˵������ʾ�������֮��ķָ�������
		���� MIME/BASE64������ʼ�����鿴����Դ��ʱһ�㶼����:��This is a multi-part message in MIME format.��
		�����ľ��ӡ�Ҳ���Ա����������email������н��룬����Netscape��MS Mail��Eudora�ȡ�
		��Щ���������ȷʶ���ʼ������ģ��� MIME/BASE64 ����Ĳ���Ϊ��ȷ�����ֻ�д��Ķ������ļ�;

		Content-Transfer-Encoding:
		����ʾ����������ĵ��ı��뷽ʽ��ֻ��ʶ�������˵������������ȷ�Ľ��뷽ʽʵ�ֶ�����롣   
		Content-Transfer-Encoding����Base64, Quoted-printable, 7bit, 8bit, Binary�ȼ��֡�   
		����7bit��ȱʡ�ı��뷽ʽ�������ʼ�Դ��������Ϊȫ���ǿɴ�ӡ��ASCII�����ʽ��   
		��ASCII����ı�������Ҫ�����Ҫ��ĸ�ʽ��   
		Base64, Quoted-Printable���ڷ�Ӣ�����ʹ�����ʹ�ı��뷽ʽ��   
		Binary��ʽֻ�����������壬��û���κ�ʵ�ü�ֵ��

		boundary:
		����ָ����������в����ܳ��ֵ�һ�����ַ�����ϣ�
		���ĵ��У���"--"�������boundary ����ʾһ�����ֵĿ�ʼ��
		���ĵ��Ľ�������"--"��boundary����������"--"����ʾ�ĵ��Ľ�����
		���ڸ��������ǿ���Ƕ��ʹ�õģ���ˣ��ʼ��п��ܻ���boundary;
		*/
		
		memset(aucData,0,sizeof(aucData));
		if( pEmailInfo->mAttachmentGroup.ucAttachmentFlag )
		{
			sprintf(aucData,"Content-Type: multipart/mixed;%s",EMAILAPP_EOF);
			uiDataLen = strlen(aucData);
			
			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;

			memset(aucData,0,sizeof(aucData));
			sprintf(aucData,"%sboundary=\"%s\"%s",EMAILAPP_INDENT,pEmailInfo->mAttachmentGroup.aucBoundary,EMAILAPP_EOF);
			uiDataLen = strlen(aucData);
			
			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;
		}
		else
		{
			sprintf(aucData,"Content-Type: multipart/alternative;%s",EMAILAPP_EOF);
			uiDataLen = strlen(aucData);

			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;

			memset(aucData,0,sizeof(aucData));
			sprintf(aucData,"%sboundary=\"%s\"%s",EMAILAPP_INDENT,pEmailInfo->mFromEmail.aucBoundary,EMAILAPP_EOF);
			uiDataLen = strlen(aucData);
			
			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;
		}

		/*
		Content-Transfer-Encoding�����ֵ��������ѡ����������Ĺ���;
		�����������Ϳ��Կ��������head�����������������ڴ�������еı����ʽ��
		��ͬ��Content-Type��������Ǳ���ġ�
		��������������һ��Content-Transfer-EncodingҲ�ǲ����Եġ�
		����Ч�ش���޴�Ķ��������ݺͱ����Ķ��ı�������֮��Ҫ��һ�����С�
		���ԣ�����Ҫ�����ֱ����ʽ���׶��ģ��ͳ��ܵģ���ѹ���ʵģ���
		Content-Transfer-Encoding����Ϊ���Ŀ����Ƶġ�
		Content-Transfer-Encoding֧���������ݸ�ʽ��BASE64, QUOTED-PRINTABLE, 8BIT, 7BIT, BINARY, X-TOKEN��
		��Щֵ�Ǵ�Сд�����е�;
		
		7BIT��Ĭ��ֵ����������Content-Transfer-Encoding��ʱ��Ĭ�Ͼ���7BIT��
		7BIT�ĺ��������е�������ASC-II��ʽ�ĸ�ʽ���룬8BIT����ܰ�����ASCII;
		�ַ���
		BINARY���ܲ�ֹ������ASCII�ַ��������ܲ���һ�����У�����1000�ַ���
		7Bit����:
		7bit�򵥵ر�ʾ"�ҵ����ݽ�����US-ASCII�ַ�,ÿ���ַ���ʹ�õ�7λ." �������ϱ�֤�����е������ֽڶ�����SMTP������,��˲���Ҫ���⴦��.����԰�ԭ���Ķ�.
		��ע��,����ѡ��ʱ7bit,��ͬ�������е������еĳ��ȶ�����1000���ַ�.
		ֻҪ�������ݷ�����Щ����,7bit������õĴ������,��Ϊ����Ҫ����Ĺ���; ��մӹܵ��ж�ȡ/д���ֽ�.��Ҳ����������עĿ7bit�������.������뷨��,�����ֻ����"�򵥵�Ӣ���ı�"д��,���û�µ�.����2005�겢�����,���첢�����.

		8Bit����:
		8bit��ʾ"�ҵ����ݿ��ܰ�����չ��ASCII�ַ�;���ǿ���ʹ�õ�8��(���)λ��ָʾ��׼US-ASCII 7λ�ַ�֮��������ַ�." ���ͬʱ7bit,����1000���ַ���������.
		8bit����7bit,�����Ǳ�д������·��ȡʱ,ʵ���ϲ�û�ж��ֽڽ����κ�ת��.��ֻ����ζ�������ܱ�֤û���κ��ֽڽ����λ����Ϊ"1".
		���ƺ���һ������7bit,��Ϊ��Ϊ���ṩ�˸������������.����,RFC 1341�������С��Ŀ:
		�������ĵ�����ʱ,û�б�׼����Internet����,���ʼ������а���δ�����8λ������������ǺϷ���.���,���κ������,"8λ"��"������"���ݴ�������ڻ�������ʵ���϶��ǺϷ���.

		RFC 1341��20����ǰ����.����ʱ��,������RFC 6152�л����8λMIME��չ.���������,��������Ȼ��������:
		��ע��,����չ��������SMTP�����������г��ȵĿ�����; �������������ɵ�ʵ�ִ���չ,�������ò�����1000����λ�ֽڵ��г�������
		*/

		/*�����ʽ*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Transfer-Encoding: 8Bit%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		/*��������*/
		memset(aucDate,0,sizeof(aucDate));
		Tool_GetCurrentDate(0x28,aucDate);
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Date: %s%s",aucDate,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		/*�Ǳ�׼��ͷX-Priority(�Ǳ�׼��ͷʼ���Կ�ͷX-)*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"X-Priority: 3%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		/*˵��MIME��ʽ�е�һ����Ԫ��Ϣ*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"%sThis is a multi-part message in MIME format.%s",EMAILAPP_EOF,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	else
	{
		/*�Ǳ�׼��ͷX-Priority(�Ǳ�׼��ͷʼ���Կ�ͷX-)*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"X-Priority: 3%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		//���ñ߽�ֵ�������ʼ����ݵ� �����س�����BOUNDARY
		//                
		//	
		//Content-Type���������ĵ����ͣ�����ʵ������ͨ�������ʶ��֪����������ʲô���͵��ļ������磺
		//text/plain ��ʾ�����޸�ʽ���ı�����;
		//text/html ��ʾ�� Html �ĵ�;
		//image/gif ��ʾ���� gif ��ʽ��ͼƬ�ȵ�
		//Content-Type���ǡ�������/�����͡�����ʽ
		/*
		�ʼ����������ͷ�Ϊ���֣��ֱ���:�ı�(Text)�����ĵ�(mulipart)����Ϣ(Message)��ͼ��(Image)����Ƶ(audio)����Ƶ(Video)��Ӧ��(Application)��
		�ı�(Text)����������Ϣ��������������ʶ�ǡ�Plain������û�и�ʽ���ı���������Ҫ֧��ָ�����ַ���������ı���Ϣ����Ҫ�����������ı��������ڶ���Ϣ�ı���������Ӧ�����ִ���������������ı�����ۣ����ı������ݼ����������κ��������������Ͱ����κοɶ������ִ����ʽ
		���ĵ�(mulipart) ���������ж����������͵Ķ�����֡����ж�����4����ԭʼ�������ͣ�mixed(��������), alternative(���пɹ�ѡ��Ķ����ʽ), parallel(ͬʱ�����Ĳ���), digest(������Ϣ�͵Ķಿ����).
		��Ϣ(Message) �Cδ��װ����Ϣ�������͵���Ϣ�屾���ֻ�ȫ������RFC822��ʽ�����������ǡ� rfc822������partial����ʾ�ֲ���Ϣ�������ʼ������пɷֿ���С���External-body����ʾ��չ���ʼ���
		ͼ��(Image) �C��Ҫ����ʵ�豸��������Ҫ������Ӧ�ù㷺��ͼ�θ�ʽ��jpeg, gif��
		��Ƶ(audio) �C�������ࡱbasic��,��Ҫ��Ƶ����豸��
		��Ƶ(Video) �C�������ס�mpeg��,��Ҫ��Ƶ��ʾ�豸��
		Ӧ��(Application) �C�����������ݣ��޷������Ķ��������ݡ��������ࡱoctet-stream�������ڲ��ɽ����Ķ��������������Ϊ�û��ṩ����Ϣд���ļ��ķ�������PostScript����ʾ����ű��ĵ���
		*/
		/*
		���ڲ�������ʽ��RFC���кܶಹ��涨���е����������������
		��Ϊ��������:    
		������           ������           ����    
		text            charset         �ַ���    
		image           name            ����    
		application     name            ����    
		multipart       boundary        �߽�   
		multipart����   �ʼ��г��õ��ĸ�������:multipart��   
		multipart���ͱ�ʾ�������ɶ��������ɵģ������������˵��������Щ����֮��Ĺ�ϵ
		*/
		//multipart/mixed����˵���ʼ����а����ж�����ݣ�ÿ������֮��ʹ��boundary������ָ�����ַ��ı���Ϊ�ָ���ʶ��
		/*
		�ʼ�������ʼ������ݣ������������ʼ�ͷ�ġ�Content-Type�����塣�����������text/plain(���ı�)��text/html(���ı�)���ʼ��屻��Ϊ����Σ�ÿ�����ְ�����ͷ�Ͷ��������֣���������֮��Ҳ�Կ��зָ���������multipart���������֣� multipart/mixed, multipart/related��multipart/alternative��
		1.multipart/alternative����
			MIME�ʼ����Դ��ͳ��ı����ݣ������ڼ����ԵĿ��ǣ�һ���ڷ��ͳ��ı���ʽ���ݵ�ͬʱ��ͬʱ����һ�����ı����ݵĸ���������ʼ���ͬʱ���ڴ��ı��ͳ��ı����ݣ����ʼ���Ҫ��Content-Type���ж���multipart/alternative���ͣ��ʼ�ͨ����boundary�еķֶα�ʶ�����ı������ı����ʼ����������ݷֳɲ�ͬ�ĶΡ�������ʽ���£� Content-Type�� multipart/alternative;                boundary=��{�ֶα�ʶ}��
		2.multipart/mixed����
			���һ���ʼ��к��и��������ʼ���Content-Type���б��붨��multipart/mixed���ͣ��ʼ�ͨ��multipart/mixed�����ж����boundary��ʶ����������ͬ�ʼ��������ݷֳɲ�ͬ�ĶΡ�������ʽ���£� Content-Type�� multipart/mixed;                boundary=��{�ֶα�ʶ}��
		3.multipart/related����
			MIME�ʼ��г��˿���Я�����ָ����⣬�����Խ�������������Ƕ��Դ�ķ�ʽ�洢���ʼ��С����������ڷ���html��ʽ���ʼ�����ʱ������ʹ��ͼ����Ϊ html�ı�����html�ı��ᱻ�洢��alternative���У�����Ϊ������ͼ�����洢��multipart/related���Ͷ���Ķ��С�������ʽ���£� Content-Type�� multipart/related;                  type=��multipart/alternative��;                  boundary=��{�ֶα�ʶ}��
			˵��:��Ƕ��ԴҲ��MIME��һ������㣬����ʹ�ʼ����ݱ���������á��ḻ��ʡ������ʼ���multipart/related����ڶ���һЩ�����Ĺ�����ͼƬ����������������CSS��ʽ�ͽű��ĶΡ�ͨ����HTML�����ڣ�ʹ�ó�����������Ƕ��Դ����ϵ��
		4.multipart���͵�boundary����
			multipart���������ж������˸��Ե�boundary���ԣ��ʼ�ʹ����Щboundary�ж�����ַ�����Ϊ��ʶ�����ʼ����ݷֳɲ�ͬ�ĶΣ������ڵ�ÿ���Ӷ��ԡ��C��+boundary�п�ʼ���������ԡ��C��+boundary+���C���н�������ͬ��֮���ÿ��зָ�

		����֮��Ĳ�ι�ϵ�ɹ���Ϊ��ͼ��ʾ��      
		+------------------------- multipart/mixed ----------------------------+      
		|                                                                       |      
		|   +----------------- multipart/related ------------------+             |      
		|   |                                                       |             |      
		|   |   +----- multipart/alternative ------+   +----------+   |   +------+   |      
		|   |   |                                   |   | ��Ƕ��Դ   |   |   | ���� |   |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |   | ���ı����� |   | ���ı����� |   |                 |              |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |                                   |   | ��Ƕ��Դ   |   |   | ���� |   |      
		|   |   +----------------------------------+   +----------+   |   +------+   |      
		|   |                                                       |             |      
		|   +------------------------------------------------------+             |      
		|                                                                       |      
		+----------------------------------------------------------------------+    
		���Կ�����������ʼ���Ҫ��Ӹ��������붨��multipart/mixed�Σ�
		���������Ƕ��Դ������Ҫ����multipart/related�Σ�
		������ı��볬�ı����棬����Ҫ����multipart/alternative�Ρ�ʲô�ǡ����١����ٸ�����˵��
		���ֻ�д��ı��볬�ı����ģ���ô���ʼ�ͷ�н��������󻯣�����Ϊmultipart/related������multipart/mixed���������;

		��Щ�����������ǿ���Ƕ��ʹ�õģ�����˵һ�����и������ʼ���ͬʱ��html��text���ָ�ʽ�����ģ����ʼ��Ľṹ�ǣ�����
		Content-Type: multipart/mixed����
		����һ������
		Content Type : multipart/alternative������
		Text ���ģ�����
		Html ��ʽ�����ġ�����
		���ֶ�������
		��������
		�ʼ�������������
		���ڸ��������ɶ��������ɣ���ˣ���Ҫһ���ָ������ָ��������֣������������ʼ�Դ�ļ��е�boundary�������ģ�
		����ÿһ��Contect type :multipart/* �����ݣ���������ôһ��˵������ʾ�������֮��ķָ�������
		���� MIME/BASE64������ʼ�����鿴����Դ��ʱһ�㶼����:��This is a multi-part message in MIME format.��
		�����ľ��ӡ�Ҳ���Ա����������email������н��룬����Netscape��MS Mail��Eudora�ȡ�
		��Щ���������ȷʶ���ʼ������ģ��� MIME/BASE64 ����Ĳ���Ϊ��ȷ�����ֻ�д��Ķ������ļ�;

		Content-Transfer-Encoding:
		����ʾ����������ĵ��ı��뷽ʽ��ֻ��ʶ�������˵������������ȷ�Ľ��뷽ʽʵ�ֶ�����롣   
		Content-Transfer-Encoding����Base64, Quoted-printable, 7bit, 8bit, Binary�ȼ��֡�   
		����7bit��ȱʡ�ı��뷽ʽ�������ʼ�Դ��������Ϊȫ���ǿɴ�ӡ��ASCII�����ʽ��   
		��ASCII����ı�������Ҫ�����Ҫ��ĸ�ʽ��   
		Base64, Quoted-Printable���ڷ�Ӣ�����ʹ�����ʹ�ı��뷽ʽ��   
		Binary��ʽֻ�����������壬��û���κ�ʵ�ü�ֵ��

		boundary:
		����ָ����������в����ܳ��ֵ�һ�����ַ�����ϣ�
		���ĵ��У���"--"�������boundary ����ʾһ�����ֵĿ�ʼ��
		���ĵ��Ľ�������"--"��boundary����������"--"����ʾ�ĵ��Ľ�����
		���ڸ��������ǿ���Ƕ��ʹ�õģ���ˣ��ʼ��п��ܻ���boundary;
		*/
		
		memset(aucData,0,sizeof(aucData));
		if( pEmailInfo->mAttachmentGroup.ucAttachmentFlag )
		{
			sprintf(aucData,"Content-Type: multipart/mixed;%s",EMAILAPP_EOF);
			uiDataLen = strlen(aucData);

			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;

			memset(aucData,0,sizeof(aucData));
			sprintf(aucData,"%sboundary=\"%s\"%s",EMAILAPP_INDENT,pEmailInfo->mAttachmentGroup.aucBoundary,EMAILAPP_EOF);
			uiDataLen = strlen(aucData);
			
			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;
		}
		else
		{
			sprintf(aucData,"Content-Type: multipart/alternative;%s",EMAILAPP_EOF);
			uiDataLen = strlen(aucData);

			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;

			memset(aucData,0,sizeof(aucData));
			sprintf(aucData,"%sboundary=\"%s\"%s",EMAILAPP_INDENT,pEmailInfo->mFromEmail.aucBoundary,EMAILAPP_EOF);
			uiDataLen = strlen(aucData);
			
			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;
		}

		/*��ʾMIME�İ汾*/
		memset(aucData,0,sizeof(aucData));
		if( (NULL!=pEmailInfo->aucMIMEVer) && (strlen(pEmailInfo->aucMIMEVer)>0) )
		{
			sprintf(aucData,"MIME-Version: %s%s",pEmailInfo->aucMIMEVer,EMAILAPP_EOF);
		}
		else
		{
			sprintf(aucData,"MIME-Version: %s%s","1.0",EMAILAPP_EOF);
		}
		uiDataLen = strlen(aucData);
		
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}

	/*�ʼ�ͷ���ʼ���ָ���*/
	memset(aucData,0,sizeof(aucData));
	strcpy(aucData,EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucSendBuf[%s]!",aucSendBuf);

	memcpy(pucOutputData,aucSendBuf,uiSendLen);
	*puiOutputDataLen = uiSendLen;
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendHead
    FuncFunc : �����ʼ�ͷ����Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendHead(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	int iI = 0;
	unsigned int uiSendLen = 0;
	unsigned char aucToEmailBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendHead!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"MAIL FROM!");
	
	/*
	MAIL:
	�������������ʼ�����ʼ�,���ĺ�����淢�����ʼ���ַ(�����ʼ���ַ);
	��Ҳ�������ʼ��޷��ʹ�ʱ,����ʧ��֪ͨ;
	Ϊ��֤�ʼ��ĳɹ�����,�������ĵ�ַӦ�Ǳ��Է����м�ת����ͬ����ܵ�;
	������������йصĻ�����,Ϊ�µ��ʼ���׼��;
	*/
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"MAIL FROM: <%s>%s",pEmailInfo->mFromEmail.aucFromEmail,EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"To[%d],Cc[%d],Bcc[%d]!",pEmailInfo->mToEmailGroup.iToEmailNum,pEmailInfo->mCcEmailGroup.iCcEmailNum,pEmailInfo->mBccEmailGroup.iBccEmailNum);

	/*
	RCPT:
	�����������ռ����ռ��˵�����;
	���ж���ռ���ʱ,��Ҫ���ʹ�ø�����,ÿ��ֻ��ָ��һ����;
	������շ���������ͬ��ת�������ַ���ʼ�,�����뱨550�������֪ͨ������;
	���������ͬ��ת��,��Ҫ�����ʼ�����·��,���ʼ��Ŀ�ĵ�(�÷�����)������һ��������;
	*/
	if( !pEmailInfo->mToEmailGroup.iToEmailNum )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO info not exist!");
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return APP_FAILURE;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO:To!");

	//To(���ռ��˷��ʼ�)
	memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
	for(iI=0; iI<pEmailInfo->mToEmailGroup.iToEmailNum; iI++)
	{
		sprintf(aucToEmailBuf,"%s",pEmailInfo->mToEmailGroup.mToEmail[iI].aucToEmail);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucToEmailBuf[%s]!",iI,aucToEmailBuf);
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		sprintf(aucSendBuf,"RCPT TO: <%s>%s",aucToEmailBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		/*�������ݰ�*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�������ݰ�ʧ��");
			return ucRetCode;
		}

		ucRetCode = EmailApp_GetResponse();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�ʼ�����������Ӧ");
			return ucRetCode;
		}
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO:Cc!");
	
	//Cc(�������˷��ʼ�)
	memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
	for(iI=0; iI<pEmailInfo->mCcEmailGroup.iCcEmailNum; iI++)
	{
		sprintf(aucToEmailBuf,"%s",pEmailInfo->mCcEmailGroup.mCcEmail[iI].aucToEmail);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucToEmailBuf[%s]!",iI,aucToEmailBuf);
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		sprintf(aucSendBuf,"RCPT TO: <%s>%s",aucToEmailBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		/*�������ݰ�*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�������ݰ�ʧ��");
			return ucRetCode;
		}

		ucRetCode = EmailApp_GetResponse();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�ʼ�����������Ӧ");
			return ucRetCode;
		}
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO:Bcc!");
	
	//Bcc(�������˷��ʼ�)
	memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
	for(iI=0; iI<pEmailInfo->mBccEmailGroup.iBccEmailNum; iI++)
	{
		sprintf(aucToEmailBuf,"%s",pEmailInfo->mBccEmailGroup.mBccEmail[iI].aucToEmail);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucToEmailBuf[%s]!",iI,aucToEmailBuf);
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		sprintf(aucSendBuf,"RCPT TO: <%s>%s",aucToEmailBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		/*�������ݰ�*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�������ݰ�ʧ��");
			return ucRetCode;
		}

		ucRetCode = EmailApp_GetResponse();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�ʼ�����������Ӧ");
			return ucRetCode;
		}
	}
	
	/*
	DATA:
	�ռ����Ѹ�����֮���������Ϊ���͵�����;
	���ݱ��������ݻ�������,�Ե���һ����"."���н�������;
	�����ж��ڽ��շ�ͬʱ��ζ������ʼ�������ڵ����ݴ���,���ͽ�������ջ�����;
	������ͽ���,���շ��ظ�OK;
	*/
	//DATA \r\n //���߷��������濪ʼ�����ʼ�
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"DATA%s",EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	ucRetCode = EmailApp_SetHead(pEmailInfo,aucSendBuf,&uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetHead fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendText
    FuncFunc : �����ʼ��ı���Ϣ
	Input	 : unsigned char *	�� pucServerHostName,�����ʼ����ͷ�������������(��qq.com)
	           unsigned char	�� ucTextBase64Flag,�����ı���Ϣ�Ƿ�Base64����:0-������ 1-���� ����-����  
	           unsigned char *	�� pucInputData,�����ı���Ϣ
	           unsigned int		�� uiInputDataLen,�����ı���Ϣ�ĳ���
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendText(unsigned char *pucServerHostName,unsigned char ucTextBase64Flag,unsigned char *pucInputData,unsigned int uiInputDataLen)
{
	unsigned char ucRetCode = APP_SUCCESS;
	INT64 I64DataLen = 0;
	unsigned int uiDataLen = 0,uiTotalLen = 0,iMaxLen = 0,uiBase64DataLen = 0,uiSendLen = 0;
	unsigned char aucData[APP_MAXCOMMBUF/2+1];
	unsigned char aucBase64Data[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendText!");
	
	if( (NULL==pucInputData) || (!uiInputDataLen))
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	/*�����ʼ��ı�����*/
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	memset(aucData,0,sizeof(aucData));
	
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	memset(aucData,0,sizeof(aucData));
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	uiTotalLen = 0;
	I64DataLen = uiInputDataLen;
	iMaxLen = sizeof(aucData) - 2;
	while( I64DataLen>0 )
	{
		uiDataLen = 0;
		memset(aucData,0,sizeof(aucData));
		if( I64DataLen>=iMaxLen )
		{
			uiDataLen = iMaxLen;
			
		}
		else
		{
			uiDataLen = (unsigned int)I64DataLen;
		}
		memcpy(aucData,pucInputData,uiDataLen);
		I64DataLen = I64DataLen - uiDataLen;

		if( ucTextBase64Flag )
		{
			uiBase64DataLen = 0;
			memset(aucBase64Data,0,sizeof(aucBase64Data));
			ucRetCode = Tool_Base64Encrypt(aucData,uiDataLen,0x00,aucBase64Data,&uiBase64DataLen);
			if( ucRetCode || !uiBase64DataLen )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Tool_Base64Encrypt aucText fail!");
				return APP_PARAMERROR;
			}
			memset(aucData,0,sizeof(aucData));
			sprintf(aucData,"%s",aucBase64Data);
			uiDataLen = strlen(aucData);
			strcat(aucSendBuf,aucData);
			uiSendLen = uiSendLen + uiDataLen;
		}
		else
		{
			uiSendLen = 0;
			memset(aucSendBuf,0,sizeof(aucSendBuf));
			uiSendLen = uiDataLen;
			memcpy(aucSendBuf,aucData,uiDataLen);
		}

		/*�������ݰ�*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�������ݰ�ʧ��");
			return ucRetCode;
		}
		uiSendLen = 0;
		memset(aucSendBuf,0,sizeof(aucSendBuf));		
	}

	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	if( !memcmp(pucServerHostName,"qq",2) )
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendBody
    FuncFunc : �����ʼ�������Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendBody(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiDataLen = 0,uiBase64DataLen = 0,uiSendLen = 0;
	unsigned char aucData[APP_MAXCOMMBUF*6+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendBody!");
	
	if( (NULL==pEmailInfo) || (strlen(pEmailInfo->mBody.aucText)==0))
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	/*�����ʼ��ı�*/
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	memset(aucData,0,sizeof(aucData));
	if( pEmailInfo->mAttachmentGroup.ucAttachmentFlag )
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"--%s%s",pEmailInfo->mAttachmentGroup.aucBoundary,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
		
		sprintf(aucData,"Content-Type: multipart/alternative;%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"%sboundary=\"%s\"%s",EMAILAPP_INDENT,pEmailInfo->mFromEmail.aucBoundary,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		/*�������ݰ�*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�������ݰ�ʧ��");
			return ucRetCode;
		}
		uiSendLen = 0;
		memset(aucSendBuf,0,sizeof(aucSendBuf));
	}

	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"--%s%s",pEmailInfo->mFromEmail.aucBoundary,EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	if( !memcmp(pEmailInfo->mFromEmail.aucServerHostName,"qq",2) )
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Type: text/plain;%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"%scharset=\"%s\"%s",EMAILAPP_INDENT,pEmailInfo->aucCharset,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	else
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Type: text/plain; charset=%s%s",pEmailInfo->aucCharset,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}

	if( !pEmailInfo->mBody.ucTextBase64Flag )
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Transfer-Encoding: 7bit%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	else
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Transfer-Encoding: base64%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}

	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
		
	ucRetCode = EmailApp_SendText(pEmailInfo->mFromEmail.aucServerHostName,pEmailInfo->mBody.ucTextBase64Flag,pEmailInfo->mBody.aucText,strlen(pEmailInfo->mBody.aucText));
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendText fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�����ʼ��ı���Ϣʧ��");
		return ucRetCode;
	}
	
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"--%s%s",pEmailInfo->mFromEmail.aucBoundary,EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	if( !memcmp(pEmailInfo->mFromEmail.aucServerHostName,"qq",2) )
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Type: text/html;%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"%scharset=\"%s\"%s",EMAILAPP_INDENT,pEmailInfo->aucCharset,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	else
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Type: text/html; charset=%s%s",pEmailInfo->aucCharset,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}

	if( pEmailInfo->mBody.ucTextBase64Flag )
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Transfer-Encoding: base64%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	else
	{
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Transfer-Encoding: 7bit%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);
		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}

	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ı����ʽ���ݰ�ʧ��");
		return ucRetCode;
	}
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	
	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	/*�����������ε�*/
	if( pEmailInfo->mBody.ucTextDecorationFlag )
	{
		//<meta http-equiv="Content-Type" content="text/html; charset=GB18030"><div><span style="font-family: &quot;lucida Grande&quot;, Verdana, &quot;Microsoft YaHei&quot;;">Hello World</span></div>
		//sprintf(aucData,"<div stype=\"line-height:1.7;color:#538bd7;font-size:20px;font-family:Arial\"><p style=\"margin:0;\">%s</p></div><br><br><span title=\"neteasefooter\"><p>&nbsp;</p></sapn>",pEmailInfo->mBody.aucText);
		sprintf(aucData,"<div stype=\"line-height:%s;color:%s;font-size:%s;font-family:%s\"><p style=\"margin:0;\">%s</p></div><br><br><span title=\"neteasefooter\"><p>&nbsp;</p></sapn>",pEmailInfo->mBody.mTextAttr.aucLineHeight,pEmailInfo->mBody.mTextAttr.aucColor,pEmailInfo->mBody.mTextAttr.aucFontSize,pEmailInfo->mBody.mTextAttr.aucFontFamily,pEmailInfo->mBody.aucText);
	}
	else
	{
		sprintf(aucData,"%s",pEmailInfo->mBody.aucText);
	}
	uiDataLen = strlen(aucData);
	ucRetCode = EmailApp_SendText(pEmailInfo->mFromEmail.aucServerHostName,pEmailInfo->mBody.ucTextBase64Flag,aucData,uiDataLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendText fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�����ʼ��ı���Ϣʧ��");
		return ucRetCode;
	}

	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"--%s--%s",pEmailInfo->mFromEmail.aucBoundary,EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	memset(aucData,0,sizeof(aucData));
	sprintf(aucData,"%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	


	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendAttachment
    FuncFunc : �����ʼ�������Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendAttachment(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char ucDispFlag = 0;
	int iI = 0,iJ = 0,iDataLen = 0;
	unsigned int uiBase64DataLen = 0,uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;
	long lFileSize = 0,lReadSize = 0,lReadTotalSize = 0;
	//unsigned char aucToEmailBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];
	unsigned char aucBase64Data[APP_MAXCOMMBUF+1];
	unsigned char aucDataBuf[APP_MAXCOMMBUF/2+1];
	//unsigned char aucBase64Buf[APP_MAXCOMMBUF*2+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	FILE *fp = NULL;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendAttachment!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	if( !pEmailInfo->mAttachmentGroup.ucAttachmentFlag )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Email Attachment not exist!");
		return APP_SUCCESS;
	}
	
	/*���͸���ͷ����Ϣ*/
	//Content-Type: application/pdf; name="=?UTF-8?B?4oCLwqDlhajlm73ov5vlhaXkuIDnuqfmiJjlpIcucGRm?="
	//Content-Disposition: attachment; filename="=?UTF-8?B?4oCLwqDlhajlm73ov5vlhaXkuIDnuqfmiJjlpIcucGRm?="
	//Content-Transfer-Encoding: base64
	//strcat(aucSendBuf,"Content-Type:text/plain;name=123.txt\r\n");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iAttachmentNum[%d]!",pEmailInfo->mAttachmentGroup.iAttachmentNum);
	//Ҫʹ��SMTP���͸���,��Ҫ��SMTPͷ��Ϣ����˵��,�ı�Content-type��Ϊÿһ���������BOUNDARY��
	for(iI=0; iI<pEmailInfo->mAttachmentGroup.iAttachmentNum; iI++)
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucAttachmentFileName[%s]!",iI,pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName);
		
		memset(aucFileName,0,sizeof(aucFileName));
		ucRetCode = Tool_GetFileName(pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName,aucFileName);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Tool_GetFileName [%s] fail,ucRetCode[%02X]!",pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName,ucRetCode);
			return APP_FAILURE;
		}
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucFileName[%s]!",iI,aucFileName);

		uiBase64DataLen = sizeof(aucBase64Data);
		memset(aucBase64Data,0,sizeof(aucBase64Data));
		ucRetCode = EmailApp_GetBase64(pEmailInfo->mAttachmentGroup.ucAttachmentEncodeFlag,pEmailInfo->aucCharset,aucFileName,strlen(aucFileName),aucBase64Data,&uiBase64DataLen);
		if( ucRetCode || !uiBase64DataLen )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetBase64 aucFromEmail fail!");
			return APP_PARAMERROR;
		}
			
		uiSendLen = 0;
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		sprintf(aucSendBuf,"--%s%s",pEmailInfo->mAttachmentGroup.aucBoundary,EMAILAPP_EOF);
		ucRetCode = EmailApp_GetAttachmentContentType(pEmailInfo->mFromEmail.aucServerHostName,aucFileName,&pEmailInfo->mAttachmentGroup.mAttachment[iI].ucContentType,pEmailInfo->mAttachmentGroup.mAttachment[iI].aucContentType,sizeof(pEmailInfo->mAttachmentGroup.mAttachment[iI].aucContentType));
		if( !memcmp(pEmailInfo->mFromEmail.aucServerHostName,"qq",2) )
		{
			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"Content-Type: %s;%s",pEmailInfo->mAttachmentGroup.mAttachment[iI].aucContentType,EMAILAPP_EOF);
			strcat(aucSendBuf,aucDataBuf);
		
			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"%scharset=\"%s\";%s",EMAILAPP_INDENT,pEmailInfo->aucCharset,EMAILAPP_EOF);
			strcat(aucSendBuf,aucDataBuf);
			
			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"%sname=\"%s\"%s",EMAILAPP_INDENT,aucBase64Data,EMAILAPP_EOF);
			strcat(aucSendBuf,aucDataBuf);
		
			strcat(aucSendBuf,"Content-Disposition: attachment;");
			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"%sfilename=\"%s\"%s",EMAILAPP_INDENT,aucBase64Data,EMAILAPP_EOF);
			strcat(aucSendBuf,aucDataBuf);
			strcat(aucSendBuf,"Content-Transfer-Encoding: base64");
			strcat(aucSendBuf,EMAILAPP_EOF);
		}
		else
		{
			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"Content-Type: %s;",pEmailInfo->mAttachmentGroup.mAttachment[iI].aucContentType);
			strcat(aucSendBuf,aucDataBuf);

			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"%sname=\"%s\";%s",EMAILAPP_INDENT,aucBase64Data,EMAILAPP_EOF);
			strcat(aucSendBuf,aucDataBuf);
			
			strcat(aucSendBuf,"Content-Transfer-Encoding: base64");
			strcat(aucSendBuf,EMAILAPP_EOF);
			strcat(aucSendBuf,"Content-Disposition: attachment;");
			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"%sfilename=\"%s\"%s",EMAILAPP_INDENT,aucBase64Data,EMAILAPP_EOF);
			strcat(aucSendBuf,aucDataBuf);
		}
		strcat(aucSendBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		
		/*�������ݰ�*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�������ݰ�ʧ��");
			return ucRetCode;
		}

		uiSendLen = 0;
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		
		/*���͸���������Ϣ*/
		if( NULL==(fp = fopen(pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName,"rb")) )
		{  
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"fopen file[%s] fail!",pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName);
			//AppUtils_Warning("���ļ�ʧ��");
			return APP_FAILURE;
		}

		fseek(fp,0L,SEEK_END);
		/* ��ȡ�ļ���С */
		lFileSize = ftell(fp);
		if( -1==lFileSize )
		{
			fclose(fp);
			fp = NULL;
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"get file[%s] size fail!",pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName);
		    return APP_FAILURE;
		}

		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"file[%s],lFileSize[%d]!",aucFileName,lFileSize);
		
		if( lFileSize>0 )
		{
			fseek(fp,0,SEEK_SET);
			iJ = 0;
			lReadTotalSize = 0;
			memset(aucDataBuf,0,sizeof(aucDataBuf));
		    while( (iDataLen = fread(aucDataBuf,1,sizeof(aucDataBuf)-1,fp))>0 )
		    {	
		    	if( ((long)iDataLen + lReadTotalSize)>lFileSize )  /*�Ѷ���β*/
		    	{
	        		iDataLen = lFileSize - lReadTotalSize;
		      	}
				
		    	uiSendLen = 0;
				memset(aucSendBuf,0,sizeof(aucSendBuf));
				ucRetCode = Tool_Base64Encrypt(aucDataBuf,iDataLen,0x02,aucSendBuf,&uiSendLen);
				if( ucRetCode )
				{	
					fclose(fp);
					fp = NULL;
					Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Tool_Base64Encrypt fail,ucRetCode[0x%02X]!",ucRetCode);
					//AppUtils_Warning("�������ݰ�ʧ��");
					return ucRetCode;
				}

				//Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Cur iJ[%d],iDataLen[%d],uiSendLen[%d]!",iJ+1,iDataLen,uiSendLen);

				/*�������ݰ�*/
				ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
				if( ucRetCode )
				{
					fclose(fp);
					fp = NULL;
					Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
					//AppUtils_Warning("�������ݰ�ʧ��");
					return ucRetCode;
				}
				

				
				lReadTotalSize = lReadTotalSize + iDataLen;
				++iJ;
				iDataLen = 0;
				memset(aucDataBuf,0,sizeof(aucDataBuf));				
		   	}
		}
		fclose(fp);
		fp = NULL;

		//Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"file[%s],lFileSize[%d],lReadTotalSize[%d]!",aucFileName,lFileSize,lReadTotalSize);
		
		uiSendLen = 0;
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		strcat(aucSendBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		if( !memcmp(pEmailInfo->mFromEmail.aucServerHostName,"qq",2) )
		{
			memset(aucDataBuf,0,sizeof(aucDataBuf));
			sprintf(aucDataBuf,"%s",EMAILAPP_EOF);
			strcat(aucSendBuf,aucDataBuf);
			uiSendLen = strlen(aucSendBuf);
		}
		
		/*�������ݰ�*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("�������ݰ�ʧ��");
			return ucRetCode;
		}

	}	

	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"--%s--%s",pEmailInfo->mAttachmentGroup.aucBoundary,EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}	
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SendData
    FuncFunc : �����ʼ���Ϣ
	Input	 : EMAIL_PRM *		�� pEmailInfo,�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo,����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendData(EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendData!");
	
	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	ucRetCode = EmailApp_SendHead(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendHead fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�����ʼ�ͷ��Ϣʧ��");
		return ucRetCode;
	}

	/*�����ʼ��ı�*/
	ucRetCode = EmailApp_SendBody(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendBody fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�����ʼ�������Ϣʧ��");
		return ucRetCode;
	}


	/*�����ʼ�����*/
	ucRetCode = EmailApp_SendAttachment(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendAttachment fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�����ʼ�������Ϣʧ��");
		return ucRetCode;
	}

	/*�����ʼ�����\r\n.\r\n���ݽ������*/
	/*�����ʼ��������*/
	ucRetCode = EmailApp_SendEnd();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendEnd fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�����ʼ��������ʧ��");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_Smtp
    FuncFunc : SMTPЭ�鷢���ʼ���Ϣ
	Input	 : void *			�� pDummy			����
			   unsigned char *	�� pucDispTitle		������ʾ��Ϣ
			   EMAIL_PRM *		�� pEmailInfo		�����ʼ���Ϣ
	Output	 : EMAIL_PRM *		�� pEmailInfo		����ʼ���Ϣ
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Smtp(void *pDummy,unsigned char *pucDispTitle,EMAIL_PRM *pEmailInfo)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_Smtp!");

	if( ((void*)1==pDummy) && (NULL!=pucDispTitle) && (strlen(pucDispTitle)) )
	{
		AppUtils_FormatDisp(pucDispTitle);
	}

	if( NULL==pEmailInfo )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	memset(pEmailInfo->mFromEmail.aucUserName,0,sizeof(pEmailInfo->mFromEmail.aucUserName));
	memset(pEmailInfo->mFromEmail.aucServerHostName,0,sizeof(pEmailInfo->mFromEmail.aucServerHostName));
	memset(pEmailInfo->mFromEmail.aucServerHostIp,0,sizeof(pEmailInfo->mFromEmail.aucServerHostIp));
	ucRetCode = EmailApp_Init((void*)pDummy,pEmailInfo->mFromEmail.aucFromEmail,pEmailInfo->mFromEmail.usServerHostPort,pEmailInfo->mFromEmail.aucUserName,pEmailInfo->mFromEmail.aucServerHostName,pEmailInfo->mFromEmail.aucServerHostIp);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("ͨѶ��ʼ��ʧ��");
		return ucRetCode;
	}
	
	/*GB2312����ASCII����,GBK����GB2312����,GB18030����GB2312�����GBK����*/
	if( !memcmp(pEmailInfo->mFromEmail.aucServerHostName,"163",3) )
	{
		strcpy(pEmailInfo->aucCharset,"GBK");
		Tool_SetMEMILineLen(76);
	}
	else if( !memcmp(pEmailInfo->mFromEmail.aucServerHostName,"qq",2) )
	{
		strcpy(pEmailInfo->aucCharset,"gb18030");
		Tool_SetMEMILineLen(72);
	}
	else if( !strlen(pEmailInfo->aucCharset) )
	{
		strcpy(pEmailInfo->aucCharset,"GB2312");
		Tool_SetMEMILineLen(76);
	}
	else
	{
		Tool_SetMEMILineLen(76);
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucUserName[%s],aucServerHostName[%s],aucServerHostIp[%s]!",pEmailInfo->mFromEmail.aucUserName,pEmailInfo->mFromEmail.aucServerHostName,pEmailInfo->mFromEmail.aucServerHostIp);
	
	ucRetCode = EmailApp_ConnectEmailHost((void*)pDummy);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_ConnectEmailHost fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�����ʼ�������ʧ��");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_Logon(pEmailInfo->mFromEmail.aucFromEmail,pEmailInfo->mFromEmail.aucUserName,pEmailInfo->mFromEmail.aucUserPassword,pEmailInfo->mFromEmail.aucServerHostName);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Logon fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�ʼ���½ʧ��");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_SendData(pEmailInfo);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendData fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�ʼ�����ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_SendQuit();
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendQuit fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�ʼ��˳�ʧ��");
		return ucRetCode;
	}
	
	Comm_Disconnect(0);

	AppUtils_Warning("�ͻ��˷����ʼ����ݰ��ɹ�!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_Help
    FuncFunc : Email��Ŀ�����˵�
	Input	 : void *			�� pDummy	����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Help(void *pDummy)
{
	unsigned char aucDispBuf[128],aucTitle[64];

	AppUtils_FormatDisp("\n");
	if( strlen(g_mApp.aucUserName) )
	{
		
		memset(aucDispBuf,0,sizeof(aucDispBuf));
		memset(aucDispBuf,'*',61);

		memset(aucTitle,0,sizeof(aucTitle));
		//sprintf(aucTitle,"��ӭ%sʹ��",g_mApp.aucUserName);
		sprintf(aucTitle,"��ӭʹ��");
		memcpy(aucDispBuf+(61-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
	}
	
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**�������:%.58s",EMAILAPP_FUNCTION);
	AppUtils_FormatDisp("**����汾:%.58s",EMAILAPP_VERSION);  
	AppUtils_FormatDisp("**��Ȩ����:%.58s",EMAILAPP_AUTHOR);
	AppUtils_FormatDisp("**�����ϵ:%.58s",EMAILAPP_CONTACT);
	AppUtils_FormatDisp("**�������:%.58s",EMAILAPP_DESCPTION);
	AppUtils_FormatDisp("**�������:%.58s",EMAILAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_Test
	FuncFunc : �ʼ�����
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2016-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Test(void *pDummy)
{
	unsigned char ucRetCode = APP_FAILURE;		
	EMAIL_PRM mEmailInfo;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_Test!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_EMAIL;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	memset(&mEmailInfo,0,sizeof(mEmailInfo));
	
	/*��ʼ���ʼ���Ϣ*/
	ucRetCode = EmailApp_InitMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_InitMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*�����ʼ���������Ϣ*/
	ucRetCode = EmailApp_SetFromMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetFromMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*�����ʼ����յ��ʼ�����Ϣ*/
	ucRetCode = EmailApp_SetToMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetToMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*�����ʼ����͵��ʼ�����Ϣ*/
	ucRetCode = EmailApp_SetCcMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetCcMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*�����ʼ����͵��ʼ�����Ϣ*/
	ucRetCode = EmailApp_SetBccMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetBccMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	/*�����ʼ�������Ϣ*/
	ucRetCode = EmailApp_SetMailSubject(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailSubject fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*�����ʼ��ı���Ϣ*/
	ucRetCode = EmailApp_SetMailText(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailText fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*�����ʼ���������Ϣ*/
	ucRetCode = EmailApp_SetMailAttachment(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailAttachment fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	/*�����ʼ���ǩ��Ϣ*/
	ucRetCode = EmailApp_SetMailBoundary(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailBoundary fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_Smtp((void *)1,"�����ʼ�...",&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Smtp fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	return ucRetCode;
}


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
unsigned char EmailApp_Menu(void *pDummy)
{
	unsigned char ucMenuOption = 0;
	unsigned char aucDispTitleBuf[32];
	AppUtils_MenuItem aucMenuItem[] =
	{
		{ 1, "�����ʼ�",	EmailApp_Test, (void *) 3 },
		{ 2, "����",    	EmailApp_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "Email");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60, NULL);
}
