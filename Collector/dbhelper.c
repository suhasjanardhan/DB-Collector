#include <stdio.h>
#include "dbhelper.h"

const char * getSqliteType(CCHECK_DATATYPE_ENUM_T type_t){

	static const char * SQLITE_TYPES []={
	  CCHECK_NEW_DATATYPE(sqlite_type) 
	};	

     if(type_t > UNDEFINED){
        fprintf(stderr, "TYPE ERROR: %u is not defined as DB data type \n", type_t); 
	return "UNDEFINED";
     }
     return SQLITE_TYPES[type_t];
}

const char * getMongoType (CCHECK_DATATYPE_ENUM_T type_t) {
      static const char * MONGO_TYPES[] = {  
	    CCHECK_NEW_DATATYPE(mongo_type) 
	};
      
      if(type_t > UNDEFINED) {
     	  fprintf(stderr, "TYPE ERROR: %u is not defined as DB data type\n", type_t);
	  return "UNDEFINED"; 
      }

      return MONGO_TYPES[type_t];   
 }
