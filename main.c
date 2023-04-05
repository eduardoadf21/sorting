#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "selection_sort.h" 
#include "merge_sort.h"     
#include "quick_Sort.h"     
#include "insertion_sort.h" 
#include "storewords.h"
//menu

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n'){}
}


int main(){
	

	FILE *fptr;
	
	int qnt;
	printf("quantos nomes organizar? ");
	scanf("%d", &qnt);

	// array of pointers to char
	char **words;	
	words = malloc(qnt * sizeof(char*));
	int i;
	for(i=0;i<qnt;i++){
		words[i] = malloc(50*sizeof(char));	
	}

	words =	storewords(fptr,words,qnt);	
	

	clock_t begin, end;	
	double time_spent;
    char op;
    while(1){
        printf("\na:quick sort\nb:merge sort\nc:insertion sort\nd:selection sort\nf:listar\n0:sair\n\n");
        flush_in();
        op = getchar();
        switch(op)
        {
            case 'a':begin = clock();
				   	 quicksort(words,0,qnt-1);
					 end = clock();
					 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    				 printf("tempo gasto: %lf\n", time_spent);


                     break;

            case 'b':begin = clock();
				   	 mergeSort(words,0,qnt-1);
					 end = clock();
					 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    				 printf("tempo gasto: %lf\n", time_spent);


                     break;

            case 'c':begin = clock();
				   	 insertionSort(words,qnt);//
					 end = clock();
					 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    				 printf("tempo gasto: %lf\n", time_spent);

                     break;

			case 'd':begin = clock();
					 selecSort(words,qnt);
					 end = clock();
					 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    				 printf("tempo gasto: %lf\n", time_spent);

                     break;
			case 'e':words = storewords(fptr,words,qnt);	
					 break;
            case 'f'://
					 for(i=0;i<qnt;i++){
					   printf("%s", words[i]);
					 }
                     break;

            case '0':return 0;
        
		}
	}
	
	
	
}
