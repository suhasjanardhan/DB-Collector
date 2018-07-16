#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbhelper.h"
#include "collector.h"
//#include "collector1.h"



int main() {


int numOfColumn = 0;
numOfColumn = getColumnNum();

if(numOfColumn > 0) {
tabstruct **t = malloc(sizeof(tabstruct*) * numOfColumn);
t = getStruct_Collector();
//printf("before print\n");
//printf("%s: %s: %s: %s\n",t[0]->field,t[0]->field,t[1]->field,t[1]->type);
createTable(t,numOfColumn);
/*
//memset(t, 0, sizeof(tabstruct*) *numOfColumn);
t = malloc(sizeof(tabstruct*) * numOfColumn);
printf("debug 1\n");
numOfColumn = getColumnNum_1();
printf("%d\n",numOfColumn);
t = getStruct_Collector1();
createTable(t,numOfColumn);
*/
}

return 0;
}
