#include <stdio.h>

void display(char * p);

int main(){
	display("./logo.map");
	display("./indexmen.map");
}

void display(char * p){
	FILE * fptr;
	fptr = fopen(p,"r");
	char buff[100];

	while(1){
		char * a = fgets(buff,100,fptr);
		if(  a == NULL) break;
		printf("%s",buff);
	}

	printf("\n");;
}

