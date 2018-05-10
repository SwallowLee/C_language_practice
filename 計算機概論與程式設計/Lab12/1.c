# include<stdio.h>
# include<stdlib.h>

int main(void)
{
    char *size,ch;
    int i,n=2,j=0,k;
    size=malloc(n*sizeof(char));
    printf("Please enter the line:\n");
    scanf("%c",&ch);
    printf("Store '%c' to array[%d]; Array size: %d\n",ch,0,n);
    j++;
    size[0]=ch;
    for(i=1;ch!='\n';i++)
    {
        scanf("%c",&ch);
        if(ch=='\n')
        {
            break;
        }
        if(ch!='/n')
        {
            printf("Store '%c' to array[%d]; Array size: %d\n",ch,i,n);
            j++;
            if(j==n)
            {
                printf("The array size is reallocated from %d to %d\n",n,2*n);
                n=n*2;
                size=(char*)realloc(size,n*sizeof(char));
            }
            size[i]=ch;
        }
    }
    if(j==n)
    {
        printf("The array size is reallocated from %d to %d\n",n,2*n);
        n=n*2;
        size=(char*)realloc(size,n*sizeof(char));
    }
    size[i]='\0';
    printf("Store \'\\0\' to array[%d]; Array size: %d\n\n",i,n);
    printf("String Length: %d\n",i);
    printf("Array Size: %d\n",n);
    printf("The String: %s",size);
    return 0;
}
