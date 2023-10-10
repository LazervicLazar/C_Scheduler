//  Lazar Lazarevic
//  Apr/23/23 ©
/*
    This is a file that contains the main functions used in project10.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "job.h"


///////////////////
// main function //
///////////////////

int main() {
    // Declaration of all the variables used.
    char code;
    char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
    int num_cpus, num_gpus, memory, priority;
    double time;
    // Struct pointer we will use to construct our linked list.
    struct job *scheduler = NULL;
    // Listing all the options to the user.
    help();
    printf("\n");
    // Infinite loop that goes until user inputs q.
    for (;;) {
        // read operation code
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n') /* skips to end of line */
            ;

        // run operation
        switch (code) {
            case 'h':
                help();
                break;
            case 'a':
                read1(job_name, user_name, &num_cpus, &num_gpus, &memory, &time, &priority);
                scheduler = add_job(scheduler, job_name, user_name, num_cpus, num_gpus, memory, time, priority);
                break;
            case 'p':
                scheduler = pop_job(scheduler);
                break;
            case 'u':
                read1(NULL, user_name, NULL, NULL, NULL, NULL, NULL);
                list_user(scheduler, user_name);
                break;
            case 'j':
                read1(NULL, NULL, &num_cpus, &num_gpus, &memory, &time, NULL);
                list_jobs(scheduler, num_cpus, num_gpus, memory, time);
                break;
            case 'l':
                list_all_jobs(scheduler);
                break;
            case 'q':
                scheduler = clear_jobs(scheduler);
                return 0;
            default:
                printf("Illegal operation code!\n");
        }
        printf("\n");
    }
}

