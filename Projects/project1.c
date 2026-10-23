#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

char tasks[MAX][LEN];
int done[MAX];
int count = 0;

void showMenu()
{
    printf("\n===== TASK MANAGER =====\n");
    printf("1. Add a task\n");
    printf("2. View all tasks\n");
    printf("3. Mark a task as done\n");
    printf("4. Delete a task\n");
    printf("5. Show pending count\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addTask()
{
    if (count == MAX)
    {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter task: ");
    fgets(tasks[count], LEN, stdin);
    tasks[count][strcspn(tasks[count], "\n")] = '\0';
    done[count] = 0;
    count++;
    printf("Task added!\n");
}

void viewTasks()
{
    int i;
    if (count == 0)
    {
        printf("No tasks yet.\n");
        return;
    }
    for (i = 0; i < count; i++)
    {
        printf("%d. %s", i + 1, tasks[i]);
        if (done[i] == 1)
        {
            printf(" [DONE]\n");
        }
        else
        {
            printf(" [PENDING]\n");
        }
    }
}

void markDone()
{
    int num;
    printf("Enter task number: ");
    scanf("%d", &num);
    if (num >= 1 && num <= count)
    {
        done[num - 1] = 1;
        printf("Task marked as done!\n");
    }
    else
    {
        printf("Invalid task number.\n");
    }
}

void deleteTask()
{
    int num, i;
    printf("Enter task number to delete: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid task number.\n");
        return;
    }
    for (i = num - 1; i < count - 1; i++)
    {
        strcpy(tasks[i], tasks[i + 1]);
        done[i] = done[i + 1];
    }
    count--;
    printf("Task deleted!\n");
}

int countPending()
{
    int i, pending = 0;
    for (i = 0; i < count; i++)
    {
        if (done[i] == 0)
        {
            pending++;
        }
    }
    return pending;
}

int main()
{
    int choice;

    do
    {
        showMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markDone();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            printf("Pending tasks: %d\n", countPending());
            break;
        case 6:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);

    return 0;
}