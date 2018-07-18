#ifndef DBHELPER_H_
#define DBHELPER_H_

//#include "collector.h"
#include<stdio.h>
//extern int useSqlite();
//extern int useMongo();
#define MAX_TYPES 1000
#define enum_type(x, y, z) x,
#define sqlite_type(x, y, z) y,
#define mongo_type(x, y, z) z, 
#define concat(x,y) x##y
#define str(x) #x

#define CCHECK_NEW_DATATYPE(enum_sqlite_mongo) \
	enum_sqlite_mongo(UINT8_T, "TINYINT", "INT32") \
	enum_sqlite_mongo(UINT16_T, "SMALLINT", "INT32") \
	enum_sqlite_mongo(INT, "INT", "INT32") \
	enum_sqlite_mongo(INT32, "INT", "INT32") \
	enum_sqlite_mongo(UNSIGNED_INT, "UNSIGNED BIG INT", "INT32") \
	enum_sqlite_mongo(UNSIGNED_LONG_INT, "INTEGER", "INT64") \
	enum_sqlite_mongo(STRING, "TEXT", "UTF8")\
	enum_sqlite_mongo(CHAR, "TEXT", "UTF8") \
	enum_sqlite_mongo(UNSIGNED_CHAR, "TEXT", "UTF8")\
	enum_sqlite_mongo(DOUBLE, "REAL", "DOUBLE") \
	enum_sqlite_mongo(BOOLEAN, "INT2", "BOOL") \
	enum_sqlite_mongo(FLOAT, "REAL", "DOUBLE")\
	enum_sqlite_mongo(TIMESTAMP, "NUMERIC", "TIMESTAMP")\


enum cchecker_data_types \
	{
	   CCHECK_NEW_DATATYPE(enum_type) UNDEFINED
	};
typedef enum cchecker_data_types CCHECK_DATATYPE_ENUM_T;
//extern const char * SQLITE_TYPES[];

const char * getSqliteType (CCHECK_DATATYPE_ENUM_T type_t);
const char * getMongoType (CCHECK_DATATYPE_ENUM_T type_t);



typedef struct {
   char *field;
   CCHECK_DATATYPE_ENUM_T type;
} tabstruct;

int getColumnNum();
int getColumnNum_1();
extern tabstruct** getStruct_Collector();
extern tabstruct** getStruct_Collector1();
extern void createTable(tabstruct** t, int col);
//extern void createTab(tabstruct** t, int col);
#endif
