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
table_name = getTableName();
tabstruct **t = malloc(sizeof(tabstruct*) * numOfColumn);
t = getStruct_Collector();



/*
//memset(t, 0, sizeof(tabstruct*) *numOfColumn);
t = malloc(sizeof(tabstruct*) * numOfColumn);
//printf("debug 1\n");
numOfColumn = getColumnNum_1();
//printf("%d\n",numOfColumn);
table_name = getTableName_1();
t = getStruct_Collector1();
<<<<<<< Updated upstream
createTable(t,numOfColumn);
*/

createTable(table_name, t, numOfColumn);
insertDataToTable(t);



}



return 0;
}
