/*************************************************************************************************
	FileName : EmailApp.c
    FileFunc : ʵ���ʼ���ĿӦ�ýӿ�
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2017-06-08 11:13:15
	Descp    : ʵ���ʼ���ĿӦ�ýӿں���
    History  : None
*************************************************************************************************/
#include "define.h"




/***********************************************************************************************
	FuncName : EmailApp_InitComm
    FuncFunc : ��ʼ�����������ͨѶ��Ϣ
	Input	 : void *			�� pDummy,����
	           unsigned char *	�� pucSendMail,�����ʼ��ĵ�ַ
	Output	 : unsigned char *	�� pucEmailUserName,�û���
	           unsigned char *	�� pucEmailServerHostName,�ʼ����ͷ�������������
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:10:22
    Descp    : Ŀǰֻ֧��163��qq����
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
		AppUtils_DisplayLeft("ͨѶ��ʼ��...\n",LINE2);
		AppUtils_DisplayLeft("���Ժ�...\n",LINE3);
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
    FuncFunc : ��ʼ��
	Input	 : void *			�� pDummy,����
	           unsigned char *	�� pucSendMail,�����ʼ��ĵ�ַ
	Output	 : unsigned char *	�� pucEmailUserName,�û���
	           unsigned char *	�� pucEmailServerHostName,�ʼ����ͷ�������������
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	if( '5'==aucRecvBuf[0] )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"��֧��SMTPЭ��!");
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_CheckConnect [ucRetCode=0x%02X]!",ucRetCode);
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
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
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,1,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"%s\r\n",aucEmailUserName);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : EmailApp_SendData
    FuncFunc : �����ʼ���Ϣ
	Input	 : unsigned char *	�� pucFromEmail,�����ʼ���ַ
	           unsigned char *	�� pucToEmail,�����ʼ���ַ
	           unsigned char *	�� pucSubject,�ʼ�����
	           unsigned char *	�� pucText,�ʼ�����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
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
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"RCPT TO: <%s>\r\n",pucToEmail);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,"DATA\r\n");
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}

	memset(aucSendBuf,0,sizeof(aucSendBuf));
	sprintf(aucSendBuf,"Subject: %s\r\n\r\n%s\r\n\r\n.\r\n",pucSubject,pucText);
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}
	
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	strcpy(aucSendBuf,"QUIT\r\n");
	uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	ucRetCode = EmailApp_GetResponse();
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_GetResponse fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("�ʼ�����������Ӧ");
		return ucRetCode;
	}
	
	return APP_SUCCESS;	
}

/***********************************************************************************************
	FuncName : Email_Smtp
    FuncFunc : SMTPЭ�鷢���ʼ���Ϣ
	Input	 : void *			�� pDummy			����
			   unsigned char *	�� pucDispTitle		������ʾ��Ϣ
	           unsigned char *	�� pucInputData		���뷢����Ϣ
	           unsigned int		�� uiInputDataLen	���뷢����Ϣ����
	           unsigned char *	�� pucFromEmail 	���뷢���ʼ���ַ
	           unsigned char *	�� pucEmailUserPassword���뷢���ʼ�����
	           unsigned char *	�� pucToEmail		��������ʼ���ַ
	           unsigned char *	�� pucSubject		�����ʼ�����
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
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
		AppUtils_Warning("ͨѶ��ʼ��ʧ��");
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
		AppUtils_Warning("�����ʼ�������ʧ��");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_Logon(aucFromEmail,aucEmailUserName,aucEmailUserPassword,aucEmailServerHostName);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Logon fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�ʼ���½ʧ��");
		return ucRetCode;
	}
	
	ucRetCode = EmailApp_SendData(aucFromEmail,aucToEmail,aucSubject,aucText);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_SendData fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�ʼ�����ʧ��");
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
	FuncName : Trans_EmailTest
	FuncFunc : ���Խ���
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
	ucRetCode = AppUtils_GetText(LINE2,"�����뷢���ʼ���ַ:",aucTmpBuf,7,32,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ���ַʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucFromEmail,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetPassWordEx(LINE2,"�����뷢���ʼ�����:",aucTmpBuf,4,32,0);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetPassWordEx fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ�����ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucEmailUserPassword,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetText(LINE2,"����������ʼ���ַ:",aucTmpBuf,7,32,0,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�����ʼ���ַʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucToEmail,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetText(LINE2,"�������ʼ�����:",aucTmpBuf,2,32,0,60);
	//ucRetCode = AppUtils_GetCN(LINE2,"�������ʼ�����:",aucTmpBuf,2,32,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�ʼ�����ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	strcpy(aucSubject,aucTmpBuf);	
	
	ucRetCode = EmailApp_Smtp((void *)1,"�����ʼ�...",aucSendBuf,uiSendLen,aucFromEmail,aucEmailUserPassword,aucToEmail,aucSubject);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"EmailApp_Smtp fail,ucRetCode[0x%02X]!",ucRetCode);
		return APP_PARAMERROR;
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
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}




