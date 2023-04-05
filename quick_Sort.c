

#include <string.h>

void quicksort(char **words,int first,int last){
   int i, j, pivot; 
   char temp[50];

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
		 while(strcmp(words[i],words[pivot])<=0&&i<last)
            i++;
		 while(strcmp(words[j],words[pivot])>0)
            j--;
         if(i<j){
            strcpy(temp,words[i]);//temp=number[i];
            strcpy(words[i],words[j]);//number[i]=number[j];
            strcpy(words[j],temp);//number[j]=temp;
         }
      }

      strcpy(temp,words[pivot]);//temp=number[pivot];
      strcpy(words[pivot],words[j]);//number[pivot]=number[j];
      strcpy(words[j],temp);//number[j]=temp;
      quicksort(words,first,j-1);
      quicksort(words,j+1,last);

   }
}
