#include <stdio.h>

typedef struct
{
    int roll;
    char name[30];
    double cgpa;
} studentTemp;

int main()
{
    int n;
    FILE *scholarshipFile, *simpleFile, *punishmentFile;

    // input number of students
    printf("Enter how many student results you want to store: ");
    scanf("%d", &n);

    studentTemp student[n];
    studentTemp temp;

    // input student's data
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data (Roll, one_word_Name, CGPA) of student no. %d\n", i + 1);
        scanf("%d %s %lf", &student[i].roll, &student[i].name, &student[i].cgpa);
    }

    // alternative input formate
    /* for (int i = 0; i < n; i++)
    {
        printf("\nEnter the data of student no. %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &student[i].roll);
        printf("Name: ");
        scanf("\n");
        scanf("%[^\n]%*c", &student[i].name);
        printf("CGPA: ");
        scanf("%lf", &student[i].cgpa);
    } */

    // data sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (student[j].cgpa < student[j + 1].cgpa)
            {
                // Swap the two records
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }

    // output student's data
    printf("\nRoll\tName\tCGPA\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%0.2lf\n", student[i].roll, student[i].name, student[i].cgpa);
    }

    // creating output files
    scholarshipFile = fopen("scholarship.txt", "w");
    fprintf(scholarshipFile, "Those, who obtain 3.5 or above will get a scholarship\n\nRoll\tName\tCGPA\n");
    fclose(scholarshipFile);

    simpleFile = fopen("simple.txt", "w");
    fprintf(simpleFile, "Those, who obtain in between 3.0 and 3.5 pased simply\n\nRoll\tName\tCGPA\n");
    fclose(simpleFile);

    punishmentFile = fopen("punishment.txt", "w");
    fprintf(punishmentFile, "Those, who obtain below 3.0 will receive punishment\n\nRoll\tName\tCGPA\n");
    fclose(punishmentFile);

    // appending scholarship file
    for (int i = 0; i < n; i++)
    {
        if (student[i].cgpa >= 3.5 && student[i].cgpa <= 4.0)
        {
            scholarshipFile = fopen("scholarship.txt", "a");
            fprintf(scholarshipFile, "%d\t\t%s\t\t%0.2lf\n", student[i].roll, student[i].name, student[i].cgpa);
            fclose(scholarshipFile);
        }
    }

    // appending simple file
    for (int i = 0; i < n; i++)
    {
        if (student[i].cgpa >= 3.0 && student[i].cgpa < 3.5)
        {
            simpleFile = fopen("simple.txt", "a");
            fprintf(simpleFile, "%d\t\t%s\t\t%0.2lf\n", student[i].roll, student[i].name, student[i].cgpa);
            fclose(simpleFile);
        }
    }

    // appending punishment file
    for (int i = 0; i < n; i++)
    {
        if (student[i].cgpa > 0 && student[i].cgpa < 3.0)
        {
            punishmentFile = fopen("punishment.txt", "a");
            fprintf(punishmentFile, "%d\t\t%s\t\t%0.2lf\n", student[i].roll, student[i].name, student[i].cgpa);
            fclose(punishmentFile);
        }
    }

    return 0;
}