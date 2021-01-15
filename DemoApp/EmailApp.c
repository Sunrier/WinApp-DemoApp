/*************************************************************************************************
	FileName : EmailApp.c
    FileFunc : 实现邮件项目应用接口
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2017-06-08 11:13:15
	Descp    : 实现邮件项目应用接口函数
    History  : None
*************************************************************************************************/
#include "define.h"




/***********************************************************************************************
	FuncName : EmailApp_InitComm
    FuncFunc : 初始化邮箱服务器通讯信息
	Input	 : void *			— pDummy,参数
	           unsigned char *	— pucSendMail,发送邮件的地址
	Output	 : unsigned char *	— pucEmailUserName,用户名
	           unsigned char *	— pucEmailServerHostName,邮件发送服务器主机域名
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : 目前只支持163和qq邮箱
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_InitComm(void *pDummy,unsigned char *pucSendMail,unsigned char *pucEmailUserName,unsigned char *pucEmailServerHostName)
{
	unsigned char ucRetCode = 0;
	unsigned char aucTmpBuf[256+1];
	unsigned char aucEmailSmtp[16];
	unsigned char aucEmailServerIP[16];
	unsigned char aucEmailServerDomain[128];
	unsigned short usEmailServerPort = 25;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_InitComm");

	if( (NULL==pucSendMail) || (strlen(pucSendMail)<9) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = Tool_Strrchr(pucSendMail,'@',0x03,aucTmpBuf);
	if( ucRetCode || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Get Email user name fail!");
		return APP_FAILURE;
	}
	strcpy(pucEmailUserName,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = Tool_Strrchr(pucSendMail,'@',0x00,aucTmpBuf);
	if( ucRetCode || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Get Email server domain name fail!");
		return APP_FAILURE;
	}

	memset(aucEmailSmtp,0,sizeof(aucEmailSmtp));
	memset(aucEmailServerDomain,0,sizeof(aucEmailServerDomain));
	if( !memcmp(aucTmpBuf,"@163.com",8) )
	{
		strcpy(aucEmailSmtp,"smtp.163.com");
		strcpy(aucEmailServerDomain,"https://smtp.163.com");
		strcpy(pucEmailServerHostName,"163.com");
	}
	else if( !memcmp(aucTmpBuf,"@qq.com",7) )
	{
		strcpy(aucEmailSmtp,"smtp.qq.com");
		strcpy(aucEmailServerDomain,"https://smtp.qq.com");
		strcpy(pucEmailServerHostName,"qq.com");
	}
	else
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param,pucSendMail[%s]!",pucSendMail);
		return APP_FAILURE;
	}

	ucRetCode = Comm_GetInfoFromUrl(aucEmailServerDomain,1,aucEmailServerIP,NULL,NULL,NULL);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_GetInfoFromURL [ucRetCode=0x%02X,aucEmailServerDomain=%s]!",ucRetCode,aucEmailServerDomain);
		return ucRetCode;
	}

	if( (void*)1!=pDummy )
	{
		AppUtils_DisplayLeft("通讯初始化...\n",LINE2);
		AppUtils_DisplayLeft("请稍候...\n",LINE3);
	}

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter Comm_InitComm!");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_InitComm [CommPort=COM%d,BaudRate=%d]!",g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate);
	
	ucRetCode = Comm_InitComm(g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate,g_mTermCfg.usRS232Timeout);	
	if( APP_SUCCESS==ucRetCode )
	{
		#if 1
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter Comm_InitSock!");
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_InitSock [BakCommFlag=%d,TCPIP1=%s,TCPHostPort1=%d,TCPIP2=%s,TCPHostPort2=%d,SelfHttpProtocolFlag=%d,HttpURL=%s,HttpRequestWayFlag=%d,TCPServerIP=%s,TCPServerPort=%d,TcpServerBlockTimeout=%d]!",
							g_mTermCfg.ucBakCommFlag,aucEmailServerIP,usEmailServerPort,
							aucEmailServerIP,usEmailServerPort,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
		//ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
		#endif
		ucRetCode = Comm_InitSock(aucEmailServerIP,usEmailServerPort,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,0,NULL,g_mTermCfg.ucRequestWayFlag,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : EmailApp_Init
    FuncFunc : 初始化
	Input	 : void *			— pDummy,参数
	           unsigned char *	— pucSendMail,发送邮件的地址
	Output	 : unsigned char *	— pucEmailUserName,用户名
	           unsigned char *	— pucEmailServerHostName,邮件发送服务器主机域名
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Init(void *pDummy,unsigned char *pucSendMail,unsigned char *pucEmailUserName,unsigned char *pucEmailServerHostName)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,3,DEBUG,"Enter EmailApp_Init!");
	
	ucRetCode = EmailApp_InitComm(pDummy,pucSendMail,pucEmailUserName,pucEmailServerHostName);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	return ucRetCode;
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("接收数据包失败");
		return ucRetCode;
	}

	if( '5'==aucRecvBuf[0] )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"不支持SMTP协议!");
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_CheckConnect [ucRetCode=0x%02X]!",ucRetCode);
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
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
	unsigned char ucDispFlag = 0;
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned char aucEmailUserName[512];
	unsigned char aucEmailUserPassword[512];
	
	if( (NULL==pucEmailUserName) || (strlen(pucEmailUserName)==0) || (NULL==pucEmailUserPassword) || (strlen(pucEmailUserPassword)==0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,1,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"%s\r\n",aucEmailUserName);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SendData
    FuncFunc : 发送邮件信息
	Input	 : unsigned char *	— pucFromEmail,发送邮件地址
	           unsigned char *	— pucToEmail,接收邮件地址
	           unsigned char *	— pucSubject,邮件标题
	           unsigned char *	— pucText,邮件内容
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_SendData(unsigned char *pucFromEmail,unsigned char *pucToEmail,unsigned char *pucSubject,unsigned char *pucText)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char ucDispFlag = 0;
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];	

	if( (NULL==pucFromEmail) || (strlen(pucFromEmail)==0) 
		|| (NULL==pucToEmail) || (strlen(pucToEmail)==0)
		|| (NULL==pucSubject) || (strlen(pucSubject)==0)
		|| (NULL==pucText) || (strlen(pucText)==0))
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}
	
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"MAIL FROM: <%s>\r\n",pucFromEmail);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"RCPT TO: <%s>\r\n",pucToEmail);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,"DATA\r\n");
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"Subject: %s\r\n\r\n%s\r\n\r\n.\r\n",pucSubject,pucText);
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}
	
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,"QUIT\r\n");
	uiSendLen = strlen(aucSendBuf);
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("邮件服务器无响应");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : Email_Smtp
    FuncFunc : SMTP协议发送邮件信息
	Input	 : void *			— pDummy			参数
			   unsigned char *	— pucDispTitle		输入显示信息
	           unsigned char *	— pucInputData		输入发送信息
	           unsigned int		— uiInputDataLen	输入发送信息长度
	           unsigned char *	— pucFromEmail 	输入发送邮件地址
	           unsigned char *	— pucEmailUserPassword输入发送邮件密码
	           unsigned char *	— pucToEmail		输入接收邮件地址
	           unsigned char *	— pucSubject		输入邮件标题
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char EmailApp_Smtp(void *pDummy,unsigned char *pucDispTitle,unsigned char *pucInputData,unsigned int uiInputDataLen,
							unsigned char *pucFromEmail,unsigned char *pucEmailUserPassword,unsigned char *pucToEmail,
							unsigned char *pucSubject)
{
	unsigned char ucRetCode = APP_SUCCESS,ucDispFlag = 0;
	//unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned int uiDataLen = 0,uiLen = 0,uiSendLen = 0,uiRecvLen = 0;
	//unsigned char aucClientIP[16];
	//unsigned short usClientPort;
#if 1
	unsigned char aucFromEmail[128] = {0};
	unsigned char aucEmailUserName[128] = {0};
	unsigned char aucEmailUserPassword[128] = {0};
	unsigned char aucEmailServerHostName[128];
	unsigned char aucToEmail[128] = {0};
#else

#if 1
	unsigned char aucFromEmail[128] = "sunrier@163.com";
	unsigned char aucEmailUserName[128] = {0};
	unsigned char aucEmailUserPassword[128] = {0};
	unsigned char aucEmailServerHostName[128];
	unsigned char aucToEmail[128] = "sunrier@163.com";
#else
	unsigned char aucFromEmail[128] = "407279935@qq.com";
	unsigned char aucEmailUserName[128] = {0};
	unsigned char aucEmailUserPassword[128] = {0};
	unsigned char aucEmailServerHostName[128];
	unsigned char aucToEmail[128] = "407279935@qq.com";
#endif
#endif
	unsigned char aucSubject[256] = "Smtp Test";
	unsigned char aucText[1024] = "Hello World";
	//unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_Smtp!");

	if( ((void*)1==pDummy) && (NULL!=pucDispTitle) && (strlen(pucDispTitle)) )
	{
		AppUtils_FormatDisp(pucDispTitle);
	}

	if( (NULL==pucFromEmail) || (strlen(pucFromEmail)==0) 
		|| (NULL==pucEmailUserPassword) || (strlen(pucEmailUserPassword)==0)
		|| (NULL==pucToEmail) || (strlen(pucToEmail)==0)
		|| (NULL==pucSubject) || (strlen(pucSubject)==0)
		|| (NULL==pucInputData) || (strlen(pucInputData)==0))
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Invalid input param!");
		return APP_PARAMERROR;
	}

	strcpy(aucFromEmail,pucFromEmail);
	strcpy(aucEmailUserPassword,pucEmailUserPassword);
	strcpy(aucToEmail,pucToEmail);
	strcpy(aucSubject,pucSubject);
	strcpy(aucText,pucInputData);

	memset(aucEmailUserName,0,sizeof(aucEmailUserName));
	memset(aucEmailServerHostName,0,sizeof(aucEmailServerHostName));
	ucRetCode = EmailApp_Init((void*)pDummy,aucFromEmail,aucEmailUserName,aucEmailServerHostName);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("通讯初始化失败");
		return ucRetCode;
	}

	//https://blog.csdn.net/tanqiuwei/article/details/17141641
	//https://blog.csdn.net/coolingcoding/article/details/7339945
	//https://www.cnblogs.com/funnylinux/archive/2014/02/28/3574050.html
	ucRetCode = EmailApp_ConnectEmailHost((void*)pDummy);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_ConnectEmailHost fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("连接邮件服务器失败");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_Logon(aucFromEmail,aucEmailUserName,aucEmailUserPassword,aucEmailServerHostName);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Logon fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("邮件登陆失败");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_SendData(aucFromEmail,aucToEmail,aucSubject,aucText);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendData fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("邮件发送失败");
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
	FuncName : Trans_EmailTest
	FuncFunc : 测试交易
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
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned int uiSendLen = 0;
	unsigned char aucFromEmail[128] = "sunrier@163.com";
	unsigned char aucEmailUserPassword[128] = {0};
	unsigned char aucToEmail[128] = "sunrier@163.com";
	unsigned char aucSubject[256] = "Smtp Test";

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter EmailApp_Test!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_EMAIL;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);
	
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,"Hello World");
	uiSendLen = strlen(aucSendBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetText(LINE2,"请输入发送邮件地址:",aucTmpBuf,7,32,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取发送邮件地址失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucFromEmail,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetPassWordEx(LINE2,"请输入发送邮件密码:",aucTmpBuf,4,32,0);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetPassWordEx fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取发送邮件密码失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucEmailUserPassword,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetText(LINE2,"请输入接收邮件地址:",aucTmpBuf,7,32,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取接收邮件地址失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucToEmail,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetText(LINE2,"请输入邮件标题:",aucTmpBuf,2,32,0,60);
	//ucRetCode = AppUtils_GetCN(LINE2,"请输入邮件标题:",aucTmpBuf,2,32,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("获取邮件标题失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucSubject,aucTmpBuf);	
	
	ucRetCode = EmailApp_Smtp((void *)1,"发送邮件...",aucSendBuf,uiSendLen,aucFromEmail,aucEmailUserPassword,aucToEmail,aucSubject);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Smtp fail,ucRetCode[0x%02X]!",ucRetCode);
		return APP_PARAMERROR;
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
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}




