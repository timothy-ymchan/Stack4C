#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int StackInit(Stack* s,BufferType type,int size){
    if(size<1){
        printf("Error: Improper Stack Size!\n");
        return INVALID_STACK_SIZE;
    }
    if(type == INT){
        s->buffer.i = (int*)malloc(type*size);
    } else if(type == CHAR){
        s->buffer.c = (char*)malloc(type*size);
    } else if(type == FLOAT){
        s->buffer.f = (float*)malloc(type*size);
    } else {
        printf("Error: Unknown Stack Type!\n");
        return UNKNOWN_STACK_TYPE;
    }
    s->buffer_type = type;
    s->maxSize = size;
    s->head = 0;
    s->size = 0;
    return 0;
}

void* StackPop(Stack *s){
    int offset = s->head;
    BufferType buffer_type = s->buffer_type;
    void *data;
    if(s->size == 0){
        printf("Error: Stack is Empty!\n");
        return NULL;
    }
    if(buffer_type == INT){
        data = (s->buffer.i + offset);
    } else if(buffer_type == CHAR){
        data = (s->buffer.c + offset);
    } else if(buffer_type == FLOAT){
        data = (s->buffer.f + offset);
    }
    if(s->head == (s->maxSize-1)){
        s->head = 0;
    } else {
        s->head ++;
    }
    s->size--;
    return data;
}

int StackPush(Stack *s, void* data){
    BufferType buffer_type = s->buffer_type;
    if(s->size == s->maxSize){
        printf("Error: Stack Full!\n");
        return NULL;
    }
    if(s->head == 0){
        s->head = (s->maxSize-1);
    } else {
        s->head--;
    }
    int offset = s->head;
    if(buffer_type == INT){
        *(s->buffer.i + offset) = *((int*)data);
    } else if(buffer_type == FLOAT){
        *(s->buffer.f + offset) = *((float*)data);
    } else if(buffer_type == CHAR){
        *(s->buffer.c + offset) = *((char*)data);
    }
    s->size++;
    return 1;
}

