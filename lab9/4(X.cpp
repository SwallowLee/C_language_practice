# include<stdio.h>
int start[3][3],end[3][3];
void change(int row,int col,int zero_row,int zero_col,int times);
int main(void)
{
	int j,i;
	printf("start_board:\n");
	for(i=0;i<3;i++)
	{   for(j=0;j<3;j++)
	    	scanf("%d",&start[i][j]);
	}
	printf("end_board:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		    scanf("%d",&end[i][j]);
	}
	for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
		    {
		    	if(start[i][j]!=end[i][j]);
		            break;
			}
			if(start[i][j]!=end[i][j]);
		            break;
		}
		if(i==3&&j==3)
		{
			printf("Total Step: 0");
		}
		else
		{
			change(2,1,2,2,1);
	        change(1,2,2,2,1);
		}
	return 0;
} 

void change(int row,int col,int zero_row,int zero_col,int times)
{
	int i,j,re;
	static int stop=0;
	if(stop==1)
	    return;
	if(times<=31)
	{
		re=end[row][col];
		end[row][col]=0;
		end[zero_row][zero_col]=re;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
		    {
		    	
		    	if(start[i][j]!=end[i][j])
			    break;
			}
			if(start[i][j]!=end[i][j])
		            break;
		}
		if(i==3&&j==3)
		{
			stop=1;
			printf("Total Step: %d",times);
		    return;
		}
		else if(end[2][2]==0)
		{
			change(row,col-1,row,col,times+1);
	        change(row-1,col,row,col,times+1);
		}
		else if(end[2][0]==0)
		{
			change(row-1,col,row,col,times+1);
	        change(row,col+1,row,col,times+1);
		}
		else if(end[0][2]==0)
		{
			change(row+1,col,row,col,times+1);
	        change(row,col-1,row,col,times+1);
		}
		else if(end[0][0]==0)
		{
			change(row,col+1,row,col,times+1);
	        change(row+1,col,row,col,times+1);
		}
		else if(end[1][0]==0)
		{
			change(row+1,col,row,col,times+1);
	        change(row-1,col,row,col,times+1);
			change(row,col+1,row,col,times+1);
		}
		else if(end[0][1]==0)
		{
			change(row+1,col,row,col,times+1);
	        change(row,col+1,row,col,times+1);
			change(row,col-1,row,col,times+1);	
		}
		else if(end[2][1]==0)
		{
			change(row-1,col,row,col,times+1);
	        change(row,col+1,row,col,times+1);
			change(row,col-1,row,col,times+1);
		}
		else if(end[1][2]==0)
		{
			change(row-1,col,row,col,times+1);
	        change(row+1,col,row,col,times+1);
			change(row,col-1,row,col,times+1);
		
		}
		else if(end[1][1]==0)
		{
			change(row-1,col,row,col,times+1);
	        change(row+1,col,row,col,times+1);
			change(row,col+1,row,col,times+1);
			change(row,col-1,row,col,times+1);
		}
	}
	if(times>31)
    {
    	if(stop==0)
    	{
    		stop=1;
    		printf("No solution!!");
    	    return;
		}
	}
}
