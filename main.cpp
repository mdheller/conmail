#include <stdio.h>

void display(char * p);

int main(){
	display("./logo.map");
}

void display(char * p){
	FILE * fptr;
	fptr = fopen(p,"r");
	char buff[100];

	while(!feof(fptr)){
		fgets(buff,100,fptr);
		printf("%s",buff);
	}

	printf("\n");;
}

