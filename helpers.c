#include "task_manager.h"

void addTask(Task tasks[], int *taskCount) {
    printf("Enter task name: ");
    scanf(" %[^\n]", tasks[*taskCount].taskName);
    printf("Enter task priority: ");
    scanf(" %[^\n]", tasks[*taskCount].taskPriority);
    printf("Enter task deadline: ");
    scanf(" %[^\n]", tasks[*taskCount].taskDeadline);
    tasks[*taskCount].isCompleted = 0;
    (*taskCount)++;
}

void modifyTask(Task tasks[], int taskCount, int index) {
    printf("Enter new task name: ");
    scanf(" %[^\n]", tasks[index].taskName);
    printf("Enter new task priority: ");
    scanf(" %[^\n]", tasks[index].taskPriority);
    printf("Enter new task deadline: ");
    scanf(" %[^\n]", tasks[index].taskDeadline);
    tasks[index].isCompleted = 0;
}

void deleteTask(Task tasks[], int *taskCount, int index) {
    for (int i = index; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*taskCount)--;
}

Task *filterByPriority(Task tasks[], int taskCount, char *priority, int *filteredCount) {
    Task *filteredTasks = (Task *)malloc(taskCount * sizeof(Task));
    *filteredCount = 0;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].taskPriority, priority) == 0) {
            filteredTasks[*filteredCount] = tasks[i];
            (*filteredCount)++;
        }
    }
    return filteredTasks;
}

Task *filterByDeadline(Task tasks[], int taskCount, char *deadline, int *filteredCount) {
    Task *filteredTasks = (Task *)malloc(taskCount * sizeof(Task));
    *filteredCount = 0;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].taskDeadline, deadline) == 0) {
            filteredTasks[*filteredCount] = tasks[i];
            (*filteredCount)++;
        }
    }
    return filteredTasks;
}

void displayTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks, click 1 to add task.\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s - Priority: %s - Deadline: %s - Completed: %s\n", i + 1, tasks[i].taskName, tasks[i].taskPriority, tasks[i].taskDeadline, tasks[i].isCompleted ? "Yes" : "No");
    }
}

void markAsCompleted(Task tasks[], int taskCount, int index) {
    tasks[index].isCompleted = 1;
}

void saveTasksToFile(Task tasks[], int taskCount) {
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "name: %s| priority: %s| Deadline: %s| Completed: %d\n", tasks[i].taskName, tasks[i].taskPriority, tasks[i].taskDeadline, tasks[i].isCompleted);
    }

    fclose(file);
}