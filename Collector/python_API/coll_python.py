import sqlite3


def createTable(columns,tableName):
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

    conn.commit() 
    conn.close()

def insertToTable(data, tableName):
    conn = sqlite3.connect("{}.db".format(tableName));
    c = conn.cursor()
   
    keyStmt = ",".join([x for x in data]);
    valStmt = ""
    for v in data.values():
        if isinstance(v, str):
            v = "\'" +v+"\'"
        else: v = str(v)
        valStmt += "," + v 
   
    
    insertStmt = "INSERT INTO {0}({1}) values({2});".format(tableName,keyStmt,valStmt[1:]);
    
        
    print(insertStmt);
           
    c.execute(insertStmt);
    
    conn.commit()
    conn.close()
