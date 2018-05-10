#include <stdio.h>
#include <stdlib.h>
#define sizeNum 100
int main(){
    int n;
    int old,top,north,west;
    int i;
    char space;
    char command[sizeNum];
    top = 1;
    north = 2;
    west = 4;
    while(scanf("%c",&space) && space!='0'){
            old = top;
            switch(space){
                case 'n':
                    top = 7-north;
                    north = old;
                break;
                case 's':
                    top = north;
                    north = 7-old;
                break;
                case 'w':
                    top = 7-west;
                    west = old;
                break;
                case 'e':
                    top = west;
                    west = 7-old;
                break;
            }


    }
    printf("%d\n",top);
    return 0;
}
