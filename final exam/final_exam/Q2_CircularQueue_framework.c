#include<stdio.h>
#include<conio.h>



void main()
{
   char ch;
    while(1)
    {
        system("cls");
        printf(" ----------------------------\n");
        printf("| 1. Enqueue.               |\n");
        printf("| 2. Dequeue.               |\n");
        printf("| 3. Display.               |\n");
        printf("| 4. Exit.                  |\n");
        printf(" ---------------------------\n");
        printf("What are you going to do? - ");
        scanf(" %c",&ch);
        switch(ch)
        {
            case '1':
               /* Enqueue(); */
                break;
            case '2':
               /* Dequeue(); */
                break;
            case '3':
              /*  Display(); */
                break;
            case '4':
             /* Exit(); */
            default:
                printf("Wrong input. Please enter an input 1-4.\n");
                break;
        }
        printf("\n");

    }


    return 0;
}
