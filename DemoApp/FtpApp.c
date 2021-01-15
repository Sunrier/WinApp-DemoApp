/*************************************************************************************************
	FileName : FtpApp.c
    FileFunc : ʵ��FTP����Ӧ�ýӿ�
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2018-09-08 11:13:15
	Descp    : ʵ��FTP��ĿӦ����ں���
    History  : None
*************************************************************************************************/
#include "define.h"


/***********************************************************************************************
	FuncName : FtpApp_GetCommCfg
    FuncFunc : ��ȡFTP��ĿͨѶ������Ϣ
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
unsigned char FtpApp_GetCommCfg(void *pDummy)
{
	unsigned char aucFileName[100];		/*�����ļ���*/
	unsigned char aucSectionName[100];	/*����*/
	unsigned char aucKeyName[100];		/*����*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];		/*��ֵ*/
	unsigned char ucRetCode = APP_FAILURE;

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter JN_GetCommCfg!");
	
	if( APP_SUCCESS!=Tool_IsExistFile(GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME,0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "JN_GetCommCfg APP_FAILURE!");
		return APP_FAILURE;
	}
	
	//memset(&g_mApp,0,sizeof(App_Prm));
	//Tool_GetCurrentDate(0,g_mApp.aucCurrDate);

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s%s",GLOBAL_DEFAULTCONFIGPATH,DEMOAPP_CONFIGFILENAME);
	
	memset(aucSectionName,0,sizeof(aucSectionName));
	sprintf(aucSectionName,"%s",DEMOAPP_APPCOMMSECNAME);

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

	/*�������趨��IP*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPServerIP1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerIP[%s]!",aucKeyValue);
	}

	/*����������PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerPort");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerPort[%s]!",aucKeyValue);
	}

	/*TCP����������ʱ��ʱʱ��(S)*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerBlockTimeout");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpServerBlockTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerBlockTimeout[%s]!",aucKeyValue);
	}

	/*��ȡFTP IP1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPIP1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPServerIP1,0,sizeof(g_mTermCfg.aucFTPServerIP1));
		memcpy(g_mTermCfg.aucFTPServerIP1,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP IP1[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPServerIP1,"127.0.0.1");
	}

	/*��ȡFTP PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPORT1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usFTPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP PORT1[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerPort1 = 21;
	}

	/*��ȡFTP IP2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPIP2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPServerIP2,0,sizeof(g_mTermCfg.aucFTPServerIP2));
		memcpy(g_mTermCfg.aucFTPServerIP2,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP IP2[%s]!",aucKeyValue);
	}
	
	/*��ȡFTP PORT2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPORT2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usFTPServerPort2 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP PORT2[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerPort2 = 21;
	}
	
	/*��ȡFTP HOSTNAME1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAME1");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPHostName1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP HOSTNAME1[%s]!",aucKeyValue);
	}

	/*��ȡFTP HOSTNAME2*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAME2");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucFTPHostName2,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP HOSTNAME2[%s]!",aucKeyValue);
	}

	/*��ȡFTP BakCommFlag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPBakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPSockBakFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP BakCommFlag[%s]!",aucKeyValue);
	}

	/*��ȡFTP HOSTNAMEFLAG*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPHOSTNAMEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);	
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP DomainNameFlag[%s]!",aucKeyValue);
		g_mTermCfg.ucFTPHostNameFlag = atoi((char *)aucKeyValue);
	}
	else
	{
		g_mTermCfg.ucFTPHostNameFlag = 0;
	}

	/*��ȡFTP USER*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPUSER");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPUserName,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP User[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPUserName,"ftpuser");
	}

	/*��ȡFTP USERPASSWORD*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPPWD");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=64) ) )
	{
		strcpy(g_mTermCfg.aucFTPUserPassword,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Password[%s]!",aucKeyValue);
	}
	else
	{
		strcpy(g_mTermCfg.aucFTPUserPassword,"ftpuser");
	}

	/*��ȡFTP Local IP*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPLOCALIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		memset(g_mTermCfg.aucFTPLocalIP,0,sizeof(g_mTermCfg.aucFTPLocalIP));
		memcpy(g_mTermCfg.aucFTPLocalIP,aucKeyValue,strlen(aucKeyValue));
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Local IP[%s]!",aucKeyValue);
	}
	
	/*��ȡFtpTimeout*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usFTPServerTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpTimeout[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.usFTPServerTimeout = 120;
	}

	/*��ȡFTP Local PATH*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPLOCALPATH");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=128) ) )
	{
		strcpy(g_mTermCfg.aucFTPLocalPath,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Local PATH[%s]!",aucKeyValue);
	}
	else
	{
		//strcpy(g_mTermCfg.aucFTPLocalPath,"./");
		//strcpy(g_mTermCfg.aucFTPLocalPath,"D:\\FTP\\upload");
		strcpy(g_mTermCfg.aucFTPLocalPath,"D:\\360Download\\Del\\FTP\\upload");
	}

	/*��ȡFTP Remote PATH*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPREMOTEPATH");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (strlen(aucKeyValue) && (strlen(aucKeyValue)<=128) ) )
	{
		strcpy(g_mTermCfg.aucFTPRemotePath,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP Remote PATH[%s]!",aucKeyValue);
	}
	else
	{
		//strcpy(g_mTermCfg.aucFTPRemotePath,"download");
		strcpy(g_mTermCfg.aucFTPRemotePath,"LCC_trans");
	}

	/*FTP File type*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPFILETYPE");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && (('I'==aucKeyValue[0]) || ('A'==aucKeyValue[0]) || ('E'==aucKeyValue[0])))
	{
		g_mTermCfg.aucFTPFileType[0] = aucKeyValue[0];
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP File Type[%s]!",aucKeyValue);
	}
	else
	{
		g_mTermCfg.aucFTPFileType[0] = 'I';
	}

	/*FTP Support file null flag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPFILENULLFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && (('0'==aucKeyValue[0]) || ('1'==aucKeyValue[0]) ) )
	{
		g_mTermCfg.ucFTPFileNullFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP FileNullFlag[%s]!",aucKeyValue);
	}

	/*FTP Upload tmp file flag*/ 
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPUPLOADTMPFILEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPUploadTmpFileFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP UploadTmpFileFlag[%s]!",aucKeyValue);
	}

	/*FTP Del Remote file flag*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","FTPDELREMOTEFILEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucFTPDelRemoteFileFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FTP DelRemoteFileFlag[%s]!",aucKeyValue);
	}
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_InitComm
    FuncFunc : ��ʼ��ͨѶ��Ϣ
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
unsigned char FtpApp_InitComm( void )
{
	unsigned char ucRetCode = 0;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_InitComm");
	
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

		ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
	}

	if( !ucRetCode )
	{
		ucRetCode = Comm_InitFtp(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.ucFTPSockBakFlag,g_mTermCfg.aucFTPServerIP2,g_mTermCfg.usFTPServerPort2,g_mTermCfg.ucFTPHostNameFlag,g_mTermCfg.aucFTPHostName1,g_mTermCfg.aucFTPHostName2,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalIP,g_mTermCfg.usFTPServerTimeout);
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : FtpApp_GetCfg
    FuncFunc : ��ȡFTP��Ŀ������Ϣ
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
unsigned char FtpApp_GetCfg(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	if( ((void *) 0==pDummy) || ((void *) 3==pDummy) )
	{
		ucRetCode = FtpApp_GetCommCfg(pDummy);
	} 
#if 0
	else if( (void *) 1==pDummy )
	{
		ucRetCode = FtpApp_GetCardCfg(pDummy);
	}
#endif

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : FtpApp_Init
    FuncFunc : FTP��ĿӦ�ó�ʼ��
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
unsigned char FtpApp_Init(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,3,DEBUG, "Enter FtpApp_Init!");

	ucRetCode = FtpApp_GetCfg(pDummy);

	if( (void *) 3==pDummy )
	{
		ucRetCode = FtpApp_InitComm();
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
			return ucRetCode;
		}
	}

	return ucRetCode;
}

/***********************************************************************************************
	FuncName : FtpApp_DownloadFile
    FuncFunc : ����FTP�ļ�����
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
unsigned char FtpApp_DownloadFile(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_DownloadFile!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_DOWNLOADFILE;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	//ucRetCode = AppUtils_GetText(LINE2,"�������ļ���:",aucTmpBuf,1,32,0,60);
	ucRetCode = AppUtils_GetCn(LINE2,"�������ļ���:",aucTmpBuf,1,32,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetCn fail,ucRetCode[0x%02X]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�ļ���ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s",aucTmpBuf);

	g_mTermCfg.ucFTPFileNullFlag = 1;
		
	#if 1
	ucRetCode = Comm_FtpDownloadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("����Ftp�ļ�ʧ��,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#else
	ucRetCode = Comm_FtpDownloadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("����Ftp�ļ�ʧ��,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif

	AppUtils_FormatDisp("����Ftp�ļ�[%s]�ɹ�!\n",aucFileName);
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_DownloadFiles
    FuncFunc : ����FTPĿ¼�ļ�����
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
unsigned char FtpApp_DownloadFiles(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiI = 0;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];
	unsigned char aucReplyBuf[1024] = {0};
    unsigned char aucFileList[1024] = {0};    
	unsigned char *pucPtr = NULL;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_DownloadFiles!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_DOWNLOADFILE;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	g_mTermCfg.ucFTPListType = 0;
	g_mTermCfg.ucFTPFileNullFlag = 1;
	//g_mTermCfg.ucFTPDelRemoteFileFlag = 1;

	memset(aucReplyBuf,0,sizeof(aucReplyBuf));
	/*��ȡftp�ϵ��ļ��б�*/
	#if 1
	ucRetCode = Comm_FtpGetFileList(g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPRemotePath,g_mTermCfg.ucFTPListType,aucReplyBuf);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpGetFileList fail,ucRetCode[%d],aucFTPRemotePath[%s]!",ucRetCode,g_mTermCfg.aucFTPRemotePath);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("����FtpԶ��Ŀ¼�ļ��б�ʧ��,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#else
	ucRetCode = Comm_FtpGetFileListEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPRemotePath,g_mTermCfg.ucFTPListType,aucReplyBuf);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpGetFileListEx fail,ucRetCode[%d],aucFTPRemotePath[%s]!",ucRetCode,g_mTermCfg.aucFTPRemotePath);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("����FtpԶ��Ŀ¼�ļ��б�ʧ��,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif

	Tool_TraceLog(1,g_mApp.ucLogLevel,2,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucReplyBuf[%s]!",aucReplyBuf);	

	if( !strlen(aucReplyBuf) )
	{
		AppUtils_FormatDisp("����FtpԶ��Ŀ¼Ϊ��,aucFTPRemotePath[%s]!\n",g_mTermCfg.aucFTPRemotePath);
		AppUtils_WaitKey(5);
		return APP_SUCCESS;
	}
	
	if( (2==g_mTermCfg.ucFTPListType) || (3==g_mTermCfg.ucFTPListType) || (4==g_mTermCfg.ucFTPListType) )
	{
		memset(aucFileList,0,sizeof(aucFileList));
	    strcpy(aucFileList,aucReplyBuf);
	}
	else
	{
		memset(aucFileList,0,sizeof(aucFileList));
	    ucRetCode = Comm_FtpParseList(aucReplyBuf,g_mTermCfg.ucFTPListType,aucFileList);
		if( ucRetCode )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpParseList fail,ucRetCode[%d]!",ucRetCode);
			memset(aucTmpBuf,0,sizeof(aucTmpBuf));
			Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
			AppUtils_FormatDisp("����FtpԶ��Ŀ¼�ļ��б�ʧ��,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
			AppUtils_WaitKey(5);
			return ucRetCode;
		}
	}
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileList[%s]!",aucFileList);
	
    Tool_StrTrimAll(aucFileList);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_StrTrimAll aucFileList[%s]!",aucFileList);
    pucPtr = aucFileList;
    uiI = 0;
	memset(aucFileName,0,sizeof(aucFileName));
    while( '\0'!=*pucPtr )
    {
        if( '|'==*pucPtr )
        {
            Tool_StrTrimAll(aucFileName);
			//AppUtils_FormatDisp("����Ftp�ļ�[%s]!",aucFileName);
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Org aucFileName[%s]!",aucFileName);

			/*�����ļ�������*/
			memset(aucTmpBuf,0,sizeof(aucTmpBuf));
			Tool_CodeConvert(CP_UTF8,aucFileName,CP_ACP,aucTmpBuf);
			Tool_StrTrimAll(aucTmpBuf);
			strcpy(aucFileName,aucTmpBuf);

			AppUtils_FormatDisp("����Ftp�ļ�[%s]!",aucFileName);
			
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileName[%s]!",aucFileName);

            /*����ļ����Ƿ��ظ�*/
			ucRetCode = Tool_IsExistFile(g_mTermCfg.aucFTPLocalPath,aucFileName,1);
			if( !ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_IsExistFile,ucRetCode[0x%02X],aucFileName[%s]!",ucRetCode,aucFileName);
				AppUtils_FormatDisp("�ļ�[%s]�Ѿ�����!",aucFileName);
				uiI = 0;
		        pucPtr++;
				memset(aucFileName,0,sizeof(aucFileName));
				continue;
			}
			
			#if 0
			ucRetCode = Comm_FtpDownloadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("����Ftp�ļ�ʧ��,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#else
			ucRetCode = Comm_FtpDownloadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPDelRemoteFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpDownloadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("����Ftp�ļ�ʧ��,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#endif

			AppUtils_FormatDisp("����Ftp�ļ�[%s]�ɹ�!",aucFileName);
           	
            uiI = 0;
            pucPtr++;
			memset(aucFileName,0,sizeof(aucFileName));
            continue;
        }

		if( uiI>256 )
		{
			pucPtr = NULL;
			AppUtils_FormatDisp("�ļ���������Ч,������󳤶�[%d]\n",uiI);
			AppUtils_WaitKey(5);
			return ucRetCode;
		}
		
        aucFileName[uiI] = *pucPtr;
        uiI++;
        pucPtr++;
    }

	pucPtr = NULL;

	AppUtils_FormatDisp("\n����FtpԶ���ļ��ɹ�!\n");
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_UploadFile
    FuncFunc : �ϴ�FTP�ļ�����
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
unsigned char FtpApp_UploadFile(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_UploadFile!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_UPLOADFILE;
	
	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	//ucRetCode = AppUtils_GetText(LINE2,"�������ļ���:",aucTmpBuf,1,32,0,60);
	ucRetCode = AppUtils_GetCn(LINE2,"�������ļ���:",aucTmpBuf,1,32,60);
	if( (APP_SUCCESS!=ucRetCode) || (!strlen(aucTmpBuf)) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"AppUtils_GetText fail,ucRetCode[%d]!",ucRetCode);
		AppUtils_FormatDisp("��ȡ�ļ���ʧ��,ucRetCode[%d]\n",ucRetCode);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	memset(aucFileName,0,sizeof(aucFileName));
	sprintf(aucFileName,"%s",aucTmpBuf);

	g_mTermCfg.ucFTPFileNullFlag = 1;
	g_mTermCfg.ucFTPUploadTmpFileFlag = 0;
	
	#if 0
	ucRetCode = Tool_IsExistFile(g_mTermCfg.aucFTPLocalPath,aucFileName, g_mTermCfg.ucFTPFileNullFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Tool_IsExistFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Tool_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("�ϴ�Ftp�ļ�ʧ��,ucRetCode[%d:%s],aucFileName[%s]\n",ucRetCode,aucTmpBuf,aucFileName);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif
	
	#if 0
	ucRetCode = Comm_FtpUploadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
		AppUtils_FormatDisp("�ϴ�Ftp�ļ�ʧ��,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#else
	ucRetCode = Comm_FtpUploadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
		memset(aucTmpBuf,0,sizeof(aucTmpBuf));
		Comm_GetDescpFromCode(ucRetCode,aucTmpBuf);
		AppUtils_FormatDisp("�ϴ�Ftp�ļ�ʧ��,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
		AppUtils_WaitKey(5);
		return ucRetCode;
	}
	#endif

	AppUtils_FormatDisp("�ϴ������ļ�[%s]��FtpԶ��Ŀ¼�ɹ�!\n",aucFileName);
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_UploadFiles
    FuncFunc : �ϴ�FTPĿ¼�ļ�����
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
unsigned char FtpApp_UploadFiles(void *pDummy)
{
	unsigned char ucRetCode = APP_SUCCESS;
	unsigned int uiI = 0;
	unsigned char aucTmpBuf[APP_MAXCOMMBUF+1];
	unsigned char aucFileName[256+1];
	//unsigned char aucTmpFileName[256+1];
	unsigned char aucReplyBuf[1024] = {0};
    unsigned char aucFileList[1024] = {0};    
	unsigned char *pucPtr = NULL;
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter FtpApp_UploadFiles!");
	
	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	g_mCurrTrans.ucTransType = TTYPE_FTP_UPLOADFILE;

	AppUtils_UserClear(LINE1);
	Trans_DisplayTransName(g_mCurrTrans.ucTransType);

	ucRetCode = FtpApp_Init((void*)pDummy);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "FtpApp_Init fail,ucRetCode[0x%02X]!",ucRetCode);
		return ucRetCode;
	}

	g_mTermCfg.ucFTPFileNullFlag = 0; 
	
	/*��ȡftp�ϴ����ļ�Ŀ¼�б�*/
	memset(aucFileList,0,sizeof(aucFileList));
    ucRetCode = Tool_GetFileListToBuf(g_mTermCfg.aucFTPLocalPath,aucFileList);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_GetFileListToBuf fail,[ucRetCode=0x%02X]!",ucRetCode);
		return ucRetCode;
	}
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileList[%s]!",aucFileList);
	
    Tool_StrTrimAll(aucFileList);
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_StrTrimAll aucFileList[%s]!",aucFileList);
    pucPtr = aucFileList;
    uiI = 0;
	memset(aucFileName,0,sizeof(aucFileName));
    while( '\0'!=*pucPtr )
    {
        if( '|'==*pucPtr )
        {
            Tool_StrTrimAll(aucFileName);
			AppUtils_FormatDisp("�ϴ�Ftp�ļ�[%s]!",aucFileName);
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "aucFileName[%s]!",aucFileName);

            /*����ļ����Ƿ����*/
			ucRetCode = Tool_IsExistFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.ucFTPFileNullFlag);
			if( ucRetCode )
			{
				uiI = 0;
		        pucPtr++;
				memset(aucFileName,0,sizeof(aucFileName));
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_IsExistFile fail,ucRetCode[0x%02X],aucFileName[%s]!",ucRetCode,aucFileName);
				AppUtils_FormatDisp("�ļ�[%s]������!",aucFileName);
				continue;
			}
			
			#if 1
			ucRetCode = Comm_FtpUploadFile(g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFile fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("�ϴ�Ftp�ļ�ʧ��,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#else
			ucRetCode = Comm_FtpUploadFileEx(g_mTermCfg.aucFTPServerIP1,g_mTermCfg.usFTPServerPort1,g_mTermCfg.aucFTPUserName,g_mTermCfg.aucFTPUserPassword,g_mTermCfg.aucFTPLocalPath,aucFileName,g_mTermCfg.aucFTPRemotePath,aucFileName,g_mTermCfg.aucFTPFileType,,g_mTermCfg.ucFTPFileNullFlag,g_mTermCfg.ucFTPUploadTmpFileFlag);
			if( ucRetCode )
			{
				Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG,"Comm_FtpUploadFileEx fail,ucRetCode[%d],aucFileName[%s]!",ucRetCode,aucFileName);
				memset(aucTmpBuf,0,sizeof(aucTmpBuf));
				Comm_GetDescpFromCode(ucRetCode, aucTmpBuf);
				AppUtils_FormatDisp("�ϴ�Ftp�ļ�ʧ��,ucRetCode[%d:%s]\n",ucRetCode,aucTmpBuf);
				AppUtils_WaitKey(5);
				return ucRetCode;
			}
			#endif

			AppUtils_FormatDisp("�ϴ�Ftp�ļ�[%s]�ɹ�!",aucFileName);
           	
            uiI = 0;
            pucPtr++;
			memset(aucFileName,0,sizeof(aucFileName));
            continue;
        }

		if( uiI>256 )
		{
			pucPtr = NULL;
			AppUtils_FormatDisp("�ļ���������Ч,������󳤶�[%d]\n",uiI);
			AppUtils_WaitKey(5);
			return ucRetCode;
		}
		
        aucFileName[uiI] = *pucPtr;
        uiI++;
        pucPtr++;
    }

	pucPtr = NULL;

	AppUtils_FormatDisp("�ϴ�����Ŀ¼�ļ���FtpԶ��Ŀ¼�ɹ�!\n");
	AppUtils_WaitKey(5);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_Help
    FuncFunc : FTP��Ŀ�����˵�
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
unsigned char FtpApp_Help(void *pDummy)
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
	AppUtils_FormatDisp("**�������:%.58s",FTPAPP_FUNCTION);
	AppUtils_FormatDisp("**����汾:%.58s",FTPAPP_VERSION);  
	AppUtils_FormatDisp("**��Ȩ����:%.58s",FTPAPP_AUTHOR);
	AppUtils_FormatDisp("**�����ϵ:%.58s",FTPAPP_CONTACT);
	AppUtils_FormatDisp("**�������:%.58s",FTPAPP_DESCPTION);
	AppUtils_FormatDisp("**�������:%.58s",FTPAPP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : FtpApp_Menu
    FuncFunc : FTP��ĿӦ�ò˵�
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
unsigned char FtpApp_Menu(void *pDummy)
{
	unsigned char ucMenuOption = 0;
	unsigned char aucDispTitleBuf[32];
	AppUtils_MenuItem aucMenuItem[] =
	{
		{ 1, "Ftp�����ļ�����",	FtpApp_DownloadFile, (void *) 3 },
		{ 2, "FtpĿ¼�ļ�����",	FtpApp_DownloadFiles, (void *) 3 },
		{ 3, "Ftp�����ļ��ϴ�",	FtpApp_UploadFile, (void *) 3 },
		{ 4, "FtpĿ¼�ļ��ϴ�",	FtpApp_UploadFiles, (void *) 3 },
		{ 5, "����",    		FtpApp_Help, (void *) pDummy },
	};
	
	memset(aucDispTitleBuf, 0, sizeof(aucDispTitleBuf));
	sprintf(aucDispTitleBuf, "%s", "Ftp�ļ�");
	
	ucMenuOption = MENUOPT_INORDER | MENUOPT_EXEC_FUNC | MENUOPT_UP_DOWN_ARROW;
	
	return AppUtils_DisplayMenu(LINE1, aucDispTitleBuf, ucMenuOption, sizeof(aucMenuItem) / sizeof(AppUtils_MenuItem), aucMenuItem, 60);
}


