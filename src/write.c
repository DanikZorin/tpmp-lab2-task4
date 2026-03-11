#include "../include/write.h"
int n;
Worker** workers;
void readFile(char* file){
printf("readFile start");
	FILE* fptr = fopen(file, "r");
	if (fptr == 0){
		printf("no input file! %s\n", strerror(errno));
		return;
	}
	printf("file opened\n");
	fscanf(fptr, "%d", &n);	

	workers = (Worker**)malloc(n*sizeof(Worker*));
	printf("cycle start\n");
	for (int i=0;i<n;i++){
		Worker* w = (Worker*) malloc(sizeof(Worker));
		fscanf(fptr,"%s %s %s %s %s %s %s %s %s %d %d %d %d %d %s %d",
 w->surname, w->name, w->father, w->home, w->index, w->country, w->city, w->flat, w->nation, &w->bday, &w->bmonth, &w->byear,
 &w->factoryNum, &w->tabNum, w->education, &w->workyear);

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

