#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STUDENT_MAX     100
#define NAME_MAX_LENGTH 100

//structure declaration
typedef struct
{
    char name[NAME_MAX_LENGTH];
    int grades;
}studentNode;

typedef struct
{
    studentNode studentList[STUDENT_MAX];
    int studentNum;
    double avg;
}gradeNode;

//function declaration
void add_student(gradeNode* myGrades);
void rm_student(gradeNode* myGrades);
void show_student(gradeNode myGrades);
void update_student(gradeNode* myGrades);
void search_student(gradeNode myGrades);


int main(void)
{
    char ch;
    gradeNode myGrades;
    myGrades.studentNum=0;

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
    char add_name[NAME_MAX_LENGTH];
    int add_grade,a,i,j,exist=0,yes=0;
    printf("Adding Name: ");
    scanf("%s",&add_name);
    if(myGrades->studentNum==0)
    {
    	if(strcmp(add_name,myGrades->studentList[0].name)==0)
        {
            printf("Student %s has already been added.",add_name);
            exist=1;
        }
    }
    for(i=0;i<myGrades->studentNum;i++)
    {
        if(strcmp(add_name,myGrades->studentList[i].name)==0)
        {
            printf("Student %s has already been added.",add_name);
            exist=1;
            break;
        }
    }
    if(exist==0)
    {
        printf("Adding grade: ");
        scanf("%d",&add_grade);
        /**********************order*********************************/
        if((*myGrades).studentNum>1)
        {
        	for(i=1;i<myGrades->studentNum;i++)
            {
                if(myGrades->studentList[i-1].grades>add_grade&&myGrades->studentList[i].grades<add_grade)
                {
                    myGrades->studentNum++;
                    for(j=myGrades->studentNum;j>i;j--)
                    {
                        strcpy(myGrades->studentList[j].name,myGrades->studentList[j-1].name);
                        myGrades->studentList[j].grades=myGrades->studentList[j-1].grades;
                    }
                    strcpy(myGrades->studentList[i].name,add_name);
                    myGrades->studentList[i].grades=add_grade;
                    yes=1;
                    break;
                }
                if(myGrades->studentList[i].grades==add_grade)
                {
                	myGrades->studentNum++;
                    for(j=myGrades->studentNum;j>i;j--)
                    {
                        strcpy(myGrades->studentList[j].name,myGrades->studentList[j-1].name);
                        myGrades->studentList[j].grades=myGrades->studentList[j-1].grades;
                    }
                    strcpy(myGrades->studentList[i].name,add_name);
                    myGrades->studentList[i].grades=add_grade;
                    yes=1;
                    break;
                }
			}
            if(yes==0)
            {
			    if(myGrades->studentList[0].grades<add_grade&&myGrades->studentList[myGrades->studentNum].grades<add_grade)
                {
                	myGrades->studentNum++;
            	    for(j=myGrades->studentNum;j>0;j--)
                    {
                        strcpy(myGrades->studentList[j].name,myGrades->studentList[j-1].name);
                        myGrades->studentList[j].grades=myGrades->studentList[j-1].grades;
                    }
                    strcpy(myGrades->studentList[0].name,add_name);
                    myGrades->studentList[0].grades=add_grade;
                }
                if(myGrades->studentList[myGrades->studentNum-1].grades>add_grade)
                {
					strcpy(myGrades->studentList[myGrades->studentNum].name,add_name);
                    myGrades->studentList[myGrades->studentNum].grades=add_grade;
                    myGrades->studentNum++;
                }
            } 
        }
        if(myGrades->studentNum==1)
        {
		    if(myGrades->studentList[0].grades<add_grade)
            {
            	strcpy(myGrades->studentList[1].name,myGrades->studentList[0].name);
                myGrades->studentList[1].grades=myGrades->studentList[0].grades;
                myGrades->studentList[0].grades=add_grade;
                 strcpy(myGrades->studentList[0].name,add_name);
                myGrades->studentNum++;
            }
            else
            {
                strcpy(myGrades->studentList[1].name,add_name);
                myGrades->studentList[1].grades=add_grade;
                myGrades->studentNum++;
            }
        }
        if(myGrades->studentNum==0)
        {
            strcpy(myGrades->studentList[0].name,add_name);
            myGrades->studentList[0].grades=add_grade;
            myGrades->studentNum++;
        }
        /**********************order*********************************/
    }
} 
void rm_student(gradeNode* myGrades)
{
    char rm_name[NAME_MAX_LENGTH];
    int i,j,exist=0;
    printf("Removing Name: ");
    scanf("%s",&rm_name);
    if(myGrades->studentNum==0)
        printf("The list has already been empty.");
    else
    {
        for(i=0;i<myGrades->studentNum;i++)
        {
            if(strcmp(myGrades->studentList[i].name,rm_name)==0)
            {
            	myGrades->studentNum--;
                for(j=i;j<myGrades->studentNum;j++)
                {
                    strcpy(myGrades->studentList[j].name,myGrades->studentList[j+1].name);
                    myGrades->studentList[j].grades=myGrades->studentList[j+1].grades;
                }
                exist=1;
                break;
            }
        }
        if(exist==0)
            printf("No such a student called %s",rm_name);
    }
}

void show_student(gradeNode myGrades)
{
    int i;
    myGrades.avg=0;
    if(myGrades.studentNum==0)
        printf("The list has already been empty.");
    for(i=0;i<myGrades.studentNum;i++)
    {
        printf("%-15s",myGrades.studentList[i].name);
        printf("%d\n",myGrades.studentList[i].grades);
        myGrades.avg=myGrades.avg+myGrades.studentList[i].grades;
    }
    myGrades.avg=myGrades.avg/myGrades.studentNum;
    printf("AVG            %0.3f",myGrades.avg);
}
void update_student(gradeNode* myGrades)
{
	char up_name[NAME_MAX_LENGTH],re[NAME_MAX_LENGTH];
	int exist=0,yes=0,up_grade,i,j,k; 
    printf("Student Name: ");
    scanf("%s",&up_name);
    for(i=0;i<myGrades->studentNum;i++)
    {
        if(strcmp(up_name,myGrades->studentList[i].name)==0)
        {
            printf("Original grade: %d\n",myGrades->studentList[i].grades);
            printf("Update:");
			scanf("%d",&up_grade);
			/**********************order*********************************/
			if((*myGrades).studentNum>2)
            {
        	    for(j=1;j<myGrades->studentNum;j++)
                {
                    if(myGrades->studentList[j-1].grades>up_grade&&myGrades->studentList[j].grades<up_grade)
                    {
                    	if(j>i)
                        {
                        	for(k=i;k<j-1;k++)
						    { 
							     myGrades->studentList[k].grades=myGrades->studentList[k+1].grades;
							     strcpy(myGrades->studentList[k].name,myGrades->studentList[k+1].name); 
						    }
						    strcpy(myGrades->studentList[j-1].name,up_name);
                            myGrades->studentList[j-1].grades=up_grade; 
                            yes=1;
					        break;
                        } 
                        else if(i>j)
                        {
                        	for(k=i;k>j;k--)
						    { 
							     myGrades->studentList[k].grades=myGrades->studentList[k-1].grades;
							     strcpy(myGrades->studentList[k].name,myGrades->studentList[k-1].name); 
						    }
						    strcpy(myGrades->studentList[j].name,up_name);
                            myGrades->studentList[j].grades=up_grade; 
                            yes=1;
					        break;	
                        }
                        else if(i==j)
                        {
                        	 strcpy(myGrades->studentList[j].name,up_name);
                             myGrades->studentList[j].grades=up_grade; 
                             yes=1;
					         break;	
                        }
                    }
                    if(myGrades->studentList[j].grades==up_grade)
                    {
                    	if(j>i)
						{
							for(k=i;k<j;k++)
					        {
					            myGrades->studentList[k].grades=myGrades->studentList[k+1].grades;
					            strcpy(myGrades->studentList[k].name,myGrades->studentList[k+1].name); 
					        }  
                            strcpy(myGrades->studentList[j].name,up_name);
                            myGrades->studentList[j].grades=up_grade;
                            yes=1;
                            break;
						}
						else if(i>j)
                        {
                        	for(k=i;k>j;k--)
						    { 
							     myGrades->studentList[k].grades=myGrades->studentList[k-1].grades;
							     strcpy(myGrades->studentList[k].name,myGrades->studentList[k-1].name); 
						    }
						    strcpy(myGrades->studentList[j].name,up_name);
                            myGrades->studentList[j].grades=up_grade; 
                            yes=1;
					        break;	
                        }
                    }
                }
			}
            if(yes==0)
            {
			    if(myGrades->studentList[0].grades<up_grade&&myGrades->studentList[myGrades->studentNum].grades<up_grade)
                {
            	    for(k=i;k>0;k--)
                    {
                        strcpy(myGrades->studentList[k].name,myGrades->studentList[k-1].name);
                        myGrades->studentList[k].grades=myGrades->studentList[k-1].grades;
                    }
                    strcpy(myGrades->studentList[0].name,up_name);
                    myGrades->studentList[0].grades=up_grade;
                }
                if(myGrades->studentList[myGrades->studentNum-1].grades>up_grade)
                {
                	for(k=i;k<myGrades->studentNum;k++)
                    {
                        strcpy(myGrades->studentList[k].name,myGrades->studentList[k+1].name);
                        myGrades->studentList[k].grades=myGrades->studentList[k+1].grades;
                    }
					strcpy(myGrades->studentList[myGrades->studentNum-1].name,up_name);
                    myGrades->studentList[myGrades->studentNum-1].grades=up_grade;
                }
            }
            if(myGrades->studentNum==2)
            {
		        if(myGrades->studentList[0].grades<up_grade&&i!=0)
                {
            	    strcpy(myGrades->studentList[1].name,myGrades->studentList[0].name);
                    myGrades->studentList[1].grades=myGrades->studentList[0].grades;
                    myGrades->studentList[0].grades=up_grade;
                    strcpy(myGrades->studentList[0].name,up_name);
                    myGrades->studentNum++;
                }
                else if(myGrades->studentList[1].grades>up_grade&&i!=1) 
                {
                    strcpy(myGrades->studentList[1].name,up_name);
                    myGrades->studentList[1].grades=up_grade;
                    myGrades->studentNum++;
                }
            }
			if(myGrades->studentNum==1)
			{ 
			    myGrades->studentList[i].grades=up_grade;
			}
			/**********************order*********************************/ 
            exist=1;
            break;
        }
    }
    if(exist==0)
	    printf("No such a student called %s.",up_name); 
}

void search_student(gradeNode myGrades)
{
	char search_name[NAME_MAX_LENGTH];
	int exist=0,i; 
	printf("Student Name: ");
    scanf("%s",&search_name);
    for(i=0;i<=myGrades.studentNum;i++)
    {
        if(strcmp(search_name,myGrades.studentList[i].name)==0)
        {
            printf("%-15s",myGrades.studentList[i].name);
            printf("%d\n",myGrades.studentList[i].grades);
            exist=1;
            break;
        }
    }
    if(exist==0)
	    printf("No such a student called %s.",search_name);
}
