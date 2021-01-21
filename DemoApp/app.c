/*************************************************************************************************
	FileName : app.c
    FileFunc : 实现应用接口
    Version  : V0.0.1
    Author   : Sunrier
	Date     : 2017-06-08 11:13:15
	Descp    : 实现应用入口函数
    History  : None
*************************************************************************************************/
#include "define.h"


/*配置文件参数已初始化的标志*/
static unsigned char s_ucInitCfgFlag = 0;


unsigned char App_Demo( void )
{
	unsigned char ucRetCode = 0;

	//unsigned char aucDispBuf[1024+1];

	unsigned int uiLen = 0;

	unsigned char ucI = 0,ucJ = 0;


	for(ucI = 0; ucI<100; ucI++)
	{
		;
	}

	return ucRetCode;
}

//X
//X1 X2
// X1>X
// X2<X

//X3
//
// Y=
//
//
//

unsigned char App_Test( void )
{
	unsigned char aucNumber[512],aucBuffer[512],aucCardNo[256+1],aucTmpBuf[32+1];
	unsigned char aucInitKey[8+1] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	unsigned char ucRetCode = 0;
	unsigned long ulData = 1384936600,ulData2 = 0,lt =0;
	unsigned char ucNumber = 0;
	//unsigned char aucURL[512+1],aucIP[16],aucDomain[512+1],aucPage[256+1];
	unsigned short usPort = 0;
	unsigned int uiI = 0,uiJ = 0,uiLen = 0;
	unsigned char aucApdu[4+1],aucApduDespInfo[256+1];
	unsigned uValue = 0;
	int iValue = 0,iLen = 0 ;
	int iRetCode = 0;
	char *pcPtr = "dsfdsfsfdsds";
	long lData = 0;

	//

	//

	unsigned int uiBeginYear = 2021,uiEndYear = 2047;
	//unsigned long ulBeginPrice = 1,ulEndPrice = 10000000000;
	double dData = 0,dYear = 0,dOrgAmout = 0;
	unsigned char aucOrgAmount[30],aucCurAmount[30];
	//unsigned char aucAnnualInterestRate[30];
	double dCurAmount = 0;
	unsigned long ulI = 0,ulStart = 0,ulEnd = 0;
	double dStart = 0,dEnd = 0;
	double dInterestRate = 0;
	unsigned char aucInterestRate[16];
	unsigned int uiInterestYear = 0;


	Tool_GetPriceTrend();

	strcpy(aucOrgAmount,"10");
	strcpy(aucCurAmount,"16.9");
	Tool_GetROI(aucOrgAmount,aucCurAmount);
	
	AppUtils_WaitKey(500);

	return 0;
		
	Tool_GetPrincipalInterest(50000,0.03,30,1,&dCurAmount);
	printf("dCurAmount[%.2f]\n",dCurAmount);

	Tool_GetInterestYear(50000,dCurAmount,0.03,&uiInterestYear);
	printf("uiInterestYear[%d]\n",uiInterestYear);
	
	Tool_GetPrincipalInterest(50000,0.03,30,0,&dCurAmount);
	printf("dCurAmount[%.2f]\n",dCurAmount);
	
	dInterestRate = 0;
	memset(aucInterestRate,0,sizeof(aucInterestRate));
	Tool_GetAnnualInterestRate(50000,dCurAmount,30,aucInterestRate);
	//printf("dInterestRate[%.2f]\n",dInterestRate);
	printf("aucInterestRate[%s]\n",aucInterestRate);

	Tool_GetPrincipalInterest(10000,0.05,10,1,&dCurAmount);
	printf("dCurAmount[%.2f]\n",dCurAmount);

	Tool_GetInterestYear(10000,dCurAmount,0.05,&uiInterestYear);
	printf("uiInterestYear[%d]\n",uiInterestYear);
	
	Tool_GetPrincipalInterest(10000,0.05,10,0,&dCurAmount);
	printf("dCurAmount[%.2f]\n",dCurAmount);
	dInterestRate = 0;
	memset(aucInterestRate,0,sizeof(aucInterestRate));
	Tool_GetAnnualInterestRate(10000,dCurAmount,10,aucInterestRate);
	//printf("dInterestRate[%.2f]\n",dInterestRate);
	printf("aucInterestRate[%s]\n",aucInterestRate);

	dCurAmount = 0;
	Tool_GetPrincipalInterest(500000,2,3,0,&dCurAmount);
	printf("dCurAmount[%.2f]\n",dCurAmount);

	dInterestRate = 0;
	memset(aucInterestRate,0,sizeof(aucInterestRate));
	dCurAmount = 4000;
	Tool_GetAnnualInterestRate(50000,dCurAmount,30,aucInterestRate);
	//printf("dInterestRate[%.2f]\n",dInterestRate);
	printf("aucInterestRate[%s]\n",aucInterestRate);

	dInterestRate = 0;
	memset(aucInterestRate,0,sizeof(aucInterestRate));
	dCurAmount = 4000;
	Tool_GetAnnualInterestRate(-10000,dCurAmount,30,aucInterestRate);
	//printf("dInterestRate[%.2f]\n",dInterestRate);
	printf("aucInterestRate[%s]\n",aucInterestRate);

	
#if  0
	uiJ = uiEndYear - uiBeginYear;
	for(uiI<0; uiI<uiJ; uiI++)
	{
		printf("uiBeginYear[%d]\n",uiBeginYear+uiI);
		;
	}
#else
#if 0
	uiJ = uiEndYear - uiBeginYear;
	dYear = (double)(uiJ);
	printf("dYear[%f]\n",dYear);
	dData = 1/dYear;
	memset(aucOrgAmount,0,sizeof(aucOrgAmount));
	strcpy(aucOrgAmount,"1");
	dOrgAmout = atof(aucOrgAmount);
	memset(aucCurAmount,0,sizeof(aucCurAmount));
	strcpy(aucCurAmount,"10000000000");
	dOrgAmout = fabs(atof(aucCurAmount))/dOrgAmout;
	memset(aucAnnualInterestRate,0,sizeof(aucAnnualInterestRate));
	sprintf(aucAnnualInterestRate,"%.3f%%",(pow(dOrgAmout,dData)-1)*100);
	printf("aucAnnualInterestRate[%s]\n",aucAnnualInterestRate);
	
	for(uiI<0; uiI<uiJ; uiI++)
	{
		dCurAmount = dOrgAmout*(1+atol(aucAnnualInterestRate));
		printf("uiBeginYear[%d],dCurAmount[%.2f]\n",uiBeginYear+uiI,dCurAmount);
	}
#else
	uiJ = uiEndYear - uiBeginYear;
	memset(aucInterestRate,0,sizeof(aucInterestRate));
	Tool_GetAnnualInterestRate(1,10000000000,uiJ,aucInterestRate);
	printf("aucInterestRate[%s]\n",aucInterestRate);
#if 0
	dOrgAmout = 1;
	for(uiI<0; uiI<uiJ; uiI++)
	{
		dCurAmount = dOrgAmout*(1*1000+atof(aucInterestRate)*1000)/1000;
		printf("uiBeginYear[%d],dCurAmount[%.2f]\n",uiBeginYear+uiI,dCurAmount);
	}
#else
	dOrgAmout = 1;
	printf("aucInterestRate[%s]\n",aucInterestRate);
	printf("atof(aucInterestRate)[%.2f]\n",atof(aucInterestRate));
	printf("uiBeginYear[%d],dCurAmount[%.2f]\n",uiBeginYear+uiI,dOrgAmout/100);
	for(uiI=0; uiI<uiJ; uiI++)
	{
		dCurAmount = 0;
		Tool_GetPrincipalInterest(1,atof(aucInterestRate)/100,uiI+1,0,&dCurAmount);
		printf("uiBeginYear[%d],dCurAmount[%.2f]\n",uiBeginYear+uiI+1,dCurAmount/100);
	}
#endif
#endif
#endif
	//0107-泽民
	//0116-世纪大道
	//
	AppUtils_WaitKey(500);
	
	return 0;
	

	

	iRetCode =100;

	strcpy(aucBuffer,"0003554210FFFFFFFF0000000000");
	printf( "strlen[%d]\n", strlen(aucBuffer));
	
	lData = atol(aucBuffer);
	printf( "lData[%d]\n", lData);

	strcpy(aucBuffer,"00022058102030032701000000001220581000000000");
	printf( "strlen[%d]\n", strlen(aucBuffer));
	
	lData = atol(aucBuffer);
	printf( "lData[%d]\n", lData);


	AppUtils_WaitKey(500);
	
	return 0;

	Tool_GetByteOfSysDataType();

	//%.*s
	iValue = 12345678;
	sprintf(aucBuffer, "%04X", iValue);
	printf("aucBuffer[%.*s]\n",2,aucBuffer);
	printf("aucBuffer[%.*s]\n",10,aucBuffer);
	printf("aucBuffer[%.*s]\n",sizeof(aucBuffer),aucBuffer);

	sprintf(aucBuffer, "%d", iValue);
	printf("aucBuffer[%.*s]\n",2,aucBuffer);
	printf("aucBuffer[%.*s]\n",10,aucBuffer);
	printf("aucBuffer[%.*s]\n",sizeof(aucBuffer),aucBuffer);
	
	iValue = 4294967295;
	//iValue = 99999999999;		
	memset(aucBuffer,0,sizeof(aucBuffer));
	Tool_IntToStrEx(iValue,1,aucBuffer);
	printf("aucBuffer[%.*s]\n",sizeof(aucBuffer),aucBuffer);
	
	ulData = 4294967294;
	iValue = 4294967294;	
	printf("%u\n" , ulData);
	memset(aucBuffer,0,sizeof(aucBuffer));
	Tool_LongToStrEx(ulData,1,aucBuffer);
	printf("aucBuffer[%.*s]\n",sizeof(aucBuffer),aucBuffer);

	//sprintf(aucBuffer, "%%0%dd" , 10);
	//sprintf(aucNumber, aucBuffer, iValue);
	//printf("aucBuffer[%.*s]\n",sizeof(aucBuffer),aucBuffer);

	AppUtils_WaitKey(500);
	
	return 0;
	
	sprintf(aucBuffer, "%04X", 0);
	printf("aucBuffer[%s]\n",aucBuffer);

	iRetCode = 100;

	sprintf(aucBuffer, "%04X", iRetCode);
	printf("aucBuffer[%s]\n",aucBuffer);

	iRetCode = 1200;

	sprintf(aucBuffer, "%04X", iRetCode);
	printf("aucBuffer[%s]\n",aucBuffer);
	
	iRetCode = 888;

	sprintf(aucBuffer, "%04X", iRetCode);
	printf("aucBuffer[%s]\n",aucBuffer);

	ulData = 3;
	uiLen = 0;
	memset(aucBuffer,0,sizeof(aucBuffer));
	Tool_LongToHexEx(ulData,aucBuffer,&uiLen);
	
	for(uiI=0; uiI<uiLen; uiI++)
	{
		printf("aucBuffer[%d]=[0x%02X]\n",uiI,aucBuffer[uiI]);
	}
	
	AppUtils_WaitKey(500);
	
	return 0;
	
	
	//AppUtils_FormatDisp("sPayType[%02Xd],\n",aucBuffer);
	//AppUtils_FormatDisp("sPayType[%02Xd],\n",mData.sPayType);
	//AppUtils_FormatDisp("sPayType[0x%02X],\n",mData.sPayType[0]);
	AppUtils_WaitKey(500);
	return 0;


	//pcPtr = aucApduDespInfo;
	iLen = sizeof(pcPtr);
	
	AppUtils_FormatDisp("iLen[%d],pcData[%s],\n",iLen,pcPtr);
	
	
	AppUtils_WaitKey(5);
	return 0;
		
	memset(aucApduDespInfo,0,sizeof(aucApduDespInfo));
	ucRetCode = AppUtils_GetBcd(LINE2,"请输入密钥:",32,32,60,aucApduDespInfo,&uiLen);
	printf("aucApduDespInfo:%s\n",aucApduDespInfo);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,0,NULL,aucApduDespInfo,uiLen,1,16);
	return 0;
	memset(aucApdu,0,sizeof(aucApdu));
	strcpy(aucApdu,"6E00");
	memset(aucApduDespInfo,0,sizeof(aucApduDespInfo));
	AppUtils_FormatDisp("%s:%s",aucApdu,aucApduDespInfo);
	AppUtils_WaitKey(5);
	memset(aucCardNo,0,sizeof(aucCardNo));
	sprintf(aucCardNo,"%s","HelloWorld");
	uiLen = strlen(aucCardNo);
#if 0
	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	AppUtils_Asc2Bcd(aucCardNo,aucTmpBuf, uiLen);
	printf("Name:%s\n",aucCardNo);
	Tool_DisplayHexData("Name Cov:",aucTmpBuf, uiLen/2);

	memset(aucCardNo,0,sizeof(aucCardNo));
	AppUtils_Bcd2Asc(aucTmpBuf,aucCardNo, uiLen);
	printf("Name:%s\n",aucCardNo);
#else
	printf("Name:%s\n",aucCardNo);
	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	AppUtils_Bcd2Asc(aucCardNo,aucTmpBuf, uiLen*2);
	Tool_DisplayHexData("Name Cov:",aucTmpBuf, uiLen*2);
	
	memset(aucCardNo,0,sizeof(aucCardNo));
	AppUtils_Asc2Bcd(aucTmpBuf,aucCardNo, uiLen);
	printf("Name:%s\n",aucCardNo);
#endif
	return 0;

	memset(aucCardNo,0,sizeof(aucCardNo));
	aucCardNo[0] = '1';
	sprintf(aucBuffer, "%060s", aucCardNo);
	printf("aucBuffer:%s\n");
	printf("%d\n",strlen(aucBuffer));
	return 0;
	memset(aucNumber,0,sizeof(aucNumber));
	memset(aucCardNo,0,sizeof(aucCardNo));
	strcpy(aucCardNo,"4740940000000108");

	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTLOGPATH, g_mApp.aucLogFileName, 6, 6, "App_Test Send Packet", aucCardNo, 32, 2, APP_MAXCOMMBUF);
	
	return 0;
	memset(aucTmpBuf,0,sizeof(aucTmpBuf));
	AppUtils_Asc2Bcd(aucCardNo,aucTmpBuf, 16);
	memset(aucBuffer,0,sizeof(aucBuffer));
	Tool_Xor(aucInitKey,aucTmpBuf,8,aucBuffer);
	Tool_DisplayHexData("Tool_Xor aucBuffer:",aucBuffer, 8);
	//memset(aucBuffer,0,sizeof(aucBuffer));
	//memset(aucNumber,0,sizeof(aucNumber));
	//memcpy(aucBuffer,"\xCC\x6D\x61\xE6\x61\x85\xCB\xB6",8);
	Tool_DisplayHexData("aucBuffer:",aucBuffer, 8);
	Tool_HexToAsc(aucBuffer, 16,aucNumber);
	//sprintf(aucNumber,"%s","aucNumber");
	
	//34373430393430303030303030313038
	//CBC8CBCFC6CBCFCFCFCFCFCFCFCECFC7
	
	//memset(aucBuffer, 0, sizeof(aucBuffer));
	//memcpy(aucBuffer,"\x02\x00\x0e\x03\x10\x30\x37\x32\x35\x32\x33\x42\x35\x1c\x1c\x1c\x1c\x03\x68",19);

	//客户端校验Key:0x42 0x38 0x42 0x46 0x36 0x42 0x46 0x46 0x46 0x46 0x46 0x46 0x46 0x45 0x46 0x37
	//服务器校验Key:0xCB 0xC8 0xCB 0xCF 0xC6 0xCB 0xCF 0xCF 0xCF 0xCF 0xCF 0xCF 0xCF 0xCE 0xCF 0xC7
	//66  56  66  70  54
	//203 200 203 207 198
	//137 144 137 137 144
	//0x89 0x90
	//memset(aucBuffer, 0, sizeof(aucBuffer));
	//memcpy(aucBuffer,"\xCB\xC8\xCB\xCF\xC6\xCB\xCF\xCF\xCF\xCF\xCF\xCF\xCF\xCE\xCF\xC7",16);
	//Tool_HexToAsc(aucBuffer,8,aucNumber);
	//Tool_BcdToAscEx(unsigned char ucFillFlag, unsigned char * pucInputData, unsigned int uiOutputLen, unsigned char * pucOutputData)
	//CBC8CBCFC6CBCFCFCFCFCFCFCFCECFC7
	//memset(aucNumber, 0, sizeof(aucNumber));
	//Tool_BcdToAscEx(0,aucBuffer,16,aucNumber);
	//Tool_DisplayHexData("Recv Packet:",aucNumber, 16);
	AppUtils_DisplayHexData("Recv Packet:",aucNumber, 16);
	//App_PrintWidthHexAsc("Test",aucBuffer,256);
	return 0;
	//sprintf(aucNumber,"%s","aucNumber");
	
	Tool_TraceInfor(2,DEBUG,"ucRetCode = %d",ucRetCode);
		
	return 0;
}


/*********************************************************************************************** 
    FuncName : App_ConsoleHandler  
    FuncFunc : 异常事件处理
	Input	 : DWORD	— CEvent	输入事件
	Output	 : None
	Return	 : BOOL		— 成功,返回非0
						— 失败,返回0x00
    Author   : Sunrier    
    Date     : 2015-08-05 10:10:22
    Descp    : 实现应用异常事件处理
	History  : None
*************************************************************************************************/
BOOL WINAPI App_ConsoleHandler(DWORD CEvent)
{	
	switch( CEvent )
	{
		case CTRL_C_EVENT:
		case CTRL_BREAK_EVENT:
				break;
				
		case CTRL_CLOSE_EVENT:	 		//5s
		case CTRL_LOGOFF_EVENT:	 		//20s
		case CTRL_SHUTDOWN_EVENT:		//20s
				if( g_mApp.ucLastRunNodeFlag )
				{
					Tool_RemoveFile(g_mApp.aucDefTmpPath,g_mApp.aucDefTmpFile);
					g_mApp.ucLastRunNodeFlag = 0;
				}
				break;
	}

	return TRUE;
}

/***********************************************************************************************
	FuncName : App_GetConfigPrm
    FuncFunc : 获取默认配置参数
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
unsigned char App_GetConfigPrm( void )
{
	unsigned char ucRetCode = 0;
	unsigned char ucCfgFileFlag = 0;
	unsigned char aucFileName[100];		/*配置文件名*/
	unsigned char aucSectionName[100];	/*节名*/
	unsigned char aucKeyName[100];		/*键名*/	
	unsigned char aucKeyValue[100];		/*键值*/
	unsigned char aucLogFileName[128+1];
	unsigned char aucDate[16+1];
	unsigned char aucPrefixBuf[128+1],aucSuffixBuf[128+1];
	unsigned char aucCfgFileName[256+1];

	if( s_ucInitCfgFlag )
	{
		return APP_SUCCESS;
	}

	Tool_SetCfgFile(GLOBAL_CONFIGFILENAME);

	memset(&g_mApp,0,sizeof(App_Prm));
	strcpy(g_mApp.aucUserName,GLOBAL_APPNAME);
	Tool_GetCurrentDate(0,g_mApp.aucCurrDate);

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	App_SetCommCfg();
	
	if( APP_SUCCESS!=Tool_IsExistFile(GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME,0) )
	{
		ucRetCode = App_InitCfg();
		ucCfgFileFlag = 0;
	}
	else
	{
		ucCfgFileFlag = 0;
	}

	memset(aucFileName,0,sizeof(aucFileName));
	if( !ucCfgFileFlag )
	{
		sprintf(aucFileName,"%s%s",GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME);
		strcpy(g_mApp.aucCfgFileName,GLOBAL_CONFIGFILENAME);
	}
	else
	{
		sprintf(aucFileName,"%s%s",GLOBAL_DEFAULTCONFIGPATH,aucCfgFileName);
		strcpy(g_mApp.aucCfgFileName,aucCfgFileName);
	}

	memset(aucSectionName,0,sizeof(aucSectionName));
	sprintf(aucSectionName,"%s",GLOBAL_LOGSECNAME);
	
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","LOGFILEFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mApp.ucLogFileFlag = 1;
	}

	if( g_mApp.ucLogFileFlag )
	{
		memset(aucKeyName,0,sizeof(aucKeyName));
		sprintf(aucKeyName,"%s","LOGFILE");
		memset(aucKeyValue,0,sizeof(aucKeyValue));
		ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
		if( (APP_SUCCESS==ucRetCode) && (strlen((char *)aucKeyValue) && (strlen((char *)aucKeyValue)<64)) )
		{
			memset(aucLogFileName, 0, sizeof(aucLogFileName));
			memcpy(aucLogFileName, aucKeyValue, strlen((char *)aucKeyValue));
		}
		else
		{
			g_mApp.ucLogFileFlag = 0;
		}
	}

	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","LOGCNTIPFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mApp.ucCNTipFlag = 1;
	}
	
	memset(aucDate,0,sizeof(aucDate));
	Tool_GetCurrentDate(0,aucDate);
	if( !g_mApp.ucLogFileFlag )
	{
		memset(aucLogFileName,0,sizeof(aucLogFileName));
		sprintf(aucLogFileName,"%s_%s.LOG",GLOBAL_APPNAME,aucDate);
		
		memset(g_mApp.aucLogFileName,0,sizeof(g_mApp.aucLogFileName));
		sprintf(g_mApp.aucLogFileName,"%s",aucLogFileName);
	}
	else
	{	
		memset(aucSuffixBuf,0,sizeof(aucSuffixBuf));
		Tool_Strrchr(aucLogFileName,'.',0,aucSuffixBuf);
		if( strlen(aucSuffixBuf)>1 && (strlen(aucLogFileName)>(strlen(aucSuffixBuf))) )
		{
			memset(aucPrefixBuf,0,sizeof(aucPrefixBuf));
			memcpy(aucPrefixBuf,aucLogFileName,strlen(aucLogFileName)-strlen(aucSuffixBuf));	
		}
		else
		{
			memset(aucSuffixBuf,0,sizeof(aucSuffixBuf));
			strcpy(aucPrefixBuf,aucLogFileName);

			memset(aucSuffixBuf,0,sizeof(aucSuffixBuf));
			strcpy(aucSuffixBuf,".LOG");
		}
		
		memset(g_mApp.aucLogFileName,0,sizeof(g_mApp.aucLogFileName));
		sprintf(g_mApp.aucLogFileName,"%s_%s%s",aucPrefixBuf,aucDate,aucSuffixBuf);
	}
	
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","LOG_LEVEL");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (1==strlen((char *)aucKeyValue)) && (aucKeyValue[0]>='0') && (aucKeyValue[0]<='5') )
	{
		if( !atoi(aucKeyValue) )
		{
			g_mApp.ucLogLevel = 0;
		}
		else
		{
			g_mApp.ucLogLevel = (unsigned char)pow(2,(atoi(aucKeyValue)-1));
		}
	}
	else
	{
		g_mApp.ucLogLevel = 0;
	}
	
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","DISPFLAG");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mApp.ucDispFlag = 1;
	}

	if( g_mApp.ucLogLevel )
	{
		Tool_TraceLog(0,g_mApp.ucLogLevel,LOG_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,3,DEBUG, "CfgFileName[%s]",g_mApp.aucCfgFileName);
		Tool_TraceLog(0,g_mApp.ucLogLevel,LOG_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "LogFileFlag[%d]",g_mApp.ucLogFileFlag);
		Tool_TraceLog(0,g_mApp.ucLogLevel,LOG_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "OrgLogFileName[%s]",aucLogFileName);
		Tool_TraceLog(0,g_mApp.ucLogLevel,LOG_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "LogFileName[%s]",g_mApp.aucLogFileName);
		Tool_TraceLog(0,g_mApp.ucLogLevel,LOG_INFO,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "LogLevel[%d]",g_mApp.ucLogLevel);
		//Tool_TraceLog(0,g_mApp.ucLogLevel,LOG_INFO,CERTAPP_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "[DispFlag:%d]!",g_mApp.ucDispFlag);
	}
	
	s_ucInitCfgFlag = 1;

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_InitCommCfg
    FuncFunc : 初始化配置文件通讯信息
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
unsigned char App_InitCommCfg( void )
{
	unsigned char ucRetCode = 0;
	unsigned char aucBuffer[1000];
	unsigned int uiLen = 0;

/*
XXX.ini
[COMM]
#测试项目配置
#COMMTYPE:通讯类型
COMMTYPE=10
#COMMPORT:串口通讯号(1~10)
COMMPORT=1
#BAUDRATE:串口拨特率
BAUDRATE=115200
#RS232TIMEOUT:串口超时时间
RS232TIMEOUT=60
#IP1:主机地址1
#IP1=222.92.214.246
IP1=112.95.135.89
#PORT1:主机端口1
#PORT1=443
PORT1=88
#IP2:主机地址2
IP2=222.92.214.246
#PORT2:主机端口2
PORT2=443
#HOSTNAME1:主机域名1
HOSTNAME1=
#HOSTNAME2:主机域名2
HOSTNAME2=
#HTTPLIBFLAG:http或https的通讯时是否支持库的协议 0-不支持 1-支持
HTTPLIBFLAG=1
#HTTPWAYFLAG:http或https通讯时请求方法 0-POST 1-GET
HTTPWAYFLAG=1
#AUTOURLFLAG:http或https通讯时URL是否自解析0-不支持 1-支持
AUTOURLFLAG=1
#AUTOURLCOMMFLAG:http或https通讯时是否支持URL自解析失败后尝试Host IP/Name 0-不支持 1-支持
AUTOURLCOMMFLAG=1
#AUTOHTTPPARSEFLAG:http或https接收的包是否自解析:0-不解析 1-解析
AUTOHTTPPARSEFLAG=0
#URL:http或https的URL
#URL=https://wx.helloworld.com/mcg/xxx
URL=http://s300test.hq.iboxpay.com/sdk-device/device/auth.json
#DOMAIN:http或https的DOMAIN
#DOMAIN=wx.suzhoubank.com
DOMAIN=s300test.hq.iboxpay.com
#PAGE:http或https的PAGE
PAGE=/sdk-device/device/auth.json
#BAKCOMMFLAG:是否启用备机0-不启用 1-启用
BAKCOMMFLAG=0
#HOSTNAMEFLAG:是否启用域名解析0-不启用 1-启用
HOSTNAMEFLAG=0
#SSLFLAG:是否启用SSL 0-不启用 1-启用
SSLFLAG=0
#TCPTIMEOUT:网络超时时间
TCPTIMEOUT=60
#SSLTIMEOUT:SSL网络超时时间
SSLTIMEOUT=60
#服务器端口
SERVERPORT1=6666
[DEMOAPPLOG]
#LOG_LEVEL:输出日志信息等级
LOG_LEVEL=4
[COMMLIBLOG]
LOG_LEVEL=4
LOGFILEFLAG=1
LOGFILE=DEMOAPP
*/

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
	sprintf(aucBuffer,"%s","URL=https://wx.helloworld.com/mcg/xxx\n");
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

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","SERVERPORT1=6666\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_InitDebugCfg
    FuncFunc : 初始化配置文件调试信息
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
unsigned char App_InitDebugCfg( void )
{
	unsigned char ucRetCode = APP_FAILURE;
	unsigned char aucBuffer[1000];
	unsigned int uiLen = 0;

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"[%s]\n",GLOBAL_LOGSECNAME);
	
	uiLen = strlen(aucBuffer);
	ucRetCode = AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	if( APP_SUCCESS!=ucRetCode )
	{
		return ucRetCode;
	}

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","#LOG_LEVEL:输出日志信息等级\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);

	memset(aucBuffer,0,sizeof(aucBuffer));
	sprintf(aucBuffer,"%s","LOG_LEVEL=4\n");
	uiLen = strlen(aucBuffer);
	AppUtils_AppendInfoToFile(0,0,GLOBAL_DEFAULTCONFIGPATH,GLOBAL_CONFIGFILENAME, 0, 0, NULL, aucBuffer, uiLen, 0, APP_MAXBUFFER);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_InitTranCfg
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
unsigned char App_InitTranCfg( void )
{
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_InitCfg
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
unsigned char App_InitCfg( void )
{
	App_InitCommCfg();
	App_InitTranCfg();
	App_InitDebugCfg();

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_Init
    FuncFunc : 初始化信息
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
unsigned char App_InitComm(unsigned char ucAppFlag)
{
	unsigned char ucRetCode = APP_FAILURE;

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter App_InitComm,ucAppFlag[%d]!",ucAppFlag);
	
	AppUtils_DisplayLeft("\n通讯初始化...", LINE2);
	AppUtils_DisplayLeft("请稍候...\n", LINE3);

	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitComm!");
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "CommPort[COM%d],BaudRate[%d]!",g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate);
	
	ucRetCode = Comm_InitComm(g_mTermCfg.uiCommPort,g_mTermCfg.uiBaudRate,g_mTermCfg.usRS232Timeout);	
	if( APP_SUCCESS==ucRetCode )
	{
		if( g_mTermCfg.ucSSLFlag )
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitSSL!");
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%d],TCPIP1[%s],TCPHostPort1[%d],TCPIP2[%s],TCPHostPort2[%d],SelfHttpsProtocolFlag[%d],HttpsURL[%s],HttpsRequestWayFlag[%d]!",
							g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,
							g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag);
			ucRetCode = Comm_InitSSL(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,2,0,0,"",0,1,NULL,NULL,NULL,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpsURL,g_mTermCfg.ucRequestWayFlag);
		}
		else
		{
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter Comm_InitSock!");
			Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%d],TCPIP1[%s],TCPHostPort1[%d],TCPIP2[%s],TCPHostPort2[%d],SelfHttpProtocolFlag[%d],HttpURL[%s],HttpRequestWayFlag[%d],TCPServerIP[%s],TCPServerPort[%d],TcpServerBlockTimeout[%d]!",
							g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,
							g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
			ucRetCode = Comm_InitSock(g_mTermCfg.aucTCPIP1,g_mTermCfg.usTCPHostPort1,g_mTermCfg.ucBakCommFlag,g_mTermCfg.aucTCPIP2,g_mTermCfg.usTCPHostPort2,g_mTermCfg.ucDomainNameFlag,g_mTermCfg.aucTCPDomainName1,g_mTermCfg.aucTCPDomainName2,g_mTermCfg.ucSelfProtocolFlag,g_mTermCfg.aucHttpURL,g_mTermCfg.ucRequestWayFlag,NULL,NULL,g_mTermCfg.aucTCPServerIP1,g_mTermCfg.usTCPServerPort1,g_mTermCfg.usTcpServerBlockTimeout);
		}
	}

	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "App_InitComm fail,ucRetCode[0x%02X]!",ucRetCode);
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : App_GetVersion
    FuncFunc : 获取项目版本信息
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
unsigned char App_GetVersion( void )
{
	unsigned char ucRetCode = APP_FAILURE;
	unsigned char aucVersion[256];	
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter App_GetVersion!");

	memset(aucVersion,0,sizeof(aucVersion));
	ucRetCode = Tool_GetLibVersion(aucVersion);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_GetLibVersion fail,ucRetCode[0x%02X]!",ucRetCode);
		return APP_FAILURE;
	}
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Tool_GetLibVersion aucVersion[%s]!",aucVersion);

	memset(aucVersion,0,sizeof(aucVersion));
	ucRetCode = AppUtils_GetLibVersion(aucVersion);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AppUtils_GetLibVersion fail,ucRetCode[0x%02X]!",ucRetCode);
		return APP_FAILURE;
	}
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "AppUtils_GetLibVersion aucVersion[%s]!",aucVersion);

	memset(aucVersion,0,sizeof(aucVersion));
	ucRetCode = WComm_GetLibVersion(aucVersion);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "WComm_GetLibVersion fail,ucRetCode[0x%02X]!",ucRetCode);
		return APP_FAILURE;
	}
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "WComm_GetLibVersion aucVersion[%s]!",aucVersion);

	memset(aucVersion,0,sizeof(aucVersion));
	ucRetCode = Comm_GetLibVersion(aucVersion);
	if( ucRetCode )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_GetLibVersion fail,ucRetCode[0x%02X]!",ucRetCode);
		return APP_FAILURE;
	}
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Comm_GetLibVersion aucVersion[%s]!",aucVersion);
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_SetCommCfg
    FuncFunc : 设置项目默认通讯配置信息
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
unsigned char App_SetCommCfg( void )
{
	memset(&g_mTermCfg,0,sizeof(Comm_Prm));

	g_mTermCfg.usRS232Timeout = 60;
	g_mTermCfg.usTcpServerTimeout = 60;
	g_mTermCfg.usTcpServerBlockTimeout = 60;
	g_mTermCfg.usTCPServerPort1 = 6666;
	
	g_mTermCfg.ucCommFlag = 1;
	g_mTermCfg.uiCommPort = COM1;
	g_mTermCfg.uiBaudRate = UBPS115200;
	strcpy(g_mTermCfg.aucTCPIP1,"222.92.214.246");
	g_mTermCfg.usTCPHostPort1 = 443;

	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_GetCommCfg
    FuncFunc : 获取项目通讯配置信息
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
unsigned char App_GetCommCfg( void )
{
	unsigned char aucFileName[100];		/*配置文件名*/
	unsigned char aucSectionName[100];	/*节名*/
	unsigned char aucKeyName[100];		/*键名*/	
	unsigned char aucKeyValue[APP_MAXBUFFER+1];		/*键值*/
	unsigned char ucRetCode = APP_FAILURE;

	memset(&g_mCurrTrans,0,sizeof(Trans_Prm));
	
	Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "Enter App_GetCommCfg!");
	
	if( APP_SUCCESS!=Tool_IsExistFile(GLOBAL_DEFAULTCONFIGPATH,g_mApp.aucCfgFileName,0) )
	{
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_ERROR,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "App_GetCommCfg fail!");
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

	/*获取BakCommFlag是否启用备机标志*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","BakCommFlag");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);

	if( (APP_SUCCESS==ucRetCode) && 1==strlen((char *)aucKeyValue) && ('1'==aucKeyValue[0]) )
	{
		g_mTermCfg.ucBakCommFlag = atoi((char *)aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "BakCommFlag[%s]!",aucKeyValue);
	}

	/*获取HOSTNAMEFLAG是否启用主机域名标志*/
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

	/*获取RS232Timeout串口超时时间(S)*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","RS232TIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usRS232Timeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "RS232Timeout[%s]!",aucKeyValue);
	}

	/*获取TcpTimeout网络超时时间(S)*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTcpTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TcpTimeout[%s]!",aucKeyValue);
	}

	/*是否启用SSL标志:0-不启用 1-启用*/
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

	/*获取SSLTimeout通讯超时时间(S)*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","SSLTIMEOUT");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usSSLTimeout = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "SSLTimeout[%s]!",aucKeyValue);
	}

	/*服务器设定的IP*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerIP");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckValidIp(aucKeyValue)) )
	{
		strcpy(g_mTermCfg.aucTCPServerIP1,aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerIP[%s]!",aucKeyValue);
	}
	
	/*服务器监听PORT1*/
	memset(aucKeyName,0,sizeof(aucKeyName));
	sprintf(aucKeyName,"%s","TCPServerPort");
	memset(aucKeyValue,0,sizeof(aucKeyValue));
	ucRetCode = Tool_GetConfigStringValue(aucFileName,aucSectionName,aucKeyName,aucKeyValue);
	if( (APP_SUCCESS==ucRetCode) && (APP_SUCCESS==Tool_CheckDigital(aucKeyValue)) )
	{
		g_mTermCfg.usTCPServerPort1 = atoi(aucKeyValue);
		Tool_TraceLog(1,g_mApp.ucLogLevel,LOG_DEBUG,GLOBAL_DEFAULTLOGPATH,g_mApp.aucLogFileName,0,2,DEBUG, "TCPServerPort[%s]!",aucKeyValue);
	}
	
	return APP_SUCCESS;
}


/***********************************************************************************************
	FuncName : App_Init
    FuncFunc : 初始化信息
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
unsigned char App_Init( void )
{
	unsigned char ucRetCode = APP_FAILURE;

	ucRetCode = App_GetConfigPrm();
	if( APP_SUCCESS!=ucRetCode )
	{
		return ucRetCode;
	}

	ucRetCode = App_GetVersion();
	if( APP_SUCCESS!=ucRetCode )
	{
		return ucRetCode;
	}
	
	ucRetCode = App_GetCommCfg();
	if( APP_SUCCESS!=ucRetCode )
	{
		return ucRetCode;
	}

	ucRetCode = App_InitComm(0);
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : App_Help
    FuncFunc : 软件帮助菜单
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
unsigned char App_Help( void )
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

#if 0
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**软件功能:%.58s",APP_FUNCTION);
	AppUtils_FormatDisp("**软件版本:%.58s",APP_VERSION);  
	AppUtils_FormatDisp("**版权所有:%.58s",APP_AUTHOR);
	AppUtils_FormatDisp("**软件联系:%.58s",APP_CONTACT);
	AppUtils_FormatDisp("**软件描述:%.58s",APP_DESCPTION);
	AppUtils_FormatDisp("**软件发布:%.58s",APP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
#else
	AppUtils_FormatDisp("*****************************Help****************************");
	AppUtils_FormatDisp("**软件功能:%.*s",APP_ALIGNWIDTH,APP_FUNCTION);
	AppUtils_FormatDisp("**软件版本:%.*s",APP_ALIGNWIDTH,APP_VERSION);  
	AppUtils_FormatDisp("**版权所有:%.*s",APP_ALIGNWIDTH,APP_AUTHOR);
	AppUtils_FormatDisp("**软件联系:%.*s",APP_ALIGNWIDTH,APP_CONTACT);
	AppUtils_FormatDisp("**软件描述:%.*s",APP_ALIGNWIDTH,APP_DESCPTION);
	AppUtils_FormatDisp("**软件发布:%.*s",APP_ALIGNWIDTH,APP_DATE);
	AppUtils_FormatDisp("*************************************************************");
	AppUtils_FormatDisp("\n");
#endif
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_DrawInterface
    FuncFunc : 画软件应用界面
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
unsigned char App_DrawInterface( void )
{
	unsigned char aucDispBuf[128],aucTitle[64];
	unsigned char ucKey = 0;

	if( !g_mApp.ucFirstRun )
	{
		g_mApp.ucFirstRun = 1;
	}
	
	AppUtils_Cls();
	
	if( strlen(g_mApp.aucUserName) )
	{	
		memset(aucDispBuf,0,sizeof(aucDispBuf));
		memset(aucDispBuf,'*',48);

		memset(aucTitle,0,sizeof(aucTitle));
		sprintf(aucTitle,"欢迎%s使用",g_mApp.aucUserName);
		memcpy(aucDispBuf+(48-strlen(aucTitle))/2,aucTitle,strlen(aucTitle));
	
		AppUtils_FormatDisp("%s\n",aucDispBuf);
		
	}
	AppUtils_FormatDisp("*********************工具集应用*****************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("**********************应用类型******************");
	AppUtils_FormatDisp("*********************1.Demo应用*****************");
	AppUtils_FormatDisp("*********************H.帮    助*****************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("************************************************");
	//AppUtils_FormatDisp("***********H.帮    助***************************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("************************************************");
	AppUtils_FormatDisp("************************************************");	
	
	return APP_SUCCESS;
}

/***********************************************************************************************
	FuncName : App_SelectOption
    FuncFunc : 应用菜单
	Input	 : None
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
    Author	 : Sunrier
    Date     : 2016-12-23 10:12:55
    Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_SelectOption( void )
{
	unsigned char ucKey = 0;
	unsigned char ucRetCode = 0;
	
RESTART:


	App_DrawInterface();

	AppUtils_DisplayLeft("请输入您需要操作的类型:\n",LINE1);
	AppUtils_FlushKbd();
	ucKey = AppUtils_WaitKey(60);
	
	switch( ucKey )
	{
		case '1':
			ucRetCode = DemoApp_Menu((void *)0);
			break;
		
		case 'H':
		case 'h':
			ucRetCode = App_Help();
			break;
		case 'T':
		case 't':
			ucRetCode = App_Test();
			break;
		case 0x1B:
		case 0x00:
			return APP_SUCCESS;
		default:
			//AppUtils_FormatDisp("ucKey =  %d,%c,0x%x\n",ucKey,ucKey,ucKey);
			//AppUtils_WaitKey(0);
			goto RESTART;
	}
	
	return ucRetCode;
}

/***********************************************************************************************
	FuncName : App_PrintWidthHexAsc
	FuncFunc : 将数据信息保存到LOG日志文件
	Input	 : unsigned char *	— pucInputTitle	输入的标题
			   unsigned char *	— pucInputData		输入的数据
			   unsigned int		— uiInputDataLen	输入的数据长度
	Output	 : None
	Return	 : unsigned char	— 成功,返回APP_SUCCESS
								— 失败,返回APP_FAILURE
	Author	 : Sunrier
	Date     : 2014-12-24 12:00:55
	Descp    : None
	History  : None
	Other    : None
*************************************************************************************************/
unsigned char App_PrintWidthHexAsc(unsigned char *pucInputTitle,unsigned char *pucInputData,unsigned int uiInputDataLen)
{
	AppUtils_AppendInfoToFile(0, 0, GLOBAL_DEFAULTLOGPATH, g_mApp.aucLogFileName, 6, 6, pucInputTitle, pucInputData, uiInputDataLen, 2, APP_MAXBUFFER);

	return APP_SUCCESS;
}


/***********************************************************************************************
	FuncName 	: main
	FuncFunc 	: 入口函数
	Input	 	: int 	 — argc 接受参数个数
				  char * — argv 接受内容
	Output	 	: None
	Return	 	: int — 返回操作结果
    Author		: Sunrier
    Date     	: 2016-12-23 10:13:55
    Descp    	: None 
	History  	: None
	Other    	: None
*************************************************************************************************/
int main(int argc,char *argv[])
{
	unsigned char ucKey = 0,ucRetCode = 0;
	
	ucRetCode = App_Init();
	if( APP_SUCCESS!=ucRetCode )
	{
		return ucRetCode;
	}

	if( !SetConsoleCtrlHandler((PHANDLER_ROUTINE)App_ConsoleHandler, TRUE) )
	{
		//AppUtils_Warning("安装事件处理失败!\n");
		return 0;
	}
	
	while(1)
	{
		App_SelectOption();
		AppUtils_DisplayLeft("\n按任意键继续刷新界面,退出(Esc)?\n",LINE2);
		ucKey = AppUtils_WaitKey(3000);
		if( 0x1B==ucKey || 0x00==ucKey )
		{
			SetConsoleCtrlHandler((PHANDLER_ROUTINE)App_ConsoleHandler, FALSE);
			return 0;
		}
	}

	return 0;
}

