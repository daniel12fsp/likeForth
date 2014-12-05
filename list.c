#include <stdio.h>
#include <malloc.h>

struct type_node{

	int value;
	struct type_node *next;
	struct type_node *previous;

};

struct type_stack{

	struct type_node *top;
	struct type_node *last;

};


struct type_stack *init_stack(){
	/*	
		Inicializa o ponteiro para o topo da pilha  e o ultimo da pilha
	*/

	struct type_stack *stack = malloc(sizeof(struct type_stack));
	stack->top = NULL;
	stack->last = NULL;
	return stack;

}

void push(struct type_stack *stack, int value){

	/*
		Adiciona o valor no topo da pilha
	*/

	struct type_node *p = malloc(sizeof(struct type_node));

	if(p != NULL){
	
		p->value = value;
		p->next = stack->top;
		p->previous = NULL;


		if( stack->top == NULL){

			stack->last = p;
		}else{

			stack->top->previous = p;
		}

		stack->top = p;
	}


}

int drop(struct type_stack *stack){

	int value;
	struct type_node *aux = stack->top;
	stack->top = stack->top->next;
	stack->top->previous = NULL;
	value = aux->value;
	//free(aux);
	return value;
}

void pick(struct type_stack *stack, int pick){
	struct type_node *top = stack->top;
	int i = 0;
	while(top != NULL){

		if(i == pick){
			push(stack, top->value);
			return;
		}
		top = top->next;
		i += 1;
	}

}

void print_stack(struct type_stack *stack){
	printf("\n");
	struct type_node *top = stack->top;
	while(top != NULL){
		printf(" %d", top->value);
		top = top->next;
	}

}

void print_stack_rev(struct type_stack *stack){
	printf("\n");
	struct type_node *top = stack->last;
	while(top != NULL){
		printf(" %d", top->value);
		top = top->previous;
	}

}


void swap(struct type_stack *stack){ 

	struct type_node *top = stack->top;
	struct type_node *next = top->next;
	int aux = top->value;
	top->value = next->value;
	next->value = aux;

}

void dup(struct type_stack *stack){ 

	push(stack, stack->top->value);
}

int main(){
	struct type_stack *stack = init_stack();
	push(stack, 6);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	push(stack, 8);
	print_stack(stack);
	swap(stack);
	pick(stack, 3);
	print_stack(stack);
	
	return 0;
}
