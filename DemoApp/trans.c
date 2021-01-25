/*************************************************************************************************
	FileName : trans.c
    FileFunc : ʵ����ĿӦ�ò��Խӿ�
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2015-06-08 11:13:15
	Descp    : ʵ����ĿӦ�ò��Խӿں���
    History  : None
	Other    : None
*************************************************************************************************/
#include "define.h"



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
unsigned char Trans_InitConfig( void )
{
	unsigned char ucRetCode = 0;
	unsigned char aucBuffer[1000];
	unsigned int uiLen = 0;

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"[%s]\n",GLOBAL_APPCOMMSECNAME);
	
	uiLen = strlen(aucBuffer);
	ucRetCode = AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	if( APP_SUCCESS!=ucRetCode )
	{
		return ucRetCode;
	}

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#������Ŀ����\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#COMMTYPE:ͨѶ����\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","COMMTYPE=10\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#COMMPORT:����ͨѶ��(1~10)\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","COMMPORT=1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#BAUDRATE:���ڲ�����\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","BAUDRATE=115200\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#RS232TIMEOUT:���ڳ�ʱʱ��\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","RS232TIMEOUT=60\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#IP1:������ַ1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","IP1=222.92.214.246\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#PORT1:�����˿�1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","PORT1=443\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#IP2:������ַ2\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","IP2=222.92.214.246\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#PORT2:�����˿�2\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","PORT2=443\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HOSTNAME1:��������1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HOSTNAME1=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HOSTNAME2:��������2\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HOSTNAME2=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HTTPLIBFLAG:http��https��ͨѶʱ�Ƿ�֧�ֿ��Э�� 0-��֧�� 1-֧��\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HTTPLIBFLAG=1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#AUTOURLFLAG:http��httpsͨѶʱURL�Ƿ��Խ���0-��֧�� 1-֧��\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","AUTOURLFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#AUTOURLCOMMFLAG:http��httpsͨѶʱ�Ƿ�֧��URL�Խ���ʧ�ܺ���Host IP/Name 0-��֧�� 1-֧��\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","AUTOURLCOMMFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#AUTOHTTPPARSEFLAG:http��https���յİ��Ƿ��Խ���:0-������ 1-����\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","AUTOHTTPPARSEFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HTTPWAYFLAG:http��httpsͨѶʱ���󷽷� 0-POST 1-GET\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HTTPWAYFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
		
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#URL:http��https��URL\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","URL=https://wx.suzhoubank.com/mcg/posp\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#DOMAIN:http��https��DOMAIN\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","DOMAIN=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#PAGE:http��https��PAGE\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","PAGE=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#BAKCOMMFLAG:�Ƿ����ñ���0-������ 1-����\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","BAKCOMMFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HOSTNAMEFLAG:�Ƿ�������������0-������ 1-����\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HOSTNAMEFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#SSLFLAG:�Ƿ�����SSL 0-������ 1-����\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","SSLFLAG=1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#TCPTIMEOUT:���糬ʱʱ��\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","TCPTIMEOUT=60\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#SSLTIMEOUT:SSL���糬ʱʱ��\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","SSLTIMEOUT=60\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_SetHttpComm
    FuncFunc : ��ʼ��HTTPͨѶ��Ϣ
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
unsigned char Trans_SetHttpComm( void )
{
	unsigned char ucRetCode = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_SetHttpComm");
	
	AppUtils_DisplayLeft("ͨѶ��ʼ��...\n", LINE2);
	AppUtils_DisplayLeft("���Ժ�...\n", LINE3);
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitComm!");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "CommPort[COM%d],BaudRate[%d]!",g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate);
	
	ucRetCode = Comm_InitComm(g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate,g_mTermCfg.usRS232Timeout);	
	if( APP_SUCCESS==ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitSock!");
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%d],TCPIP1[%s],TCPHostPort1[%d],TCPIP2[%s],TCPHostPort2[%d],SelfHttpProtocolFlag[%d],HttpURL[%s],HttpRequestWayFlag[%d],TCPServerIP[%s],TCPServerPort[%d],TcpServerBlockTimeout[%d]!",
							g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,
							g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);

		ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,0x0F,g_mTermCfg.aucHttpURL,1,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
	}
	
	if( !ucRetCode )
	{
		ucRetCode = Comm_InitFtp(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.ucFTPSockBakFlag,g_mTermCfg.aucFTPServerIP2,g_mTermCfg.usFTPServerPort2,g_mTermCfg.ucFTPHostNameFlag,g_mTermCfg.aucFTPHostName1,g_mTermCfg.aucFTPHostName2,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalIP,g_mTermCfg.usFTPServerTimeout);
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Trans_SetHttpComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : Trans_GetCfgInfor
    FuncFunc : ��ȡ������Ŀ������Ϣ
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
unsigned char Trans_GetCfgInfor( void )
{
	unsigned char aucFileName[100];		/*�����ļ���*/
	unsigned char aucSectionName[100];	/*����*/
	unsigned char aucKeyName[100];		/*����*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];		/*��ֵ*/
	unsigned char ucRetCode = APP_FAILURE;

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_GetCfgInfor!");
	
	if( APP_SUCCESS!=Tool_IsExistFile(GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucCfgFileName,0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Trans_GetCfgInfor fail!");
		return APP_FAILURE;
	}
	
	//memset(&g_mApp,0,sizeof(App_Prm));
	//Tool_GetCurrentDate(0,g_mApp.aucCurrDate);

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s%s",GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucCfgFileName);
	memset(aucSectionName,0,sizeof(aucSectionName));
	sprintf(aucSectionName,"%s","COMM");

	/*��ȡ��ǰͨѶ����*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","COMMTYPE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 2==strlen((char *)aucKeyValue) )
	{
		if( !memcmp(aucKeyValue,"08",2) )
		{
			g_mTermCfg.ucCommFlag = 0;
		}
		else if( !memcmp(aucKeyValue,"09",2) )
		{
			g_mTermCfg.ucCommFlag = 1;
		}
		else if( !memcmp(aucKeyValue,"10",2) )
		{
			g_mTermCfg.ucCommFlag = 2;
		}
		else
		{
			g_mTermCfg.ucCommFlag = 1;
		}

		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "CurrentCommMode[%s]!",aucKeyValue);
	}

	/*��ȡCOMMPORT*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","COMMPORT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && ((strlen(aucKeyValue)>0) &&  (strlen(aucKeyValue)<=2) ) )
	{
		//if( COMM_TYPE_RS232==g_mTermCfg.ucCurrentCommMode )
		{
			if( 1==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM1;
			}
			else if( 2==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM2;
			}
			else if( 3==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM3;
			}
			else if( 4==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM4;
			}
			else if( 5==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM5;
			}
			else if( 6==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM6;
			}
			else if( 7==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM7;
			}
			else if( 8==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM8;
			}
			else if( 9==atoi(aucKeyValue) )
			{
				g_mTermCfg.uiCommPort = COM9;
			}

			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "COMMPORT[%s]!",aucKeyValue);
		}
	}

	/*��ȡBAUDRATE*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BAUDRATE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && ( strlen(aucKeyValue)>0 &&  strlen(aucKeyValue)<7 ) )
	{
		//if( COMM_TYPE_RS232==g_mTermCfg.ucCurrentCommMode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BAUDRATE[%s]!",aucKeyValue);
			
			switch( atol(aucKeyValue) )
			{
				case UBPS300:
				case UBPS1200:
				case UBPS2400:
				case UBPS4800:
				case UBPS7200:
				case UBPS9600:
				case UBPS19200:
				case UBPS38400:
				case UBPS57600:
				case UBPS76800:
				case UBPS115200:
						g_mTermCfg.uiBaudRate = atol(aucKeyValue);
						break;
				default:
						break;
			}
		}
	}
	
	/*��ȡIP1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","IP1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucTCPIP1,0,sizeof(g_mTermCfg.aucTCPIP1));
		memcpy(g_mTermCfg.aucTCPIP1,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "IP1[%s]!",aucKeyValue);
	}

	/*��ȡPORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT1[%s]!",aucKeyValue);
	}

	/*��ȡIP2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","IP2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucTCPIP2,0,sizeof(g_mTermCfg.aucTCPIP2));
		memcpy(g_mTermCfg.aucTCPIP2,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "IP2[%s]!",aucKeyValue);
	}
	
	/*��ȡPORT2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT2[%s]!",aucKeyValue);
	}

	/*��ȡhttp��httpsͨѶʱ�Ƿ�֧�ֿ��Э��0-��֧�� 1-֧��*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPLIBFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x04;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPLIBFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��httpsͨѶʱURL�Ƿ��Խ���0-��֧�� 1-֧��*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x01;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https�Ƿ�֧��URL�Խ���ʧ�ܺ���Host IP/Name 0-��֧�� 1-֧��*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLCOMMFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x02;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLCOMMFLAG[%s]!",aucKeyValue);
	}

	/*http��https���յİ��Ƿ��Խ���:0-������ 1-����*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOHTTPPARSEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x08;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOHTTPPARSEFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��httpsͨѶʱ���󷽷�:0-POST���� 1-GET����*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPWAYFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucRequestWayFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPWAYFLAG[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https��URL*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","URL");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=256) ) )
	{
		strcpy(g_mTermCfg.aucHttpURL,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "URL[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https��DOMAIN*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","DOMAIN");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpDomain,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DOMAIN[%s]!",aucKeyValue);
	}

	/*��ȡhttp��https��PAGE*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PAGE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpPage,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PAGE[%s]!",aucKeyValue);
	}

	/*��ȡHOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME1[%s]!",aucKeyValue);
	}

	/*��ȡHOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME2[%s]!",aucKeyValue);
	}

	/*��ȡBakCommFlag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucBakCommFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%s]!",aucKeyValue);
	}

	/*��ȡHOSTNAMEFLAG*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAMEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DomainNameFlag[%s]!",aucKeyValue);
		g_mTermCfg.ucDomainNameFlag = atoi((char *)aucKeyValue);
	}
	else
	{
		g_mTermCfg.ucDomainNameFlag = 0;
	}

	/*��ȡRS232Timeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","RS232TIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usRS232Timeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "RS232Timeout[%s]!",aucKeyValue);
	}

	/*��ȡTcpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TcpTimeout[%s]!",aucKeyValue);
	}

	/*��ȡSSLFLAG*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLFlag[%s]!",aucKeyValue);
		g_mTermCfg.ucSSLFlag = atoi((char *)aucKeyValue);
	}
	else
	{
		g_mTermCfg.ucSSLFlag = 0;
	}

	/*��ȡSSLTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usSSLTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLTimeout[%s]!",aucKeyValue);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_GetTransName
	FuncFunc : ��ȡ�������Ͷ�Ӧ����������
	Input	 : unsigned char	�� ucTransType			��������
	Output	 : unsigned char *	�� pucOutputTransName	�������Ͷ�Ӧ����������
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2016-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_GetTransName(unsigned char ucTransType,unsigned char *pucOutputTransName)
{
  switch( ucTransType )
  {
    case TTYPE_LOGON:
      sprintf(pucOutputTransName, "%s",  "ǩ��");
      break;
    case TTYPE_LOGOUT:
      sprintf(pucOutputTransName, "%s",  "ǩ��");
      break;
    case TTYPE_AID_INQUERY:
      sprintf(pucOutputTransName, "%s",  "EMV������������");
      break;
    case TTYPE_AID_UPDATE:
      sprintf(pucOutputTransName, "%s",  "EMV��������");
      break;
    case TTYPE_AID_END:
      sprintf(pucOutputTransName, "%s",  "EMV�������ؽ���");
      break;
    case TTYPE_CAKEY_INQUERY:
      sprintf(pucOutputTransName, "%s",  "EMV��Կ��������");
      break;
    case TTYPE_CAKEY_UPDATE:
      sprintf(pucOutputTransName, "%s",  "EMV��Կ����");
      break;
    case TTYPE_CAKEY_END:
      sprintf(pucOutputTransName, "%s",  "EMV��Կ���ؽ���");
      break;
    case TTYPE_SALE:
      sprintf(pucOutputTransName, "%s",  "����");
      break;
    case TTYPE_LOGON_CASHIER:
      sprintf(pucOutputTransName, "%s",  "����Ա����ǩ��");
      break;
    case TTYPE_SETTLE:
      sprintf(pucOutputTransName, "%s",  "����");
      break;
    case TTYPE_SETTLE_END:
      sprintf(pucOutputTransName, "%s",  "�����ͽ���");
      break;
    case TTYPE_BATCH_UPLOAD:
      sprintf(pucOutputTransName, "%s",  "������");
      break;
    case TTYPE_SCRIPTADVICE:
      sprintf(pucOutputTransName, "%s",  "�ű����֪ͨ");
      break;
    case TTYPE_ICOFFLINE_UPLOAD:
      sprintf(pucOutputTransName, "%s",  "IC���ѻ���������");
      break;
    case TTYPE_TC_UPLOAD:
      sprintf(pucOutputTransName, "%s",  "IC��TC����");
      break;
    case TTYPE_DOWNLOAD_PARAMETERS:
      sprintf(pucOutputTransName, "%s",  "��������");
      break;
	case TTYPE_QPS_PARAMETERS_DOWNLOAD:
	  sprintf(pucOutputTransName, "%s",  "�ǽӲ�������");
	  break;
    case TTYPE_UPLOAD_STATUS:
      sprintf(pucOutputTransName, "%s",  "״̬����");
      break;
    case TTYPE_ECHO_TESTING:
      sprintf(pucOutputTransName, "%s",  "�������");
      break;
    case TTYPE_DOWNLOAD_END:
      sprintf(pucOutputTransName, "%s",  "�������ؽ���");
      break;
    case TTYPE_BALANCE:
      sprintf(pucOutputTransName, "%s",  "����ѯ");
      break;
    case TTYPE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "���ѳ���");
      break;
    case TTYPE_REFUND:
      sprintf(pucOutputTransName, "%s",  "�˻�");
      break;
    case TTYPE_PREAUTH:
      sprintf(pucOutputTransName, "%s",  "Ԥ��Ȩ");
      break;
    case TTYPE_PREAUTH_VOID:
      sprintf(pucOutputTransName, "%s",  "Ԥ��Ȩ����");
      break;
    case TTYPE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "Ԥ��Ȩ�������");
      break;
    case TTYPE_COMPLETE_VOID:
      sprintf(pucOutputTransName, "%s",  "Ԥ��Ȩ��ɳ���");
      break;
    case TTYPE_OFFLINE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "Ԥ��Ȩ���֪ͨ");
      break;
    case TTYPE_OFFLINE_SETTLE:
      sprintf(pucOutputTransName, "%s",  "���߽���");
      break;
    case TTYPE_OFFLINE_ADJUST:
      sprintf(pucOutputTransName, "%s",  "�������");
      break;
    case TTYPE_ECASH_CASH_RELOAD:
      sprintf(pucOutputTransName, "%s",  "�ֽ��ֵ");
      break;
    case TTYPE_ECASH_CASH_RELOAD_VOID:
      sprintf(pucOutputTransName, "%s",  "�ֽ��ֵ����");
      break;
    case TTYPE_ECASH_IN_RELOAD:
      sprintf(pucOutputTransName, "%s",  "ָ���˻�Ȧ��");
      break;
    case TTYPE_ECASH_OUT_RELOAD:
      sprintf(pucOutputTransName, "%s",  "��ָ���˻�Ȧ��");
      break;
    case TTYPE_ECASH_REFUND:
      sprintf(pucOutputTransName, "%s",  "�����ֽ��ѻ��˻�");
      break;
    case TTYPE_MAG_ACCT_VERIFY:
      sprintf(pucOutputTransName, "%s",  "�����ֽ��ֵ��֤");
      break;
    case TTYPE_MAG_CASHLOAD:
      sprintf(pucOutputTransName, "%s",  "�������ֽ��ֵ");
      break;
    case TTYPE_MAG_CASHLOAD_CONFIRM:
      sprintf(pucOutputTransName, "%s",  "�����ֽ��ֵȷ��");
      break;
    case TTYPE_MAG_ACCTLOAD:
      sprintf(pucOutputTransName, "%s",  "�������˻���ֵ");
      break;
    case TTYPE_INSTALLMENT:
      sprintf(pucOutputTransName, "%s",  "���ڸ���");
      break;
    case TTYPE_INSTALLMENT_VOID:
      sprintf(pucOutputTransName, "%s",  "���ڸ����");
      break;
    case TTYPE_YUYUE_SALE:
      sprintf(pucOutputTransName, "%s",  "ԤԼ����");
      break;
    case TTYPE_YUYUE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "ԤԼ���ѳ���");
      break;
    case TTYPE_ISSUER_SCORE_SALE:
      sprintf(pucOutputTransName, "%s",  "�����л�������");
      break;
    case TTYPE_ISSUER_SCORE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "�����л��ֳ���");
      break;
    case TTYPE_UNION_SCORE_SALE:
      sprintf(pucOutputTransName, "%s",  "���˻�������");
      break;
    case TTYPE_UNION_SCORE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "���˻��ֳ���");
      break;
    case TTYPE_UNION_SCORE_BALANCE:
      sprintf(pucOutputTransName, "%s",  "���˻��ֲ�ѯ");
      break;
    case TTYPE_UNION_SCORE_REFUND:
      sprintf(pucOutputTransName, "%s",  "���˻����˻�");
      break;
    case TTYPE_MCHIP_BALANCE:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ����ѯ");
      break;
    case TTYPE_MCHIP_SALE:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ����");
      break;
    case TTYPE_MCHIP_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ���ѳ���");
      break;
    case TTYPE_MCHIP_REFUND:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ�˻�");
      break;
    case TTYPE_MCHIP_PREAUTH:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬԤ��Ȩ");
      break;
    case TTYPE_MCHIP_PREAUTH_VOID:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ��Ȩ����");
      break;
    case TTYPE_MCHIP_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ�������");
      break;
    case TTYPE_MCHIP_COMPLETE_VOID:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ��ɳ���");
      break;
    case TTYPE_MCHIP_OFFLINE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "�ֻ�оƬ���֪ͨ");
      break;
    case TTYPE_ORDER_SALE:
      sprintf(pucOutputTransName, "%s",  "��������");
      break;
    case TTYPE_ORDER_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "�������ѳ���");
      break;
    case TTYPE_ORDER_REFUND:
      sprintf(pucOutputTransName, "%s",  "�����˻�");
      break;
    case TTYPE_ORDER_PREAUTH:
      sprintf(pucOutputTransName, "%s",  "����Ԥ��Ȩ");
      break;
    case TTYPE_ORDER_PREAUTH_VOID:
      sprintf(pucOutputTransName, "%s",  "����Ԥ��Ȩ����");
      break;
    case TTYPE_ORDER_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "�����������");
      break;
    case TTYPE_ORDER_COMPLETE_VOID:
      sprintf(pucOutputTransName, "%s",  "������ɳ���");
      break;
    case TTYPE_ORDER_OFFLINE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "�������֪ͨ");
      break;
    case TTYPE_ORDER_CARDHOLDER_VERIFY:
      sprintf(pucOutputTransName, "%s",  "�ֿ�����Ϣ��֤");
      break;
    case TTYPE_TMS_UPDATE_PARAMETER:
      sprintf(pucOutputTransName, "%s",  "����TMS");
      break;
    case TTYPE_TC_UPLOAD_END:
      sprintf(pucOutputTransName, "%s",  "IC��TC�������");
      break;
    case TTYPE_REVERSAL:
      sprintf(pucOutputTransName, "%s",  "����");
      break;
    case TTYPE_BLACK_UPDATE:
      sprintf(pucOutputTransName, "%s",  "����������");
      break;
    case TTYPE_BLACK_END:
      sprintf(pucOutputTransName, "%s",  "���������ؽ���");
      break;
    case TTYPE_ECASH_BALANCE:
      sprintf(pucOutputTransName, "%s",  "�����ֽ��ѯ���");
      break;
	case TTYPE_LINK:
      sprintf(pucOutputTransName, "%s",  "��·����");
      break;
	case TTYPE_CANCEL:
      sprintf(pucOutputTransName, "%s",  "ȡ������");
      break;
	case TTYPE_GETBATTERY:
      sprintf(pucOutputTransName, "%s",  "��ȡ����");
      break;
	case TTYPE_GETAPPVER:
      sprintf(pucOutputTransName, "%s",  "��ȡ�汾");
      break;
	case TTYPE_GETAPPINFO:
      sprintf(pucOutputTransName, "%s",  "��ȡӦ����Ϣ");
      break;
	case TTYPE_TRANS_INQUIRY:
	  sprintf(pucOutputTransName, "%s",  "���ײ�ѯ");
      break;
	case TTYPE_GETPRINTINFO:
	  sprintf(pucOutputTransName, "%s",  "ȡ������Ϣ��ӡ");
      break;
	case TTYPE_GETREPRINTINFO:
	  sprintf(pucOutputTransName, "%s",  "ȡ������Ϣ�ش�ӡ");
	  break;
	case TTYPE_GETSETTLEINFO:
	  sprintf(pucOutputTransName, "%s",  "ȡ������Ϣ��ӡ");
	  break;
	case TTYPE_GETRESETTLEINFO:
	  sprintf(pucOutputTransName, "%s",  "ȡ������Ϣ�ش�ӡ");
	  break;
	case TTYPE_ORDER_INQUIRY:
      sprintf(pucOutputTransName, "%s",  "������ѯ");
      break;	   
	case TTYPE_GETPARAM:
      sprintf(pucOutputTransName, "%s",  "������ȡ");
      break;
	case TTYPE_SETPARAM:
      sprintf(pucOutputTransName, "%s",  "��������");
      break;
	case TTYPE_BARSCAN:
      sprintf(pucOutputTransName, "%s",  "�����ȡ");
      break;
	case TTYPE_BARCLOSE:
      sprintf(pucOutputTransName, "%s",  "����ǹ�ر�");
      break;
	case TTYPE_SETRSAKEY:
      sprintf(pucOutputTransName, "%s",  "����RSA��Կ");
      break;
	case TTYPE_GETCARDINFO:
      sprintf(pucOutputTransName, "%s",  "����Ϣ��ȡ");
      break;
	case TTYPE_ACTIVATE:
	  sprintf(pucOutputTransName, "%s",  "������");
      break;
	case TTYPE_INACTIVATE:
	  sprintf(pucOutputTransName, "%s",  "�������");
      break;
	case TTYPE_CARDQUERY:
	  sprintf(pucOutputTransName, "%s",  "��״̬��ѯ");
      break;
	case TTYPE_POSINIT:
      sprintf(pucOutputTransName, "%s",  "��װ����ʼ��");
      break;
	case TTYPE_DOWNKEY:
      sprintf(pucOutputTransName, "%s",  "������Կ");
      break;
	case TTYPE_ONLINEREG:
      sprintf(pucOutputTransName, "%s",  "����ע��");
      break;
	case TTYPE_ONLINEREPORT:
      sprintf(pucOutputTransName, "%s",  "��������");
      break;
	case TTYPE_REPLACEPOS:
      sprintf(pucOutputTransName, "%s",  "����");
      break;
	case TTYPE_TEST:
      sprintf(pucOutputTransName, "%s",  "����");
      break;
	case TTYPE_UPDATEAPP:
      sprintf(pucOutputTransName, "%s",  "�̼�����");
      break;
	case TTYPE_GETDATATYPE:
      sprintf(pucOutputTransName, "%s",  "�������ͳ���");
      break;
	case TTYPE_RSATEST:
      sprintf(pucOutputTransName, "%s",  "����RSA�㷨");
      break;
	case TTYPE_TESTSERVER:
      sprintf(pucOutputTransName, "%s",  "���Է�����");
      break;
	case TTYPE_TCPSERVER1:
      sprintf(pucOutputTransName, "%s",  "TCP������");
      break;
	case TTYPE_EMAIL:
      sprintf(pucOutputTransName, "%s",  "�����ʼ�");
      break;
	case TTYPE_TESTHTTP:
      sprintf(pucOutputTransName, "%s",  "HTTP����");
      break;	  
	case TTYPE_FTP_DOWNLOADFILE:
      sprintf(pucOutputTransName, "%s",  "FTP�����ļ�");
      break;
	case TTYPE_FTP_UPLOADFILE:
      sprintf(pucOutputTransName, "%s",  "FTP�ϴ��ļ�");
      break;
    default:
      sprintf(pucOutputTransName, "%s",  "δ֪����");
      break;
  }
  
  return APP_SUCCESS;
}

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
unsigned char Trans_DisplayTransName(unsigned char ucTransType)
{
  unsigned char aucDispBuf[ 128 ];
  
  memset(aucDispBuf, 0, sizeof(aucDispBuf));
  
  Trans_GetTransName(ucTransType, aucDispBuf);
  
  AppUtils_DisplayCenter(aucDispBuf, LINE1, TRUE);
  
  return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_TestServer
	FuncFunc : ���Է�����IP
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_TestServer(void *pDummy)
{
	unsigned char ucRetCode = 0;
	unsigned char aucTcpIp[16];
	unsigned short usTCPHostPort;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	//unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;
	unsigned int uiLen = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_TestServer!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_TESTSERVER;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetIpAddress(LINE2,"�������������ַ:",60,aucTmpBuf);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) || (strlen(aucTmpBuf)>16) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetIpAddress fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ��������ַʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	strcpy(aucTcpIp,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetNum(LINE2,"������������˿�:",aucTmpBuf,1,6,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) || (strlen(aucTmpBuf)>6) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetNum fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�������˿�ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	usTCPHostPort = atoi(aucTmpBuf);
	
	g_mCurrTrans.ucCommFlag = COMM_TCP;
	g_mCurrTrans.ucDataFormat = COMM_FMT_HEXLEN_DATA;
	g_mCurrTrans.ucTimeoutFlag = TIMEOUT_TCP;

	if( g_mCurrTrans.ucReLinkFlag )
	{
		g_mCurrTrans.usTimeout = 10;
	}
	else if( TIMEOUT_RS232==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usRS232Timeout;
	}
	else if( TIMEOUT_TCP==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}
	else if( TIMEOUT_SSL==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usSSLTimeout;
	}
	else if( TIMEOUT_ESC==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = 3;
	}
	else
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}
	
	ucRetCode = Comm_InitSock(aucTcpIp,usTCPHostPort,0,NULL,0,0,NULL,NULL,0,NULL,0,NULL,NULL,NULL,0,g_mTermCfg.usTcpServerBlockTimeout);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_InitSock fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("��ʼ��ʧ��");
		return ucRetCode;
	}
	
	/*�������*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect [%s:%d] fail,ucRetCode[0x%02X]!",aucTcpIp,usTCPHostPort,ucRetCode);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode,aucTmpBuf);
		AppUtils_FormatDisp("���ӷ�����ʧ��[%s:%d],ucRetCode[%d:%s]\n",aucTcpIp,usTCPHostPort,ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		//AppUtils_Warning("���ӷ�����ʧ��");
		return ucRetCode;
	}
	
	Comm_Disconnect(0);
	
	AppUtils_FormatDisp("���Է������ɹ�[%s:%d]\n",aucTcpIp,usTCPHostPort);
	AppUtils_WaitKey(5);
	//AppUtils_Warning("���Է������ɹ�!");
	
	return APP_SUCCESS;
}

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
unsigned char Trans_EchoTesting(void *pDummy)
{
	unsigned char ucRetCode = 0;
	unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_EchoTesting!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_ECHO_TESTING;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);



	if( g_mTermCfg.ucSSLFlag )
	{
		g_mCurrTrans.ucCommFlag = COMM_HTTPS;
	}
	else
	{
		g_mCurrTrans.ucCommFlag = COMM_HTTP;
	}
	
	if( !g_mTermCfg.ucSelfProtocolFlag )
	{
		g_mCurrTrans.ucDataFormat = COMM_FMT_NOFMT;
	}
	else
	{
		g_mCurrTrans.ucDataFormat = COMM_FMT_HEXLEN_DATA;
	}
	g_mCurrTrans.ucTimeoutFlag = TIMEOUT_TCP;
	
	//�������
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect [ucRetCode=0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	uiSendLen = 0;
	memset(aucSendBuf, 0, sizeof(aucSendBuf));
	memset(aucDataBuf, 0, sizeof(aucDataBuf));
	//strcpy(aucDataBuf,"600006000060320099000208200000000000C0001031313030303238343538353239303034383134303030310011000000013010");
	//strcpy(aucDataBuf,"600002000060000000000007403020000000C9001354000000000000000100026431353030343837395A3033303030303031363435323630183133343730383233333332323935353836370005443730313100089400003200033030313346323732374332");
	uiSendLen = strlen(aucDataBuf)/2;
	Tool_AscToHex(aucDataBuf,uiSendLen,aucSendBuf);
	
	//�������ݰ�
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag, g_mCurrTrans.ucDataFormat, aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	//�������ݰ�
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag, g_mCurrTrans.ucDataFormat, g_mTermCfg.usTcpTimeout, aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("������Գɹ�!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_VerifyData
	FuncFunc : ��֤���ݽ���
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_VerifyData(void *pDummy)
{
	unsigned char ucRetCode = 0;
	unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_VerifyData!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_ECHO_TESTING;
	
	AppUtils_UserClear(LINE1);
	AppUtils_DisplayCenter("��֤����", LINE1, TRUE);

	g_mCurrTrans.ucCommFlag = COMM_TCP;
	g_mCurrTrans.ucDataFormat = COMM_FMT_HEXLEN_DATA;
	g_mCurrTrans.ucTimeoutFlag = TIMEOUT_TCP;

	if( g_mCurrTrans.ucReLinkFlag )
	{
		g_mCurrTrans.usTimeout = 10;
	}
	else if( TIMEOUT_RS232==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usRS232Timeout;
	}
	else if( TIMEOUT_TCP==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}
	else if( TIMEOUT_SSL==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usSSLTimeout;
	}
	else if( TIMEOUT_ESC==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = 3;
	}
	else
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}

	#if 0
	pack[0] = COMM_STX;
      pack[1] = len / 256;
      pack[2] = len % 256;
      memcpy(&pack[3], data, len);
      s = BankUtil_GenLrc((unsigned char *)data, len);
      pack[len + 3] = s;
      pack[len + 4] = COMM_ETX;
      iRet = len + 5;
	#endif

	/*�������*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("���ӷ�����ʧ��");
		return ucRetCode;
	}
	  
	uiSendLen = 0;
	memset(aucSendBuf, 0, sizeof(aucSendBuf));
	memset(aucDataBuf, 0, sizeof(aucDataBuf));
	//strcpy(aucDataBuf,"600006000060320099000208200000000000C0001031313030303238343538353239303034383134303030310011000000013010");
	//strcpy(aucDataBuf,"600002000060000000000007403020000000C9001354000000000000000100026431353030343837395A3033303030303031363435323630183133343730383233333332323935353836370005443730313100089400003200033030313346323732374332");
	uiSendLen = strlen(aucDataBuf)/2;
	Tool_AscToHex(aucDataBuf,uiSendLen,aucSendBuf);
	
	//�������ݰ�
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	//�������ݰ�
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("������Գɹ�!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_Test
	FuncFunc : ������Խ���
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_Test(void *pDummy)
{
	unsigned char ucRetCode = 0;
	unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_Test!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_ECHO_TESTING;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	
	g_mCurrTrans.ucCommFlag = COMM_TCP;
	g_mCurrTrans.ucDataFormat = COMM_FMT_HEXLEN_DATA;
	g_mCurrTrans.ucTimeoutFlag = TIMEOUT_TCP;

	if( g_mCurrTrans.ucReLinkFlag )
	{
		g_mCurrTrans.usTimeout = 10;
	}
	else if( TIMEOUT_RS232==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usRS232Timeout;
	}
	else if( TIMEOUT_TCP==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}
	else if( TIMEOUT_SSL==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usSSLTimeout;
	}
	else if( TIMEOUT_ESC==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = 3;
	}
	else
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}

	
	/*�������*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("���ӷ�����ʧ��");
		return ucRetCode;
	}

	uiSendLen = 0;
	memset(aucSendBuf, 0, sizeof(aucSendBuf));
	memset(aucDataBuf, 0, sizeof(aucDataBuf));
	//strcpy(aucDataBuf,"600006000060320099000208200000000000C0001031313030303238343538353239303034383134303030310011000000013010");
	strcpy(aucDataBuf,"02190000000000000001501111000000000000000209      0109070278C1C41801090702000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001222.22.2.222   20171127170953000033C60000000000000000");
#if 0
	uiSendLen = strlen(aucDataBuf)/2;
	Tool_AscToHex(aucDataBuf,uiSendLen,aucSendBuf);
#else
	uiSendLen = strlen(aucDataBuf);
#endif
	
	//�������ݰ�
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	//�������ݰ�
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("������Գɹ�!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_HttpTesting
	FuncFunc : ���Խ���
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_HttpTesting(void *pDummy)
{
	unsigned char ucRetCode = 0;
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;
	unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucHttpURL[256+1];	/*HTTP������URL*/
	//unsigned char aucYear[4+1];
	//unsigned char aucCityCode[2+1];
	//unsigned char aucCode[6+1];
	//unsigned char aucTmpBuf[256+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Enter Trans_HttpTesting!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_TESTHTTP;
		
	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	if( g_mTermCfg.ucSSLFlag )
	{
		//g_mCurrTrans.ucCommFlag = COMM_HTTPS;
		g_mCurrTrans.ucCommFlag = COMM_HTTP;
	}
	else
	{
		g_mCurrTrans.ucCommFlag = COMM_HTTP;
	}
	
	if( !g_mTermCfg.ucSelfProtocolFlag )
	{
		g_mCurrTrans.ucDataFormat = COMM_FMT_NOFMT;
	}
	else
	{
		g_mCurrTrans.ucDataFormat = COMM_FMT_NOFMT;
	}
	
	g_mCurrTrans.ucTimeoutFlag = TIMEOUT_TCP;
	
	if( COMM_RS232==g_mCurrTrans.ucCommFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usRS232Timeout;
	}
	else if( COMM_TCP==g_mCurrTrans.ucCommFlag )
	{
		//g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
		g_mCurrTrans.usTimeout = 60;
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

	strcpy(g_mTermCfg.aucHttpURL,"http://data.gtimg.cn/flashdata/hushen/daily/19/sz000750.js?visitDstTime=1");
	//sprintf(g_mTermCfg.aucHttpURL,"https://xueqiu.com/S/SH688089");
	Comm_SetHttpParam(g_mTermCfg.aucHttpURL,1,1);

	Trans_SetHttpComm();
	
	/*�������*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_CheckConnect [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("���ӷ�����ʧ��");
		return ucRetCode;
	}
	
	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	memset(aucDataBuf,0,sizeof(aucDataBuf));
	//strcpy(aucDataBuf,"600006000060320099000208200000000000C0001031313030303238343538353239303034383134303030310011000000013010");
	//strcpy(aucDataBuf,"600002000060000000000007403020000000C9001354000000000000000100026431353030343837395A3033303030303031363435323630183133343730383233333332323935353836370005443730313100089400003200033030313346323732374332");
	//uiSendLen = strlen(aucDataBuf)/2;
	//Tool_AscToHex(aucDataBuf,uiSendLen,aucSendBuf);
	//sprintf(aucSendBuf,"%s","sz000750.js?visitDstTime=1");
	//uiSendLen = strlen(aucSendBuf);
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	/*�������ݰ�*/
	uiRecvLen = 0;
	memset(aucRecvBuf,0,sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf,&uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("HTTP���Գɹ�!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_Tcp
	FuncFunc : ������Խ���
	Input	 : void *			�� pDummy	��ڲ�����־
	Output	 : None
	Return	 : unsigned char	�� �ɹ�,����APP_SUCCESS
								�� ʧ��,����APP_FAILURE
	Author	 : Sunrier
	Date     : 2015-12-23 10:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char Trans_Tcp(void *pDummy)
{
	unsigned char ucRetCode = 0;
	unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_Tcp!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_ECHO_TESTING;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	
	g_mCurrTrans.ucCommFlag = COMM_TCP;
	g_mCurrTrans.ucDataFormat = COMM_FMT_HEXLEN_DATA;
	g_mCurrTrans.ucTimeoutFlag = TIMEOUT_TCP;

	if( g_mCurrTrans.ucReLinkFlag )
	{
		g_mCurrTrans.usTimeout = 10;
	}
	else if( TIMEOUT_RS232==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usRS232Timeout;
	}
	else if( TIMEOUT_TCP==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}
	else if( TIMEOUT_SSL==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usSSLTimeout;
	}
	else if( TIMEOUT_ESC==g_mCurrTrans.ucTimeoutFlag )
	{
		g_mCurrTrans.usTimeout = 3;
	}
	else
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
	}

	
	/*�������*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("���ӷ�����ʧ��");
		return ucRetCode;
	}

	uiSendLen = 0;
	memset(aucSendBuf, 0, sizeof(aucSendBuf));
	memset(aucDataBuf, 0, sizeof(aucDataBuf));
	//strcpy(aucDataBuf,"600006000060320099000208200000000000C0001031313030303238343538353239303034383134303030310011000000013010");
	strcpy(aucDataBuf,"02190000000000000001501111000000000000000209      0109070278C1C41801090702000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001222.22.2.222   20171127170953000033C60000000000000000");
#if 0
	uiSendLen = strlen(aucDataBuf)/2;
	Tool_AscToHex(aucDataBuf,uiSendLen,aucSendBuf);
#else
	uiSendLen = strlen(aucDataBuf);
#endif
	
	/*�������ݰ�*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}
	
	/*�������ݰ�*/
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("�������ݰ�ʧ��");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("������Գɹ�!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_Help
    FuncFunc : ��Ŀ�����˵�
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
unsigned char Trans_Help(void *pDummy)
{
	unsigned char aucDispBuf[128],aucTitle[64];

	AppUtils_FormatDisp("\n");
	if( strlen(g_mApp.aucUserName) )
	{
		
		memset(aucDispBuf,0,sizeof(aucDispBuf));
		memset(aucDispBuf,'*',61);

		memset(aucTitle,0,sizeof(aucTitle));
		sprintf(aucTitle,"��ӭ%sʹ��",g_mApp.aucUserName);
		memcpy(aucDispBuf+(61-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
	}
	
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**�������:%.58s",DEMOAPP_FUNCTION);
	AppUtils_FormatDisp("**����汾:%.58s",DEMOAPP_VERSION);  
	AppUtils_FormatDisp("**��Ȩ����:%.58s",DEMOAPP_AUTHOR);
	AppUtils_FormatDisp("**�����ϵ:%.58s",DEMOAPP_CONTACT);
	AppUtils_FormatDisp("**�������:%.58s",DEMOAPP_DESCPTION);
	AppUtils_FormatDisp("**�������:%.58s",DEMOAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}
	
/***********************************************************************************************
	FuncName : Trans_Menu
    FuncFunc : ��ĿӦ�ò˵�
	Input	 : void *	�� pDummy	��ڲ�����־
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
unsigned char Trans_Menu(void *pDummy)
{
	unsigned char ucMenuOption = 0;
	unsigned char aucDispTitleBuf[32];
	AppUtils_MenuItem aucMenuItem[] =
	{
		{ 1, "���Է�����",	Trans_TestServer, (void *) 0 },
		{ 2, "���콻�ײ���",Trans_EchoTesting, (void *) 0 },
		{ 3, "Test",		Trans_Test, (void *) 0 },
		{ 4, "Http",		Trans_HttpTesting, (void *) 0 },
		{ 5, "Tcp",			Trans_Tcp, (void *) 0 },
		{ 6, "����",    	Trans_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "������ĿӦ��");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}


