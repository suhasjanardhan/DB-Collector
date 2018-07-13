#include "collector.h"
#include <stdlib.h>
#include <stdio.h>
#include "dbhelper.h"

int getColumnNum() {
return 4;
}

tabstruct** getStruct_Collector() {

tabstruct **t;

t = malloc(sizeof(tabstruct*) * 4);
printf("in collector\n");
for(int i=0; i<4; i++) {
printf("in for\n");
t[i] = malloc(sizeof(tabstruct));
}

t[0]->field = "sample_tab";
t[0]->type = "";

t[1]->field = "id";
t[1]->type = "INT";

t[2]->field = "name";
t[2]->type = "TEXT";

t[3]->field = "price";
t[3]->type = "REAL";

return t;
}


void printDetails(tabstruct **t) {
printf("in print\n");
for(int i=0;i<4;i++) {
printf("in for 1\n");
printf("field = %s : type = %s\n",t[i]->field,t[i]->type);
}

} 

