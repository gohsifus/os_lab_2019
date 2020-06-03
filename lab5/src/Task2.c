#include <getopt.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct for_fac_struc {
    int begin;
    int end;
    int mod;
    int *result;
};

void factorial(struct for_fac_struc *struc);
void start_thread(int beg, int end, int mod, int *result, int j);

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
    pthread_t threads[100];
    struct for_fac_struc struc[100];

int main(int argc, char **argv) {
    int result = 1;
    int k=-1, pnum=-1, mod=-1;

while (1) {
    int current_optind = optind ? optind : 1;

    static struct option options[] = {{"k", required_argument, 0, 0},
                                      {"pnum", required_argument, 0, 0},
                                      {"mod", required_argument, 0, 0},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    
    int c = getopt_long(argc, argv, "kpm", options, &option_index);

    if (c == -1) break;
    switch (c) {
        case 0: 
        switch (option_index) {
            case 0:
                k = strtod(optarg, NULL);
                if (k < 0) {
                    printf("k is a positive number\n");
                    return 1;
                }
                break;
            case 1:      
                pnum = atoi(optarg);
                if (pnum <= 0 || pnum > 100) {
                    printf("pnum is a positive number\n");
                    return 1;
                }
                break;
            case 2:
                mod = atoi(optarg);
                if (mod < 2) {
                    printf("mod should be positive\n");
                    return 1;
                }
                break;    
        }
         case '?':
                break;

        default:
        printf("!d\n");
            printf("getopt returned character code 0%o?\n", c);
    } 
  }

  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }

  if (k == -1 || pnum == -1 || mod == -1) {
    printf("Usage: %s -k \"num\" --pnum \"num\" --mod \"num\" %d %d %d\n",
           argv[0], k, pnum, mod);
    return 1;
  }

    int step = k / pnum;
    int beg = 1;
    int end = 1 + step + k % pnum;

    printf("step - %d\n", step);
    int j;

    for (j = 0; j < pnum; j++) {

       
        start_thread(beg, end, mod, &result, j);
       
        beg = end;
        end += step;
    }

    for (j = 0; j < pnum; j++) {
        pthread_join(threads[j], NULL);
    }

  printf("result - %d\n", result);
  return 0;
}

void start_thread(int beg, int end, int mod, int *result, int j) {

        struc[j].begin = beg;
        struc[j].end = end;
        struc[j].mod = mod;
        struc[j].result = result;

        printf("%d - %d\n", struc[j].begin, struc[j].end);

        pthread_create(&threads[j], NULL, (void *)factorial, &struc[j]);
}


void factorial(struct for_fac_struc *struc) 
{
    
    int begin=struc->begin;
    int end=struc->end;
    int mod=struc->mod;
    int i;
    int res = 1;

    for (i = begin; i < end; i++) {
        res *= i;
        res %= mod;
    }

    pthread_mutex_lock(&mut);
    *(struc->result) *= res;
    *(struc->result) %= mod;
    pthread_mutex_unlock(&mut);
}
