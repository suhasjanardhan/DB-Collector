#include <mongoc.h>
#include <stdio.h>
#include <sys/time.h>
#include "dbhelper.h"

int insertData_Mongo(tabstruct **t, char *table_name, int col, ...) {
   const char *uri_string = "mongodb://localhost:27017";
   mongoc_uri_t *uri;
   mongoc_client_t *client;
   mongoc_database_t *database;
   mongoc_collection_t *collection;
   bson_t *command, reply, *insert;
   bson_error_t error;
   char *str;
   bool retval;

   /*
    * Required to initialize libmongoc's internals
    */
   mongoc_init ();

   /*
    * Optionally get MongoDB URI from command line
    */
   //if (argc > 1) {
     // uri_string = argv[1];
   //}

   /*
    * Safely create a MongoDB URI object from the given string
   */ 

   uri = mongoc_uri_new_with_error (uri_string, &error);
   if (!uri) {
      fprintf (stderr,
               "failed to parse URI: %s\n"
               "error message:       %s\n",
               uri_string,
               error.message);
      return EXIT_FAILURE;
   }

   
   //Create a new client instance
    
   client = mongoc_client_new_from_uri (uri);
   if (!client) {
      return EXIT_FAILURE;
   }

   /*
    * Register the application name so we can track it in the profile logs
    * on the server. This can also be done from the URI (see other examples).
    */
   mongoc_client_set_appname (client, "connect-example");

   /*
    * Get a handle on the database "db_name" and collection "coll_name"
    */
   char dbName[33];
   strcpy(dbName, table_name);
   strcat(dbName, "_DB");
   char collectionName[33];
   strcpy(collectionName,table_name);
   strcat(collectionName, "_Coll");
   printf("DB name: %s\n",dbName);
   database = mongoc_client_get_database (client, dbName);
   printf("Collection name: %s\n",collectionName);
   collection = mongoc_client_get_collection (client, dbName, collectionName);

   /*
    * Do work. This example pings the database, prints the result as JSON and
    * performs an insert
    */
   command = BCON_NEW ("ping", BCON_INT32 (1));

   retval = mongoc_client_command_simple (
      client, "admin", command, NULL, &reply, &error);

   if (!retval) {
      fprintf (stderr, "%s\n", error.message);
      return EXIT_FAILURE;
   }

struct timeval tv;

gettimeofday(&tv, NULL);

unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;



   str = bson_as_json (&reply, NULL);
   printf ("%s\n", str);

   int id_v;
   char *n_v;
   float p_v;   

   printf("inside mongo\n");
   printf("%s\n", table_name);
   va_list ap;
   va_start(ap, col);
   for(int i=0;i<col;i++) {
    printf("type: %s\n",getSqliteType(t[i]->type));
    if(strcmp(getSqliteType(t[i]->type),"INT") == 0) {
      id_v = va_arg(ap, int);
      if(i==0)
      insert = BCON_NEW (t[i]->field, BCON_INT32(id_v));
      
      BCON_APPEND(insert, t[i]->field, BCON_INT32(id_v));
      printf("%d\n",id_v);
    } else if(strcmp(getSqliteType(t[i]->type),"REAL") == 0) {
      p_v = va_arg(ap, double);
      if(i==0)
      insert = BCON_NEW (t[i]->field, BCON_DOUBLE(p_v));

      BCON_APPEND(insert, t[i]->field, BCON_DOUBLE(p_v));
      printf("%f\n", p_v);
    } else if(strcmp(getSqliteType(t[i]->type),"TEXT") == 0) {
      n_v = va_arg(ap, char *);
      if(i==0)
      insert = BCON_NEW (t[i]->field, BCON_UTF8(n_v));

      BCON_APPEND(insert, t[i]->field, BCON_UTF8(n_v));
      printf("%s\n", n_v);
    }
  printf("in sample id = %d, name = %s, price = %f\n",id_v, n_v, p_v);
}

   //for (int i=0;i<100;i++) {
       //insert = BCON_NEW ("id", BCON_INT32(i));
       //insert = BCON_NEW ("id", BCON_INT32(c->id));
       //BCON_APPEND(insert, "Name", BCON_UTF8(c->name));
      // BCON_APPEND(insert, "Price", BCON_DOUBLE(c->price));
       //BCON_APPEND(insert, "Name", BCON_UTF8("Volkswagen"));
       //BCON_APPEND(insert, "time", BCON_DATE_TIME(millisecondsSinceEpoch));      
       

       if (!mongoc_collection_insert_one (collection, insert, NULL, NULL, &error)) {
          fprintf (stderr, "%s\n", error.message);
       }
       bson_destroy (insert);
  // }

   bson_destroy (&reply);
   bson_destroy (command);
   bson_free (str);

   /*
    * Release our handles and clean up libmongoc
    */
   mongoc_collection_destroy (collection);
   mongoc_database_destroy (database);
   mongoc_uri_destroy (uri);
   mongoc_client_destroy (client);
   mongoc_cleanup ();

   return 1;
   //return EXIT_SUCCESS;
}
