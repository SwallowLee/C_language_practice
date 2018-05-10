# include<stdio.h>

int candy;

void how_many(int wrapper)
{
	if(wrapper>=3)
	{
	    candy=candy+1;
		how_many(wrapper-2);
	}
}

int main(void)
{
 int money,wrapper;
 printf("Please input money:");
 scanf("%d",&money);
 candy=money;
 wrapper=money;
 how_many(wrapper);
 printf("You can get %d candies",candy);

 return 0;
}
