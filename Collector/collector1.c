#include "collector.h"
#include <stdlib.h>
#include <stdio.h>
#include "dbhelper.h"

int getColumnNum_1() {
return 5;
}

tabstruct** getStruct_Collector1() {

tabstruct **t;

t = malloc(sizeof(tabstruct*) * 5);
printf("in collector 2\n");

for(int i=0; i<5; i++) {
t[i] = malloc(sizeof(tabstruct));
}
printf("in for 2\n");
t[0]->field = "sample_tab2";
t[0]->type = "";

t[1]->field = "id";
t[1]->type = "INT";

t[2]->field = "name";
t[2]->type = "TEXT";

t[3]->field = "price";
t[3]->type = "REAL";

t[4]->field = "count";
t[4]->type = "INT";

return t;
}

/*
void printDetails(tabstruct **t) {

for(int i=0;i<5;i++) {
printf("field = %s : type = %s\n",t[i]->field,t[i]->type);
}

} 
*/
