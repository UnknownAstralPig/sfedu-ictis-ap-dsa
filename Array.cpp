#include <Array.h>
#include <cstddef>

namespace ArrayNS {
    template<typename TYPE>
    Array<TYPE>* newArray(int size)
    {
        return new Array<TYPE>{ new TYPE[size] , size };
    }

  
    template<typename TYPE>
    int insertToArray(Array<TYPE>* arr, TYPE value, int index)
    {
        if (index > arr->size)
            return 0;

        arr->array[index] = value;

        return 1;
    }

  
    template<typename TYPE>
    TYPE* find(Array<TYPE>* arr, TYPE value)
    {
    	int i ;
        for ( i = 0 ; i < arr->size && value != arr->array[ i ] ; i++ ) ;

	
       	if ( i - arr->size )
		return &arr->array[ i ] ;
	else
	        return NULL;
    }

    template<typename TYPE>
    void deleteArray(Array<TYPE>* arr)
    {
        if (!arr)
            return;

        delete[] arr->array;
        delete arr;

        return;
    }
};
