#include<stdio.h>
#include <string.h>
#include<sqlite3.h>
#include "dbhelper.h"
#include <sys/time.h>


void createTable(tabstruct** t, int col) {
printf("in create: col: %d\n",col);
sqlite3 *db;
sqlite3_stmt *stmt;
    char *err_msg = 0;

    int rc = sqlite3_open("test2.db", &db);
    sqlite3_exec(db, "pragma journal_mode = WAL", NULL, NULL, NULL);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        //return 1;
    }


char final[1000000];

for(int i=1;i<col;i++)
{
//printf("in for loop\n");
char temp[1000000];
if(i == 1) {
printf("in first code\n");
printf("%s\n",t[0]->field);
printf("%s: %s: %s: %s\n",t[i-1]->field,t[i-1]->field,t[i]->field,t[i]->type);
sprintf(temp,"DROP TABLE IF EXISTS %s; CREATE TABLE %s(%s %s,",t[i-1]->field,t[i-1]->field,t[i]->field,t[i]->type);
printf("%s\n",temp);
}

if( i!=1 && i!=col-1 ) {
sprintf(temp,"%s %s,",t[i]->field,t[i]->type);
printf("%s\n",temp);
}

if(i == col-1) {
sprintf(temp,"%s %s)",t[i]->field,t[i]->type);
printf("%s\n",temp);
}
strcat(final,temp);
printf("%s",final);
memset(temp, 0, 100000);
}

rc = sqlite3_exec(db,final,0,0,&err_msg);

if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        //return 1;
    } 
/*
//sqlite3_exec(db, "DROP TABLE IF EXISTS mcast;""CREATE TABLE mcast(id int, name text);",0,0,NULL);

//sqlite3_prepare_v2(db, "insert into cars(id) values(?1,?2,'string');", -1, &stmt, NULL);    
//for(int i=0;i<1000000;i++) {

//printf("id_sample = %d\nname = %s\nprice = %f\n",c->id, c->name, c->price);


  sqlite3_bind_text(stmt, 1,t[0]->field, sizeof((const char*)t[1]->field),0);
  sqlite3_bind_text(stmt, 2,t[0]->type, sizeof((const char*)t[1]->field),0);
  sqlite3_bind_text(stmt, 3,t[1]->field, sizeof((const char*)t[2]->field),0);
  sqlite3_bind_text(stmt, 4,t[1]->type, sizeof((const char*)t[2]->type),0);
  sqlite3_bind_text(stmt, 5,t[2]->field, sizeof((const char*)t[3]->field),0);
  sqlite3_bind_text(stmt, 6,t[2]->type, sizeof((const char*)t[3]->type),0);
  //sqlite3_bind_text(stmt, 7,t[3]->field, sizeof((const char*)t[3]->field),0);
  //sqlite3_bind_text(stmt, 8,t[3]->type, sizeof((const char*)t[3]->type),0);
  //sqlite3_bind_double(stmt, 3,c->price);
*/
  //rc = sqlite3_step(stmt);
  //sqlite3_reset(stmt);

//}
                                                                    /* 3 */
/*
printf("after bind\n");
if (rc != SQLITE_DONE) {
    printf("ERROR inserting data: %s\n", sqlite3_errmsg(db));


}

sqlite3_finalize(stmt);
//sqlite3_close(db);
//return 1;
*/
memset(final,0,1000000);
}






/*
int useSqlite(cars *c){
printf("in sample");
sqlite3 *db;
sqlite3_stmt *stmt;   
    char *err_msg = 0;

    int rc = sqlite3_open("test1.db", &db);
    sqlite3_exec(db, "pragma journal_mode = WAL", NULL, NULL, NULL);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        //return 1;
    }

struct timeval tv;

gettimeofday(&tv, NULL);

unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;


char *sql = "DROP TABLE IF EXISTS cars;"
                "CREATE TABLE cars(id INT,name TEXT, price REAL);";



rc = sqlite3_exec(db, sql, 0, 0, &err_msg);


sqlite3_prepare_v2(db, "insert into cars(id, name, price) values(?1,?2,?3);", -1, &stmt, NULL);     
if(rc != SQLITE_OK) {
fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);

//    return 1;
}

//sqlite3_prepare_v2(db, "insert into cars(id) values(?1,?2,'string');", -1, &stmt, NULL);     
///for(int i=0;i<1000000;i++) {

printf("id_sample = %d\nname = %s\nprice = %f\n",c->id, c->name, c->price);

 
  sqlite3_bind_int(stmt, 1,c->id);
  //sqlite3_bind_double(stmt, 2, i*1.5);
  sqlite3_bind_text(stmt, 2,c->name, sizeof((const char*)c->name),0);
  sqlite3_bind_double(stmt, 3,c->price);

  rc = sqlite3_step(stmt);
  //sqlite3_reset(stmt);

//}
                                                                    
printf("after bind\n");
if (rc != SQLITE_DONE) {
    printf("ERROR inserting data: %s\n", sqlite3_errmsg(db));


}

sqlite3_finalize(stmt);              
//sqlite3_close(db);	  
return 1;
}
*/
