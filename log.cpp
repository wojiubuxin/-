#include <string>
#inlcude <Windows.h>
#include <stdio.h>

void LogPrintf(const char* msg, ...)
{
  int flagsize = 256;
  char FileName[flagsize];
  char log_Time[flagsize];
  
  CString FilePath = "(××)日志\\";
  CTime time = CTime::GetCurrentTime();
  //GetCurrentDirectory()
  SHCreateDirectoryEx(NULL, FilePath, NULL);
  sprintf(FileName, "%d:%d:%d_log.txt", time.GetYear(), time.GetMonth(), time.GetDay());
  FILE *input = fopen(FileName, "a");
  
  if(NULL != input)
  {
    sprintf(log_Time, "log-[%d:%d]", time.GetHour(), time.GetMinute());
    fprintf(input, log_Time);
    
    va_list argptr;
    va_start(argptr, msg);
    vfprintf(input, msg, argptr);
    fprintf(input, "\n");
    fclose(input);
    va_end(argptr);
  }
}

void set_ini()
{
  CString temp = "set.ini";
  WIN32_FIND_DATA d;
  HANDLE hd = FindFirstFile(temp, &d);
  if(!hd)
  {
    //FindClose
    return;
  }
  mMaxSize = 256;//随意了
  int UserCard[mMaxsize];
  char* re = new char[mMaxSize + 1];
  ZeroMemory(re, mMaxSize);
  //GetPrivateProfileInt(secName,KeyName,IpDefault, IpFileName);
  //GetPrivateProfileString(...);
  CString key = TEXT("Game(或其它标题符号)")；
  CString byCard;
  
  GetPrivateProfileString(key, "text", "", byCard, mMaxszie, temp);
  int temp_size = 0;
  int tempj = 0;
  int suoyini = -1;
  int suoyinj = 0;
  temp_size = byCard.GetLength();
  
  for(int j = 0; j <= temp_size; j++)
  {
    if(byCard[j] >= '0' && byCard[j] <= '9')
    {
      if(suoyini == -1)
      {
        suoyini = j;
      }
    }
    else
    {
      suoyinj = j;
      UserCard[tempj++] = atoi(byCard.Mid(suoyini, suoyinj - suoyini));
      suoyini = -1;
    }
    if(tempj >= mMaxsize)
      break;
  }
}

void SetKeyString()
{
  CString temp = "set.ini";
  CString key = TEXT("Game(或其它标题符号)")；
  __int64 temp_number=a-b;
  //WritePrivateProfileString(secName,keyName,Val,IpFileName);
  WritePrivateProfileString(key, "resetrobothavewinmoney",temp_number, temp);
  
}
