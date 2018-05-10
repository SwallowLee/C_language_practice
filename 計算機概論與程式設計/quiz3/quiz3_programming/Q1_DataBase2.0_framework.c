#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STUDENT_MAX     100
#define NAME_MAX_LENGTH 100

//structure declaration
typedef struct
{
    int grades;

}subject;
typedef struct
{
    char name[NAME_MAX_LENGTH];
    subject exams[2];
    float average;
}studentNode;

typedef struct
{
    studentNode studentList[STUDENT_MAX];
    int studentNum;
    double avg[2];
}gradeNode;

//function declaration
void update_student(gradeNode* myGrades);
void add_student(gradeNode* myGrades);
void show_student(gradeNode myGrades);
void rm_student(gradeNode* myGrades);
void search_student(gradeNode myGrades);
int main(void)
{
    char ch;
    gradeNode myGrades;
    myGrades.studentNum = 0;

    while(1)
    {
        printf(" -------------------------------------------------\n");
        printf("| 1. Add a student and his/her score to list.    |\n");
        printf("| 2. Remove a student from list.                 |\n");
        printf("| 3. Show the information of the list.           |\n");
        printf("| 4. Update a student's score.                   |\n");
        printf("| 5. Search a student's score.                   |\n");
        printf("| 6. Exit.                                       |\n");
        printf(" -------------------------------------------------\n");
        printf("What are you going to do? - ");
        scanf(" %c",&ch);
        switch(ch)
        {
            case '1':
                add_student(&myGrades);
                break;
            case '2':
                rm_student(&myGrades);
                break;
            case '3':
                show_student(myGrades);
                break;
            case '4':
                update_student(&myGrades);
                break;
            case '5':
                search_student(myGrades);
				break;
			case '6':
                return 0;
            default:
                printf("Wrong input. Please enter an input 1-4.\n");
                break;
        }
        printf("\n");

    }
    return 0;
}

void add_student(gradeNode* myGrades)
{
    int i,j,exist=0,time=0,re1,re2,re3,re4,re5,re6;
    float aver,add_eng,add_chi;
    char add_name[NAME_MAX_LENGTH];
    printf("Adding name: ");
    scanf("%s",&add_name);
    for(i=0;i<myGrades->studentNum;i++)
    {
        if(strcmp(add_name,myGrades->studentList[i].name)==0)
        {
            exist=1;
            break;
        }
    }
    if(exist==1)
    {
        printf("Student %s has already been added\n",add_name);
    }
    else
    {
        printf("Adding English grade: ");
        scanf("%f",&add_eng);
        printf("Adding Chinese grade: ");
        scanf("%f",&add_chi);
        aver=(add_eng+add_chi)/2.0;
      // printf("%0.f %0.f",add_chi,add_eng);


            strcpy(myGrades->studentList[myGrades->studentNum].name,add_name);
                myGrades->studentList[myGrades->studentNum].exams[0].grades=(int)add_eng;
                myGrades->studentList[myGrades->studentNum].exams[1].grades=(int)add_chi;
                myGrades->studentList[myGrades->studentNum].average=aver;
    myGrades->studentNum++;
    }
}


void show_student(gradeNode myGrades)
{
    int i;
    float aver1=0,aver2=0;
    if(myGrades.studentNum==0)
    {
        printf("The list is empty.");
    }
else
{printf("Name    English Chinese Avg\n");
for(i=0;i<myGrades.studentNum;i++)
{
    printf("%-8s",myGrades.studentList[i].name);
    printf("%0.f",myGrades.studentList[i].exams[0].grades);
    printf("     %0.f",myGrades.studentList[i].exams[1].grades);
    printf("     %1.f\n",myGrades.studentList[i].average);
    aver1=aver1+myGrades.studentList[i].exams[0].grades;
    aver2=aver2+myGrades.studentList[i].exams[1].grades;
}
aver1=aver1/myGrades.studentNum;
aver2=aver2/myGrades.studentNum;
printf("AVG     %2.f  %2.f",aver1,aver2);
}
}


void rm_student(gradeNode* myGrades)
{
    int i,j,exist=0;
    char rm_name[NAME_MAX_LENGTH];
    printf("Removing Name: ");
    scanf("%s",&rm_name);
    for(i=0;i<myGrades->studentNum;i++)
    {
        if(strcmp(rm_name,myGrades->studentList[i].name)==0)
        {
            exist=1;
            break;
        }
    }
    if(exist==0)
    {
        printf("No such a student called %s",rm_name);
    }
    else
    {
        for(j=i;j<myGrades->studentNum;j++)
        {
            strcpy(myGrades->studentList[j].name,myGrades->studentList[j+1].name);
            myGrades->studentList[j].exams[0].grades=myGrades->studentList[j+1].exams[0].grades;
            myGrades->studentList[j].exams[1].grades=myGrades->studentList[j+1].exams[1].grades;
            myGrades->studentList[j].average=myGrades->studentList[j+1].average;
        }
    }
    myGrades->studentNum--;
}



void update_student(gradeNode* myGrades)
{
    char up_name[NAME_MAX_LENGTH];
    int eng,chi,p=0,i;
    printf("Student Name:");
    scanf("%s",&up_name);
    for(i=0;i<myGrades->studentNum;i++)
    {
        if(strcmp(myGrades->studentList[i].name,up_name)==0)
        {
            p=1;
            printf("Original English Grade: %d",myGrades->studentList[i].exams[0].grades);
            printf("NewGrade:");
            scanf("%d",&eng);
            if(eng!=-1)
                myGrades->studentList[i].exams[0].grades=eng;
            printf("Original Chinese Grade: %d",myGrades->studentList[i].exams[1].grades);
            printf("NewGrade:");
            scanf("%d",&chi);
            if(chi!=-1)
                myGrades->studentList[i].exams[0].grades=chi;
            break;
        }
    }
    if(p==0)
        printf("No such a student called %s",up_name);
    /**************************
        Finish you code here
    **************************/
}

void search_student(gradeNode myGrades)
{
    int i,p=0;
    char search[NAME_MAX_LENGTH];
    printf("Student Name:");
    scanf("%s",&search);
    for(i=0;i<myGrades.studentNum;i++)
    {
        if(strcmp(myGrades.studentList[i].name,search)==0)
        {
            p=1;
            printf("Name    English Chinese Avg\n");
   printf("%-8s",myGrades.studentList[i].name);
    printf("%0.f",myGrades.studentList[i].exams[0].grades);
    printf("     %0.f",myGrades.studentList[i].exams[1].grades);
    printf("     %1.f\n",myGrades.studentList[i].average);
    break;
        }
    }
    if(p==0)
        printf("No such a student called %s",search);
    /**************************
        Finish you code here
    **************************/
}

