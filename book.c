
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "book.h"

PElement copy_book(PElement original){
	pbook org = (pbook)original;
	pbook cp = (pbook)malloc(sizeof(book));
	if(!cp) return NULL;
	cp->name = (char*)malloc(strlen(org->name)+sizeof(char));
	if(!cp->name) {
		free(cp);
		return NULL;
	}
	
	stpcpy(cp->name,org->name);
	cp->serial_number = org->serial_number;
	return cp;
}

void delete_book(PElement to_del) {
	pbook b = (pbook)to_del;
	free(b->name);
	free(b);
}

void print_book(PElement b_){
	pbook b = (pbook)b_;
	printf("name: %s serial number: %d\n",b->name, b->serial_number);
}

pbook creat_book(char* name , int serial_number) {
	pbook cp = (pbook)malloc(sizeof(book));
	if(!cp) return NULL;
	cp->name = (char*)malloc(strlen(name)+sizeof(char));
	if(!cp->name) {
		free(cp);
		return NULL;
	}
	
	stpcpy(cp->name,name);
	cp->serial_number = serial_number;
	return cp;
}
