# include <stdio.h>

int main(void)
{
int year=2015, month=9, day=23;
float temperature = 23.5;
printf("\"Date\": %d",year);
printf("\\%d",month);
printf("\\%d\n",day);
printf("\"Temperature\": %f",temperature);
return 0;
}
