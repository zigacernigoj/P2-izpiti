#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Izpit 1, Naloga 2
 * NEOPTIMIZIRANA
 * DELUJE
 * 
 * Uporaba na lastno odgovornost!
 * (vem, da ni najlepsa koda)
 * 
 * Ce spreminjas kodo, 
 * prosim opisi/opozori na spremembo 
 * (na kakrsen koli nacin),
 * za lazje sledenje spremembam.
 * 
 * Hvala.
 * */

typedef struct node {
	int value;
	struct node *next;
} node;
node *start, *tmp, *p, *nazaj;

void addS(int a){
	tmp=(node*)malloc(sizeof(node));
	tmp->value=a;
	
	if(start==NULL){
		start=tmp;
		tmp->next=NULL;
	}
	else{
		tmp->next=start;
		start=tmp;
	}
}

//__________________//
// NALOGA OD TU  -->//

void addNazaj(int a){
	tmp=(node*)malloc(sizeof(node));
	tmp->value=a;
	
	if(nazaj==NULL){
		nazaj=tmp;
		tmp->next=NULL;
	}
	else{
		tmp->next=nazaj;
		nazaj=tmp;
	}
}

node* sezNazaj(node *kaz){
	p=kaz;
	int n;
	
	while(p!=NULL){
		n=p->value;
		addNazaj(n);
		p=p->next;
	}
	
	return nazaj;
}

// <-- NALOGA DO TU //
//__________________//

void printS(){
	p=start;
	while(p!=NULL){
		printf("%d", p->value);
		p=p->next;
	}
}

void printNazaj(node *ptr){
	p=ptr;
	while(p!=NULL){
		printf("%d", p->value);
		p=p->next;
	}
	
}

int main(){
	int a;
	start=NULL;
	
	while(scanf("%d", &a)!=EOF){
		addS(a);
	}
	
	printf("\noriginal\n");
	printS();
	
	printf("\nobratni vrstni red\n");
	printNazaj(sezNazaj(start));
	
	printf("\n");
	return 0;
}
