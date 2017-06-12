#ifndef  UTIL_H_
#define  UTIL_H_

int randInt(int num){
	srand( time( NULL ) );
	int r = ( rand() % num) + 1;
}

#endif /* UTIL_H_ */