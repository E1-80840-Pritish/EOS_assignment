#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

void sigint_hadler(int sig)
{
    printf("signal caught : %d\n",sig);
}

int main()
{
    signal(SIGINT,sigint_hadler);
    char *ptr, cmd[512], *args[32];
    int i,ret,err,s;
    
    
    while(1)
    {
        
        printf("cmd-> ");
        gets(cmd);
        if (cmd[0] == '\0') {
            continue; 
        }

        i=0;
        ptr = strtok(cmd," ");
        args[i] = ptr;
        i++;

        do
        {
            ptr = strtok(NULL," ");
            args[i] = ptr;
            i++;
        } while (ptr != NULL);
        
        if(strcmp(args[0],"exit")==0)
            _exit(0);
        else if (strcmp(args[0],"cd")==0)
            chdir(args[1]);
        else
        {
            ret = fork();
            if(ret == 0)
            {
                err = execvp(args[0],args);
                if(err < 0)
                {
                    perror("bad command!!!\n");
                    _exit(1);
                }    
            }
            else
                 waitpid(-1,&s,0);
        }        
    }
    return 0;
}