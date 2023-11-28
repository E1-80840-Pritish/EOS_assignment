#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void fun(int max){
    int i;
    for(i= 1; i<=max; i++){
        printf("[%d] fun: %d\n", getpid(),i);
        sleep(1);
    }

}
int main(){
    int i, max=5, status, ret, pid[5];
    for(i =0; i<5; i++){
        pid[i] = fork();
        if(pid[i] == 0){
            fun(5);
            _exit(1);

        }
    }
    fun(5);

    for (i=0; i<5; i++){
        ret = waitpid(-1, &status, 0);
        printf("chlid[%d] exit status: %d\n", ret, WEXITSTATUS(status));
    } 
    return 0;
}