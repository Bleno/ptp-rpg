#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef  UTIL_H_
#define  UTIL_H_

int randInt(int num){
	int r;
    
    srand( time( NULL ) );
    r = ( rand() % num) + 1;
    return r;
}

void sortArray(int * array, int length){
	int i, j, aux = 0;

	for(i = 0; i < length; i++){
		for (j = i + 1; j < length; j++)
		{
			if(array[j] > array[i]){
				aux = array[i];
				array[i] = array[j];
				array[j] = array[i];
			}
		}
	}

}



int* unionArray(int * array1, int * array2){
	return NULL;
}


char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
            if (a_delim == *tmp)
            {
                        count++;
                        last_comma = tmp;
                    }
            tmp++;
        }


    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
            size_t idx  = 0;
            char* token = strtok(a_str, delim);
    
            while (token)
            {
                        assert(idx < count);
                        *(result + idx++) = strdup(token);
                        token = strtok(0, delim);
                    }
            assert(idx == count - 1);
            *(result + idx) = 0;
        }

    return result;
}                                                                                                                                                                                                                
  







#endif /* UTIL_H_ */