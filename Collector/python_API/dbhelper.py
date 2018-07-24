import sqlite3
import coll_python


DB_SWITCH = 0 #SQLITE = 0, MONGO = 1

CCHECK_DATA_TYPES = {
    'UINT8_T'               : ('TINYINT', 'INT32'), 
    'UINT16_T'              : ('SMALLINT', 'INT32'),
    'INT'                   : ('INT', 'INT32'),
    'UNSIGNED_INT'          : ('UNSIGNED BIG INT', 'INT32'),
    'INT32'                 : ('INT', 'INT32'),
    'UNSINGED_LONG_INT'     : ('INTEGER', 'INT64'),
    'STRING'                : ('TEXT', 'UTF8'),
    'CHAR'                  : ('TEXT', 'UTF8'),
    'UNSIGNED_CHAR'         : ('TEXT', 'UTF8'),
    'TIMESTAMP'             : ('NUMERIC', 'TIMESTAMP'),
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


    def add_data_to_table(self, **kwargs):
        coll_python.insertToTable(kwargs, self.table_name);
    
    def create_table(self):
        print("calling create table");
        coll_python.createTable(self.columns,self.table_name);

    #def insert_to_table(self):
        #print("calling insert to table");
        #coll_python.insertToTable(self.table_data_list, self.table_name);
   
     

sample_table_data = Tabledata("test")
sample_table_data.add_column('col1', 'INT');
sample_table_data.add_column('col2', 'STRING');


print(sample_table_data);
sample_table_data.create_table();
sample_table_data.add_data_to_table(col1=1,col2='abc');
sample_table_data.add_data_to_table(col1=2,col2='sat');
sample_table_data.add_data_to_table(col1=3,col2='xyz');


dic = { 'col2':'abc', 'col1': '4'};
sample_table_data.add_data_to_table(**dic);
