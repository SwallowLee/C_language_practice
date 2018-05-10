#include <stdio.h>
#include <stdlib.h>

struct DynaIntArr {
    int capacity;
    int size;
    int *data;
};

void initalArr(struct DynaIntArr *arr);
int addOne(struct DynaIntArr *arr, int value);
int* getOne(struct DynaIntArr *arr, int index);
int removeOne(struct DynaIntArr *arr, int index);
void clearArr(struct DynaIntArr *arr);
void destroyArr(struct DynaIntArr *arr);
void printArr(const struct DynaIntArr *arr);

int main() {
    struct DynaIntArr testArr;
    initalArr(&testArr);

    int opt;
    for(;;) {
        system("cls");
        printf(" -------------------------------------------------\n");
        printf("| 1. Add a value to the dynamic array.           |\n");
        printf("| 2. Get the value of the input index.           |\n");
        printf("| 3. Remove a value from the dynamic array.      |\n");
        printf("| 4. Show all the data of the dynamic array.     |\n");
        printf("| 5. Clear the dynamic array.                    |\n");
        printf("| 6. Destroy the dynamic array.                  |\n");
        printf("| 7. Exit.                                       |\n");
        printf(" -------------------------------------------------\n");
        printf("What are you going to do? -> ");
        scanf("%d",&opt);

        switch(opt) {
        case 1: {
            printf("Please input the value: ");
            int tmpVal;
            scanf("%d", &tmpVal);
            if(!addOne(&testArr, tmpVal)) {
                printf("Error, Memory insufficient!!\n");
                system("pause");
            }
            break;
        }
        case 2: {
            printf("Please input the index: ");
            int tmpIdx;
            scanf("%d", &tmpIdx);
            int *theValP = getOne(&testArr, tmpIdx);
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
            if(!removeOne(&testArr, tmpIdx)) {
                printf("Wrong index!!\n");
                system("pause");
            }
            break;
        }
        case 4:
            printArr(&testArr);
            system("pause");
            break;
        case 5:
            clearArr(&testArr);
            break;
        case 6:
            destroyArr(&testArr);
            break;
        case 7:
            return 0;
        default:
            printf("Wrong input. Please enter an input 1-7.\n");
            break;
        }
        printf("\n");
    }
    destroy(testArr);

    return 0;
}

void initalArr(struct DynaIntArr *arr){
	arr->capacity = 0;
	arr->size = 0;
	arr->data = 0;
}

int addOne(struct DynaIntArr *arr, int value){
	int i=0;
	if(arr->capacity==arr->size)
    {
        arr->data=realloc(arr->data,((arr->size)+1)*sizeof(int));
        arr->data[arr->size]=value;
        arr->size++;
        arr->capacity++;
        i=1;
    }
    else
    {
        arr->data[arr->size]=value;
        arr->size++;
        i=1;
    }
	/*
	behave:
		if the capacity is enough
			do not allocate new memory space
			just add the new value at end
		else
			allocate new memory space with size + 1
			copy old data into new space
			add the new value at end

	return 0 when action fail
	return 1 when action success
	*/
	return i;
}

int* getOne(struct DynaIntArr *arr, int index){
    int *p,i;
    for(i=0;i<arr->size;i++)
    {
        if(i==index)
        {
            p=&arr->data[i];
            return p;
        }
    }
	/*
	behave:
		return "the pointer" to the target value
		if the index is invalid, please return null pointer
	*/
	return NULL;
}

int removeOne(struct DynaIntArr *arr, int index){
    int i,j,p=0,re;
    for(i=0;i<arr->size;i++)
    {
        if(i==index)
        {
            for(j=i;j<arr->size;j++)
            {
                arr->data[j]=arr->data[j+1];
            }
            arr->size--;
            p=1;
        }
    }
	/*
	behave:
		remove the value from the array but do not deallocate the memory

	return 0 when action fail
	return 1 when action success
	*/
	return p;
}

void clearArr(struct DynaIntArr *arr){
    arr->size=0;
	/*
	behave:
		remove all data	but do not give back the memory space
	*/
}

void destroyArr(struct DynaIntArr *arr){
    int *p;
    for(p=&arr->data[0];p<&arr->data[arr->capacity];p++)
    {
        free(p);
    }
    arr->data=0;
    arr->size=0;
    arr->capacity=0;
    //arr->capacity=0;
	/*
	behave:
		remove all data	and give back the memory space
	*/
}

void printArr(const struct DynaIntArr *arr) {
    int i;
    printf("    size: %10d\ncapacity: %10d\n", arr->size, arr->capacity);

    for(i = 0; i < arr->size; i++) printf("%d ", arr->data[i]);

    putchar('\n');
}
