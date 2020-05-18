#include <stdio.h>
#include <stdlib.h>
 
int main (int argc, char **argv) {
 
        /* fork и exec в порожденном процессе */
        if (fork() == 0) {
  		printf("Выполняется %s", argv[0]);
  		execl("seq"," ",argv[1], argv[2], NULL);
        }
        printf("Execution continues in parent process\n");
}
