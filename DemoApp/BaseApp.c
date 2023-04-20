/*************************************************************************************************
	FileName : BaseApp.c
    FileFunc : 实现基础测试应用接口
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2018-09-08 11:13:15
	Descp    : 实现基础项目应用入口函数
    History  : None
	Other    : None
*************************************************************************************************/
#include "define.h"


/***********************************************************************************************
	FuncName : BaseApp_GetCommCfg
    FuncFunc : 获取基础项目通讯配置信息
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
unsigned char BaseApp_GetCommCfg(void *pDummy)
{
	unsigned char aucFileName[100];		/*配置文件名*/
	unsigned char aucSectionName[100];	/*节名*/
	unsigned char aucKeyName[100];		/*键名*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];		/*键值*/
	unsigned char ucRetCode = APP_FAILURE;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter BaseApp_GetCommCfg!");

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	
	if( APP_SUCCESS!=Tool_IsExistFile(GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME,0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BaseApp_GetCommCfg fail!");
		return APP_FAILURE;
	}
	
	//memset(&g_mApp,0,sizeof(App_Prm));
	//Tool_GetCurrentDate(0,g_mApp.aucCurrDate);

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s%s",GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME);
	
	memset(aucSectionName,0,sizeof(aucSectionName));
	sprintf(aucSectionName,"%s",DEMOAPP_APPCOMMSECNAME);

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

		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "CurrentCommMode[%s]!",aucKeyValue);
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

			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "COMMPORT[%s]!",aucKeyValue);
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
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BAUDRATE[%s]!",aucKeyValue);
			
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "IP1[%s]!",aucKeyValue);
	}

	/*获取PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usTCPHostPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT1[%s]!",aucKeyValue);
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
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "IP2[%s]!",aucKeyValue);
	}
	
	/*获取PORT2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usTCPHostPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PORT2[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时是否支持库的协议0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPLIBFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x04;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPLIBFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时URL是否自解析0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x01;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https是否支持URL自解析失败后尝试Host IP/Name 0-不支持 1-支持*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOURLCOMMFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x02;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOURLCOMMFLAG[%s]!",aucKeyValue);
	}

	/*http或https接收的包是否不自解析:0-不解析 1-解析*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","AUTOHTTPPARSEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucSelfProtocolFlag = g_mTermCfg.ucSelfProtocolFlag | 0x08;
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AUTOHTTPPARSEFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https通讯时请求方法:0-POST方法 1-GET方法*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HTTPWAYFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucRequestWayFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HTTPWAYFLAG[%s]!",aucKeyValue);
	}

	/*获取http或https的URL*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","URL");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=256) ) )
	{
		strcpy(g_mTermCfg.aucHttpURL,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "URL[%s]!",aucKeyValue);
	}

	/*获取http或https的DOMAIN*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","DOMAIN");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpDomain,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DOMAIN[%s]!",aucKeyValue);
	}

	/*获取http或https的PAGE*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","PAGE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucHttpPage,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "PAGE[%s]!",aucKeyValue);
	}

	/*获取HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME1[%s]!",aucKeyValue);
	}

	/*获取HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPDomainName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "HOSTNAME2[%s]!",aucKeyValue);
	}
	
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);

	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucBakCommFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%s]!",aucKeyValue);
	}

	/*获取HOSTNAMEFLAG主机域名标志*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","HOSTNAMEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "DomainNameFlag[%s]!",aucKeyValue);
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
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usRS232Timeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "RS232Timeout[%s]!",aucKeyValue);
	}

	/*获取TcpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usTcpTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TcpTimeout[%s]!",aucKeyValue);
	}

	/*获取SSL通讯标志*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLFlag[%s]!",aucKeyValue);
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
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usSSLTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLTimeout[%s]!",aucKeyValue);
	}

	/*服务器设定的IP*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPServerIP1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerIP[%s]!",aucKeyValue);
	}

	/*服务器监听PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerPort");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usTCPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerPort[%s]!",aucKeyValue);
	}

	/*TCP服务器阻塞时超时时间(S)*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerBlockTimeout");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usTcpServerBlockTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerBlockTimeout[%s]!",aucKeyValue);
	}

	/*获取FTP IP1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPIP1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPServerIP1,0,sizeof(g_mTermCfg.aucFTPServerIP1));
		memcpy(g_mTermCfg.aucFTPServerIP1,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP IP1[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPServerIP1,"127.0.0.1");
	}

	/*获取FTP PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usFTPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP PORT1[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerPort1 = 21;
	}

	/*获取FTP IP2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPIP2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPServerIP2,0,sizeof(g_mTermCfg.aucFTPServerIP2));
		memcpy(g_mTermCfg.aucFTPServerIP2,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP IP2[%s]!",aucKeyValue);
	}
	
	/*获取FTP PORT2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usFTPServerPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP PORT2[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerPort2 = 21;
	}
	
	/*获取FTP HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPHostName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP HOSTNAME1[%s]!",aucKeyValue);
	}

	/*获取FTP HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucFTPHostName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP HOSTNAME2[%s]!",aucKeyValue);
	}

	/*获取FTP BakCommFlag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPBakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);

	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPSockBakFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP BakCommFlag[%s]!",aucKeyValue);
	}

	/*获取FTP HOSTNAMEFLAG*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAMEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP DomainNameFlag[%s]!",aucKeyValue);
		g_mTermCfg.ucFTPHostNameFlag = atoi((char *)aucKeyValue);
	}
	else
	{
		g_mTermCfg.ucFTPHostNameFlag = 0;
	}

	/*获取FTP USER*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPUSER");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPUserName,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP User[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPUserName,"ftpuser");
	}

	/*获取FTP USERPASSWORD*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPWD");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPUserPassword,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Password[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPUserPassword,"ftpuser");
	}

	/*获取FTP Local IP*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPLOCALIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPLocalIP,0,sizeof(g_mTermCfg.aucFTPLocalIP));
		memcpy(g_mTermCfg.aucFTPLocalIP,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Local IP[%s]!",aucKeyValue);
	}
	
	/*获取FtpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue,0)) )
	{
		g_mTermCfg.usFTPServerTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpTimeout[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerTimeout = 120;
	}

	/*获取FTP Local PATH*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPLOCALPATH");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=128) ) )
	{
		strcpy(g_mTermCfg.aucFTPLocalPath,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Local PATH[%s]!",aucKeyValue);
	}
	else
	{
		//strcpy(g_mTermCfg.aucFTPLocalPath,"./");
		strcpy(g_mTermCfg.aucFTPLocalPath,"D:\\FTP\\upload");
	}

	/*获取FTP Remote PATH*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPREMOTEPATH");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=128) ) )
	{
		strcpy(g_mTermCfg.aucFTPRemotePath,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Remote PATH[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPRemotePath,"download");
	}

	/*FTP File type*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPFILETYPE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && (('I'==aucKeyValue[0]) || ('A'==aucKeyValue[0]) || ('E'==aucKeyValue[0])))
	{
		g_mTermCfg.aucFTPFileType[0] = aucKeyValue[0];
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP File Type[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.aucFTPFileType[0] = 'I';
	}

	/*FTP Support file null flag */
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPFILENULLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && (('0'==aucKeyValue[0]) || ('1'==aucKeyValue[0]) ) )
	{
		g_mTermCfg.ucFTPFileNullFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP FileNullFlag[%s]!",aucKeyValue);
	}

	/*FTP Upload tmp file flag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPUPLOADTMPFILEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPUploadTmpFileFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP UploadTmpFileFlag[%s]!",aucKeyValue);
	}

	/*FTP Del Remote file flag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPDELREMOTEFILEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPDelRemoteFileFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP DelRemoteFileFlag[%s]!",aucKeyValue);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : BaseApp_InitComm
    FuncFunc : 初始化通讯信息
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
unsigned char BaseApp_InitComm( void )
{
	unsigned char ucRetCode = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter BaseApp_InitComm");
	
	AppUtils_DisplayLeft("通讯初始化...\n", LINE2);
	AppUtils_DisplayLeft("请稍候...\n", LINE3);
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitComm!");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "CommPort[COM%d],BaudRate[%d]!",g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate);
	
	ucRetCode = Comm_InitComm(g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate,g_mTermCfg.usRS232Timeout);	
	if( APP_SUCCESS==ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitSock!");
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%d],TCPIP1[%s],TCPHostPort1[%d],TCPIP2[%s],TCPHostPort2[%d],SelfHttpProtocolFlag[%d],HttpURL[%s],HttpRequestWayFlag[%d],TCPServerIP[%s],TCPServerPort[%d],TcpServerBlockTimeout[%d]!",
							g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,
							g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);

		ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
	}

	if( !ucRetCode )
	{
		ucRetCode = Comm_InitFtp(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.ucFTPSockBakFlag,g_mTermCfg.aucFTPServerIP2,g_mTermCfg.usFTPServerPort2,g_mTermCfg.ucFTPHostNameFlag,g_mTermCfg.aucFTPHostName1,g_mTermCfg.aucFTPHostName2,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalIP,g_mTermCfg.usFTPServerTimeout);
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BaseApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : BaseApp_GetCfg
    FuncFunc : 获取基础项目配置信息
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
unsigned char BaseApp_GetCfg(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	if( ((void *) 0==pDummy) || ((void *) 3==pDummy) )
	{
		ucRetCode = BaseApp_GetCommCfg(pDummy);
	} 
#if 0
	else if( (void *) 1==pDummy )
	{
		ucRetCode = BaseApp_GetCardCfg(pDummy);
	}
#endif

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : BaseApp_Init
    FuncFunc : 基础项目应用初始化
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
unsigned char BaseApp_Init(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,3,DEBUG, "Enter BaseApp_Init!");

	ucRetCode = BaseApp_GetCfg(pDummy);

	if( (void *) 3==pDummy )
	{
		ucRetCode = BaseApp_InitComm();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BaseApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
			return ucRetCode;
		}
	}

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : BaseApp_DataType
    FuncFunc : 基础数据类型长度
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
unsigned char BaseApp_DataType(void *pDummy)
{
	char *pcPrt  = NULL;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter BaseApp_DataType!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_GETDATATYPE;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);
	
	printf("char[%d]\n",sizeof(char));
	printf("unsigned char[%d]\n",sizeof(unsigned char));
	
	printf("short int[%d]\n",sizeof(short int));
	printf("unsigned short int[%d]\n",sizeof(unsigned short int));

	printf("int[%d]\n",sizeof(int));
	printf("unsigned int[%d]\n",sizeof(unsigned int));

	printf("long[%d]\n",sizeof(long));
	printf("unsigned long[%d]\n",sizeof(unsigned long));

	//printf("long long[%d]\n",sizeof(long long));

	printf("float[%d]\n",sizeof(float));
	printf("double[%d]\n",sizeof(double));

	printf("pcPrt[%d]\n",sizeof(*pcPrt));
	
	AppUtils_WaitKey(0);

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : BaseApp_RsaTest
    FuncFunc : RSA测试
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
unsigned char BaseApp_RsaTest(void *pDummy)
{
	unsigned char ucRetCode = APP_FAILURE;
    int iRet = 0x01;
	unsigned int uiI = 0,uiLen = 0,uiInLen = 0,uiOutLen = 0;
    unsigned int tlen = 0,len = 0;
    unsigned char plaint_buf[128]={0};
    unsigned char cipher_buf[128]={0};
    unsigned char N[256]={0};
    unsigned char D[256]={0};
    unsigned char P[256]={0};
    unsigned char Q[256]={0};
    unsigned char DP[256]={0};
    unsigned char DQ[256]={0};
    unsigned char QINV[256]={0};
    unsigned char E[256]={0};

    const char *p="CAEB9887EB0162A1BCA52C01423ACF995234CA790B43DE9D95C0E6F41A56FAB203F4C5D976F125050F7F0376DD5474619E960F7A3C068FBB896FAB79394F3513";
    const char *q="A2D8D444F55860EEFB8FDE8D273DB48E78712CC07CB7121804848FC328E047707D55B0DD9316B3A1B372883BD87ACD5BEEEFE76E48719C6E66E4EFEAE72446E5";
    const char *dp="8747BB05475641C1286E1D562C273510E17886FB5CD7E9BE63D5EF4D66E4A72157F883E64F4B6E035FAA024F3E384D9669B95FA6D2AF0A7D064A7250D0DF78B7";
    const char *dq="6C908D834E3AEB49FD0A945E1A292309A5A0C8805324B6BAADADB52CC5EADA4AFE392093B76477C1224C5AD29051DE3D49F544F4304BBD9EEF434A9C9A182F43";
    const char *qinv="20C541FEFC7EBE9F1E2CC6974A8A1CF6312380D145B38BA5786B17D65279E9777646580E09C80C7698B68D19DC263071FD7D3F01F06A20352CD1EE18163D6DC7";
    const char *n="8114F59078C3C3196E26BF502B2D68CD13FDBE683DF3A7A8F45044ADCF1335A71D64FA39FD1992E42EEE60268BECB6868B9384DFFEEB511747A4F886F63E49A1D88A8CACCC067AE28F38328A1EBB43308A4F825B5FD0DAB8D204B0712FA0438749A73939AB6375919223906BC84F3F554A8E10F27C47D6EF256951818809ABFF";
    const char *d="560DF90AFB2D2CBB9EC47F8AC7739B3362A9299AD3F7C51B4D8AD873DF6223C4BE43517BFE110C981F49956F07F32459B2625895549CE0BA2FC35059F97EDBC0472EBFEA9D1DCF8BE4ACC55278D72A05D51BB2168FE3F1577A7F7BD1484600EDDAE881AC6B92689C8A21587B61AAA90FD35ABC06A5351C8378B87968EFB9755B";
    const char *e = "00000003";    
    RSAPUBLICKEY_PRM rsa_pub_key;
    RSAPRIVATEKEY_PRM rsa_pri_key;


	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter BaseApp_DataType!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_RSATEST;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

    memset(&rsa_pub_key,0,sizeof(rsa_pub_key));
    memset(&rsa_pri_key,0,sizeof(rsa_pri_key));

    //填充公钥
    rsa_pub_key.uiBits = 1024;
    len = strlen(n);
	Tool_StrToHex((char *)n,len/2,N);
	len = len/2;
    memcpy(&rsa_pub_key.aucModulus[256 - len], N, len);
	
	len = strlen(e);
    Tool_StrToHex((char *)e,len/2,E);
	len = len/2;
    memcpy(&rsa_pub_key.aucExponent[256 - len], E, len);
    Tool_DisplayHexData("rsa_pub_key.modulus:",rsa_pub_key.aucModulus,256);
    Tool_DisplayHexData("rsa_pub_key.exponent:",rsa_pub_key.aucExponent,256);

    //填充私钥
    rsa_pri_key.uiBits = 1024;
	
	len = strlen(p);
    Tool_StrToHex((char *)p,len/2,P);
	len = len/2;
    memcpy(&rsa_pri_key.aucPrime[0][128 - len], P, len);

	len = strlen(q);
    Tool_StrToHex((char *)q,len/2,Q);
	len = len/2;
    memcpy(&rsa_pri_key.aucPrime[1][128 - len], Q, len);
	
	len = strlen(dp);
    Tool_StrToHex((char *)dp,len/2,DP);
	len = len/2;
    memcpy(&rsa_pri_key.aucPrimeExponent[0][128 - len], DP, len);

	len = strlen(dq);
    Tool_StrToHex((char *)dq,len/2,DQ);
	len = len/2;
    memcpy(&rsa_pri_key.aucPrimeExponent[1][128 - len], DQ, len);

	len = strlen(qinv);
    Tool_StrToHex((char *)qinv,len/2,QINV);
	len = len/2;
    memcpy(&rsa_pri_key.aucCoefficient[128 - len], QINV, len);

	len = strlen(n);
    Tool_StrToHex((char *)n,len/2,N);
	len = len/2;
    memcpy(&rsa_pri_key.aucModulus[128 - len], N, len);

#if 1
	len = strlen(d);
    Tool_StrToHex((char *)d,len/2,D);
	len = len/2;
    //memcpy(&rsa_pri_key.aucExponent[MAX_RSA_MODULUS_LEN - len], D, len);

	len = strlen(e);
    Tool_StrToHex((char *)e,len/2,E);
	len = len/2;
    //memcpy(&rsa_pri_key.aucPublicExponent[MAX_RSA_MODULUS_LEN - len], E, len);
#endif

    Tool_DisplayHexData("rsa_pri_key.modulus:",rsa_pri_key.aucModulus,256);
    Tool_DisplayHexData("rsa_pri_key.exponent:",rsa_pri_key.aucExponent,256);
    Tool_DisplayHexData("rsa_pri_key.publicExponent:",rsa_pri_key.aucPublicExponent,256);
    Tool_DisplayHexData("rsa_pri_key.prime[0]:",rsa_pri_key.aucPrime[0],128);
    Tool_DisplayHexData("rsa_pri_key.prime[1]:",rsa_pri_key.aucPrime[1],128);
    Tool_DisplayHexData("rsa_pri_key.primeExponent[0]:",rsa_pri_key.aucPrimeExponent[0],128);
    Tool_DisplayHexData("rsa_pri_key.primeExponent[1]:",rsa_pri_key.aucPrimeExponent[1],128);
    Tool_DisplayHexData("rsa_pri_key.coefficient:",rsa_pri_key.aucCoefficient,128);


	printf("---------------------\n");

    memset((void *)(plaint_buf),0x00,sizeof(plaint_buf));

	uiInLen = 38;
    //填充测试数据
    for(uiI=0; uiI<uiInLen; uiI++)
    {
        plaint_buf[uiI] = 0 + uiI*2; 
    }
    Tool_DisplayHexData("plaint_buf1 data:",plaint_buf,uiInLen);

	Tool_DisplayHexData("E:",E,4);
	
    //公钥加密
    //ret = RSAPublicBlock(cipher_buf,&tlen,plaint_buf,128,&rsa_pub_key);
    uiOutLen = 0;
    memset(cipher_buf,0,sizeof(cipher_buf));
    ucRetCode = Tool_RsaPublicKey(0,1024,E,4,N,128,0,plaint_buf,uiInLen,cipher_buf,&uiOutLen);
    printf("RSAPublicBlock ucRetCode[%d]\r\n",ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("cipher data:",cipher_buf,uiOutLen);
    }
	
    //私钥解密
    //ucRetCode = RSAPrivateBlock(plaint_buf, &tlen, cipher_buf, 128, &rsa_pri_key);
    uiInLen = uiOutLen;
    tlen = 0;
    memset(plaint_buf,0,sizeof(plaint_buf));
	//cipher_buf[0] =0x00;
	//cipher_buf[1] =0x02;
    ucRetCode = Tool_RsaPrivateKey(1,1024,N,128,P,64,Q,64,DP,64,DQ,64,QINV,64,0,cipher_buf, uiInLen, plaint_buf, &tlen);
    printf("RSAPrivateBlock ucRetCode[%d,0x%X]\r\n",ucRetCode,ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("plaint data::",plaint_buf,tlen);
    } 
	/*
	0x1C 0x2D 0xB1 0x0A 0x85 0x5E 0xBA 0x4E
0x37 0xEB 0xC1 0xBB 0xAA 0xC7 0xFF 0xCE
0x53 0xBD 0x6B 0x52 0x7D 0x0B 0x68 0x61
0x4F 0xDB 0x90 0xA7 0x56 0x36 0xD8 0xCA
0x06 0x02 0xCA 0x39 0xB9 0xE4 0xCE 0xB4
0xF9 0x9B 0x24 0x17 0x9A 0x00 0xAA 0x53
0xD0 0x6B 0x37 0x7F 0xC5 0xAB 0x35 0x69
0x42 0x8E 0xCF 0xC1 0x06 0x34 0x08 0xD5
0xD3 0x44 0xDC 0xFA 0xB6 0x17 0x1F 0x06
0x2A 0x9B 0x28 0xA9 0x3B 0xA6 0xA4 0xB9
0x80 0x0E 0x1D 0x32 0xE5 0x60 0x29 0xC5
0x34 0x05 0xE5 0x87 0xF1 0x9F 0x90 0xCA
0xEC 0x88 0xAA 0x91 0xEF 0xA8 0x35 0x82
0x1D 0x38 0x8C 0xDF 0xA2 0x1E 0xC8 0x03
0x85 0xC7 0x45 0x49 0x9C 0xBF 0xFD 0xB1
0x03 0xBB 0x0E 0x73 0x43 0x23 0xA4 0xA2

RSAPrivateBlock ret[0][0x0]
plaint data::  Length:39
0x0A 0x0B 0x0C 0x0D 0x0E 0x0F 0x10 0x11
0x12 0x13 0x14 0x15 0x16 0x17 0x18 0x19
0x1A 0x1B 0x1C 0x1D 0x1E 0x1F 0x20 0x21
0x22 0x23 0x24 0x25 0x26 0x27 0x28 0x29
0x2A 0x2B 0x2C 0x2D 0x2E 0x2F 0x30

0A0B0C0D0E0F101112131415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F30
	*/
	
	//return 0;

    memset(&plaint_buf, 0, sizeof(plaint_buf));
    memset(&cipher_buf, 0, sizeof(cipher_buf));

    //填充测试数据
    uiInLen = 42;
    for(uiI=0; uiI<uiInLen; uiI++)
    {
        plaint_buf[uiI] = 20+uiI; 
    }
    Tool_DisplayHexData("plaint_buf2 data:", plaint_buf,uiInLen);

    //私钥加密
    //ret = RSAPrivateBlock(cipher_buf, &tlen, plaint_buf, 128, &rsa_pri_key);
    tlen = 0;
    memset(cipher_buf, 0, sizeof(cipher_buf));
    ucRetCode = Tool_RsaPrivateKey(0,1024,N,128,P,64,Q,64,DP,64,DQ,64,QINV,64,0,plaint_buf, uiInLen, cipher_buf, &tlen);
    printf("RSAPrivateBlock ucRetCode[%d]\r\n",ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("cipher data:", cipher_buf, tlen);
    }

    //公钥解密
    //ret = RSAPublicBlock(plaint_buf, &tlen, cipher_buf, 128, &rsa_pub_key);
    len = 0;
	memset(plaint_buf, 0, sizeof(plaint_buf));
    ucRetCode = Tool_RsaPublicKey(1,1024,E,4,N,128,0,cipher_buf,tlen,plaint_buf,&len);
    printf("RSAPublicBlock ucRetCode[%d]\r\n",ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("cipher data:",plaint_buf,len);
    }

	return 0;

	//输入加密数据不足128需要补齐
	memset((void *)(plaint_buf),0x00,sizeof(plaint_buf));
    //填充测试数据
    for(uiI=0; uiI<37; uiI++)
    {
        plaint_buf[uiI] = 23 + uiI; 
    }
    Tool_DisplayHexData("plaint_buf1 data:",plaint_buf,sizeof(plaint_buf));
	
    //公钥加密
    //ucRetCode = RSAPublicBlock(cipher_buf,&tlen,plaint_buf,128,&rsa_pub_key);
    printf("RSAPublicBlock ucRetCode[%d]\r\n",ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("cipher data:",cipher_buf,sizeof(cipher_buf));
    }
	
    //私钥解密
    //ucRetCode = RSAPrivateBlock(plaint_buf, &tlen, cipher_buf, 128, &rsa_pri_key);
    printf("RSAPrivateBlock ucRetCode[%d]\r\n",ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("plaint data::",plaint_buf,tlen);
    } 

    memset(&plaint_buf, 0, sizeof(plaint_buf));
    memset(&cipher_buf, 0, sizeof(cipher_buf));

    //填充测试数据
    for(uiI=0; uiI<37; uiI++)
    {
        plaint_buf[uiI] = 3+uiI; 
    }
    Tool_DisplayHexData("plaint_buf2 data:", plaint_buf, sizeof(plaint_buf));

    //私钥加密
    //ucRetCode = RSAPrivateBlock(cipher_buf, &tlen, plaint_buf, 128, &rsa_pri_key);
    printf("RSAPrivateBlock ucRetCode[%d]\r\n",ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("cipher data:", cipher_buf, sizeof(cipher_buf));
    }

    //公钥解密
    //ucRetCode = RSAPublicBlock(plaint_buf, &tlen, cipher_buf, 128, &rsa_pub_key);
    printf("RSAPublicBlock ucRetCode[%d]\r\n",ucRetCode);
    if( !ucRetCode )
    {
        Tool_DisplayHexData("cipher data:",plaint_buf,sizeof(plaint_buf));
    }

	/*
rsa_pub_key.modulus::00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000008114F59078C3C3196E26BF502B2D68CD13FDBE683DF3A7A8F45044ADCF1335A71D64FA39FD1992E42EEE60268BECB6868B9384DFFEEB511747A4F886F63E49A1D88A8CACCC067AE28F38328A1EBB43308A4F825B5FD0DAB8D204B0712FA0438749A73939AB6375919223906BC84F3F554A8E10F27C47D6EF256951818809ABFF
rsa_pub_key.exponent::00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003
rsa_pri_key.modulus::00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000008114F59078C3C3196E26BF502B2D68CD13FDBE683DF3A7A8F45044ADCF1335A71D64FA39FD1992E42EEE60268BECB6868B9384DFFEEB511747A4F886F63E49A1D88A8CACCC067AE28F38328A1EBB43308A4F825B5FD0DAB8D204B0712FA0438749A73939AB6375919223906BC84F3F554A8E10F27C47D6EF256951818809ABFF
rsa_pri_key.exponent::0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000560DF90AFB2D2CBB9EC47F8AC7739B3362A9299AD3F7C51B4D8AD873DF6223C4BE43517BFE110C981F49956F07F32459B2625895549CE0BA2FC35059F97EDBC0472EBFEA9D1DCF8BE4ACC55278D72A05D51BB2168FE3F1577A7F7BD1484600EDDAE881AC6B92689C8A21587B61AAA90FD35ABC06A5351C8378B87968EFB9755B
rsa_pri_key.publicExponent::00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003
rsa_pri_key.prime[0]::00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000CAEB9887EB0162A1BCA52C01423ACF995234CA790B43DE9D95C0E6F41A56FAB203F4C5D976F125050F7F0376DD5474619E960F7A3C068FBB896FAB79394F3513
rsa_pri_key.prime[1]::00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000A2D8D444F55860EEFB8FDE8D273DB48E78712CC07CB7121804848FC328E047707D55B0DD9316B3A1B372883BD87ACD5BEEEFE76E48719C6E66E4EFEAE72446E5
rsa_pri_key.primeExponent[0]::000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000008747BB05475641C1286E1D562C273510E17886FB5CD7E9BE63D5EF4D66E4A72157F883E64F4B6E035FAA024F3E384D9669B95FA6D2AF0A7D064A7250D0DF78B7
rsa_pri_key.primeExponent[1]::000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006C908D834E3AEB49FD0A945E1A292309A5A0C8805324B6BAADADB52CC5EADA4AFE392093B76477C1224C5AD29051DE3D49F544F4304BBD9EEF434A9C9A182F43
rsa_pri_key.coefficient::0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000020C541FEFC7EBE9F1E2CC6974A8A1CF6312380D145B38BA5786B17D65279E9777646580E09C80C7698B68D19DC263071FD7D3F01F06A20352CD1EE18163D6DC7
plaint_buf1 data::0A0B0C0D0E0F101112131415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F80818283848586878889
RSAPublicBlock ret[0]
cipher data::42C9AD9A62A7317904C93F002C9A82B21FC2E06C974B0F1BE8FE0AE7E61F9EC886BAA5CF6FE911C39CF86AD922C5355ACF9106C2B698D89C505CADAFF3E6DDBB666C63C4786365E8DBEE2F06834711D536FAA14218DF6A5F87A0ABAA9CD2DD01875E215154658648CDB1D5B314004F5503171405B9443B29B4A41348D4826445
RSAPrivateBlock ret[0]
plaint data:::0A0B0C0D0E0F101112131415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F80818283848586878889
plaint_buf2 data::1415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F808182838485868788898A8B8C8D8E8F90919293
RSAPrivateBlock ret[0]
cipher data::530DB01D193E6E7861722265A246A65D4AAB94E7633AC012B5632F3E3625EF8198B6285FB33E0ED5FF5151F88B813A6317E2FAAF19A206E376E87CC7076A7129CF85655BEE8CF7CCA3CC983C4C68E74E6E6AC43033AE416FAC5A5D91B94DA90CCFD558BDAD0D96F3C80053AC8E65A5E4ED0EF414540E25C2AA754A15CE4946BB
RSAPublicBlock ret[0]
cipher data::1415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F808182838485868788898A8B8C8D8E8F90919293
*/
	
	return APP_SUCCESS;
}


/***********************************************************************************************
	FuncName : BaseApp_ProcData
	FuncFunc : 处理交易
	Input	 : unsigned char *	— pucInputData,输入数据
		       unsigned int		— uiInputDataLen,输入数据长度
	Output	 : unsigned char *	— pucOutputData,输出数据
		       unsigned int		— puiOutputDataLen,输出数据长度
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
 	Author	 : Sunrier
	Date     : 2016-12-28 19:12:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char BaseApp_ProcData(unsigned char *pucInputData,unsigned int uiInputDataLen,unsigned char *pucOutputData,unsigned int *puiOutputDataLen)
{
	unsigned char ucRetCode = APP_SUCCESS;
	//unsigned char aucLineInfoBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	//unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned int uiSendLen = 0;
	//unsigned char ucKeyValue = 0;
	
	unsigned int uiOffset = 0,uiParamLen = 0;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter BaseApp_ProcData!");

	if( !Tool_CheckLogLevel(g_mApp.ucLogLevel,LOG_DEBUG) )
	{
		App_PrintWidthHexAsc("BaseApp_ProcData Recv Packet:",pucInputData, uiInputDataLen);
	}

#if 0
	if( g_mApp.ucDispFlag )
	{
		AppUtils_DisplayHexData("GY_ProcData Recv Packet:",pucInputData, uiInputDataLen);
	}
#endif

	if( (NULL==pucInputData) || (uiInputDataLen<2) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "接收数据包长度[%d]有误!",uiInputDataLen);
		AppUtils_Warning("接收数据包长度有误!");
		return APP_ESC;
	}

	/*根据实际TCP服务器功能加入具体处理细节*/
#if 0
	memset(&g_mGYCurrTrans,0,sizeof(GYTrans_Prm));
	memcpy(g_mGYCurrTrans.aucCmdCode,pucInputData,2);
	if( !memcmp(g_mGYCurrTrans.aucCmdCode,GY_CMDCODE_U1,2) )
	
	else if( !memcmp(g_mGYCurrTrans.aucCmdCode,GY_CMDCODE_EI,2) )
	
	else if( !memcmp(g_mGYCurrTrans.aucCmdCode,GY_CMDCODE_EH,2) )
	
	else
	{
		if( !Tool_CheckLogLevel(g_mApp.ucLogLevel,LOG_DEBUG) )
		{
			memset(aucLineInfoBuf,0,sizeof(aucLineInfoBuf));
			sprintf(aucLineInfoBuf,"无效命令代码:%s\n",g_mGYCurrTrans.aucCmdCode);
			AppUtils_AppendInfoToFile(0, 0, GLOBAL_DEFAULTLOGPATH, g_mApp.aucLogFileName, 0, 0, NULL, aucLineInfoBuf, strlen(aucLineInfoBuf), 0, APP_MAXCOMMBUF);
		}

		return APP_ESC;
	}
#endif
		
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : BaseApp_ServerStart
    FuncFunc : 服务器开启功能
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
unsigned char BaseApp_ServerStart(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS,ucDispFlag = 0;
	//unsigned char aucDataBuf[APP_MAXCOMMBUF+1];
	unsigned char aucSendBuf[APP_MAXCOMMBUF+1];
	unsigned char aucRecvBuf[APP_MAXCOMMBUF+1];
	unsigned int uiDataLen = 0,uiSendLen = 0,uiRecvLen = 0;
	unsigned char aucClientIP[16];
	unsigned short usClientPort;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter BaseApp_ServerStart!");
	
	ucRetCode = BaseApp_Init((void*)3);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BaseApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_TCPSERVER1;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);
	
	if( g_mTermCfg.ucSSLFlag )
	{
		g_mCurrTrans.ucCommFlag = COMM_TCP;
	}
	else
	{
		g_mCurrTrans.ucCommFlag = COMM_TCP;
	}
	
	g_mCurrTrans.ucDataFormat = COMM_FMT_HEXLEN_DATA;
	if( COMM_RS232==g_mCurrTrans.ucCommFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usRS232Timeout;
	}
	else if( COMM_TCP==g_mCurrTrans.ucCommFlag )
	{
		g_mCurrTrans.usTimeout = g_mTermCfg.usTcpTimeout;
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

RESTART:
	
	//开启Server服务
	AppUtils_DisplayLeft("开启服务器...",LINE2);
	ucRetCode = Comm_StartServer(g_mCurrTrans.ucCommFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_StartServer fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

RELISTEN:
	//判断是否接收到一个客户端的连接
	AppUtils_DisplayLeft("检查客户端...",LINE2);
	while(1)
	{
		usClientPort = 0;
		memset(aucClientIP,0,sizeof(aucClientIP));
		ucRetCode = Comm_CheckServerAccept(g_mCurrTrans.ucCommFlag,aucClientIP,&usClientPort);
		if( APP_SUCCESS==ucRetCode )
		{
			break;
		}
		else if( 0x8C==ucRetCode )
		{
			Comm_StopServer(g_mCurrTrans.ucCommFlag);
			goto RESTART;
		}

		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_CheckServerAccept fail,ucRetCode[0x%02X]!",ucRetCode);
	}

	if( g_mApp.ucCNTipFlag )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "客户端地址[%s],客户端端口号[%d]!",aucClientIP,usClientPort);
	}
	else
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Client IP[%s],Client Port[%d]!",aucClientIP,usClientPort);
	}
	
	//server接收客户端通讯数据包
	uiRecvLen = 0;
	memset(aucRecvBuf, 0, sizeof(aucRecvBuf));
	ucRetCode = Comm_ServerRecvPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,g_mCurrTrans.usTimeout,aucRecvBuf, &uiRecvLen);
	if( APP_TIMEOUT==ucRetCode )
	{
		Comm_StopClient(g_mCurrTrans.ucCommFlag);
		goto RELISTEN;
	}
	else if( ucRetCode )
	{
		Comm_StopServer(g_mCurrTrans.ucCommFlag);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_ServerRecvPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_Warning("服务器接收客户端数据包失败");
		return ucRetCode;
	}

	uiSendLen = 0;
	memset(aucSendBuf,0,sizeof(aucSendBuf));
	ucRetCode = BaseApp_ProcData(aucRecvBuf,uiRecvLen,aucSendBuf,&uiSendLen);
	//if( APP_SUCCESS!=ucRetCode )
	if( (APP_ESC==ucRetCode) || (!uiSendLen) )
	{
		Comm_StopClient(g_mCurrTrans.ucCommFlag);
		goto RELISTEN;
	}
	
	//server发送数据包给客户端
	ucRetCode = Comm_ServerSendPacket(g_mCurrTrans.ucCommFlag,g_mCurrTrans.ucDataFormat,aucSendBuf,uiSendLen);
	if( ucRetCode )
	{
		Comm_StopClient(g_mCurrTrans.ucCommFlag);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_CHECK_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_ServerSendPacket fail,ucRetCode[0x%02X]!",ucRetCode);
		//AppUtils_Warning("服务器发送数据包给客户端失败");
		//return ucRetCode;
		goto RELISTEN;
	}
	Comm_StopClient(g_mCurrTrans.ucCommFlag);

goto RELISTEN;	
	
	Comm_StopServer(g_mCurrTrans.ucCommFlag);

	AppUtils_Warning("服务器接收客户端数据包成功!");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : BaseApp_Help
    FuncFunc : 基础项目帮助菜单
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
unsigned char BaseApp_Help(void *pDummy)
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
	AppUtils_FormatDisp("**软件功能:%.58s",BASEAPP_FUNCTION);
	AppUtils_FormatDisp("**软件版本:%.58s",BASEAPP_VERSION);  
	AppUtils_FormatDisp("**版权所有:%.58s",BASEAPP_AUTHOR);
	AppUtils_FormatDisp("**软件联系:%.58s",BASEAPP_CONTACT);
	AppUtils_FormatDisp("**软件描述:%.58s",BASEAPP_DESCPTION);
	AppUtils_FormatDisp("**软件发布:%.58s",BASEAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : BaseApp_Menu
    FuncFunc : 基础项目应用菜单
	Input	 : void *			— pDummy	入口参数标志
	Output	 : None
	Return	 : unsigned char	— 成功,返回按键值
								— 失败,返回超时或取消
										APP_ABORT
										APP_TIMEOUT
    Author	 : Sunrier
    Date     : 2013-06-28 18:26:10
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char BaseApp_Menu(void *pDummy)
{
	unsigned char ucMenuOption = 0;
	unsigned char aucDispTitleBuf[32];
	AppUtils_MenuItem aucMenuItem[] =
	{
		{ 1, "基础数据类型长度",	BaseApp_DataType, (void *) 1 },
		{ 2, "测试RSA算法",			BaseApp_RsaTest, (void *) 1 },
		{ 3, "开启服务器",			BaseApp_ServerStart, (void *) 1 },
		{ 4, "交易测试",			Trans_Menu, (void *) pDummy },
		{ 5, "帮助",    			BaseApp_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "基础测试");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60, NULL);
}





