#!/usr/bin/env python
import pymssql
conn=pymssql.connect(host='localhost:14330',user='marcin',password='Project123',database='AdventureWorks',as_dict=True)
cur=conn.cursor()
#cur.execute("SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE'")
#cur.execute("exec sp_databases")
cur.execute("select * from information_schema.columns where table_name='Contact'")
result=cur.fetchall()
for row in result:
#row[3] name
#row[7] type
	print row[3]
conn.close()
