#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void display(char * p);
int login();
int getpass();

int main(){
	display("./logo.map");
	display("./indexmen.map");

	int opt;
	printf(">> ");
	scanf("%d",&opt);

	if(opt == 1) login();

	printf("\n");
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

	printf("\n");
}

int login(){
	char u[30];
	char p[30];
	printf("\nEnter User ID: ");
	scanf("%s",u);
	printf("Enter password: ");
	int i = 0;
	fflush(stdin);
	fflush(stdout);
	

	while(1){
		char c = getpass();
		p[i] = c;
		i++;
		if(c == '\n' && i > 3) break;
	}

	p[0]='a';

	p[--i] = '\0';

	printf("\nPass: %s",p);

	return 0;
}



int getpass() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
