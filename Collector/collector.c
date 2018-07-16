#include "collector.h"
#include <stdlib.h>
#include <stdio.h>

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
t[0]->type = 100;

t[1]->field = "id";
t[1]->type = UINT8_T;

t[2]->field = "name";
t[2]->type = STRING;

t[3]->field = "price";
t[3]->type = FLOAT;

return t;
}


void printDetails(tabstruct **t) {
printf("in print\n");
for(int i=0;i<4;i++) {
printf("in for 1\n");
printf("field = %s : type = %u\n",t[i]->field,t[i]->type);
}

} 

