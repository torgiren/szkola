#!/usr/bin/env python
import pymssql
conn=pymssql.connect(host='localhost:14330',user='marcin',password='Project123',database='AdventureWorks',as_dict=True)
cur=conn.cursor()
#cur.execute("SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE'")
cur.execute("select * from master..sysdatabases")
result=cur.fetchall()
for row in result:
	print row['name']
conn.close()
