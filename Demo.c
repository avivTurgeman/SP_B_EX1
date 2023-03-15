/**
 * Demo program for ADT exercise.
 * 
 * Author: Evgeny Hershkovitch Neiterman
 * Since : 2023-02
 */

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {

	pbook b1 = creat_book("harry Potter",12345) ;
	pbook b2= creat_book("C intro", 45678) ;
	PAdptArray mybooks = CreateAdptArray(copy_book,delete_book,print_book);
	SetAdptArrayAt(mybooks,3,b1);
	SetAdptArrayAt(mybooks,5,b2);
	printf("the size is %d\n",GetAdptArraySize(mybooks));  //should print 6
	pbook b = GetAdptArrayAt(mybooks,4); // should return null;
	assert(b==NULL); // doesn't fail
	b = GetAdptArrayAt(mybooks,3);
	printf("the book is %s\n",b->name); //should print "Harry Potter"
	PrintDB(mybooks);

	pperson p1 = creat_person("Harry","Potter", 934);
	pperson p2 = creat_person("Ron","Weasley", 789);
	PAdptArray HP_caracters = CreateAdptArray(copy_person,delete_person,print_person);
	SetAdptArrayAt(HP_caracters,2,p1);
	SetAdptArrayAt(HP_caracters,8,p2);
	printf("the size is %d\n",GetAdptArraySize(HP_caracters)); // prints 9
	PrintDB(HP_caracters); // prints:
	//first name: Harry last name: Potter id: 934
        //first name: Ron last name: Weasley id: 789
	
	DeleteAdptArray(mybooks);
	DeleteAdptArray(HP_caracters);
	delete_book(b1);
	delete_book(b2);
	delete_book(b);
	delete_person(p1);
	delete_person(p2);
	return 0;
}
