// This code takes the input of a matrix that denotes marks given by rows number of teachers to columns number of students and returns the student who scored maximum marks

#include <stdio.h>


int main()
{

    int teachers, students;
    printf("Enter number of teachers: ");
    scanf("%d", &teachers);

    printf("Enter number of students: ");
    scanf("%d", &students);

    int marks[teachers][students];

    for (int i = 0; i < teachers; i++)
    {
        for (int j = 0; j < students; j++)
        {
            printf("Enter marks by teacher %d to student %d: ", i + 1, j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    int max_marks = 0;
    int max_idx = 0;
    for (int i = 0; i < students; i++)
    {
        int cur_marks = 0;
        for (int j = 0; j < teachers; j++)
        {
            cur_marks += marks[j][i];
        }
        if (max_marks < cur_marks)
        {
            max_marks = cur_marks;
            max_idx = i;
        }
    }

    printf("Max marks %d are scored by student %d\n", max_marks, max_idx + 1);

    return 0;
}