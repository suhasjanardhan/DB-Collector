#ifndef DBHELPER_H_
#define DBHELPER_H_

//#include "collector.h"

//extern int useSqlite();
//extern int useMongo();
#define MAX_TYPES 1000
#define enum_type(x, y, z) x,
#define sqlite_type(x, y, z) y,
#define mongo_type(x, y, z) z
#define concat(x,y) x##y
#define str(x) #x

#define NEW_TYPE(enum_sqlite_mongo) \
	enum_sqlite_mongo(UINT8_T, "TINYINT", "INT32") \
	enum_sqlite_mongo(UINT16_T, "SMALLINT", "INT32") \
	enum_sqlite_mongo(INT, "INT", "INT32") \
	enum_sqlite_mongo(UNSINGED_INT, "UNSIGNED BIG INT", "INT32") \
	enum_sqlite_mongo(STRING, "TEXT", "UTF8")\
	enum_sqlite_mongo(CHAR, "TEXT", "UTF8") \
	enum_sqlite_mongo(UNSIGNED_CHAR, "TEXT", "UTF8")\
	enum_sqlite_mongo(DOUBLE, "REAL", "DOUBLE") \
	enum_sqlite_mongo(BOOLEAN, "INT2", "BOOL") \
	enum_sqlite_mongo(FLOAT, "REAL", "DOUBLE")\
	enum_sqlite_mongo(TIMESTAMP, "NUMERIC", "TIMESTAMP")\


enum types \
	{
	   NEW_TYPE(enum_type) UNDEFINED
	};
typedef enum types TYPE_ENUM;
//extern const char * SQLITE_TYPE[];

static const char * SQLITE_TYPE[MAX_TYPES] ={
	  NEW_TYPE(sqlite_type) "UNDEFINED"
	};


typedef struct {
char *field;
TYPE_ENUM type;
}tabstruct;

int getColumnNum();
int getColumnNum_1();
extern tabstruct** getStruct_Collector();
extern tabstruct** getStruct_Collector1();
extern void createTable(tabstruct** t, int col);
//extern void createTab(tabstruct** t, int col);
const char * getSqliteType(TYPE_ENUM);
#endif
