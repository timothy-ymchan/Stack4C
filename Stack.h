/*
Stack4C: Simple Stack Library for C, written by a beginner! ;p
Creator: Timothy Chan Yan Mong
Date: 06-01-2017
Description: A Stack library for C
*/
#ifndef _STACK_H_
#define _STACK_H_
#define UNKNOWN_STACK_TYPE 1
#define INVALID_STACK_SIZE -1
typedef union{int*i;float*f;char*c;} BufferPointer;
typedef enum{INT=sizeof(int),CHAR=sizeof(char),FLOAT=sizeof(float)} BufferType;
typedef struct{
    BufferPointer buffer;
    BufferType buffer_type;
    int maxSize;
    int head,size;
}Stack;
//Functions Prototypes

//StackInit Function:
int StackInit(Stack *s,BufferType type,int size); 
/*
Description:
This function Initialize a stack of size(ie max. length) "size", data type "type".

Parameters:
Stack s: A pointer to the target Stack
BufferType type: type of the stack (Options: INT, CHAR,FLOAT)
int size: Size/ Length of the stack

Returns:
0: Successfully initialize the stack
UNKNOWN_STACK_TYPE: "type" parameter is not defined
INVALID_STACK_SIZE: "size" parameter is not a positive, non-zero integer

Example:
Stack stack;
StackInit(&stack,INT,20); 

*/

//StackPop function:
void* StackPop(Stack*s);
/*
Description:
This function pop the stack and return the value of the popped data as void pointer, type cast to use

Parameter:
Stack s: A pointer to the target stack

Return:
A void pointer points to the data popped, NULL pointer if the stack is empty

Example:
//Assume the stack have the configuration: {1,2,3} and the stack is INT type
int *output;
output = (int*)StackPop(&stack);
if(!output){
	printf("The popped value: %d\n",*output);
} 

*/
//StackPush function:
int StackPush(Stack*s,void* data);
/*
Description: 
This function push a value to the Stack

Parameter:
Stack s: A pointer points to the target stack
void data: A pointer points to the value that would be passed

Return:
Return NULL if stack is full, and 1 if successful

Example:
int temp = 5;
if(!StackPush(&stack,&temp)){
	printf("The stack is full!");
}
*/
#endif
