/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  04/12/20 19:37:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
/*
 * =====================================================================================
 *
 *       Filename:  stack_ops_using_ll.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Friday 10 April 2020 09:59:27  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

struct Stack{
	int value;
	struct Stack* next;
};
typedef struct Stack stack;

//Utility Function 
void push(int);
void pop();
void showstack();

// Limiting Condition
int top = -1;
int MAX = 20;

// Global reference to the stack 
stack* stackTop;

// Defining Push Function

void push(int num){
	// if(top == -1){
	// 	top++;
	// 	stack* s=(stack*) malloc(sizeof(stack));
	// 	s -> value = num;
	// 	s -> next = NULL;
	// 	stackTop = s;
	// 	printf ( "%d\n", s -> value );
	// }

	if(top == MAX-1){
		printf ( "stack overflow\n" );
	}
	else {
		// top++;
		stack* temp = (stack*) malloc(sizeof(stack));
		// stack* t = s ;
		// printf ( "%d\n",t-> value );
		// printf("%p\n",s);
		temp -> value = num;
		temp -> next = top == -1 ? NULL:stackTop ;
		stackTop = temp;
		// printf("%p %p\n",s,temp);
		printf ( "%d\n",stackTop -> value);
		top++;
	}
}

// Stack PoP Operation
void pop(){
	if(top == -1){
		printf("Underflow");
	}
	else{
		stack* temp = (stack*) malloc(sizeof(stack));
		temp = stackTop;
		printf("%d is popped\n",temp->value);
		stackTop = stackTop->next;
		free(temp);
		
		
		// int temp = s -> value;
		// top--;
	}
}

// Travesing Stack
void showstack(){
	stack* temp=stackTop;
	while(temp!=NULL){
		printf ( "%d " ,temp -> value);
		temp = temp -> next;
	}
	printf("\n");
}

// main function
int main(){
	char ch;
	// stack* s=(stack*) malloc(sizeof(stack));
	int num;
	while(1){
		printf ( "enter a choice(push-a,pop-d,Stacktop-t,show-s,exit-e):\n" );
		scanf ( " %c", &ch );
		switch (ch){
			case 'a':
				printf("Enter a num: ");
				scanf ( "%d", &num );
				push(num);
				// printf ( "%p\n",);
				// printf("%d",stackTop->value);
				break;
			case 'd':
				pop();
				// printf("%d is poped\n",num);
				break;
			case 't':
				printf("Stack Top:%d\n",stackTop->value);
				// printf("%p\n",stackTop->next);
				break;

			case 's':
				showstack();
				break;

			case 'e':
				exit(0);
				break ;
			case '\n':
				break;

			default :
				printf ( "enter a valid choice\n" );

		}
	}
}




