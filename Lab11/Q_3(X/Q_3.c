#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct Position {
    int row;
    int col;
};

struct Path {
    int score;
    int length;
    struct Position steps[MAX_SIZE * MAX_SIZE];
};

int mapRowCount, mapColCount; //height, width
char map[MAX_SIZE][MAX_SIZE];
struct Position curPos;
struct Path bestPath;

int loadMap(const char *fileName);
void printMap();
void delay(int mSec);
void goThrough(const struct Path *thePath);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        loadMap("map1.map");
    } else {
        loadMap(argv[1]);
    }

    printMap();

	bestPath.length = 0;
    bestPath.score = -1;

	/*my code*/

	/*
		Please write your code here.
		You should modify bestPath into the real best path. (With best score)
		If you cannot find exit, please set score to -1.
		(You can add some supported functions.)
	*/

    if(bestPath.score == -1) {
        printf("Can not exit!!\n");
    } else {
        goThrough(&bestPath);
        printf("Exit and get %d treasure(s)\n", bestPath.score);
    }
	system("pause");
    return 0;
}



int loadMap(const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if(!fp) return 0;

    fscanf(fp, "%d", &mapRowCount);
    fscanf(fp, "%d", &mapColCount);

    int i, j;
    for(i = 0; i < mapRowCount; i++) {
        for(j = 0; j < mapColCount; j++) {
            char tmpC = getc(fp);
            while(tmpC == ' ' || tmpC == '\n') tmpC = getc(fp);
            if(tmpC == '@') {
                curPos.row = i;
                curPos.col = j;
            }
            map[i][j] = tmpC;
        }
    }
    fclose(fp);
    return 1;
}

void printMap() {
    int i, j;
    for(i = 0; i < mapRowCount; i++) {
        for(j = 0; j < mapColCount; j++) {
            putchar(map[i][j]);
            putchar(' ');
        }
        printf("\n");
    }
}

void goThrough(const struct Path *thePath) {
    int i;
    for(i = 0; i < thePath -> length; i++) {
        delay(200);
        system("cls");
        curPos = thePath -> steps[i];
        map[curPos.row][curPos.col] = '0';
        printMap();
    }

}

void delay(int mSec) {
    int start=clock();
    int end;
    while(1) {
        end=clock();
        if(((end-start))>=mSec)
            return;
    }
}
