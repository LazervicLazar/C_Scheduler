//  Lazar Lazarevic
//  Apr/23/23 ©
/*
    This is a file that contains all the functions used in project10.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "job.h"

// This function prints all the options available to the user.
void help() {
    printf("List of operation codes:\n");
    printf("\t'h' for help;\n");
    printf("\t'a' for adding a job to the scheduler;\n");
    printf("\t'p' for removing a job from the scheduler;\n");
    printf("\t'u' for searching jobs per user;\n");
    printf("\t'j' for searching jobs per capacity;\n");
    printf("\t'l' for listing all jobs;\n");
    printf("\t'q' for quit.\n");
}
// This function reaads user input and stores it in variables of our struct.
void read1(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) {
    if(job_name != NULL) {
        printf("Enter the name of the job: ");
        scanf("%s", job_name);
    }
    if(user_name != NULL) {
        printf("Enter the name of the user: ");
        scanf("%s", user_name);
    }
    if(num_cpus != NULL) {
        printf("Enter the number of CPUs: ");
        scanf("%d", num_cpus);
    }
    if(num_gpus != NULL) {
        printf("Enter the number of GPUs: ");
        scanf("%d", num_gpus);
    }
    if(memory != NULL) {
        printf("Enter the amount of memory: ");
        scanf("%d", memory);
    }
    if(time != NULL) {
        printf("Enter the amount of time: ");
        scanf("%lf", time);
    }
    if(priority != NULL) {
        printf("Enter the priority: ");
        scanf("%d", priority);
    }
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////
///
// Function adds a job to the end of the list
struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) {
    struct job *temp, *curr, *prev;
    // Allocating memory for the new job
    temp = malloc(sizeof(struct job));
    // Error checking if malloc didn't work.
    if (temp == NULL) {
        return scheduler;
    }
    // Saving all the new values into are new job.
    strcpy(temp->job_name, job_name);
    strcpy(temp->user_name, user_name);
    temp->num_cpus = num_cpus;
    temp->num_gpus = num_gpus;
    temp->memory = memory;
    temp->time = time;
    temp->priority = priority;
    temp->next = NULL;
    
    // for that finds the end of the list or stops when priority given by use is less than priority of jobs
    for (curr = scheduler, prev = NULL; curr != NULL && priority <= curr->priority; prev = curr, curr = curr->next);
    // Checking if linked list is empty.
    if (scheduler == NULL || priority > scheduler->priority) {
            temp->next = scheduler;
            return temp;
        }
    // Check if there are no elements in the list.
    if (prev == NULL) {
        return temp;
    }
    // Appending the new job to the end.
    else {
        temp->next = curr;
        prev->next = temp;
        return scheduler;
    }
}

// Function that prints and deletes the head of the list.
struct job *pop_job(struct job *scheduler) {
    // Check if list has any elements.
    if (scheduler == NULL)
        return scheduler;
    struct job *prev, *curr;
    prev = scheduler;
    // Again checking if list has any elements.
    if (prev == NULL) {
        scheduler = NULL;
        return scheduler;
    }
    curr = prev->next;
    // Formating and printing output / the first element.
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", prev->job_name, prev->user_name, prev->num_cpus, prev->num_gpus, prev->memory, prev->time, prev->priority);
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    scheduler = curr;
    // Checking if only one element was in the list are freeing it if so.
    if (prev->next == NULL){
        free(prev);
        return NULL;
    }
    // Pointing back the original pointer to the new head.
    scheduler = curr;
    // Freeing the old head we "poped"
    free(prev);
    return scheduler;
}

// Lists the jobs that have the username provided by user.
void list_user(struct job *scheduler, char *user_name) {

    struct job *curr;
    // Check if list has any elements.
    if (scheduler == NULL)
        return;
    // Printing the header only if we find the username and breaking the loop.
    for (curr = scheduler; curr != NULL; curr = curr->next){
        if(strcmp(curr->user_name , user_name) == 0){
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            break;
        }
        
    }
    // Printing the job if we find the matching username provided by the user.
    for (curr = scheduler; curr != NULL; curr = curr->next) {
        if(strcmp(curr->user_name , user_name) == 0){
            printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", curr->job_name, curr->user_name, curr->num_cpus, curr->num_gpus, curr->memory, curr->time, curr->priority);
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        }
            
    }

}
// Function that lists all the job that have necessary equipement to complete the job.
void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) {
    struct job *curr;
    // Check if list has any elements.
    if (scheduler == NULL)
        return;
    // Printing the header only if we find the values necessary to complete the job and breaking the loop.
    for (curr = scheduler; curr != NULL; curr = curr->next){
        if((curr->num_cpus <= num_cpus) && (curr->num_gpus <= num_gpus) && (curr->memory <= memory) && (curr->time <= time)){
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                break;}
    }
    // Printing the job if we find the matching values necessary to complete the job provided by the user.
    for (curr = scheduler; curr != NULL; curr = curr->next){
        if((curr->num_cpus <= num_cpus) && (curr->num_gpus <= num_gpus) && (curr->memory <= memory) && (curr->time <= time)){
            printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", curr->job_name, curr->user_name, curr->num_cpus, curr->num_gpus, curr->memory, curr->time, curr->priority);
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");}
    }

}
// Function that lists all the jobs in the list.
void list_all_jobs(struct job *scheduler) {
    struct job *curr;
    // Check if list has any elements.
    if (scheduler == NULL)
        return;
    // Printing the header once.
    if (scheduler != NULL){
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");}
    // Loop that goes through the whole list and prints all the components with an appropriate format.
    for (curr = scheduler; curr != NULL; curr = curr->next){
        printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", curr->job_name, curr->user_name, curr->num_cpus, curr->num_gpus, curr->memory, curr->time, curr->priority);
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    }
    
}
// Function that deletes all the jobs and frees the memory.
struct job * clear_jobs(struct job *scheduler) {

    struct job *temp;
    // Going through the whole list and releasing every job.
    while(scheduler != NULL) {
        temp = scheduler;
        scheduler = scheduler->next;
        free(temp);
    }
    // Returning NULL at the end.
    return NULL;
}
