#include <stdio.h>
#include "dbhelper.h"

/*void createTable(tabstruct** t, int col) {
createTab(t,col);
}*/

const char * getSqliteType(TYPE_ENUM type_t){
     if(type_t > UNDEFINED){
     	fprintf(stderr, "TYPE ERROR: %u is not defined as DB data type \n", type_t);
	return "UNDEFINED";
     }
     return SQLITE_TYPE[type_t];
}
