#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// 2. From a parent process (A) create a child process (B). The child (B) 
// in turn creates new child process (C) and it (C) in turn create new child (D). All these
// processes should run concurrently for 5 seconds and cleaned up properly upon termination
int main() {
    int i, pidb, sb, pidc,pidd,pide, sc;

    // parent a
    pidb = fork();
    if(pidb == 0) { 
        // child b
        pidc = fork();
        if(pidc == 0) {
                pidd = fork();
                if(pidd == 0) {
                        pide = fork();
                        if(pide == 0) {
                            // child e
                            for(i=1; i<=5; i++) {
                                printf("E. sunbeam desd: %d\n", i);
                                sleep(1);
                            }
                            _exit(0);
                        }
                    // child d
                    for(i=1; i<=5; i++) {
                        printf("D. sunbeam desd: %d\n", i);
                        sleep(1);
                    }
                    _exit(0);
                }
        
            // child c
            for(i=1; i<=5; i++) {
                printf("C. sunbeam desd: %d\n", i);
                sleep(1);
            }
            _exit(0);
        }
        
        // child b
        for(i=1; i<=5; i++) {
            printf("B. sunbeam pune: %d\n", i);
            sleep(1);
        }
        waitpid(pidc, &sc, 0);
        _exit(0);
    }

    // parent a
    for(i=1; i<=5; i++) {
        printf("A. sunbeam: %d\n", i);
        sleep(1);
    }
    waitpid(pidb, &sb, 0);

    return 0;
}