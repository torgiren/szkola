#!/usr/bin/env python
# -*- coding: utf-8 -*-
import pymssql
class Bazowiec:
	def __init__(self):
		"""Zerujemy potrzebne zmienne"""
		self.itsConn=None
		self.itsCur=None
	def __del__(self):
		"""Zamykamy połączenie do bazy"""
		if self.itsConn:
			self.itsConn.close()
	def connect(self,host,port):
		"""Łączenie do bazy danych z ustawionymi na sztywno parametrami,
			pobieramy kursor bazy"""
		h="%s:%s"%(host,port)
		self.itsConn=pymssql.connect(host=h,user='marcin',password='Project123',database='AdventureWorks',as_dict=True)
		self.itsCur=self.itsConn.cursor()
		return self.itsConn
	def setDatabase(self,baza):
		"""Wybieranie aktywnej bazy dancyh"""
		self.itsCur.execute("use %s"%baza)
	def listDatabases(self):
		"""Pobieramy listę baz danych wykorzystując funkcje MS SQLa"""
		self.itsCur.execute("exec sp_databases")
		return [row[0] for row in self.itsCur.fetchall()]
	def listTables(self):
		"""Pobieramy z tabeli bazowej informacje o nazwach tablic"""
		self.itsCur.execute("SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE' order by table_schema,table_name")
		return ["%s.%s"%(row[1],row[2]) for row in self.itsCur.fetchall()]
	def listColumns(self,table):
		"""Pobieramy z tablicy bazowej informacje o kolumnach dla badanej tablicy"""
		table=table.split('.')
		self.itsCur.execute("select * from information_schema.columns where table_schema='%s' and table_name='%s'"%(table[0],table[1]))
		return [ (row[3],row[7]) for row in self.itsCur.fetchall()]
	def query(self,query):
		"""Wykonuje zadane polecenie"""
		self.itsCur.execute(query)
		return self.itsCur.fetchall()
#row[3] name
#row[7] type
if __name__=="__main__":
	baz=Bazowiec()
	baz.connect()
	lista=baz.listDatabases()
	for i in lista:
		print i
