#include <stdio.h>
int main()
{
    int num, i, sum = 0;
    char ch;
    printf("Enter number of students: ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter student marks: ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter gender: ");
    scanf(" %c", &ch);

    if (ch == 'b')
    {
        for (i = 0; i < num; i = i + 2)
        {
            sum += arr[i];
        }
    }
    if (ch == 'g')
    {
        for (i = 1; i < num; i = i + 2)
        {
            sum += arr[i];
        }
    }
    printf("%d", sum);
    return 0;
}