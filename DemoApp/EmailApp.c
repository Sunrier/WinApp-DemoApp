/*************************************************************************************************
	FileName : EmailApp.c
    FileFunc : 实现邮件项目应用接口
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2017-06-08 11:13:15
	Descp    : 实现邮件项目应用接口函数
    History  : None
	Other    : None
*************************************************************************************************/
#include "define.h"




/***********************************************************************************************
	FuncName : EmailApp_InitComm
    FuncFunc : 初始化邮箱服务器通讯信息
	Input	 : void *			— pDummy,参数	
	           unsigned char *	— pucEmailFromMail,发送邮件的地址
	           unsigned short 	— usEmailServerPort,邮件发送服务器主机的端口
	Output	 : unsigned char *	— pucEmailUserName,用户名
	           unsigned char *	— pucEmailServerHostName,邮件发送服务器主机域名
	           unsigned char *	— pucEmailServerIP,邮件发送服务器主机的IP	           
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 目前支持163和qq邮箱
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
		AppUtils_DisplayLeft("通讯初始化...\n",LINE2);
		AppUtils_DisplayLeft("请稍候...\n",LINE3);
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
    FuncFunc : 邮箱初始化
	Input	 : void *			— pDummy,参数
	           unsigned char *	— pucEmailFromMail,发送邮件的地址
	           unsigned short 	— usEmailServerPort,邮件发送服务器主机的端口
	Output	 : unsigned char *	— pucEmailUserName,用户名
	           unsigned char *	— pucEmailServerHostName,邮件发送服务器主机域名
	           unsigned char *	— pucEmailServerIP,邮件发送服务器主机的IP
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 设置邮件正文属性信息
	Input	 : TEXT_ATTR_PRM *	— pTextAttr,输入邮件正文属性信息
	Output	 : TEXT_ATTR_PRM *	— pTextAttr,输出邮件正文属性信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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

	/*行高度*/
	strcpy(pTextAttr->aucLineHeight,"1.7");

	/*字体颜色*/
	strcpy(pTextAttr->aucColor,"#538bd7");	/*字体颜色:https://blog.csdn.net/IT1039871366/article/details/46726979*/

	/*字体大小*/
	strcpy(pTextAttr->aucFontSize,"20px");

	/*字体名称*/
	strcpy(pTextAttr->aucFontFamily,"Arial");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetQQAutoRsp
    FuncFunc : 设置QQ邮箱收到邮件后自动回复信息
	Input	 : unsigned char *	— pucServerHostName,输入邮件发送服务器主机域名(如qq.com)
	Output	 : unsigned char *	— pucText,输出邮件正文信息
	           unsigned int *	— puiTextLen,输出邮件正文信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	sprintf(aucData,"<div>看到邮件后，会马上回复。谢谢。</div>%s",EMAILAPP_EOF);
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
	sprintf(aucData,"<div>&nbsp;天天开心!<img src=\"http://cache.soso.com/img/img/e113.gif\"/></div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	*puiTextLen = uiSendLen;
	memcpy(pucText,aucSendBuf,uiSendLen);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetDefAutoRsp
    FuncFunc : 设置邮箱收到邮件后自动回复信息
	Input	 : unsigned char *	— pucServerHostName,输入邮件发送服务器主机域名(如qq.com)
	Output	 : unsigned char *	— pucText,输出邮件正文信息
	           unsigned int *	— puiTextLen,输出邮件正文信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	sprintf(aucData,"<div>看到邮件后，会马上回复。谢谢。</div>%s",EMAILAPP_EOF);
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
	sprintf(aucData,"<div>&nbsp;天天开心!</div>%s",EMAILAPP_EOF);
	uiDataLen = strlen(aucData);
	strcat(aucSendBuf,aucData);
	uiSendLen = uiSendLen + uiDataLen;

	*puiTextLen = uiSendLen;
	memcpy(pucText,aucSendBuf,uiSendLen);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetAutoRsp
    FuncFunc : 设置收到邮件后自动回复信息
	Input	 : unsigned char *	— pucServerHostName,输入邮件发送服务器主机域名(如qq.com)
	Output	 : unsigned char *	— pucText,输出邮件正文信息
	           unsigned int *	— puiTextLen,输出邮件正文信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 获取邮件发送的boundary标签
	Input	 : unsigned char *	— pucFromEmail,输入发送邮件地址
	           unsigned int *	— puiOutputDataLen,输入缓冲区最大长度
	Output	 : unsigned char *	— pucOutputData,输出boundary标签
	           unsigned int *	— puiOutputDataLen,输出boundary标签长度
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 初始化邮件信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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

	/*邮件端口号默认25*/
	pEmailInfo->mFromEmail.usServerHostPort = 25;

	/*MIME版本:默认1.0*/
	strcpy(pEmailInfo->aucMIMEVer,"1.0");

	/*默认编码集:GBK(163)/gb18030(qq)/GB2312*/
	strcpy(pEmailInfo->aucCharset,"GBK");

	/*邮件头信息(如邮件地址)是否编码:0-不编码 1-GB2312编码 2-UTF8编码 其他-GB2312编码*/
	pEmailInfo->ucHeadEncodeFlag = 1;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucFromEmail[%s]!",pEmailInfo->mFromEmail.aucFromEmail);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetFromMail
    FuncFunc : 设置邮件发送方信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	ucRetCode = AppUtils_GetText(LINE2,"请输入发送邮件地址:",aucInputBuf,7,32,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取发送邮件地址失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	Tool_StrTrim(aucInputBuf,4);
	Tool_StrLowerCase(aucInputBuf);
	strcpy(pEmailInfo->mFromEmail.aucFromEmail,aucInputBuf);

	memset(aucDispTitle,0,sizeof(aucDispTitle));
	if( !memcmp(aucInputBuf+strlen(aucInputBuf)-6,"qq.com",6) )
	{
		strcpy(aucDispTitle,"请输入发送邮件验证码:");
	}
	else
	{
		strcpy(aucDispTitle,"请输入发送邮件密码:");
	}
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetPassWordEx(LINE2,aucDispTitle,aucInputBuf,4,32,0);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetPassWordEx fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取发送邮件密码失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(pEmailInfo->mFromEmail.aucUserPassword,aucInputBuf);
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucFromEmail[%s]!",pEmailInfo->mFromEmail.aucFromEmail);
	
	return APP_SUCCESS;
}


/***********************************************************************************************
	FuncName : EmailApp_DispFromMail
    FuncFunc : 显示发送的邮件信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 显示邮件接收的邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 显示邮件接收的抄送邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 显示邮件接收的密送邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 显示邮件接收的邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 设置邮件接收的邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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

	/*设置默认邮件接收的邮件组信息*/
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

	/*设置输入的邮件接收的邮件组信息*/
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"请输入接收邮件地址(多个邮件分号区分):",aucInputBuf,7,1024,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText ToEmail fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取接收邮件地址失败,ucRetCode[%d]\n",ucRetCode);
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
    FuncFunc : 设置邮件抄送的邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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

	/*设置默认邮件抄送的邮件组信息*/
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

	/*是否输入邮件抄送的邮件组信息*/
	iInputFlag = 0;
	ucRetCode = AppUtils_YesOrNo("\n请输入是否抄送邮件:","0-不抄送 1-抄送",0,&iInputFlag);
	if( APP_SUCCESS!=ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_YesOrNo Cc fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("获取是否抄送邮件失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	if( !iInputFlag )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iCcEmailNum[%d]!",pEmailInfo->mCcEmailGroup.iCcEmailNum);
		return APP_SUCCESS;
	}

	/*设置输入的邮件抄送的邮件组信息*/
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"请输入抄送邮件地址(多个抄送邮件分号区分):",aucInputBuf,7,1024,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText CcEmail fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取抄送邮件地址失败,ucRetCode[%d]\n",ucRetCode);
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
    FuncFunc : 设置邮件密送的邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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

	/*设置默认邮件密送的邮件组信息*/
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

	/*是否输入邮件密送的邮件组信息*/
	iInputFlag = 0;
	ucRetCode = AppUtils_YesOrNo("\n请输入是否密送邮件:","0-不密送 1-密送",0,&iInputFlag);
	if( APP_SUCCESS!=ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_YesOrNo Bcc fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("获取是否密送邮件失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	if( !iInputFlag )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iBccEmailNum[%d]!",pEmailInfo->mBccEmailGroup.iBccEmailNum);
		return APP_SUCCESS;
	}
	
	/*设置输入的邮件密送的邮件组信息*/
	memset(aucInputBuf,0,sizeof(aucInputBuf));
	ucRetCode = AppUtils_GetText(LINE2,"请输入密送邮件地址(多个密送邮件分号区分):",aucInputBuf,7,1024,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText BccEmail fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取密送邮件地址失败,ucRetCode[%d]\n",ucRetCode);
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
    FuncFunc : 设置邮件密送的邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	ucRetCode = AppUtils_GetText(LINE2,"请输入邮件标题:",aucInputBuf,2,EMAILAPP_SUBJECT_MAXLEN,0,60);
	//ucRetCode = AppUtils_GetCN(LINE2,"请输入邮件标题:",aucInputBuf,2,EMAILAPP_SUBJECT_MAXLEN,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取邮件标题失败,ucRetCode[%d]\n",ucRetCode);
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
    FuncFunc : 设置邮件文本信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	ucRetCode = AppUtils_GetText(LINE2,"请输入邮件文本:",aucInputBuf,2,1024,0,60);
	//ucRetCode = AppUtils_GetCN(LINE2,"请输入邮件文本:",aucInputBuf,2,1024,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucInputBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取邮件文本失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	
	if( !strlen(pEmailInfo->mBody.aucText) )
	{
		strcpy(pEmailInfo->mBody.aucText,aucText);
	}

	/*邮件正文是否修饰:0-不修饰 非0-修饰*/
	pEmailInfo->mBody.ucTextDecorationFlag = 0;
	if( pEmailInfo->mBody.ucTextDecorationFlag )
	{
		EmailApp_SetBodyTextAttr(&pEmailInfo->mBody.mTextAttr);
	}
	
	/*邮件内容是否Base64编码:0-不编码 1-编码*/
	pEmailInfo->mBody.ucTextBase64Flag = 1;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"aucText[%s]!",pEmailInfo->mBody.aucText);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SetMailAttachment
    FuncFunc : 设置邮件密送的邮件组信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	strcpy(pEmailInfo->mAttachmentGroup.mAttachment[pEmailInfo->mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\资料2.docx");
	++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	strcpy(pEmailInfo->mAttachmentGroup.mAttachment[pEmailInfo->mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\资料3.pdf");
	++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	strcpy(pEmailInfo->mAttachmentGroup.mAttachment[pEmailInfo->mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\测试2.txt");
	++pEmailInfo->mAttachmentGroup.iAttachmentNum;
	#else
	//strcpy(pEmailInfo->mAttachmentGroup.mAttachment[mEmailInfo.mAttachmentGroup.iAttachmentNum].aucAttachmentFileName,".\\测试2.txt");
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
    FuncFunc : 设置邮件标签信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
    FuncFunc : 获取编码后信息
	Input	 : unsigned char 	— ucEncodeFlag,输入信息是否编码:0-不编码 1-GB2312编码 2-UTF8编码 其他-GB2312编码
	           unsigned char *	— pucCharset,输入编码字符集
			   unsigned char *	— pucInputData,输入数据
			   int 				— iInputDataLen,输入数据的长度
	           unsigned int *	— puiOutputDataLen,输入缓冲区最大长度
	Output	 : unsigned char *	— pucOutputData,输出编码后信息
	           unsigned int *	— puiOutputDataLen,输出编码后信息的长度
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 编码后的信息包括了编码说明
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
			//AppUtils_Warning("UTF8编码数据失败");
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
			//AppUtils_Warning("GB2312编码数据失败");
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
    FuncFunc : 获取邮件附件的正文类型
	Input	 : unsigned char *	— pucServerHostName,输入邮件发送服务器主机域名(如qq.com)
			   unsigned char *	— pucFileName,输入附件文件名
	           unsigned int		— uiContentTypeMaxSize,输入正文类型字符串最大缓冲区空间
	Output	 : unsigned char *	— pucContentType,输出正文类型
	           unsigned char *	— pucContentTypeStr,输出正文类型字符串
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	//Content-Type定义了正文的类型，我们实际上是通过这个标识来知道正文内是什么类型的文件。比如：
	//text/plain 表示的是无格式的文本正文;
	//text/html 表示的 Html 文档;
	//image/gif 表示的是 gif 格式的图片等等
	//Content-Type都是“主类型/子类型”的形式
	/*
	邮件的数据类型分为七种，分别是:文本(Text)、多文档(mulipart)、消息(Message)、图像(Image)、音频(audio)、视频(Video)、应用(Application)。
	文本(Text)—文字类信息，其基本的子类标识是”Plain”，即没有格式的文本。除了需要支持指定的字符集，获得文本信息不需要特殊的软件。文本子类用于多信息文本，在其上应用文字处理软件可以美化文本的外观，但文本的内容及涵义无需任何软件。因此子类型包括任何可读得文字处理格式
	多文档(mulipart) —包含具有独立数据类型的多个部分。其中定义了4个最原始的子类型：mixed(基本类型), alternative(具有可供选择的多个格式), parallel(同时阅览的部分), digest(都是消息型的多部内容).
	消息(Message) –未封装的消息。该类型的消息体本身部分或全部都是RFC822格式。基本子类是” rfc822”。”partial”表示局部消息，允许邮件传输中可分块进行。”External-body”表示扩展大邮件。
	图形(Image) –需要有现实设备。子类主要是两种应用广泛的图形格式：jpeg, gif。
	声频(audio) –基本子类”basic”,需要声频输出设备。
	视频(Video) –基本子雷”mpeg”,需要视频显示设备。
	应用(Application) –其他类型数据，无法解析的二进制数据。基本子类”octet-stream”，用于不可解析的二进制数据情况，为用户提供将信息写入文件的方法。”PostScript”表示传输脚本文档。
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
    FuncFunc : 获取邮件服务器返回信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	/*接收数据包-等待邮件服务器返回信息*/
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf,&uiRecvLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("接收数据包失败");
		return ucRetCode;
	}

	if( !memcmp(aucRecvBuf,"211",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"系统状态或系统帮助响应!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"214",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"帮助信息!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"220",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"服务就绪!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"221",3) )
	{
		/*QUIT命令请求后返回*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"服务关闭传输信道!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"235",3) )
	{
		/*AUTH LOGIN命令请求后,再输入用户和密码后返回*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"用户验证成功!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"250",3) )
	{
		/*EHLO/MAIL FROM/RCPT TO/\r\n.\r\n/等命令请求后返回*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"要求的邮件操作完成!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"251",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"用户非本地,将转发向!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"334",3) )
	{
		/*AUTH LOGIN命令请求后返回:提示输入用户和密码*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"等待用户输入验证信息!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"354",3) )
	{
		/*DATA命令请求后返回*/
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"开始邮件输入,以.结束!");
		return APP_SUCCESS;
	}
	else if( !memcmp(aucRecvBuf,"420",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"服务未就绪,关闭传输信道(当必须关闭时,此应答可以作为对任何命令的响应)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"421",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"服务未就绪,关闭传输信道(当必须关闭时,此应答可以作为对任何命令的响应)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"450",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"要求的邮件操作未完成,邮箱不可用(例如:邮箱忙)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"451",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"放弃要求的操作,处理过程中出错!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"452",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"系统存储不足,要求的操作未执行");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"500",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"格式错误,命令不可识别(此错误也包括命令行过长)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"501",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"参数格式错误!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"502",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"命令不可实现!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"503",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"错误的命令序列!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"504",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"命令参数不可实现!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"535",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"用户认证失败!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"550",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"要求的邮件操作未完成,邮箱不可用(例如:邮箱未找到或不可访问)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"551",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"用户非本地,请尝试!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"552",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"过量的存储分配,要求的操作未执行!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"553",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"邮箱名不可用,要求的操作未执行(例如:邮箱格式错误)!");
		return APP_FAILURE;
	}
	else if( !memcmp(aucRecvBuf,"554",3) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"操作失败!");
		return APP_FAILURE;
	}
	else if( '5'==aucRecvBuf[0] )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"不支持SMTP协议!");
		//AppUtils_Warning("不支持SMTP协议");
		return APP_FAILURE;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_ConnectEmailHost
    FuncFunc : 连接/检查邮件服务器
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
		AppUtils_DisplayLeft("检查网络...\n",LINE2);
	}
	
	//检查网络
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_CheckConnect [ucRetCode=0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	if( (void*)0==pDummy )
	{
		AppUtils_DisplayLeft("接收数据...\n",LINE2);
	}
	
	/*接收数据包-等待服务器返回信息*/
	uiRecvLen = 0;
	memset(aucRecvBuf,0,sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf,&uiRecvLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_Logon
    FuncFunc : 登陆邮件服务器
	Input	 : unsigned char *	— pucSendMail,发送邮件的地址
	           unsigned char *	— pucEmailUserName,用户名
	           unsigned char *	— pucEmailUserPassword,密码
	           unsigned char *	— pucEmailServerHostName,邮件发送服务器主机域名
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,"AUTH LOGIN\r\n");
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucEmailUserName[%s],aucEmailUserPassword[%s]!",aucEmailUserName,aucEmailUserPassword);

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"%s\r\n",aucEmailUserName);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"%s\r\n",aucEmailUserPassword);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SendEnd
    FuncFunc : 发送邮件结束信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 发送邮件内容\r\n.\r\n内容结束标记
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendEnd( void )
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiSendLen = 0;
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendEnd!");

	/*发送邮件内容\r\n.\r\n内容结束标记*/
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,EMAILAPP_END);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendQuit
    FuncFunc : 发送邮件退出信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 发件方通知收件方中断连接
	History  : SMTP要求接收方必须回答OK,然后中断传输;
			   在收到这个命令并回答OK前,收件方不得中断连接,即使传输出现错误;
			   发件方在发出这个命令并收到OK答复前,也不得中断连接;
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendQuit( void )
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiSendLen = 0;
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];


	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_SendQuit!");


	//终止服务器和客户端的会话
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"QUIT%s",EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SetHead
    FuncFunc : 设置邮件头部信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : unsigned char *	— pucOutputData 	头信息的数据
		       unsigned int	 *	— puiOutputDataLen	头信息数据的长度
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	To:发送给那些需要响应的人
	Cc:发送给那些需要知晓事情进展但是不需要做出行动的人
	Bcc:发送给那些不需要知道其他收件人的人或者用于大量的邮件发送
	看国内各大邮箱服务提供商,基本提供了以上三种发送方式,
	To对应在收件人中填写多个邮箱地址,
	Cc对应于添加抄送，
	Bcc对应于添加密送,
	当然还有分别发送(QQ邮箱)或群发单显(网易和新浪),
	这种服务将多个发送任务放入队列中分别发送,
	收件人会依次收到相同的邮件;
	*/
	//发送
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"From!");

	#if 0
	/*注意:163发送qq邮箱时,qq邮箱会提示"此地址未验证，请注意识别",qq邮箱对于加密的发件人没做全部解密比较*/
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

	//To收件人(显示收件人地址栏信息)
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

	//Cc抄送(显示抄送人地址栏信息)
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

	//Bcc密送(显示密送人地址栏信息)
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
	
	/*邮件标题*/
	/*
	邮件测试
	网易闪电邮：Subject: =?utf-8?B?6YKu5Lu25rWL6K+V?=
	Foxmail： Subject: =?gbk?B?08q8/rLiytQ=?=
	从网上收集了一些这方面的一些资源，整理如下：
	邮件编码分了3段，=?和?=是开始和结束标记，中间的问号是间隔符
	第一段：utf-8或者gbk，表示原来页面的编码方式
	第二段：B是表示邮件的编码方式为base64
	第三段：08q8/rLiytQ= 或者 6YKu5Lu25rWL6K+V 表示标题的内容，但是经过Base64编码了
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
		/*表示MIME的版本*/
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

		//以 X-开头的是用户定义的字段，其他是由 RFC 822 定义的
		//设置边界值，区分邮件内容的 两个回车换行BOUNDARY
		//                
		//	
		//Content-Type定义了正文的类型，我们实际上是通过这个标识来知道正文内是什么类型的文件。比如：
		//text/plain 表示的是无格式的文本正文;
		//text/html 表示的 Html 文档;
		//image/gif 表示的是 gif 格式的图片等等
		//Content-Type都是“主类型/子类型”的形式
		/*
		邮件的数据类型分为七种，分别是:文本(Text)、多文档(mulipart)、消息(Message)、图像(Image)、音频(audio)、视频(Video)、应用(Application)。
		文本(Text)—文字类信息，其基本的子类标识是”Plain”，即没有格式的文本。除了需要支持指定的字符集，获得文本信息不需要特殊的软件。文本子类用于多信息文本，在其上应用文字处理软件可以美化文本的外观，但文本的内容及涵义无需任何软件。因此子类型包括任何可读得文字处理格式
		多文档(mulipart) —包含具有独立数据类型的多个部分。其中定义了4个最原始的子类型：mixed(基本类型), alternative(具有可供选择的多个格式), parallel(同时阅览的部分), digest(都是消息型的多部内容).
		消息(Message) –未封装的消息。该类型的消息体本身部分或全部都是RFC822格式。基本子类是” rfc822”。”partial”表示局部消息，允许邮件传输中可分块进行。”External-body”表示扩展大邮件。
		图形(Image) –需要有现实设备。子类主要是两种应用广泛的图形格式：jpeg, gif。
		声频(audio) –基本子类”basic”,需要声频输出设备。
		视频(Video) –基本子雷”mpeg”,需要视频显示设备。
		应用(Application) –其他类型数据，无法解析的二进制数据。基本子类”octet-stream”，用于不可解析的二进制数据情况，为用户提供将信息写入文件的方法。”PostScript”表示传输脚本文档。
		*/
		/*
		关于参数的形式，RFC里有很多补充规定，有的允许带几个参数，
		较为常见的有:    
		主类型           参数名           含义    
		text            charset         字符集    
		image           name            名称    
		application     name            名称    
		multipart       boundary        边界   
		multipart类型   邮件中常用到的复合类型:multipart。   
		multipart类型表示正文是由多个部分组成的，后面的子类型说明的是这些部分之间的关系
		*/
		//multipart/mixed部分说明邮件体中包含有多段数据，每段数据之间使用boundary属性中指定的字符文本作为分隔标识符
		/*
		邮件体包含邮件的内容，它的类型由邮件头的“Content-Type”域定义。最常见的类型有text/plain(纯文本)和text/html(超文本)。邮件体被分为多个段，每个段又包含段头和段体两部分，这两部分之间也以空行分隔。常见的multipart类型有三种： multipart/mixed, multipart/related和multipart/alternative。
		1.multipart/alternative类型
			MIME邮件可以传送超文本内容，但出于兼容性的考虑，一般在发送超文本格式内容的同时会同时发送一个纯文本内容的副本，如果邮件中同时存在纯文本和超文本内容，则邮件需要在Content-Type域中定义multipart/alternative类型，邮件通过其boundary中的分段标识将纯文本、超文本和邮件的其它内容分成不同的段。基本格式如下： Content-Type： multipart/alternative;                boundary=”{分段标识}”
		2.multipart/mixed类型
			如果一封邮件中含有附件，那邮件的Content-Type域中必须定义multipart/mixed类型，邮件通过multipart/mixed类型中定义的boundary标识将附件内容同邮件其它内容分成不同的段。基本格式如下： Content-Type： multipart/mixed;                boundary=”{分段标识}”
		3.multipart/related类型
			MIME邮件中除了可以携带各种附件外，还可以将其它内容以内嵌资源的方式存储在邮件中。比如我们在发送html格式的邮件内容时，可能使用图像作为 html的背景，html文本会被存储在alternative段中，而作为背景的图像则会存储在multipart/related类型定义的段中。基本格式如下： Content-Type： multipart/related;                  type=”multipart/alternative”;                  boundary=”{分段标识}”
			说明:内嵌资源也是MIME的一个发光点，它能使邮件内容变得生动活泼、丰富多彩。可在邮件的multipart/related框架内定义一些与正文关联的图片、动画、声音甚至CSS样式和脚本的段。通常在HTML正文内，使用超级链接与内嵌资源相联系。
		4.multipart类型的boundary属性
			multipart的子类型中都定义了各自的boundary属性，邮件使用这些boundary中定义的字符串作为标识，将邮件内容分成不同的段，段体内的每个子段以“–”+boundary行开始，父段则以“–”+boundary+“–”行结束，不同段之间用空行分隔

		它们之间的层次关系可归纳为下图所示：      
		+------------------------- multipart/mixed ----------------------------+      
		|                                                                       |      
		|   +----------------- multipart/related ------------------+             |      
		|   |                                                       |             |      
		|   |   +----- multipart/alternative ------+   +----------+   |   +------+   |      
		|   |   |                                   |   | 内嵌资源   |   |   | 附件 |   |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |   | 纯文本正文 |   | 超文本正文 |   |                 |              |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |                                   |   | 内嵌资源   |   |   | 附件 |   |      
		|   |   +----------------------------------+   +----------+   |   +------+   |      
		|   |                                                       |             |      
		|   +------------------------------------------------------+             |      
		|                                                                       |      
		+----------------------------------------------------------------------+    
		可以看出，如果在邮件中要添加附件，必须定义multipart/mixed段；
		如果存在内嵌资源，至少要定义multipart/related段；
		如果纯文本与超文本共存，至少要定义multipart/alternative段。什么是“至少”？举个例子说，
		如果只有纯文本与超文本正文，那么在邮件头中将类型扩大化，定义为multipart/related，甚至multipart/mixed都是允许的;

		这些复合类型又是可以嵌套使用的，比如说一个带有附件的邮件，同时有html与text两种格式的正文，则邮件的结构是：　　
		Content-Type: multipart/mixed　　
		部分一：　　
		Content Type : multipart/alternative：　　
		Text 正文；　　
		Html 格式的正文　　　
		部分二：　　
		附件　　
		邮件结束符；　　
		由于复合类型由多个部分组成，因此，需要一个分隔符来分隔这多个部分，这就是上面的邮件源文件中的boundary所描述的，
		对于每一个Contect type :multipart/* 的内容，都会有这么一个说明，表示多个部分之间的分隔。　　
		含有 MIME/BASE64编码的邮件，你查看它的源码时一般都含有:“This is a multi-part message in MIME format.”
		这样的句子。也可以被绝大多数的email程序进行解码，包括Netscape、MS Mail、Eudora等。
		这些程序可以正确识别邮件的正文，恢 MIME/BASE64 编码的部分为正确的文字或夹带的二进制文件;

		Content-Transfer-Encoding:
		它表示了这个部分文档的编码方式。只有识别了这个说明，才能用正确的解码方式实现对其解码。   
		Content-Transfer-Encoding共有Base64, Quoted-printable, 7bit, 8bit, Binary等几种。   
		其中7bit是缺省的编码方式。电子邮件源码最初设计为全部是可打印的ASCII码的形式。   
		非ASCII码的文本或数据要编码成要求的格式。   
		Base64, Quoted-Printable是在非英语国家使用最广使的编码方式。   
		Binary方式只具有象征意义，而没有任何实用价值。

		boundary:
		这个分隔符是正文中不可能出现的一串古字符的组合，
		在文档中，以"--"加上这个boundary 来表示一个部分的开始，
		在文档的结束，以"--"加boundary再在最后加上"--"来表示文档的结束。
		由于复合类型是可以嵌套使用的，因此，邮件中可能会多个boundary;
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
		Content-Transfer-Encoding标题的值描述了您选择解决此问题的规则;
		从它的命名就可以看出，这个head域是用来描述内容在传输过程中的编码格式。
		不同于Content-Type，这个域不是必须的。
		不过，仅仅定义一种Content-Transfer-Encoding也是不可以的。
		在有效地传输巨大的二进制数据和便于阅读的编码数据之间要有一个折中。
		所以，至少要有两种编码格式：易读的，和稠密的（高压缩率的）。
		Content-Transfer-Encoding就是为这个目的设计的。
		Content-Transfer-Encoding支持以下数据格式：BASE64, QUOTED-PRINTABLE, 8BIT, 7BIT, BINARY, X-TOKEN。
		这些值是大小写不敏感的;
		
		7BIT是默认值，当不设置Content-Transfer-Encoding的时候，默认就是7BIT。
		7BIT的含义是所有的数据以ASC-II格式的格式编码，8BIT则可能包含非ASCII;
		字符。
		BINARY可能不止包含非ASCII字符，还可能不是一个短行（超过1000字符）
		7Bit编码:
		7bit简单地表示"我的数据仅包含US-ASCII字符,每个字符仅使用低7位." 您基本上保证内容中的所有字节都符合SMTP的限制,因此不需要特殊处理.你可以按原样阅读.
		请注意,当您选择时7bit,您同意内容中的所有行的长度都少于1000个字符.
		只要您的内容符合这些规则,7bit就是最好的传输编码,因为不需要额外的工作; 你刚从管道中读取/写入字节.它也很容易引人注目7bit并理解它.这里的想法是,如果你只是用"简单的英文文本"写作,你会没事的.但在2005年并非如此,今天并非如此.

		8Bit编码:
		8bit表示"我的数据可能包含扩展的ASCII字符;它们可能使用第8个(最高)位来指示标准US-ASCII 7位字符之外的特殊字符." 与此同时7bit,仍有1000个字符的行限制.
		8bit就像7bit,当它们被写入或从线路读取时,实际上并没有对字节进行任何转换.它只是意味着您不能保证没有任何字节将最高位设置为"1".
		这似乎是一个进步7bit,因为它为您提供了更多的内容自由.但是,RFC 1341包含这个小节目:
		截至本文档发布时,没有标准化的Internet传输,在邮件正文中包含未编码的8位或二进制数据是合法的.因此,在任何情况下,"8位"或"二进制"内容传输编码在互联网上实际上都是合法的.

		RFC 1341在20多年前问世.从那时起,我们在RFC 6152中获得了8位MIME扩展.但即便如此,行限制仍然可能适用:
		请注意,此扩展不会消除SMTP服务器限制行长度的可能性; 服务器可以自由地实现此扩展,但仍设置不低于1000个八位字节的行长度限制
		*/

		/*编码格式*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Content-Transfer-Encoding: 8Bit%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		/*发信日期*/
		memset(aucDate,0,sizeof(aucDate));
		Tool_GetCurrentDate(0x28,aucDate);
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"Date: %s%s",aucDate,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		/*非标准标头X-Priority(非标准标头始终以开头X-)*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"X-Priority: 3%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		/*说明MIME格式中的一条多元信息*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"%sThis is a multi-part message in MIME format.%s",EMAILAPP_EOF,EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;
	}
	else
	{
		/*非标准标头X-Priority(非标准标头始终以开头X-)*/
		memset(aucData,0,sizeof(aucData));
		sprintf(aucData,"X-Priority: 3%s",EMAILAPP_EOF);
		uiDataLen = strlen(aucData);

		strcat(aucSendBuf,aucData);
		uiSendLen = uiSendLen + uiDataLen;

		//设置边界值，区分邮件内容的 两个回车换行BOUNDARY
		//                
		//	
		//Content-Type定义了正文的类型，我们实际上是通过这个标识来知道正文内是什么类型的文件。比如：
		//text/plain 表示的是无格式的文本正文;
		//text/html 表示的 Html 文档;
		//image/gif 表示的是 gif 格式的图片等等
		//Content-Type都是“主类型/子类型”的形式
		/*
		邮件的数据类型分为七种，分别是:文本(Text)、多文档(mulipart)、消息(Message)、图像(Image)、音频(audio)、视频(Video)、应用(Application)。
		文本(Text)—文字类信息，其基本的子类标识是”Plain”，即没有格式的文本。除了需要支持指定的字符集，获得文本信息不需要特殊的软件。文本子类用于多信息文本，在其上应用文字处理软件可以美化文本的外观，但文本的内容及涵义无需任何软件。因此子类型包括任何可读得文字处理格式
		多文档(mulipart) —包含具有独立数据类型的多个部分。其中定义了4个最原始的子类型：mixed(基本类型), alternative(具有可供选择的多个格式), parallel(同时阅览的部分), digest(都是消息型的多部内容).
		消息(Message) –未封装的消息。该类型的消息体本身部分或全部都是RFC822格式。基本子类是” rfc822”。”partial”表示局部消息，允许邮件传输中可分块进行。”External-body”表示扩展大邮件。
		图形(Image) –需要有现实设备。子类主要是两种应用广泛的图形格式：jpeg, gif。
		声频(audio) –基本子类”basic”,需要声频输出设备。
		视频(Video) –基本子雷”mpeg”,需要视频显示设备。
		应用(Application) –其他类型数据，无法解析的二进制数据。基本子类”octet-stream”，用于不可解析的二进制数据情况，为用户提供将信息写入文件的方法。”PostScript”表示传输脚本文档。
		*/
		/*
		关于参数的形式，RFC里有很多补充规定，有的允许带几个参数，
		较为常见的有:    
		主类型           参数名           含义    
		text            charset         字符集    
		image           name            名称    
		application     name            名称    
		multipart       boundary        边界   
		multipart类型   邮件中常用到的复合类型:multipart。   
		multipart类型表示正文是由多个部分组成的，后面的子类型说明的是这些部分之间的关系
		*/
		//multipart/mixed部分说明邮件体中包含有多段数据，每段数据之间使用boundary属性中指定的字符文本作为分隔标识符
		/*
		邮件体包含邮件的内容，它的类型由邮件头的“Content-Type”域定义。最常见的类型有text/plain(纯文本)和text/html(超文本)。邮件体被分为多个段，每个段又包含段头和段体两部分，这两部分之间也以空行分隔。常见的multipart类型有三种： multipart/mixed, multipart/related和multipart/alternative。
		1.multipart/alternative类型
			MIME邮件可以传送超文本内容，但出于兼容性的考虑，一般在发送超文本格式内容的同时会同时发送一个纯文本内容的副本，如果邮件中同时存在纯文本和超文本内容，则邮件需要在Content-Type域中定义multipart/alternative类型，邮件通过其boundary中的分段标识将纯文本、超文本和邮件的其它内容分成不同的段。基本格式如下： Content-Type： multipart/alternative;                boundary=”{分段标识}”
		2.multipart/mixed类型
			如果一封邮件中含有附件，那邮件的Content-Type域中必须定义multipart/mixed类型，邮件通过multipart/mixed类型中定义的boundary标识将附件内容同邮件其它内容分成不同的段。基本格式如下： Content-Type： multipart/mixed;                boundary=”{分段标识}”
		3.multipart/related类型
			MIME邮件中除了可以携带各种附件外，还可以将其它内容以内嵌资源的方式存储在邮件中。比如我们在发送html格式的邮件内容时，可能使用图像作为 html的背景，html文本会被存储在alternative段中，而作为背景的图像则会存储在multipart/related类型定义的段中。基本格式如下： Content-Type： multipart/related;                  type=”multipart/alternative”;                  boundary=”{分段标识}”
			说明:内嵌资源也是MIME的一个发光点，它能使邮件内容变得生动活泼、丰富多彩。可在邮件的multipart/related框架内定义一些与正文关联的图片、动画、声音甚至CSS样式和脚本的段。通常在HTML正文内，使用超级链接与内嵌资源相联系。
		4.multipart类型的boundary属性
			multipart的子类型中都定义了各自的boundary属性，邮件使用这些boundary中定义的字符串作为标识，将邮件内容分成不同的段，段体内的每个子段以“–”+boundary行开始，父段则以“–”+boundary+“–”行结束，不同段之间用空行分隔

		它们之间的层次关系可归纳为下图所示：      
		+------------------------- multipart/mixed ----------------------------+      
		|                                                                       |      
		|   +----------------- multipart/related ------------------+             |      
		|   |                                                       |             |      
		|   |   +----- multipart/alternative ------+   +----------+   |   +------+   |      
		|   |   |                                   |   | 内嵌资源   |   |   | 附件 |   |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |   | 纯文本正文 |   | 超文本正文 |   |                 |              |      
		|   |   |   +------------+   +------------+   |   +----------+   |   +------+   |      
		|   |   |                                   |   | 内嵌资源   |   |   | 附件 |   |      
		|   |   +----------------------------------+   +----------+   |   +------+   |      
		|   |                                                       |             |      
		|   +------------------------------------------------------+             |      
		|                                                                       |      
		+----------------------------------------------------------------------+    
		可以看出，如果在邮件中要添加附件，必须定义multipart/mixed段；
		如果存在内嵌资源，至少要定义multipart/related段；
		如果纯文本与超文本共存，至少要定义multipart/alternative段。什么是“至少”？举个例子说，
		如果只有纯文本与超文本正文，那么在邮件头中将类型扩大化，定义为multipart/related，甚至multipart/mixed都是允许的;

		这些复合类型又是可以嵌套使用的，比如说一个带有附件的邮件，同时有html与text两种格式的正文，则邮件的结构是：　　
		Content-Type: multipart/mixed　　
		部分一：　　
		Content Type : multipart/alternative：　　
		Text 正文；　　
		Html 格式的正文　　　
		部分二：　　
		附件　　
		邮件结束符；　　
		由于复合类型由多个部分组成，因此，需要一个分隔符来分隔这多个部分，这就是上面的邮件源文件中的boundary所描述的，
		对于每一个Contect type :multipart/* 的内容，都会有这么一个说明，表示多个部分之间的分隔。　　
		含有 MIME/BASE64编码的邮件，你查看它的源码时一般都含有:“This is a multi-part message in MIME format.”
		这样的句子。也可以被绝大多数的email程序进行解码，包括Netscape、MS Mail、Eudora等。
		这些程序可以正确识别邮件的正文，恢 MIME/BASE64 编码的部分为正确的文字或夹带的二进制文件;

		Content-Transfer-Encoding:
		它表示了这个部分文档的编码方式。只有识别了这个说明，才能用正确的解码方式实现对其解码。   
		Content-Transfer-Encoding共有Base64, Quoted-printable, 7bit, 8bit, Binary等几种。   
		其中7bit是缺省的编码方式。电子邮件源码最初设计为全部是可打印的ASCII码的形式。   
		非ASCII码的文本或数据要编码成要求的格式。   
		Base64, Quoted-Printable是在非英语国家使用最广使的编码方式。   
		Binary方式只具有象征意义，而没有任何实用价值。

		boundary:
		这个分隔符是正文中不可能出现的一串古字符的组合，
		在文档中，以"--"加上这个boundary 来表示一个部分的开始，
		在文档的结束，以"--"加boundary再在最后加上"--"来表示文档的结束。
		由于复合类型是可以嵌套使用的，因此，邮件中可能会多个boundary;
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

		/*表示MIME的版本*/
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

	/*邮件头与邮件体分隔符*/
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
    FuncFunc : 发送邮件头部信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	这个命令用来开始传送邮件,它的后面跟随发件方邮件地址(返回邮件地址);
	它也用来当邮件无法送达时,发送失败通知;
	为保证邮件的成功发送,发件方的地址应是被对方或中间转发方同意接受的;
	这个命令会清空有关的缓冲区,为新的邮件做准备;
	*/
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"MAIL FROM: <%s>%s",pEmailInfo->mFromEmail.aucFromEmail,EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"To[%d],Cc[%d],Bcc[%d]!",pEmailInfo->mToEmailGroup.iToEmailNum,pEmailInfo->mCcEmailGroup.iCcEmailNum,pEmailInfo->mBccEmailGroup.iBccEmailNum);

	/*
	RCPT:
	这个命令告诉收件方收件人的邮箱;
	当有多个收件人时,需要多次使用该命令,每次只能指明一个人;
	如果接收方服务器不同意转发这个地址的邮件,它必须报550错误代码通知发件方;
	如果服务器同意转发,它要更改邮件发送路径,把最开始的目的地(该服务器)换成下一个服务器;
	*/
	if( !pEmailInfo->mToEmailGroup.iToEmailNum )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO info not exist!");
		//AppUtils_Warning("邮件服务器无响应");
		return APP_FAILURE;
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO:To!");

	//To(给收件人发邮件)
	memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
	for(iI=0; iI<pEmailInfo->mToEmailGroup.iToEmailNum; iI++)
	{
		sprintf(aucToEmailBuf,"%s",pEmailInfo->mToEmailGroup.mToEmail[iI].aucToEmail);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucToEmailBuf[%s]!",iI,aucToEmailBuf);
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		sprintf(aucSendBuf,"RCPT TO: <%s>%s",aucToEmailBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		/*发送数据包*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("发送数据包失败");
			return ucRetCode;
		}

		ucRetCode = EmailApp_GetResponse();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("邮件服务器无响应");
			return ucRetCode;
		}
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO:Cc!");
	
	//Cc(给抄送人发邮件)
	memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
	for(iI=0; iI<pEmailInfo->mCcEmailGroup.iCcEmailNum; iI++)
	{
		sprintf(aucToEmailBuf,"%s",pEmailInfo->mCcEmailGroup.mCcEmail[iI].aucToEmail);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucToEmailBuf[%s]!",iI,aucToEmailBuf);
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		sprintf(aucSendBuf,"RCPT TO: <%s>%s",aucToEmailBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		/*发送数据包*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("发送数据包失败");
			return ucRetCode;
		}

		ucRetCode = EmailApp_GetResponse();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("邮件服务器无响应");
			return ucRetCode;
		}
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"RCPT TO:Bcc!");
	
	//Bcc(给密送人发邮件)
	memset(aucToEmailBuf,0,sizeof(aucToEmailBuf));
	for(iI=0; iI<pEmailInfo->mBccEmailGroup.iBccEmailNum; iI++)
	{
		sprintf(aucToEmailBuf,"%s",pEmailInfo->mBccEmailGroup.mBccEmail[iI].aucToEmail);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iI[%d],aucToEmailBuf[%s]!",iI,aucToEmailBuf);
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		sprintf(aucSendBuf,"RCPT TO: <%s>%s",aucToEmailBuf,EMAILAPP_EOF);
		uiSendLen = strlen(aucSendBuf);
		/*发送数据包*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("发送数据包失败");
			return ucRetCode;
		}

		ucRetCode = EmailApp_GetResponse();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("邮件服务器无响应");
			return ucRetCode;
		}
	}
	
	/*
	DATA:
	收件方把该命令之后的数据作为发送的数据;
	数据被加入数据缓冲区中,以单独一行是"."的行结束数据;
	结束行对于接收方同时意味立即开始缓冲区内的数据传送,传送结束后清空缓冲区;
	如果传送接受,接收方回复OK;
	*/
	//DATA \r\n //告诉服务器下面开始传输邮件
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"DATA%s",EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	ucRetCode = EmailApp_SetHead(pEmailInfo,aucSendBuf,&uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetHead fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendText
    FuncFunc : 发送邮件文本信息
	Input	 : unsigned char *	— pucServerHostName,输入邮件发送服务器主机域名(如qq.com)
	           unsigned char	— ucTextBase64Flag,输入文本信息是否Base64编码:0-不编码 1-编码 其他-编码  
	           unsigned char *	— pucInputData,输入文本信息
	           unsigned int		— uiInputDataLen,输入文本信息的长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	/*发送邮件文本内容*/
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

		/*发送数据包*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("发送数据包失败");
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
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendBody
    FuncFunc : 发送邮件正文信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	/*发送邮件文本*/
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

		/*发送数据包*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("发送数据包失败");
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

	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
		
	ucRetCode = EmailApp_SendText(pEmailInfo->mFromEmail.aucServerHostName,pEmailInfo->mBody.ucTextBase64Flag,pEmailInfo->mBody.aucText,strlen(pEmailInfo->mBody.aucText));
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendText fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送邮件文本信息失败");
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

	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送正文编码格式数据包失败");
		return ucRetCode;
	}
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	
	uiDataLen = 0;
	memset(aucData,0,sizeof(aucData));
	/*正文字体修饰等*/
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
		//AppUtils_Warning("发送邮件文本信息失败");
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
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	


	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_SendAttachment
    FuncFunc : 发送邮件附件信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	/*发送附件头部信息*/
	//Content-Type: application/pdf; name="=?UTF-8?B?4oCLwqDlhajlm73ov5vlhaXkuIDnuqfmiJjlpIcucGRm?="
	//Content-Disposition: attachment; filename="=?UTF-8?B?4oCLwqDlhajlm73ov5vlhaXkuIDnuqfmiJjlpIcucGRm?="
	//Content-Transfer-Encoding: base64
	//strcat(aucSendBuf,"Content-Type:text/plain;name=123.txt\r\n");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"iAttachmentNum[%d]!",pEmailInfo->mAttachmentGroup.iAttachmentNum);
	//要使用SMTP发送附件,需要对SMTP头信息进行说明,改变Content-type及为每一段正文添加BOUNDARY名
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
		
		/*发送数据包*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("发送数据包失败");
			return ucRetCode;
		}

		uiSendLen = 0;
		memset(aucSendBuf,0,sizeof(aucSendBuf));
		
		/*发送附件内容信息*/
		if( NULL==(fp = fopen(pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName,"rb")) )
		{  
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"fopen file[%s] fail!",pEmailInfo->mAttachmentGroup.mAttachment[iI].aucAttachmentFileName);
			//AppUtils_Warning("打开文件失败");
			return APP_FAILURE;
		}

		fseek(fp,0L,SEEK_END);
		/* 获取文件大小 */
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
		    	if( ((long)iDataLen + lReadTotalSize)>lFileSize )  /*已读到尾*/
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
					//AppUtils_Warning("发送数据包失败");
					return ucRetCode;
				}

				//Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Cur iJ[%d],iDataLen[%d],uiSendLen[%d]!",iJ+1,iDataLen,uiSendLen);

				/*发送数据包*/
				ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
				if( ucRetCode )
				{
					fclose(fp);
					fp = NULL;
					Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
					//AppUtils_Warning("发送数据包失败");
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
		
		/*发送数据包*/
		ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
			//AppUtils_Warning("发送数据包失败");
			return ucRetCode;
		}

	}	

	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"--%s--%s",pEmailInfo->mAttachmentGroup.aucBoundary,EMAILAPP_EOF);
	uiSendLen = strlen(aucSendBuf);
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}	
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SendData
    FuncFunc : 发送邮件信息
	Input	 : EMAIL_PRM *		— pEmailInfo,输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo,输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
		AppUtils_Warning("发送邮件头信息失败");
		return ucRetCode;
	}

	/*发送邮件文本*/
	ucRetCode = EmailApp_SendBody(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendBody fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("发送邮件内容信息失败");
		return ucRetCode;
	}


	/*发送邮件附件*/
	ucRetCode = EmailApp_SendAttachment(pEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendAttachment fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("发送邮件附件信息失败");
		return ucRetCode;
	}

	/*发送邮件内容\r\n.\r\n内容结束标记*/
	/*发送邮件结束标记*/
	ucRetCode = EmailApp_SendEnd();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendEnd fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("发送邮件结束标记失败");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : EmailApp_Smtp
    FuncFunc : SMTP协议发送邮件信息
	Input	 : void *			— pDummy			参数
			   unsigned char *	— pucDispTitle		输入显示信息
			   EMAIL_PRM *		— pEmailInfo		输入邮件信息
	Output	 : EMAIL_PRM *		— pEmailInfo		输出邮件信息
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
		AppUtils_Warning("通讯初始化失败");
		return ucRetCode;
	}
	
	/*GB2312兼容ASCII编码,GBK兼容GB2312编码,GB18030兼容GB2312编码和GBK编码*/
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
		AppUtils_Warning("连接邮件服务器失败");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_Logon(pEmailInfo->mFromEmail.aucFromEmail,pEmailInfo->mFromEmail.aucUserName,pEmailInfo->mFromEmail.aucUserPassword,pEmailInfo->mFromEmail.aucServerHostName);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Logon fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("邮件登陆失败");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_SendData(pEmailInfo);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendData fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("邮件发送失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_SendQuit();
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendQuit fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("邮件退出失败");
		return ucRetCode;
	}
	
	Comm_Disconnect(0);

	AppUtils_Warning("客户端发送邮件数据包成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_Help
    FuncFunc : Email项目帮助菜单
	Input	 : void *			— pDummy	参数
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
		//sprintf(aucTitle,"欢迎%s使用",g_mApp.aucUserName);
		sprintf(aucTitle,"欢迎使用");
		memcpy(aucDispBuf+(61-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
	}
	
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**软件功能:%.58s",EMAILAPP_FUNCTION);
	AppUtils_FormatDisp("**软件版本:%.58s",EMAILAPP_VERSION);  
	AppUtils_FormatDisp("**版权所有:%.58s",EMAILAPP_AUTHOR);
	AppUtils_FormatDisp("**软件联系:%.58s",EMAILAPP_CONTACT);
	AppUtils_FormatDisp("**软件描述:%.58s",EMAILAPP_DESCPTION);
	AppUtils_FormatDisp("**软件发布:%.58s",EMAILAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_Test
	FuncFunc : 邮件测试
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	/*初始化邮件信息*/
	ucRetCode = EmailApp_InitMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_InitMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*设置邮件发件方信息*/
	ucRetCode = EmailApp_SetFromMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetFromMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*设置邮件接收的邮件组信息*/
	ucRetCode = EmailApp_SetToMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetToMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*设置邮件抄送的邮件组信息*/
	ucRetCode = EmailApp_SetCcMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetCcMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*设置邮件密送的邮件组信息*/
	ucRetCode = EmailApp_SetBccMail(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetBccMail fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	/*设置邮件标题信息*/
	ucRetCode = EmailApp_SetMailSubject(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailSubject fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*设置邮件文本信息*/
	ucRetCode = EmailApp_SetMailText(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailText fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	/*设置邮件附件组信息*/
	ucRetCode = EmailApp_SetMailAttachment(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailAttachment fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	/*设置邮件标签信息*/
	ucRetCode = EmailApp_SetMailBoundary(&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SetMailBoundary fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_Smtp((void *)1,"发送邮件...",&mEmailInfo);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Smtp fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	
	return ucRetCode;
}


/***********************************************************************************************
	FuncName : EmailApp_Menu
    FuncFunc : Email项目应用菜单
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回按键值
								— 失败,返回超时或取消
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
		{ 1, "发送邮件",	EmailApp_Test, (void *) 3 },
		{ 2, "帮助",    	EmailApp_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "Email");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60, NULL);
}
