#include "task_manager.h"

int main() {
    Task tasks[100];
    int taskCount = 0;

    int choice;
    while (1) {
        printf("\n1. Add a task\n2. Modify a task\n3. Delete a task\n4. Filter by priority\n5. Filter by deadline\n6. Mark a task as completed\n7. Display all tasks\n8. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                printf("Index of the task to modify: ");
                int index;
                scanf("%d", &index);
                if (index < 1 || index > taskCount) {
                    printf("Invalid index\n");
                    break;
                }
                modifyTask(tasks, taskCount, index - 1);
                break;
            case 3:
                printf("Index of the task to delete: ");
                scanf("%d", &index);
                if (index < 1 || index > taskCount) {
                    printf("Invalid index\n");
                    break;
                }
                deleteTask(tasks, &taskCount, index - 1);
                break;
            case 4:
                printf("Priority to filter: ");
                char priority[10];
                scanf("%s", priority);
                int filteredCount;
                Task *filteredTasks = filterByPriority(tasks, taskCount, priority, &filteredCount);
                displayTasks(filteredTasks, filteredCount);
                free(filteredTasks);
                break;
            case 5:
                printf("Deadline to filter: ");
                char deadline[10];
                scanf("%s", deadline);
                int filteredCountDeadline;
                Task *filteredTasksByDeadline = filterByDeadline(tasks, taskCount, deadline, &filteredCountDeadline);
                displayTasks(filteredTasksByDeadline, filteredCountDeadline);
                free(filteredTasksByDeadline);
                break;
            case 6:
                if (taskCount == 0) {
                    printf("no task added yet\n");
                    break;
                }
                printf("Index of the task to mark as completed: ");
                scanf("%d", &index);
                if (index < 1 || index > taskCount) {
                    printf("Invalid index\n");
                    break;
                }
                markAsCompleted(tasks, taskCount, index - 1);
                printf("Task marked as completed\n");
                break;
            case 7:
                displayTasks(tasks, taskCount);
                break;
            case 8:
                saveTasksToFile(tasks, taskCount);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
