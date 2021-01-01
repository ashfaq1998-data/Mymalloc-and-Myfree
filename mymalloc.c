#include <stdio.h>
#include<stddef.h>
#include"mymalloc.h"

void define(){
    list->free_flag = 1;
    list->size = 25000 - sizeof(struct slot);
    list->next = NULL;
}

void chop(struct slot *fixing, size_t size){
    struct slot *new = (void*)((void*)fixing + size + sizeof(struct slot));
    new->size = fixing->size - size - sizeof(struct slot);
    new->free_flag = 1;
    new->next = fixing->next;
    fixing->size = size;
    fixing->free_flag = 0;
    fixing->next = new;
}

void combine(){
    struct slot *now;
        now = list;
        while(now->next != NULL){
            if(now->free_flag && now->next->free_flag){
                now->size += now->next->size + sizeof(struct slot);
                if(now->next->next != NULL){
                    now->next = now->next->next;
                }else{
                    now->next == NULL;
                }
                
            }
            now = now->next;
        }
}

void *MyMalloc(size_t size){
    if(list->size){
        define();
    }

    struct slot *x;
    x = list;
    while((x->size < size || x->free_flag == 0) && x->next != NULL){
            x = x->next;
    }

    if(x->size == size){
        x->free_flag = 0;
        printf("Perfectly Fitted\n");
        return (void*)++x;

    }
    else if(x->size > size){
        x->free_flag = 0;
        printf("slot is now broken \n");
       chop(x,size);
        return (void*)++x;
    }
    else{
        printf("memory is insufficient \n");
        return NULL;
    }
}



void MyFree(void *p){

    if((void*)array <= p && (void*)(array + 25000) >= p){
        struct slot *y = p;
        --y;
        y->free_flag = 1;
        combine();
        printf("free space is released \n");
    }
    else{
        printf("Error \n");
    }
}
