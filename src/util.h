#ifndef  UTIL_H_
#define  UTIL_H_

int randInt(int num){
	srand( time( NULL ) );
	int r = ( rand() % num) + 1;
}

void sortArray(int * array, int length){
	int i, j, aux;
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



int * unionArray(int * array1, int * array2){

}

#endif /* UTIL_H_ */