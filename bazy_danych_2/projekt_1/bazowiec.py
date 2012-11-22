#!/usr/bin/env python
import pymssql
conn=pymssql.connect(host='localhost:14330',user='marcin',password='Project123',database='AdventureWorks')
cur=conn.cursor()
cur.execute("SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE'")
result=cur.fetchall()
for row in result:
	print row
conn.close()
