#include<stdio.h>
#include<stddef.h>
#include"mymalloc.c"

int main()
{
    int *p = (int*)MyMalloc(40*sizeof(int));
    
    MyFree(p);
    return 0;
}
