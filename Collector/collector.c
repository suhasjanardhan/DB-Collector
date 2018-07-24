#include "collector.h"
#include <stdlib.h>
#include <stdio.h>


#include "dbhelper.h"
#include <string.h>


int getColumnNum() {
return 2;
}

char *getTableName() {
char *tname = "component_a";
return tname;
}

tabstruct** getStruct_Collector() {

tabstruct **t;

t = malloc(sizeof(tabstruct*) * 2);

for(int i=0; i<2; i++) {
t[i] = malloc(sizeof(tabstruct));
}

strcpy(t[0]->field,"id");
t[0]->type = INT;

strcpy(t[1]->field,"name");
t[1]->type = CHAR;

return t;
}



void insertDataToTable(tabstruct **t) {
//for(int i=0;i<1000;i++)
//{
int id = 2010;
char *name = "ccccheck";
float price = id * 0.376;
             insertData(
		        t,
     			2, 
			id,
			name
			);
//} 
}

void insertDataToTable_Mongo(tabstruct **t, char *table_name) {
printf("insert to mongo\n");
int id = 2018;
char *name = "mongoDB";
int ret = insertData_Mongo(t, table_name,2, id, name);
}

/*
void printDetails(tabstruct **t) {
printf("in print\n");
for(int i=0;i<4;i++) {
printf("in for 1\n");
<<<<<<< Updated upstream
printf("field = %s : type = %u\n",t[i]->field,t[i]->type);
=======
printf("field = %s : type = %s\n",t[i]->field,getSqliteType(t[i]->type));
>>>>>>> Stashed changes
}
*/

 

