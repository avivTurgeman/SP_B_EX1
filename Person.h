#ifndef PERSON_H
#define PERSON_H
#include "AdptArray.h"
typedef struct PERSON_{
char *first_name;
char *last_name;
int id;
} person, *pperson;

PElement copy_person(PElement original);
void delete_person(PElement to_del);
void print_person(PElement b_);
pperson creat_person(char* first_name ,char* last_name, int id);
#endif