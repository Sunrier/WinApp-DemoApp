/*************************************************************************************************
	FileName : trans.c
    FileFunc : 实现项目应用测试接口
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2015-06-08 11:13:15
	Descp    : 实现项目应用测试接口函数
    History  : None
	Other    : None
*************************************************************************************************/
#include "define.h"



/***********************************************************************************************
	FuncName : Trans_InitConfig
    FuncFunc : 初始化配置文件信息
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	sprintf(aucBuffer,"%s","#测试项目配置\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#COMMTYPE:通讯类型\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","COMMTYPE=10\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#COMMPORT:串口通讯号(1~10)\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","COMMPORT=1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#BAUDRATE:串口拨特率\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","BAUDRATE=115200\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#RS232TIMEOUT:串口超时时间\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","RS232TIMEOUT=60\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#IP1:主机地址1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","IP1=222.92.214.246\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#PORT1:主机端口1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","PORT1=443\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#IP2:主机地址2\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","IP2=222.92.214.246\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#PORT2:主机端口2\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","PORT2=443\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HOSTNAME1:主机域名1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HOSTNAME1=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HOSTNAME2:主机域名2\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HOSTNAME2=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HTTPLIBFLAG:http或https的通讯时是否支持库的协议 0-不支持 1-支持\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HTTPLIBFLAG=1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#AUTOURLFLAG:http或https通讯时URL是否自解析0-不支持 1-支持\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","AUTOURLFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#AUTOURLCOMMFLAG:http或https通讯时是否支持URL自解析失败后尝试Host IP/Name 0-不支持 1-支持\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","AUTOURLCOMMFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#AUTOHTTPPARSEFLAG:http或https接收的包是否自解析:0-不解析 1-解析\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","AUTOHTTPPARSEFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HTTPWAYFLAG:http或https通讯时请求方法 0-POST 1-GET\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HTTPWAYFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
		
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#URL:http或https的URL\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","URL=https://wx.suzhoubank.com/mcg/posp\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#DOMAIN:http或https的DOMAIN\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","DOMAIN=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#PAGE:http或https的PAGE\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","PAGE=\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#BAKCOMMFLAG:是否启用备机0-不启用 1-启用\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","BAKCOMMFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#HOSTNAMEFLAG:是否启用域名解析0-不启用 1-启用\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","HOSTNAMEFLAG=0\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#SSLFLAG:是否启用SSL 0-不启用 1-启用\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","SSLFLAG=1\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#TCPTIMEOUT:网络超时时间\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","TCPTIMEOUT=60\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#SSLTIMEOUT:SSL网络超时时间\n");
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
    FuncFunc : 初始化HTTP通讯信息
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
unsigned char Trans_SetHttpComm( void )
{
	unsigned char ucRetCode = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Trans_SetHttpComm");
	
	AppUtils_DisplayLeft("通讯初始化...\n", LINE2);
	AppUtils_DisplayLeft("请稍候...\n", LINE3);
	
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
    FuncFunc : 获取测试项目配置信息
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
unsigned char Trans_GetCfgInfor( void )
{
	unsigned char aucFileName[100];		/*配置文件名*/
	unsigned char aucSectionName[100];	/*节名*/
	unsigned char aucKeyName[100];		/*键名*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];		/*键值*/
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

	/*获取当前通讯类型*/
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

	/*获取COMMPORT*/
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

	/*获取BAUDRATE*/
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
	
	/*获取IP1*/
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

	/*获取PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT1[%s]!",aucKeyValue);
	}

	/*获取IP2*/
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
	
	/*获取PORT2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPHostPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT2[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时是否支持库的协议0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPLIBFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x04;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPLIBFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时URL是否自解析0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x01;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https是否支持URL自解析失败后尝试Host IP/Name 0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLCOMMFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x02;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLCOMMFLAG[%s]!",aucKeyValue);
	}

	/*http或https接收的包是否不自解析:0-不解析 1-解析*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOHTTPPARSEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x08;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOHTTPPARSEFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时请求方法:0-POST方法 1-GET方法*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPWAYFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucRequestWayFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPWAYFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https的URL*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","URL");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=256) ) )
	{
		strcpy(g_mTermCfg.aucHttpURL,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "URL[%s]!",aucKeyValue);
	}

	/*获取http或https的DOMAIN*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","DOMAIN");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpDomain,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DOMAIN[%s]!",aucKeyValue);
	}

	/*获取http或https的PAGE*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PAGE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpPage,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PAGE[%s]!",aucKeyValue);
	}

	/*获取HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME1[%s]!",aucKeyValue);
	}

	/*获取HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME2[%s]!",aucKeyValue);
	}

	/*获取BakCommFlag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucBakCommFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%s]!",aucKeyValue);
	}

	/*获取HOSTNAMEFLAG*/
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

	/*获取RS232Timeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","RS232TIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usRS232Timeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "RS232Timeout[%s]!",aucKeyValue);
	}

	/*获取TcpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TcpTimeout[%s]!",aucKeyValue);
	}

	/*获取SSLFLAG*/
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

	/*获取SSLTimeout*/
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
	FuncFunc : 获取交易类型对应的中文名称
	Input	 : unsigned char	— ucTransType			交易类型
	Output	 : unsigned char *	— pucOutputTransName	交易类型对应的中文名称
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
      sprintf(pucOutputTransName, "%s",  "签到");
      break;
    case TTYPE_LOGOUT:
      sprintf(pucOutputTransName, "%s",  "签退");
      break;
    case TTYPE_AID_INQUERY:
      sprintf(pucOutputTransName, "%s",  "EMV参数下载请求");
      break;
    case TTYPE_AID_UPDATE:
      sprintf(pucOutputTransName, "%s",  "EMV参数下载");
      break;
    case TTYPE_AID_END:
      sprintf(pucOutputTransName, "%s",  "EMV参数下载结束");
      break;
    case TTYPE_CAKEY_INQUERY:
      sprintf(pucOutputTransName, "%s",  "EMV公钥下载请求");
      break;
    case TTYPE_CAKEY_UPDATE:
      sprintf(pucOutputTransName, "%s",  "EMV公钥下载");
      break;
    case TTYPE_CAKEY_END:
      sprintf(pucOutputTransName, "%s",  "EMV公钥下载结束");
      break;
    case TTYPE_SALE:
      sprintf(pucOutputTransName, "%s",  "消费");
      break;
    case TTYPE_LOGON_CASHIER:
      sprintf(pucOutputTransName, "%s",  "收银员积分签到");
      break;
    case TTYPE_SETTLE:
      sprintf(pucOutputTransName, "%s",  "结算");
      break;
    case TTYPE_SETTLE_END:
      sprintf(pucOutputTransName, "%s",  "批上送结束");
      break;
    case TTYPE_BATCH_UPLOAD:
      sprintf(pucOutputTransName, "%s",  "批上送");
      break;
    case TTYPE_SCRIPTADVICE:
      sprintf(pucOutputTransName, "%s",  "脚本结果通知");
      break;
    case TTYPE_ICOFFLINE_UPLOAD:
      sprintf(pucOutputTransName, "%s",  "IC卡脱机交易上送");
      break;
    case TTYPE_TC_UPLOAD:
      sprintf(pucOutputTransName, "%s",  "IC卡TC上送");
      break;
    case TTYPE_DOWNLOAD_PARAMETERS:
      sprintf(pucOutputTransName, "%s",  "参数下载");
      break;
	case TTYPE_QPS_PARAMETERS_DOWNLOAD:
	  sprintf(pucOutputTransName, "%s",  "非接参数下载");
	  break;
    case TTYPE_UPLOAD_STATUS:
      sprintf(pucOutputTransName, "%s",  "状态上送");
      break;
    case TTYPE_ECHO_TESTING:
      sprintf(pucOutputTransName, "%s",  "回响测试");
      break;
    case TTYPE_DOWNLOAD_END:
      sprintf(pucOutputTransName, "%s",  "参数下载结束");
      break;
    case TTYPE_BALANCE:
      sprintf(pucOutputTransName, "%s",  "余额查询");
      break;
    case TTYPE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "消费撤销");
      break;
    case TTYPE_REFUND:
      sprintf(pucOutputTransName, "%s",  "退货");
      break;
    case TTYPE_PREAUTH:
      sprintf(pucOutputTransName, "%s",  "预授权");
      break;
    case TTYPE_PREAUTH_VOID:
      sprintf(pucOutputTransName, "%s",  "预授权撤销");
      break;
    case TTYPE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "预授权完成请求");
      break;
    case TTYPE_COMPLETE_VOID:
      sprintf(pucOutputTransName, "%s",  "预授权完成撤销");
      break;
    case TTYPE_OFFLINE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "预授权完成通知");
      break;
    case TTYPE_OFFLINE_SETTLE:
      sprintf(pucOutputTransName, "%s",  "离线结算");
      break;
    case TTYPE_OFFLINE_ADJUST:
      sprintf(pucOutputTransName, "%s",  "结算调整");
      break;
    case TTYPE_ECASH_CASH_RELOAD:
      sprintf(pucOutputTransName, "%s",  "现金充值");
      break;
    case TTYPE_ECASH_CASH_RELOAD_VOID:
      sprintf(pucOutputTransName, "%s",  "现金充值撤销");
      break;
    case TTYPE_ECASH_IN_RELOAD:
      sprintf(pucOutputTransName, "%s",  "指定账户圈存");
      break;
    case TTYPE_ECASH_OUT_RELOAD:
      sprintf(pucOutputTransName, "%s",  "非指定账户圈存");
      break;
    case TTYPE_ECASH_REFUND:
      sprintf(pucOutputTransName, "%s",  "电子现金脱机退货");
      break;
    case TTYPE_MAG_ACCT_VERIFY:
      sprintf(pucOutputTransName, "%s",  "磁条现金充值验证");
      break;
    case TTYPE_MAG_CASHLOAD:
      sprintf(pucOutputTransName, "%s",  "磁条卡现金充值");
      break;
    case TTYPE_MAG_CASHLOAD_CONFIRM:
      sprintf(pucOutputTransName, "%s",  "磁条现金充值确认");
      break;
    case TTYPE_MAG_ACCTLOAD:
      sprintf(pucOutputTransName, "%s",  "磁条卡账户充值");
      break;
    case TTYPE_INSTALLMENT:
      sprintf(pucOutputTransName, "%s",  "分期付款");
      break;
    case TTYPE_INSTALLMENT_VOID:
      sprintf(pucOutputTransName, "%s",  "分期付款撤销");
      break;
    case TTYPE_YUYUE_SALE:
      sprintf(pucOutputTransName, "%s",  "预约消费");
      break;
    case TTYPE_YUYUE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "预约消费撤销");
      break;
    case TTYPE_ISSUER_SCORE_SALE:
      sprintf(pucOutputTransName, "%s",  "发卡行积分消费");
      break;
    case TTYPE_ISSUER_SCORE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "发卡行积分撤销");
      break;
    case TTYPE_UNION_SCORE_SALE:
      sprintf(pucOutputTransName, "%s",  "联盟积分消费");
      break;
    case TTYPE_UNION_SCORE_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "联盟积分撤销");
      break;
    case TTYPE_UNION_SCORE_BALANCE:
      sprintf(pucOutputTransName, "%s",  "联盟积分查询");
      break;
    case TTYPE_UNION_SCORE_REFUND:
      sprintf(pucOutputTransName, "%s",  "联盟积分退货");
      break;
    case TTYPE_MCHIP_BALANCE:
      sprintf(pucOutputTransName, "%s",  "手机芯片余额查询");
      break;
    case TTYPE_MCHIP_SALE:
      sprintf(pucOutputTransName, "%s",  "手机芯片消费");
      break;
    case TTYPE_MCHIP_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "手机芯片消费撤销");
      break;
    case TTYPE_MCHIP_REFUND:
      sprintf(pucOutputTransName, "%s",  "手机芯片退货");
      break;
    case TTYPE_MCHIP_PREAUTH:
      sprintf(pucOutputTransName, "%s",  "手机芯片预授权");
      break;
    case TTYPE_MCHIP_PREAUTH_VOID:
      sprintf(pucOutputTransName, "%s",  "手机芯片授权撤销");
      break;
    case TTYPE_MCHIP_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "手机芯片完成请求");
      break;
    case TTYPE_MCHIP_COMPLETE_VOID:
      sprintf(pucOutputTransName, "%s",  "手机芯片完成撤销");
      break;
    case TTYPE_MCHIP_OFFLINE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "手机芯片完成通知");
      break;
    case TTYPE_ORDER_SALE:
      sprintf(pucOutputTransName, "%s",  "订购消费");
      break;
    case TTYPE_ORDER_SALE_VOID:
      sprintf(pucOutputTransName, "%s",  "订购消费撤销");
      break;
    case TTYPE_ORDER_REFUND:
      sprintf(pucOutputTransName, "%s",  "订购退货");
      break;
    case TTYPE_ORDER_PREAUTH:
      sprintf(pucOutputTransName, "%s",  "订购预授权");
      break;
    case TTYPE_ORDER_PREAUTH_VOID:
      sprintf(pucOutputTransName, "%s",  "订购预授权撤销");
      break;
    case TTYPE_ORDER_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "订购完成请求");
      break;
    case TTYPE_ORDER_COMPLETE_VOID:
      sprintf(pucOutputTransName, "%s",  "订购完成撤销");
      break;
    case TTYPE_ORDER_OFFLINE_COMPLETE:
      sprintf(pucOutputTransName, "%s",  "订购完成通知");
      break;
    case TTYPE_ORDER_CARDHOLDER_VERIFY:
      sprintf(pucOutputTransName, "%s",  "持卡人信息验证");
      break;
    case TTYPE_TMS_UPDATE_PARAMETER:
      sprintf(pucOutputTransName, "%s",  "更新TMS");
      break;
    case TTYPE_TC_UPLOAD_END:
      sprintf(pucOutputTransName, "%s",  "IC卡TC上送完成");
      break;
    case TTYPE_REVERSAL:
      sprintf(pucOutputTransName, "%s",  "冲正");
      break;
    case TTYPE_BLACK_UPDATE:
      sprintf(pucOutputTransName, "%s",  "黑名单下载");
      break;
    case TTYPE_BLACK_END:
      sprintf(pucOutputTransName, "%s",  "黑名单下载结束");
      break;
    case TTYPE_ECASH_BALANCE:
      sprintf(pucOutputTransName, "%s",  "电子现金查询余额");
      break;
	case TTYPE_LINK:
      sprintf(pucOutputTransName, "%s",  "线路链接");
      break;
	case TTYPE_CANCEL:
      sprintf(pucOutputTransName, "%s",  "取消交易");
      break;
	case TTYPE_GETBATTERY:
      sprintf(pucOutputTransName, "%s",  "获取电量");
      break;
	case TTYPE_GETAPPVER:
      sprintf(pucOutputTransName, "%s",  "获取版本");
      break;
	case TTYPE_GETAPPINFO:
      sprintf(pucOutputTransName, "%s",  "获取应用信息");
      break;
	case TTYPE_TRANS_INQUIRY:
	  sprintf(pucOutputTransName, "%s",  "交易查询");
      break;
	case TTYPE_GETPRINTINFO:
	  sprintf(pucOutputTransName, "%s",  "取交易信息打印");
      break;
	case TTYPE_GETREPRINTINFO:
	  sprintf(pucOutputTransName, "%s",  "取交易信息重打印");
	  break;
	case TTYPE_GETSETTLEINFO:
	  sprintf(pucOutputTransName, "%s",  "取结算信息打印");
	  break;
	case TTYPE_GETRESETTLEINFO:
	  sprintf(pucOutputTransName, "%s",  "取结算信息重打印");
	  break;
	case TTYPE_ORDER_INQUIRY:
      sprintf(pucOutputTransName, "%s",  "订单查询");
      break;	   
	case TTYPE_GETPARAM:
      sprintf(pucOutputTransName, "%s",  "参数获取");
      break;
	case TTYPE_SETPARAM:
      sprintf(pucOutputTransName, "%s",  "参数设置");
      break;
	case TTYPE_BARSCAN:
      sprintf(pucOutputTransName, "%s",  "条码获取");
      break;
	case TTYPE_BARCLOSE:
      sprintf(pucOutputTransName, "%s",  "条码枪关闭");
      break;
	case TTYPE_SETRSAKEY:
      sprintf(pucOutputTransName, "%s",  "设置RSA公钥");
      break;
	case TTYPE_GETCARDINFO:
      sprintf(pucOutputTransName, "%s",  "卡信息获取");
      break;
	case TTYPE_ACTIVATE:
	  sprintf(pucOutputTransName, "%s",  "卡激活");
      break;
	case TTYPE_INACTIVATE:
	  sprintf(pucOutputTransName, "%s",  "卡激活撤销");
      break;
	case TTYPE_CARDQUERY:
	  sprintf(pucOutputTransName, "%s",  "卡状态查询");
      break;
	case TTYPE_POSINIT:
      sprintf(pucOutputTransName, "%s",  "新装机初始化");
      break;
	case TTYPE_DOWNKEY:
      sprintf(pucOutputTransName, "%s",  "下载密钥");
      break;
	case TTYPE_ONLINEREG:
      sprintf(pucOutputTransName, "%s",  "联机注册");
      break;
	case TTYPE_ONLINEREPORT:
      sprintf(pucOutputTransName, "%s",  "联机报到");
      break;
	case TTYPE_REPLACEPOS:
      sprintf(pucOutputTransName, "%s",  "换机");
      break;
	case TTYPE_TEST:
      sprintf(pucOutputTransName, "%s",  "测试");
      break;
	case TTYPE_UPDATEAPP:
      sprintf(pucOutputTransName, "%s",  "固件升级");
      break;
	case TTYPE_GETDATATYPE:
      sprintf(pucOutputTransName, "%s",  "数据类型长度");
      break;
	case TTYPE_RSATEST:
      sprintf(pucOutputTransName, "%s",  "测试RSA算法");
      break;
	case TTYPE_TESTSERVER:
      sprintf(pucOutputTransName, "%s",  "测试服务器");
      break;
	case TTYPE_TCPSERVER1:
      sprintf(pucOutputTransName, "%s",  "TCP服务器");
      break;
	case TTYPE_EMAIL:
      sprintf(pucOutputTransName, "%s",  "发送邮件");
      break;
	case TTYPE_TESTHTTP:
      sprintf(pucOutputTransName, "%s",  "HTTP测试");
      break;	  
	case TTYPE_FTP_DOWNLOADFILE:
      sprintf(pucOutputTransName, "%s",  "FTP下载文件");
      break;
	case TTYPE_FTP_UPLOADFILE:
      sprintf(pucOutputTransName, "%s",  "FTP上传文件");
      break;
    default:
      sprintf(pucOutputTransName, "%s",  "未知交易");
      break;
  }
  
  return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_DisplayTransName
	FuncFunc : 显示交易类型
	Input	 : unsigned char	— ucTransType			交易类型
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	FuncFunc : 测试服务器IP
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	ucRetCode = AppUtils_GetIpAddress(LINE2,"请输入服务器地址:",60,aucTmpBuf);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) || (strlen(aucTmpBuf)>16) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetIpAddress fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("获取服务器地址失败,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	strcpy(aucTcpIp,aucTmpBuf);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	ucRetCode = AppUtils_GetNum(LINE2,"请输入服务器端口:",aucTmpBuf,1,6,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) || (strlen(aucTmpBuf)>6) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetNum fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("获取服务器端口失败,ucRetCode[%d]\n",ucRetCode);
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
		AppUtils_Warning("初始化失败");
		return ucRetCode;
	}
	
	/*检查网络*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect [%s:%d] fail,ucRetCode[0x%02X]!",aucTcpIp,usTCPHostPort,ucRetCode);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode,aucTmpBuf);
		AppUtils_FormatDisp("连接服务器失败[%s:%d],ucRetCode[%d:%s]\n",aucTcpIp,usTCPHostPort,ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		//AppUtils_Warning("连接服务器失败");
		return ucRetCode;
	}
	
	Comm_Disconnect(0);
	
	AppUtils_FormatDisp("测试服务器成功[%s:%d]\n",aucTcpIp,usTCPHostPort);
	AppUtils_WaitKey(5);
	//AppUtils_Warning("测试服务器成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_EchoTesting
	FuncFunc : 回响测试交易
	Input	 : void *	— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	
	//检查网络
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
	
	//发送数据包
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag, g_mCurrTrans.ucDataFormat, aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	//接收数据包
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag, g_mCurrTrans.ucDataFormat, g_mTermCfg.usTcpTimeout, aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("接收数据包失败");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("回响测试成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_VerifyData
	FuncFunc : 验证数据交易
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	AppUtils_DisplayCenter("验证数据", LINE1, TRUE);

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

	/*检查网络*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("连接服务器失败");
		return ucRetCode;
	}
	  
	uiSendLen = 0;
	memset(aucSendBuf, 0, sizeof(aucSendBuf));
	memset(aucDataBuf, 0, sizeof(aucDataBuf));
	//strcpy(aucDataBuf,"600006000060320099000208200000000000C0001031313030303238343538353239303034383134303030310011000000013010");
	//strcpy(aucDataBuf,"600002000060000000000007403020000000C9001354000000000000000100026431353030343837395A3033303030303031363435323630183133343730383233333332323935353836370005443730313100089400003200033030313346323732374332");
	uiSendLen = strlen(aucDataBuf)/2;
	Tool_AscToHex(aucDataBuf,uiSendLen,aucSendBuf);
	
	//发送数据包
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	//接收数据包
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("接收数据包失败");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("回响测试成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_Test
	FuncFunc : 回响测试交易
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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

	
	/*检查网络*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("连接服务器失败");
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
	
	//发送数据包
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	//接收数据包
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("接收数据包失败");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("回响测试成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_HttpTesting
	FuncFunc : 测试交易
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
	//unsigned char aucHttpURL[256+1];	/*HTTP服务器URL*/
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
	
	/*检查网络*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_CheckConnect [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("连接服务器失败");
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
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	/*接收数据包*/
	uiRecvLen = 0;
	memset(aucRecvBuf,0,sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf,&uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("接收数据包失败");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("HTTP测试成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_Tcp
	FuncFunc : 回响测试交易
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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

	
	/*检查网络*/
	ucRetCode = Comm_CheckConnect(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckConnect fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("连接服务器失败");
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
	
	/*发送数据包*/
	ucRetCode = Comm_SendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf, uiSendLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_SendPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("发送数据包失败");
		return ucRetCode;
	}
	
	/*接收数据包*/
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_RecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf, &uiRecvLen);
	if( ucRetCode )
	{
		Comm_Disconnect(0);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_RecvPacket [ucRetCode=0x%02X]!",ucRetCode);
		AppUtils_Warning("接收数据包失败");
		return ucRetCode;
	}

	Comm_Disconnect(0);

	AppUtils_Warning("回响测试成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : Trans_Help
    FuncFunc : 项目帮助菜单
	Input	 : void *			— pDummy	参数
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
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
		sprintf(aucTitle,"欢迎%s使用",g_mApp.aucUserName);
		memcpy(aucDispBuf+(61-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
	}
	
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**软件功能:%.58s",DEMOAPP_FUNCTION);
	AppUtils_FormatDisp("**软件版本:%.58s",DEMOAPP_VERSION);  
	AppUtils_FormatDisp("**版权所有:%.58s",DEMOAPP_AUTHOR);
	AppUtils_FormatDisp("**软件联系:%.58s",DEMOAPP_CONTACT);
	AppUtils_FormatDisp("**软件描述:%.58s",DEMOAPP_DESCPTION);
	AppUtils_FormatDisp("**软件发布:%.58s",DEMOAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}
	
/***********************************************************************************************
	FuncName : Trans_Menu
    FuncFunc : 项目应用菜单
	Input	 : void *	— pDummy	入口参数标志
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
unsigned char Trans_Menu(void *pDummy)
{
	unsigned char ucMenuOption = 0;
	unsigned char aucDispTitleBuf[32];
	AppUtils_MenuItem aucMenuItem[] =
	{
		{ 1, "测试服务器",	Trans_TestServer, (void *) 0 },
		{ 2, "回响交易测试",Trans_EchoTesting, (void *) 0 },
		{ 3, "Test",		Trans_Test, (void *) 0 },
		{ 4, "Http",		Trans_HttpTesting, (void *) 0 },
		{ 5, "Tcp",			Trans_Tcp, (void *) 0 },
		{ 6, "帮助",    	Trans_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "测试项目应用");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}


