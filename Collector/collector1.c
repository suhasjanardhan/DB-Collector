#include "collector.h"
#include <stdlib.h>
#include <stdio.h>
#include "dbhelper.h"
#include <string.h>
/*
tabstruct** getStructure() {
return getStruct_Collector1();
}

int getColumnNumber() {
return getColumnNum_1();
}
*/
int getColumnNum_1() {
return 5;
}

char *getTableName_1() {
char *tname = "component_b";
return tname;
}

tabstruct** getStruct_Collector1() {

tabstruct **t;

t = malloc(sizeof(tabstruct*) * 5);
//printf("in collector 2\n");

for(int i=0; i<5; i++) {
t[i] = malloc(sizeof(tabstruct));
}
//printf("in for 2\n");

strcpy(t[0]->field,"id");
t[0]->type = INT;

strcpy(t[1]->field,"name");
t[1]->type = CHAR;

strcpy(t[2]->field,"price");
t[2]->type = FLOAT;

strcpy(t[3]->field,"count");
t[3]->type = INT;

return t;
}


void insertDataToTable(tabstruct **t) {
//for(int i=0;i<1000;i++)
//{
int id = 22222;
char *name = "ccccheck_2";
float price = id * 0.376;
int ct = 7;
             insertData(
                        t,
                        4,
                        id,
                        name,
                        price,
			ct);
//}
}



/*
void printDetails(tabstruct **t) {

for(int i=0;i<5;i++) {
printf("field = %s : type = %s\n",t[i]->field,t[i]->type);
}

} 
*/
