# include <stdio.h>

int main (void)
{
 int radius=10;
 float volume;
 volume=4.0f/3.0f*3.141592*radius*radius*radius;
 /*���Ƥ@�w�n��float���Φ����,�]�i��(float)4/3*3.141592*radius*radius*radius;*/
 printf("radio: %d\n",radius);
 printf("volume: %f\n",volume);
}
