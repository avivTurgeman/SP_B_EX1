#include "AdptArray.h"
#include <stdlib.h>

typedef struct AdptArray_{

    int size;
    PElement pElement;
    DEL_FUNC del_func;
    COPY_FUNC copy_func;
    PRINT_FUNC print_func;

} AdptArray;

PAdptArray CreateAdptArray(COPY_FUNC CFunc, DEL_FUNC DFunc,PRINT_FUNC PFunc){
    //Allocationg memory for AdptArray
    PAdptArray pArr = (PAdptArray) malloc (sizeof(AdptArray));
    if(pArr == NULL){
        return NULL;
    }
    //pArr's variables
    pArr->size = 0;
    pArr->pElement = NULL;

    //pArr's functions
    pArr->copy_func = CFunc;
    pArr->del_func = DFunc;
    pArr->print_func = PFunc;

    return pArr;
}

void DeleteAdptArray(PAdptArray pArr){
    if(pArr == NULL){
        return;
    }

    for (int i = 0; i < pArr->size; i++){
        pArr->del_func((pArr->pElement)[i]);
    }

    free(pArr->pElement);
    free(pArr);
}

Result SetAdptArrayAt(PAdptArray pArr, int index, PElement pElem){
    // if(pArr == NULL){
    //     return FAIL;
    // }
    //
    // if (pArr->size > index){
    //     pArr->del_func((pArr->pElement)[index]);
    //     (pArr->pElement)[index] = pArr->copy_func(pElem);
    //     return SUCCESS;
    // }
    //
    // PElement *temp = (*PElement)calloc((index + 1), sizeof(PElement));
    // if(temp == NULL){
    //     return FAIL;
    // }
    //
    // for(int i = 0; i < pArr->size; i++){
    //     pArr->copy_func((pArr->pElement)[i]);
    // }
    // free(pArr->pElement);
    // pArr->pElement = temp;
    // pArr->size++;
    // return SUCCESS;

    PElement* newpElement;
	if (pArr == NULL)
		return FAIL;

	if (index >= pArr->size){
		
        // Extend Array
		if ((newpElement = (PElement*)calloc((index + 1), sizeof(PElement))) == NULL)
			return FAIL;
		memcpy(newpElement, pArr->pElement, (pArr->size) * sizeof(PElement));
		free(pArr->pElement);
		pArr->pElement = newpElement;
	}

	// Delete Previous Elem
	pArr->del_func((pArr->pElement)[index]);
	(pArr->pElement)[index] = pArr->copy_func(pElem);

	// Update Array Size
	pArr->size = (index >= pArr->size) ? (index + 1) : pArr->size;
	return SUCCESS;

}

PElement GetAdptArrayAt(PAdptArray pArr, int index){
    if(pArr == NULL){
        return NULL;
    }
    return pArr->copy_func((pArr->pElement)[index]);
}

int GetAdptArraySize(PAdptArray pArr){
    if(pArr == NULL){
        return -1;
    }
    return pArr->size;
}

void PrintDB(PAdptArray pArr){
    if(pArr == NULL){
        return;
    }
    for(int i = 0; i < pArr->size; i++){
        pArr->print_func((pArr->pElement)[i]);
    }
}