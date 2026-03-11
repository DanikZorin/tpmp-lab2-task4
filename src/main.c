#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/write.h"
int main(){
	printf("--START--\n");
	readFile("input.txt");
	writeFile("output.txt");
}
