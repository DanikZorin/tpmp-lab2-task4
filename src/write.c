#include "../include/write.h"
int n;
Worker** workers;
void readFile(char* file){	
	printf("readFile start\n");
	FILE* fptr = fopen(file, "r");
	if (fptr == 0){
		printf("no input file! %s\n", strerror(errno));
		return;
	}
	printf("file opened\n");
	fscanf(fptr, "%d", &n);	

	workers = (Worker**)malloc(n*sizeof(Worker*));
	printf("%d\n",n);
	printf("cycle start\n");
	for (int i=0;i<n;i++){
		Worker* w = (Worker*) malloc(sizeof(Worker));
		w->surname = (char*)malloc(30);
		w->name = (char*)malloc(30);
		w->father = (char*)malloc(30);
		w->home = (char*)malloc(30);
                w->index = (char*)malloc(30);
                w->country = (char*)malloc(30);
                w->city = (char*)malloc(30);
                w->flat = (char*)malloc(30);
                w->nation = (char*)malloc(30);
                w->education = (char*)malloc(30);
		
		fscanf(fptr, "%s",w->surname);
                fscanf(fptr, "%s", w->name);
                fscanf(fptr, "%s", w->father);
                fscanf(fptr, "%s", w->home);
                fscanf(fptr, "%s", w->index);
                fscanf(fptr, "%s", w->country);
                fscanf(fptr, "%s", w->city);
                fscanf(fptr, "%s", w->flat);
                fscanf(fptr, "%s", w->nation);
                fscanf(fptr, "%d", &w->bday);
                fscanf(fptr, "%d", &w->bmonth);
                fscanf(fptr, "%d", &w->byear);
                fscanf(fptr, "%d", &w->factoryNum);
                fscanf(fptr, "%d", &w->tabNum);
                fscanf(fptr, "%s", w->education);
                fscanf(fptr, "%d", &w->workyear);

		printf("%d\n",(2020==w->workyear));
		workers[i] = w;
	}
}
void writeFile(char* file){
	FILE* fptr = fopen(file, "w");
	
	for (int i=0;i<n;i++){
		Worker* w = workers[i];
		if (w->workyear == 2020){
			fprintf(fptr,"%s %s %s %s %s %s %s %s %s %d %d %d %d %d %s %d\n",
w->surname, w->name, w->father, w->home, w->index, w->country, w->city, w->flat, w->nation, w->bday, w->bmonth, w->byear, 
 w->factoryNum, w->tabNum, w->education, w->workyear);
		}
	}
}

