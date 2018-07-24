#ifndef DBHELPER_H_
#define DBHELPER_H_

#include<stdio.h>
#define enum_type(x, y, z) x,
#define sqlite_type(x, y, z) y,
#define mongo_type(x, y, z) z, 
#define concat(x,y) x##y
#define str(x) #x
#define FIELD_SIZE 33

/*
Defining the different data types which are used 
in the process of consistency checker. Native C types 
are converted to corresponding 
native DB types using the below enums
*/
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


char *table_name;    /* table_name is used to hold the table name of components which helps in creating the table */


/*
Main struct which helps in getting all the 
columns and its types to create the table in data base.
*/
typedef struct {
char field[FIELD_SIZE];
CCHECK_DATATYPE_ENUM_T type;
}tabstruct;




int getColumnNum();
//int getColumnNum_1();
char *getTableName();
//char *getTableName_1();
extern tabstruct** getStruct_Collector();
//extern tabstruct** getStruct_Collector1();

/*
the function below is used to create the table in database.
parameters are table name, the main struct which will be
populated with field and types and the number of columns to be created 
in the table
*/
extern void createTable(char *table_name,tabstruct** t, int col);

extern void insertDataToTable(tabstruct **t);
extern void insertDataToTable_Mongo(tabstruct **t, char *table_name);


/*
the function below is used to insert the data in to 
the columns created previously. Previously populated struct 
is used as first parameter second paramter is the number of 
variable arguments which will be passed as the parameters 
which is same as the number of columns. Variable arguments should be in the 
same ordere as the columns.
*/
extern void insertData(tabstruct **t,int col,  ...);
extern int insertData_Mongo(tabstruct **t, char *table_name, int col, ...);

#endif
