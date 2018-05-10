#include <stdio.h>


int Level1_Trans_nearest_integer(float x)
{
    int y;
    float z;
    y=x;
    z=x-y;
    if(z>0.5)
        return y+1;
    else
        return y;
}

int Level2_Get_even_num(int a,int b)
{
    int ans;
    if(a%2==0&&b%2==0)
        ans=(b-a)/2+1;
    else if(a%2!=0&&b%2!=0)
        ans=(b-a)/2;
    else
        ans=(b-a)/2+1;
    return ans;
}

int Level3_check_IsWinThisGame(int input,int answer,int digits,int *A_count,int *B_count)
{
    int a[4],i[4],j,k;
    a[3]=answer%10;
    a[2]=(answer%100-a[3])/10;
    a[1]=(answer%1000-answer%100)/100;
    a[0]=answer/1000;
    i[3]=input%10;
    i[2]=(input%100-i[3])/10;
    i[1]=(input%1000-input%100)/100;
    i[0]=input/1000;
    for(j=0;j<4;j++)
        for(k=0;k<4;k++)
        {
            if(i[j]==a[k]&&j==k)
            {
                *A_count=*A_count+1;
            }
            if(i[j]==a[k]&&j!=k)
            {
                *B_count=*B_count+1;
            }
        }
    if(*A_count!=4)
        return 0;
    else
        return 1;
}

void Level4_permute(char *text, int now_pos, int final_pos, char **permutation_list, int *now_count)
{

}

int main()
{
    int i,j;

    printf("***----Welcome to the Game World!!----***\n");

    //--level 1--
    printf("***--------------level 1--------------***\n");
    printf("Write a program that asks the user to type a float number and rounds it to the nearest integer.\n");
    printf("type a float number: ");

    fflush(stdin);
    float level1_arg1=0.0f;
    scanf("%f",&level1_arg1);
    printf("Your Ans: %d\n",Level1_Trans_nearest_integer(level1_arg1));
    printf("***-----------------------------------***\n\n");
    //-----------

    //--level 2--
    printf("***--------------level 2--------------***\n");
    printf("Write a program that ask the user to type 2 numbers(0<=a<=b<=2147483647) and then calculate how many even numbers between a and b (include a and b).\n");
    printf("type 2 numbers: ");

    fflush(stdin);
    int level2_arg1=0,level2_arg2=0;
    scanf("%d %d",&level2_arg1,&level2_arg2);
    printf("Your Ans: %d\n",Level2_Get_even_num(level2_arg1,level2_arg2));
    printf("***-----------------------------------***\n\n");
    //-----------


    //--level 3--
    printf("***--------------level 3--------------***\n");
    printf("We want you to design a \"Number Riddle\" game. In this game, the player types 4 digits number (0~9, no repetition) and then he/she will get an output (OAXB).\n\n");
    printf("The \"A\" means the value and position are both correct, and the \"B\" means only value is correct. The game will proceed until the player win the game (when he get the 4A0B).\n");

    int A_count=0,B_count=0;
    int answer = 1234;
    while(1)
    {
        int A_count=0,B_count=0,input=0;
        const int digits=4;

        printf("What's your input number: ");
        fflush(stdin);
        scanf("%d",&input);
        if(Level3_check_IsWinThisGame(input,answer,digits,&A_count,&B_count))
            break;
        else
            printf("You get the %dA%dB!!\n",A_count,B_count);

    }
    printf("You win!!\n");
    printf("***-----------------------------------***\n\n");
    //-----------


    //--level 4--
    printf("***--------------level 4--------------***\n");
    printf("Please write a program to get all permutations of a given char array, the length of input is between 1 and 7.\n");
    printf("type text: ");

    char text[7],ch;
    int text_length=0,total_count=1,now_count=0;
    fflush(stdin);
    while((ch = getchar())!= '\n')
        text[text_length++] = ch;

    for(i=1;i<=text_length;i++)
        total_count*=i;

    char **permutation_list = (char**) calloc(total_count, sizeof(char*));
    for(i=0;i<total_count;i++)
        permutation_list[i] = (char*) calloc(text_length, sizeof(char));

    Level4_permute(text, 0, text_length, permutation_list, &now_count);


    for(i=0;i<now_count;i++)
    {
        for(j=0;j<text_length;j++)
            printf("%c",permutation_list[i][j]);
        printf("\n");
    }

    for(i=0;i<total_count;i++)
        free(permutation_list[i]);

    free(permutation_list);

    printf("Total: %d\n",total_count);
    printf("***-----------------------------------***\n\n");
    //-----------
    printf("***-----------------------------------***\n");
    printf("*~Congratulation!!  Mission Completed!!~*\n");
    printf("***-----------------------------------***\n");
    return 0;
}
