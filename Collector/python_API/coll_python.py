import sqlite3


dbTableName = ""

#createTab = "DROP TABLE IF EXISTS {}; CREATE TABLE {}(";

def CreateTable(columns,tableName):
    dropTab = "DROP TABLE IF EXISTS {};"
    createTab = "CREATE TABLE {}(";
    query_ext = [x + " " + y for(x,y) in columns]
    query_ext = ",".join(query_ext) 
    createTab += query_ext + ");";
    print(createTab)
    
    dropTab = dropTab.format(tableName);
    createTab = createTab.format(tableName);
    print(createTab)

    conn = sqlite3.connect("{}.db".format(tableName));
    c = conn.cursor()


    # Create createTable
    c.execute(dropTab)
    c.execute(createTab)

    # Insert a row of data
    #c.execute("INSERT INTO stocks VALUES ('2006-01-05','BUY','RHAT',100,35.14)")

    # Save (commit) the changes
    conn.commit() 
    conn.close()
