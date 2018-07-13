#ifndef DBHELPER_H_
#define DBHELPER_H_

//#include "collector.h"

//extern int useSqlite();
//extern int useMongo();


typedef struct {
char *field;
char *type;
}tabstruct;

int getColumnNum();
int getColumnNum_1();
extern tabstruct** getStruct_Collector();
extern tabstruct** getStruct_Collector1();
extern void createTable(tabstruct** t, int col);
//extern void createTab(tabstruct** t, int col);
#endif
