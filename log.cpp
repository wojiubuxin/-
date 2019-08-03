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
