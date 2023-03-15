#ifndef ADAPTARRAY_H
#define ADAPTARRAY_H
typedef struct AdptArray_* PAdptArray;
typedef enum  {FAIL = 0, SUCCESS=1} Result;
typedef void* PElement;

typedef void(*DEL_FUNC)(PElement);
typedef PElement(*COPY_FUNC)(PElement);
typedef void(*PRINT_FUNC)(PElement);

PAdptArray CreateAdptArray(COPY_FUNC, DEL_FUNC,PRINT_FUNC);
void DeleteAdptArray(PAdptArray);
Result SetAdptArrayAt(PAdptArray, int, PElement);
PElement GetAdptArrayAt(PAdptArray, int);
int GetAdptArraySize(PAdptArray);
void PrintDB(PAdptArray);
#endif