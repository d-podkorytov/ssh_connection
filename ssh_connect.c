// (C) Dmitry Podkorytov

#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int match(const char * Str,const char * SubStr)
{
// printf("%s:%d Str=%s SubStr=%s \n",__FILE__,__LINE__,Str,SubStr);
// printf("%s:%d substr=%d \n",__FILE__,__LINE__,strstr(Str,SubStr)-Str);
// fflush(stdout);
 return strstr(Str,SubStr)-Str;
}

int main(int argc , char * argv[])
{char * ENV;
 int i;
 FILE * F;
 time_t T;
 
 time(&T);
 
 F=fopen("/var/log/ssh_connect.log","at");

// fprintf(F,"Login %s",ctime(&T));
// fflush(F);

 if(getenv("SSH_CONNECTION")==0) 
   { fprintf(F," Login from console %s\n",ctime(&T));
     fflush(F);
     fclose(F); 
     return -1;

   }
  
 ENV=malloc(1024*16);
 
 sprintf(ENV,"%s",getenv("SSH_CONNECTION")?getenv("SSH_CONNECTION"):"not set");
 
// fprintf(F,"SSH_CONNECTION=%s \n",ENV);
 fprintf(F,"Connection from: %s %s",ENV,ctime(&T));
 fflush(F);

 for(i=1;i<argc;i++)
  { //fprintf(F,"argv[%d]=%s\n",i,argv[i]);
    //fflush(F);
   
    //fprintf(F,"match=%d\n",match(ENV,argv[i]));
    //fflush(F);
    
    if (match(ENV,argv[i])==0) return 0;
  }

 fprintf(F,"Try to login from unallowed address %s %s",ENV,ctime(&T));
 fflush(F);
 sleep(0);
 free(ENV);

 fclose(F);

 kill(getppid(),SIGTERM);
 kill(getppid(),SIGBUS);
 
 kill(0,SIGTERM);
 kill(0,SIGBUS);

 return 1;
}
