#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include<sqlite3.h>
#include "dbhelper.h"
#include <sys/time.h>
#include <stdarg.h>


sqlite3 *db;
sqlite3_stmt *stmt;
    char *err_msg = 0;
char db_name[32];
    int rc = 0;

char final[1000000];
char insert_1[1000000];
char insert_2[1000000];

void createTable(char *table_name, tabstruct** t, int col) {
printf("inside create table\n");
strcpy(db_name,table_name);
strcat(db_name,"_DB.db"); 
rc = sqlite3_open(db_name, &db);
    sqlite3_exec(db, "pragma journal_mode = WAL", NULL, NULL, NULL);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        //return 1;
    }

for(int i=0;i<col;i++)
{

char temp[1000000];
char temp1[1000000];
char temp2[100000];
if(i == 0) {
sprintf(temp,"DROP TABLE IF EXISTS %s; CREATE TABLE %s(%s %s,",t[i-1]->field,t[i-1]->field,t[i]->field, getSqliteType(t[i]->type));
sprintf(temp1,"INSERT INTO %s(%s,",table_name,t[i]->field);
sprintf(temp2,"values(?%d,",i+1);

}

if( i!=0 && i!=col-1 ) {
sprintf(temp,"%s %s,",t[i]->field,getSqliteType(t[i]->type));
sprintf(temp1,"%s,",t[i]->field);
sprintf(temp2, "?%d,", i+1);
}

if(i == col-1) {
sprintf(temp,"%s %s);",t[i]->field,getSqliteType(t[i]->type));
sprintf(temp1,"%s)",t[i]->field);
sprintf(temp2,"?%d);",i+1);

}

strcat(insert_2,temp2);

strcat(final,temp);

strcat(insert_1,temp1);
printf("%s\n",final);
memset(temp, 0, 1000000);
memset(temp1, 0, 1000000);
memset(temp2, 0, 100000);

}

rc = sqlite3_exec(db,final,0,0,&err_msg);

if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        //return 1;
    } 
memset(final,0,1000000);
strcat(insert_1,insert_2);
printf("final: %s\n",insert_1);
}


void insertData(tabstruct **t, int col, ...) {
rc = sqlite3_open(db_name, &db);

    int id_v;
    char *n_v;
    float p_v;
printf("insert statement: %s\n",insert_1);
rc = sqlite3_prepare_v2(db, insert_1, -1, &stmt, NULL);
    va_list ap;
    va_start(ap, col);
    for(int i=0 ; i < col; i++){
        printf("type: %s\n",getSqliteType(t[i]->type));
        if(strcmp(getSqliteType(t[i]->type),"INT") == 0) {
	  id_v = va_arg(ap, int);
	  sqlite3_bind_int(stmt, i+1,id_v);
          printf("%d\n",id_v);
        } else if(strcmp(getSqliteType(t[i]->type),"REAL") == 0) {
          p_v = va_arg(ap, double);
	  sqlite3_bind_double(stmt, i+1, p_v);
	  printf("%f\n", p_v);
        } else if(strcmp(getSqliteType(t[i]->type),"TEXT") == 0) {
          n_v = va_arg(ap, char *);
          sqlite3_bind_text(stmt, i+1,n_v, sizeof((const char*)n_v),0);
	  printf("%s\n", n_v);
        }
     printf("in sample id = %d, name = %s, price = %f\n",id_v, n_v, p_v);
    }
    va_end(ap);


  rc = sqlite3_step(stmt);
  sqlite3_reset(stmt);


printf("after bind\n");
if (rc != SQLITE_DONE) {
    printf("ERROR inserting data: %s\n", sqlite3_errmsg(db));


}

sqlite3_finalize(stmt);
memset(insert_1, 0, 1000000);
}


/*
struct timeval tv;

gettimeofday(&tv, NULL);

unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;

*/

