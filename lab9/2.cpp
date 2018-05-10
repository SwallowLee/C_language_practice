# include<stdio.h>

int main(void)
{
	int bob=0,alice=0,count,al_pla,bo_pla,distance;
	printf("Please input stone Count:");
	scanf("%d",&count);
	printf("Please input Alice position:");
	scanf("%d",&al_pla);
	printf("Please input Bob position:");
	scanf("%d",&bo_pla);
	if(al_pla>=bo_pla)
	    distance=al_pla-bo_pla;
	else
	    distance=bo_pla-al_pla;
	if(distance==1)
	{
		if(bo_pla=al_pla-1)
	    {
	    	if(bo_pla+3<count)
	    	{
	    		printf("They will meet at stone %d.\n",bo_pla+3);
	    		printf("Alice need to jump right 1 times\n");
	    		printf("Bob need to jump right 1 times.");
			}
	    	else
	    	    printf("They will never meet");
		}
		else if(bo_pla=al_pla+1)
	    {
	    	if(bo_pla-3>=0)
	    	{
	    		printf("They will meet at stone %d.\n",bo_pla-3);
	    		printf("Alice need to jump left 1 times\n");
	    		printf("Bob need to jump left 1 times.\n");
			}
	    	else
	    	    printf("They will never meet.\n");
		}
	}
	else if(bo_pla<al_pla)
	{
		if(distance>2)
		    for(bob=1;(distance-3*bob)>2;bob++)
		        bo_pla=bo_pla+3;
	    alice=(distance-3*(bob-1))/2;
		printf("They will meet at stone %d.\n",bo_pla);
		if(alice==0)
		    printf("Alice does not need to jump.\n");
		else
		    printf("Alice need to jump left %d times.\n",alice);
	    if(bob==0)
		    printf("Bob does not need to jump.\n");
		else
		    printf("Bob need to jump right %d times.\n",bob-1);
	}
	else if(bo_pla>al_pla)
	{
		if(distance>2)
			for(bob=1;(distance-3*bob)>2;bob++)
		    	bo_pla=bo_pla-3;
	    alice=(distance-3*(bob-1))/2;
		printf("They will meet at stone %d.\n",bo_pla);
		if(alice==0)
		    printf("Alice does not need to jump.\n");
		else
		    printf("Alice need to jump right %d times.\n",alice);
	    if(bob==0)
		    printf("Bob does not need to jump.\n");
		else
		    printf("Bob need to jump left %d times.\n",bob-1);
	}
}
