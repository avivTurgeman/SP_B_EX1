
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Person.h"

PElement copy_person(PElement original){
	pperson org = (pperson)original;
	pperson cp = (pperson)malloc(sizeof(person));
	if(!cp) return NULL;
	cp->first_name = (char*)malloc(strlen(org->first_name)+sizeof(char));
	if(!cp->first_name) {
		free(cp);
		return NULL;
	}

	cp->last_name = (char*)malloc(strlen(org->last_name)+sizeof(char));
	if(!cp->last_name) {
		free(cp->first_name);
		free(cp);
		return NULL;
	}
	
	stpcpy(cp->first_name,org->first_name);
	stpcpy(cp->last_name,org->last_name);
	cp->id = org->id;
	return cp;
}

void delete_person(PElement to_del) {
	pperson p = (pperson)to_del;
	free(p->first_name);
	free(p->last_name);
	free(p);
}

void print_person(PElement p_){
	pperson p = (pperson)p_;
	printf("first name: %s last name: %s id: %d\n",p->first_name,p->last_name, p->id);
}

pperson creat_person(char* first_name , char* last_name, int id) {
	pperson cp = (pperson)malloc(sizeof(person));
	if(!cp) return NULL;
	cp->first_name = (char*)malloc(strlen(first_name)+sizeof(char));
	if(!cp->first_name) {
		free(cp);
		return NULL;
	}
	cp->last_name = (char*)malloc(strlen(last_name)+sizeof(char));
	if(!cp->last_name) {
		free(cp->first_name);
		free(cp);
		return NULL;
	}
	
	stpcpy(cp->first_name,first_name);
	stpcpy(cp->last_name,last_name);
	cp->id = id;
	return cp;
}
