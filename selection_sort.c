#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void selecSort(char **words,int len){

	int i, j;
	char aux[50];

	for(i=0;i<len;i++){
		int jMin = i;
	for(j=i+1;j<len;j++){

			if(strcmp(words[j],words[jMin]) < 0){
				jMin = j;
			}
		}
		if(jMin != i){
			strcpy(aux,words[i]);
			strcpy(words[i],words[jMin]);
			strcpy(words[jMin],aux);
		}
	}
}


