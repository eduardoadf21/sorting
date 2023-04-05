#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void merge(char **V, int inicio, int meio, int fim){
	
	int p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	char **temp;
	temp = malloc(tamanho * sizeof(char*));
	int y;
	for(y=0;y<tamanho;y++){
		temp[y] = malloc(50*sizeof(char));	
	}
	
	if(temp != NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(strcmp(V[p1],V[p2]) < 0){ 	   //if(V[p1] < V[p2])
					strcpy(temp[i],V[p1++]);   //temp[i] = V[p1++];
				}
				else
					strcpy(temp[i],V[p2++]);	//temp[i] = V[p2++];

				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;		
			}
			else{
				if(!fim1)
					strcpy(temp[i],V[p1++]);//temp[i] = V[p1++];
				else
					strcpy(temp[i],V[p2++]);//temp[i] = V[p2++];
			}
		}		
		for(j=0, k=inicio; j<tamanho; j++, k++)
			strcpy(V[k],temp[j]);//V[k]=temp[j];		
	}
    free(temp);
}
			
	
void mergeSort(char **V, int inicio, int fim){
	
	int meio;
	if(inicio<fim){
		meio = floor((inicio+fim)/2);
		mergeSort(V,inicio,meio);
		mergeSort(V,meio+1,fim);
		merge(V,inicio,meio,fim);		
	}	
}


