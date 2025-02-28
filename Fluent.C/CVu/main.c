#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
#include <sys/stat.h>
#elif defined _WIN32
#include <windows.h>
#endif

int main()
{
  char dirname[50];
  #ifdef __unix__
  sprintf(dirname, "%s%s", getenv("HOME"), "/newdir/");
  #elif defined _WIN32
  sprintf(dirname, "%s%s%s", getenv("HOMEDRIVE"), getenv("HOMEPATH"), "\\newdir\\");
  #endif
  #ifdef __unix__
  mkdir(dirname,S_IRWXU);
  #elif defined _WIN32
  CreateDirectory(dirname, NULL);
  #endif
  return 0;
}
