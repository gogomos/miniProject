#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#define MAX_TASK_NAME_LENGTH 100
#define MAX_TASK_PRIORITY_LENGTH 100
#define MAX_TASK_DEADLINE_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Task {
    char taskName[100];
    char taskPriority[10];
    char taskDeadline[10];
    int isCompleted;
} Task;

void addTask(Task tasks[], int *taskCount);
void modifyTask(Task tasks[], int taskCount, int index);
void deleteTask(Task tasks[], int *taskCount, int index);
Task *filterByPriority(Task tasks[], int taskCount, char *priority, int *filteredCount);
Task *filterByDeadline(Task tasks[], int taskCount, char *deadline, int *filteredCount);
void displayTasks(Task tasks[], int taskCount);
void markAsCompleted(Task tasks[], int taskCount, int index);
void saveTasksToFile(Task tasks[], int taskCount);

#endif 
