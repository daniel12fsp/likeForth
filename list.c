#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

struct type_node{

	float value;
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

void push(struct type_stack *stack, float value){

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


float drop(struct type_stack *stack){

	float value;
	struct type_node *aux = stack->top;
	stack->top = stack->top->next;
	stack->top->previous = NULL;
	value = aux->value;
	free(aux);
	return value;
}

void pick(struct type_stack *stack, float pick){
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
		printf(" %0.2f", top->value);
		top = top->next;
	}

}

void print_stack_rev(struct type_stack *stack){
	printf("\n");
	struct type_node *top = stack->last;
	while(top != NULL){
		printf(" %0.2f", top->value);
		top = top->previous;
	}

}


void swap(struct type_stack *stack){ 

	struct type_node *top = stack->top;
	struct type_node *next = top->next;
	float aux = top->value;
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


float top(struct type_stack *stack){

	if(stack != NULL)
		return stack->top->value;
	else
		//Confirmar com o professor o valor!!!
		return -1;

}

void r_arroba(struct type_stack *work, struct type_stack *result){
	
	float top_value = top(work);
	push(result, top_value);

}

void srandf() {
     srand(time(NULL));
}

void randf(struct type_stack *work) {
        float value = rand() / (float) RAND_MAX;
        printf("DEBUG Valor: %0.2f\n", value);
        push(work, value);
}

void mv_work_to_result(struct type_stack *work, struct type_stack *result) {
        float value = drop(work);
        push(result, value);
}

void mv_result_to_work(struct type_stack *result, struct type_stack *work) {
        float value = drop(result);
        push(work, value);
}

int main(){

	struct type_stack *stack_work   = init_stack();
	struct type_stack *stack_result = init_stack();

	push(stack_work, 6.0);
	push(stack_work, 2.0);
	push(stack_work, 3.0);
	push(stack_work, 4.0);
	push(stack_work, 5.0);
	push(stack_work, 8.0);
	print_stack(stack_work);
                srandf();
        randf(stack_work);
        mv_work_to_result(stack_work, stack_result);
        print_stack(stack_result);
        mv_result_to_work(stack_result, stack_work);
        print_stack(stack_result);

	return 0;
}
