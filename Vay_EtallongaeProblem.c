/*
 ============================================================================
 Name        : c.c
 Author      : Yassine Zouari
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *file;
	file=fopen("Data/document.txt","r");
  
	if (file == NULL){
	   printf("Error opening file \n");
	   return 1;
	}
  
	char line[256];
	int val1 =0;
	int val2 =0;
	unsigned int sum_Etallonage =0;
	unsigned int ligne_Etallonage=0;
	int index=0;
	while (fgets(line,sizeof(line),file)!=NULL){

      val1=-1;
      val2=-1;
	   for (int i =0; line[i]!='\0'; i++){
	      if (line[i]=='0' ||line[i]=='1' ||line[i]=='2'
	          ||line[i]=='3'||line[i]=='4'||line[i]=='5'||line[i]=='6'
	          ||line[i]=='7'||line[i]=='8'||line[i]=='9'){

	         if (val1==-1){
	            val1 = line[i] - '0';
	         }
	         else {
	            val2 = line[i] - '0';
	         }
	      }
	   }
	   if (val1==-1){
         ligne_Etallonage=0;
      }
      else if (val2==-1){
         ligne_Etallonage = val1*10 +val1;
      }
      else{
         ligne_Etallonage = val1*10 +val2;
      }
      sum_Etallonage +=ligne_Etallonage;
      printf("ligne__%d__ = %u    sum_Etallonage = %u  \n",index,ligne_Etallonage,sum_Etallonage);
      index++;
	}
	printf("sum_Etallonage = %u",sum_Etallonage);
	fclose(file);
	return 0;
}
