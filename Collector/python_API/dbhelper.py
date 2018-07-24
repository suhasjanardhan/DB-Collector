import sqlite3
import coll_python
from enum import Enum

DB_SWITCH = 0 #SQLITE = 0, MONGO = 1

CCHECK_DATA_TYPES = {
    'UINT8_T' : ('TINYINT', 'INT32'), 
    'UINT16_T' : ('SMALLINT', 'INT32'),
    'INT' : ('INT', 'INT32'),
    'UNSIGNED_INT' : ('UNSIGNED BIG INT', 'INT32'),
    'INT32' : ('INT', 'INT32'),
    'UNSINGED_LONG_INT' : ('INTEGER', 'INT64'),
   'STRING' : ('TEXT', 'UTF8'),
   'CHAR' : ('TEXT', 'UTF8'),
   'UNSIGNED_CHAR' : ('TEXT', 'UTF8'),
   'TIMESTAMP' : ('NUMERIC', 'TIMESTAMP'),
}

class Tabledata:
    def __init__(self, table_name):
       '''
           table_name String
       '''
       self.table_name = table_name 
       '''                       
          columns should be      
          Array of Tuples, 
          for instance [("name_of_1st_column", CCHECK_DATA_TYPES.INT), ... ] 
       '''
       self.columns = []
       self.table_data_list = []

    def add_column(self, name, data_type): 
       '''
           name STRING
           data_type CCHECK_DATA_TYPES
       '''
       db_type = CCHECK_DATA_TYPES.get(data_type, None);
       if db_type is None:
           print('***TYPE WARNING : No such type for given '+data_type)
           db_type = ('TEXT', 'UTF8')
       column_tuple = (name, db_type[DB_SWITCH]);
       self.columns.append(column_tuple);

    def __str__(self):
       pretty_print = "TableName: " + self.table_name + "\nColumns:\n   "
       "      ".join(["%s %s\n" % (x[0],x[1]) for x in self.columns]) 
       return pretty_print

    def get_table_info(self):
       return {
          Table_Name: self.table_name,
          Columns: self.columns
       }

    def add_data_to_column(column_name, column_data):
       temp_array = [None] * len(self.columns)
       if(self.columns.index(column_name[0]) != -1):
           temp_array[self.columns.index(column_name)] = column_data;
           self.table_data_list.append((temp_array))
     
       else:
           print(column_name + "No such column exists in the table ")
           exit(0);

    def add_data_to_table(self, **kwargs):
        self.table_data_list.append(kwargs)
       
    
    def call_create_table(self):
       print("calling create table");
       coll_python.CreateTable(self.columns,self.table_name);
   
     
sample_table_data = Tabledata("Test_Table")
sample_table_data.add_column('col1', 'INT');
sample_table_data.add_column('col2', 'STRING');
print(sample_table_data);
sample_table_data.call_create_table();
sample_table_data.add_data_to_table(col1=1,col2='abc');
sample_table_data.add_data_to_table(col1=2,col2='sat');
sample_table_data.add_data_to_table(col1=3,col2='xyz');
dic = { 'col2':'abc', 'col1': '4'}
sample_table_data.add_data_to_table(**dic);
print(sample_table_data.table_data_list)


 
                
