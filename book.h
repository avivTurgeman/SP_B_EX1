#ifndef BOOK_H
#define BOOK_H
#include "AdptArray.h"
typedef struct BOOK_{
char *name;
int serial_number;
} book, *pbook;

PElement copy_book(PElement original);
void delete_book(PElement to_del);
void print_book(PElement b_);
pbook creat_book(char* name , int serial_number);
#endif