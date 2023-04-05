#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **storewords(FILE *fp, char **words, int qnt){
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("words", "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);
	}

	int i=0;
    while ((read = getline(&line, &len, fp)) != -1 && i<qnt) {
		//printf("%s", line);

		strcpy(words[i],line);
		//printf("%s", words[i]);
		i++;
    }

    fclose(fp);
    if (line)
        free(line);
    //exit(EXIT_SUCCESS);
	return words;
}
/*
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

	words = storewords(fptr,words,qnt);	

	
	for(i=0;i<qnt;i++){
		printf("%s", words[i]);
	}
}
*/
