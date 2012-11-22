#!/usr/bin/env python
import pymssql
def connect():
	return pymssql.connect(host='localhost:14330',user='marcin',password='Project123',database='AdventureWorks',as_dict=True)
def setDatabase(conn,baza):
	conn.cursor().execute("use %s"%baza)
def listDatabases(conn):
	cur=conn.cursor()
	cur.execute("exec sp_databases")
	return [row[0] for row in cur.fetchall()]
def listTables(conn):
	cur=conn.cursor()
	cur.execute("SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE'")
	return ["%s.%s"%(row[1],row[2]) for row in cur.fetchall()]
def listColumns(conn, table):
	table=table.split('.')
	cur=conn.cursor()
	cur.execute("select * from information_schema.columns where table_schema='%s' and table_name='%s'"%(table[0],table[1]))
	return [ (row[3],row[7]) for row in cur.fetchall()]
#row[3] name
#row[7] type
conn=connect()
lista=listColumns(conn,'Person.Contact')
for i in lista:
	print i
conn.close()
