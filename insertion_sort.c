#include <string.h>



void insertionSort(char **array, int n) 
{ 
    int i, j; 
	char aux[50];
    for (i=1; i<n; i++){ 
		
		strcpy(aux,array[i]);//element = array[i]; 
		j = i-1; 
	
	 	while(j>=0 && strcmp(array[j],aux)>0)  { //array[j] > element)
            array[j+1] = array[j]; 
			j--;
        } 
		strcpy(array[j+1],aux);  //array[j+1] = element; 
   } 
}
