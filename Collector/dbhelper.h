#ifndef DBHELPER_H_
#define DBHELPER_H_

#include<stdio.h>
#define enum_type(x, y, z) x,
#define sqlite_type(x, y, z) y,
#define mongo_type(x, y, z) z, 
#define concat(x,y) x##y
#define str(x) #x


#define CCHECK_NEW_DATATYPE(enum_sqlite_mongo) \
 	enum_sqlite_mongo(UINT8_T, "TINYINT", "INT32") \
 	enum_sqlite_mongo(UINT16_T, "SMALLINT", "INT32") \
 	enum_sqlite_mongo(INT, "INT", "INT32") \
	enum_sqlite_mongo(UNSINGED_INT, "UNSIGNED BIG INT", "INT32") \
	enum_sqlite_mongo(INT32, "INT", "INT32") \
	enum_sqlite_mongo(UNSIGNED_INT, "UNSIGNED BIG INT", "INT32") \
	enum_sqlite_mongo(UNSIGNED_LONG_INT, "INTEGER", "INT64") \
 	enum_sqlite_mongo(STRING, "TEXT", "UTF8")\
 	enum_sqlite_mongo(CHAR, "TEXT", "UTF8") \
 	enum_sqlite_mongo(UNSIGNED_CHAR, "TEXT", "UTF8")\
 	enum_sqlite_mongo(TIMESTAMP, "NUMERIC", "TIMESTAMP")\


enum cchecker_data_types \
 	{
	   
	   CCHECK_NEW_DATATYPE(enum_type) UNDEFINED
 	};

typedef enum cchecker_data_types CCHECK_DATATYPE_ENUM_T;


extern const char * getSqliteType (CCHECK_DATATYPE_ENUM_T type_t);
extern const char * getMongoType (CCHECK_DATATYPE_ENUM_T type_t);


char *table_name;

typedef struct {
char field[33];
CCHECK_DATATYPE_ENUM_T type;
}tabstruct;




int getColumnNum();
//int getColumnNum_1();
char *getTableName();
//char *getTableName_1();
extern tabstruct** getStruct_Collector();
//extern tabstruct** getStruct_Collector1();
extern void createTable(char *table_name,tabstruct** t, int col);
extern void insertDataToTable(tabstruct **t);
extern void insertData(tabstruct **t,int col,  ...);

/*
*/




#endif
