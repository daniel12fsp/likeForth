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
	free(aux);
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

int is_null(struct type_stack *stack){

	return stack==NULL;	
}

void empty(struct type_stack *stack){

	if(is_null(stack)){
		push(stack, 1);
	}else{
		push(stack, 0);
	}

}

void rempty(struct type_stack *stack){

	if(is_null(stack)){
		push(stack, 1);
	}else{
		push(stack, 0);
	}

}


int top(struct type_stack *stack){

	if(stack != NULL)
		return stack->top->value;
	else
		//Confirmar com o professor o valor!!!
		return -1;

}

void r_arroba(struct type_stack *work, struct type_stack *result){
	
	int top_value = top(work);
	push(result, top_value);

}

int main(){

	struct type_stack *stack_work   = init_stack();
	struct type_stack *stack_result = init_stack();

	push(stack_work, 6);
	push(stack_work, 2);
	push(stack_work, 3);
	push(stack_work, 4);
	push(stack_work, 5);
	push(stack_work, 8);
	print_stack(stack_work);
	swap(stack_work);
	pick(stack_work, 3);
	print_stack(stack_work);
	
	return 0;
}
