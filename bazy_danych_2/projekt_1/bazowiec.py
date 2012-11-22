#!/usr/bin/env python
import pymssql
class Bazowiec:
	def __init__(self):
		self.itsConn=None
		self.itsCur=None
	def __del__(self):
		self.itsConn.close()
	def connect(self):
		self.itsConn=pymssql.connect(host='localhost:14330',user='marcin',password='Project123',database='AdventureWorks',as_dict=True)
		self.itsCur=self.itsConn.cursor()
		return self.itsConn
	def setDatabase(self,baza):
		self.itsCur.execute("use %s"%baza)
	def listDatabases(self):
		self.itsCur.execute("exec sp_databases")
		return [row[0] for row in self.itsCur.fetchall()]
	def listTables(self):
		self.itsCur.execute("SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE' order by table_schema,table_name")
		return ["%s.%s"%(row[1],row[2]) for row in self.itsCur.fetchall()]
	def listColumns(self,table):
		table=table.split('.')
		self.itsCur.execute("select * from information_schema.columns where table_schema='%s' and table_name='%s'"%(table[0],table[1]))
		return [ (row[3],row[7]) for row in self.itsCur.fetchall()]
#row[3] name
#row[7] type
if __name__=="__main__":
	baz=Bazowiec()
	baz.connect()
	lista=baz.listDatabases()
	for i in lista:
		print i
