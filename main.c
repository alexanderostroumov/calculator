#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char* argv){	
	const char std_prompt[] = "Enter expression: ";
	char *input;
	input = readline(std_prompt);
	rRead(input);
	if(correctinformation()==1)findoperation();
	return 0;
}
