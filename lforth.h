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


struct type_stack* init_stack(){
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

/*
 * Retira e retorna o valor do topo da pilha
 *
 * NOTA para os demais desenvolvedores:
 * Para evitar falhas na remocao, foi adicionado uma condicao
 * para tratar pilha vazia e outra com a pilha possuindo um unico 
 * elemento.
 */

float drop(struct type_stack *stack){

	float value;
	struct type_node *aux = stack->top;
      
        if (stack->top != NULL) {
                if (stack->top->next != NULL) {
                        stack->top = stack->top->next;
                        stack->top->previous = NULL;
                        value = aux->value;
                        free(aux);
                } else {
                     
                        stack->top = NULL;
                        stack->last = NULL;
                        value = aux->value;
                        free(aux);
                        stack = NULL;
                }
        }

	return value;
}

/* 
 * Remove um nodo qualquer dentro da "pilha"
 */

float remove_node(struct type_node *node, struct type_stack *stack) {
        float value;
        struct type_node *aux = node;

        if (aux != NULL) {
                value = aux->value;
                printf("DEBUG pilha não nula!\n");

                if (node->previous == NULL) {
                        printf("DEBUG pilha 1!\n");
                        node = node->next;
                        aux->next = NULL;
                        if (node != NULL)
                                node->previous = NULL;
                        stack->top = node;

                } else if (node->next == NULL) {
                        printf("DEBUG pilha 2!\n");
                        node = node->previous;
                        aux->previous = NULL;
                        if (node != NULL)
                                node->next = NULL;
                        stack->last = node;

                } else {
                        printf("DEBUG pilha 3!\n");
                        node->previous->next = node->next;
                        node->next->previous = node->previous;
                        node->previous = NULL;
                        node->next = NULL;
                }
                
                free(aux);
        }

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
	printf("\n#");
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

	return stack->top==NULL;	
}

void empty(struct type_stack *stack){

	if(is_null(stack)){
		push(stack, 1);
	}else{
		push(stack, 0);
	}

}

void rempty(struct type_stack *stack, struct type_stack *stack_work){

	if(is_null(stack)){
		push(stack_work, 1);
	}else{
		push(stack_work, 0);
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
        float value = rand() % 53 - 1;
        //printf("DEBUG Valor: %0.2f\n", value);
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

void roll(struct type_stack *stack, float times) {
        
        int ntimes = (int) ntimes;
        int i = 0;
        float value;

        struct type_node *aux = stack->top;

        while (aux != NULL) {
                if (i == times) {
                        value = remove_node(aux, stack);
                        push(stack, value);
                        break;
                }

                i++;
                aux = aux->next;
        }
}

void rot(struct type_stack *stack) {
        float a = drop(stack);
        float b = drop(stack);
        float c = drop(stack);
		push(stack, a);
        push(stack, c);
		push(stack, b);
       

}

void cr() {
     
	printf("\n");
}


