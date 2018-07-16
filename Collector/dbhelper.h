#ifndef DBHELPER_H_
#define DBHELPER_H_

//#include "collector.h"

//extern int useSqlite();
//extern int useMongo();
#define MAX_TYPES 1000
#define enum_type(x, y) x,
#define sqlite_type(x, y) y,
#define str(x) #x

#define NEW_TYPE(enum_or_db) \
	enum_or_db(UINT8_T, "TINYINT") \
	enum_or_db(UINT16_T, "SMALLINT") \
	enum_or_db(INT, "INT") \
	enum_or_db(UNSINGED_INT, "UNSIGNED BIG INT") \
	enum_or_db(STRING, "TEXT")\
	enum_or_db(CHAR, "TEXT") \
	enum_or_db(UNSIGNED_CHAR, "TEXT")\
	enum_or_db(DOUBLE, "REAL") \
	enum_or_db(BOOLEAN, "INT2") \
	enum_or_db(FLOAT, "REAL")\
	enum_or_db(TIMESTAMP, "NUMERIC")\


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
