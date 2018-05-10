#include<stdio.h>

#define max_length 10

void swap(char *x, char *y);
void permute(char *list, int now_pos, int final_pos);

int main()
{
    char ch;
    char list[max_length];
    int list_length = 0;

    printf("Type text:");
    while((ch = getchar())!= '\n')
        list[list_length++] = ch;

    printf("All permutations:\n");
    permute(list, 0, list_length);
    return 0;
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *list, int now_pos, int final_pos)
{
   int i;
   if (now_pos == final_pos)
   {
        for(i=0;i<final_pos;i++)
            printf("%c", list[i]);
        printf("\n");
   }
   else
   {
       for (i = now_pos; i < final_pos; i++)
       {
          swap((list+now_pos), (list+i));
          permute(list, now_pos+1, final_pos);
          swap((list+now_pos), (list+i));
       }
   }
}
