#include<stdio.h>
#include<stddef.h>

char array[25000];

struct slot{
    size_t size;
    int free_flag; 
    struct slot *next;
};

struct slot *list = (void*)array;

void define();
void chop(struct slot *fixing,size_t size);
void *MyMalloc(size_t noOfBytes);
void combine();
void MyFree(void *p);
