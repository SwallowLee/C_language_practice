#include <stdio.h>
#include <stdlib.h>
#define MAX_DA_SIZE 100

typedef struct DynaIntArr {
    int capacity;
    int size;
    int *data;
} DynaIntArr;

DynaIntArr* createArr();
void printArr(const DynaIntArr *arr);

int addAt(DynaIntArr *arr, int index, int value);
int* getAt(DynaIntArr *arr, int index);
int removeAt(DynaIntArr *arr, int index);
void clearArr(DynaIntArr *arr);
void destroyArr(DynaIntArr *arr);

int reserveArr(DynaIntArr *arr, int size);
int copyArr(DynaIntArr *tar, DynaIntArr *src);
DynaIntArr* duplicateArr(DynaIntArr *src);

int daSize = 0;
DynaIntArr *daArr[MAX_DA_SIZE];

int daLimitCheckMsg() {
    if(daSize >= MAX_DA_SIZE) {
        printf("There cannot be more than %d dynamic arrays!!\n", MAX_DA_SIZE);
        system("pause");
        return 0;
    }
    return 1;
}

int daMemCheckMsg(void *src) {
    if(src == NULL) {
        printf("Error, Memory insufficient!!\n");
        system("pause");
        return 0;
    }
    return 1;
}

int daIdxCheckMsg(int index) {
    if(index < 0 || index >= daSize) {
        printf("Wrong index!!\n");
        system("pause");
        return 0;
    }
    return 1;
}


void printArr(const DynaIntArr *arr) {
    int i;
    printf("size: %2d, capacity: %2d\n", arr->size, arr->capacity);

    for(i = 0; i < arr->size; i++) printf("%d ", arr->data[i]);

    putchar('\n');
}

void arrModify(DynaIntArr* arr) {
    int opt;

    for(;;) {
        system("cls");
        printArr(arr);

        printf(" -------------------------------------------------\n");
        printf("| 1. Add a value to this dynamic array.          |\n");
        printf("| 2. Get the value of this input index.          |\n");
        printf("| 3. Remove a value from this dynamic array.     |\n");
        printf("| 4. Clear this dynamic array.                   |\n");
        printf("| 5. Reserve space.                              |\n");
        printf("| 6. Back.                                       |\n");
        printf(" -------------------------------------------------\n");
        printf("What are you going to do? -> ");
        scanf("%d",&opt);

        switch(opt) {
        case 1: {
            printf("Please input the index: ");
            int tmpIdx;
            scanf("%d", &tmpIdx);

            printf("Please input the value: ");
            int tmpVal;
            scanf("%d", &tmpVal);

            if(!addAt(arr, tmpIdx, tmpVal)) {
                printf("Error, Wrong index or Memory insufficient!!\n");
                system("pause");
            }
            break;
        }
        case 2: {
            printf("Please input the index: ");
            int tmpIdx;
            scanf("%d", &tmpIdx);
            int *theValP = getAt(arr, tmpIdx);
            if(theValP) {
                printf("The value of index %d: %d\n", tmpIdx, *theValP);
            } else {
                printf("Wrong index!!\n");
            }
            system("pause");
            break;
        }
        case 3: {
            printf("Please input the index: ");
            int tmpIdx;
            scanf("%d", &tmpIdx);
            if(!removeAt(arr, tmpIdx)) {
                printf("Wrong index!!\n");
                system("pause");
            }
            break;
        }
        case 4:
            clearArr(arr);
            break;
        case 5:{
		    printf("Please input the size: ");
            int tmpSize;
            scanf("%d", &tmpSize);

            if(!reserveArr(arr, tmpSize)) {
                printf("Error, Memory insufficient!!\n");
                system("pause");
            }
            break;
		}
		case 6:
            return;
        default:
            printf("Wrong input. Please enter an input 1-6.\n");
			system("pause");
            break;
        }
    }
}

int main() {
    int opt;

    for(;;) {
        system("cls");
        printf("There are %d dynamic arrays (%d at most).\n", daSize, MAX_DA_SIZE);
        int i;
        for(i = 0; i < daSize; i++) {
            printf("Array %d -> ", i);
            printArr(daArr[i]);
        }

        printf(" ----------------------------------------------- \n");
        printf("| 1. Create new Array.                          |\n");
        printf("| 2. Modify exist Array.                        |\n");
        printf("| 3. Duplicate exist Array.                     |\n");
        printf("| 4. Copy one Array into another.               |\n");
        printf("| 5. Destroy the Last dynamic array.            |\n");
        printf("| 6. Exit.                                      |\n");
        printf(" ----------------------------------------------- \n");
        printf("What do you want to do => ");

        scanf("%d",&opt);

        switch(opt) {
        case 1:
            if(!daLimitCheckMsg()) break;
            daArr[daSize] = createArr();
            if(!daMemCheckMsg(daArr[daSize])) break;
            daSize++;
            break;
        case 2: {
            printf("Please input the index: ");
            int tmpIdx;
            scanf("%d", &tmpIdx);
            if(!daIdxCheckMsg(tmpIdx)) break;
            arrModify(daArr[tmpIdx]);
            break;
        }

        case 3: {
            printf("Please input the index: ");
            int tmpIdx;
            scanf("%d", &tmpIdx);
            if(!daIdxCheckMsg(tmpIdx)) break;

            if(!daLimitCheckMsg()) break;

            daArr[daSize] = duplicateArr(daArr[tmpIdx]);

            if(!daMemCheckMsg(daArr[daSize])) break;

            daSize++;
            break;
        }

        case 4: {
            int tarIdx, srcIdx;

            printf("Please input the target index: ");
            scanf("%d", &tarIdx);
            if(!daIdxCheckMsg(tarIdx)) break;

            printf("Please input the source index: ");
            scanf("%d", &srcIdx);
            if(!daIdxCheckMsg(srcIdx)) break;

            if(!copyArr(daArr[tarIdx], daArr[srcIdx])) {
                printf("Error, Memory insufficient!!\n");
                system("pause");
            }
            break;
        }

        case 5: {
            if(daSize <= 0) {
                printf("Error, there is no array.\n");
                system("pause");
            } else {
                daSize--;
                destroyArr(daArr[daSize]);
            }
            break;
        }

        case 6: {
            int i;
            for(i = 0; i < daSize; i++) destroyArr(daArr[i]);

            return 0;
            break;
        }

        default:
            printf("Wrong input. Please enter an input 1-6.\n");
			system("pause");
            break;
        }
    }

    return 0;
}//main_end (DO NOT remove this comment, or you will got 0 point.)

//-----------------------------------------------------------------------------------
//You cannot declare new global variable, static variable or modify exist functions
//but you can add new functions and local variables
//-----------------------------------------------------------------------------------

//Please refer to pdf for the implement detail of each function
DynaIntArr* createArr() {
    int i=0;
    struct DynaIntArr *p;
    p->capacity=0;
    p->size=0;
    p->data=0;
    i=1;
    if(i==1)
        return p;
    if(i==0)
    return NULL;
}

int reserveArr(DynaIntArr *arr, int size) {

    return 0;
}
int addAt(DynaIntArr *arr, int index, int value) {
    int i,p=0;
    if(arr->capacity==arr->size)
    {
        arr->capacity++;
    }
            arr->size++;
        for(i=arr->size;i>index;i--)
        {
            arr->data[i]=arr->data[i-1];
        }
        arr->data[index]=value;
        p=1;
        if(p==1)
            return 1;
        else
    return 0;
}

int* getAt(DynaIntArr *arr, int index) {
    int *i;
    if(index<=arr->size)
    {
        i=&arr->data[index];
        return i;
    }
    return NULL;
}

int removeAt(DynaIntArr *arr, int index) {
    int i,p=0;
    for(i=index;i<arr->size;i++)
    {
        arr->data[i]=arr->data[i+1];
    }
    p=1;
    return p;
}

void clearArr(DynaIntArr *arr) {
arr->size=0;
}

void destroyArr(DynaIntArr *arr) {

}

int copyArr(DynaIntArr *tar, DynaIntArr *src) {
	return 0;
}

DynaIntArr* duplicateArr(DynaIntArr *src) {
	return NULL;
}
