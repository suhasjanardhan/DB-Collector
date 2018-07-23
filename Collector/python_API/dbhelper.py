import sqlite3
import coll_python
from enum import Enum

DB_SWITCH = 0 #SQLITE = 1, MONGO = 2

class CCHECK_DATA_TYPES(Enum):
    UINT8_T = ('TINYINT', 'INT32'); 
    UINT16_T = ('SMALLINT', 'INT32');
    INT = ('INT', 'INT32')
    UNSIGNED_INT = ('UNSIGNED BIG INT', 'INT32')
    INT32 = ('INT', 'INT32')
    UNSINGED_LONG_INT = ('INTEGER', 'INT64')
    STRING = ('TEXT', 'UTF8')
    CHAR = ('TEXT', 'UTF8')
    UNSIGNED_CHAR = ('TEXT', 'UTF8')
    TIMESTAMP = ('NUMERIC', 'TIMESTAMP')
        

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

    def add_column(self, name, data_type): #data_type should be of type CCHECK_DATA_TYPES
        column_tuple = (name, data_type.value[DB_SWITCH]);
        self.columns.append(column_tuple);

    def __str__(self):
        pretty_print = "TableName: " + self.table_name + "\nColumns:\n   "
        for x in self.columns:
            pretty_print+=x[0]+" "+x[1]+"\n   " 
        return pretty_print
    
    def callCreateTable(self):
        print("calling create table");
        coll_python.CreateTable(self.columns,self.table_name);
   
     
print(CCHECK_DATA_TYPES.UINT8_T.value[0]);
sample_table_data = Tabledata("Test_Table")
sample_table_data.add_column('col1', CCHECK_DATA_TYPES.INT);
sample_table_data.add_column('col2', CCHECK_DATA_TYPES.STRING);
print(sample_table_data);
sample_table_data.callCreateTable();
 
                
