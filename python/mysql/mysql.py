#!/usr/bin/python
# -*- coding: UTF-8 -*-
import MySQLdb
import json
class MysqlHandler():
  def __init__(self, conf):
    self.conf =conf
    self.db = (MySQLdb.connect(host=conf['host'], port=conf['port'], 
              user=conf['user'], passwd=conf['passwd'], db=conf['db']))
  def reconn(self):
    try:
      self.db.ping()
    except:
      print("db conn lost, reconnect");
      self.db = (MySQLdb.connect(host=self.conf['host'], port=self.conf['port'], 
                user=self.conf['user'], passwd=self.conf['passwd'], db=self.conf['db']))

  def update(self, sql):
    self.reconn()
    cursor = self.db.cursor(cursorclass=MySQLdb.cursors.DictCursor)
    self.db.begin()
    n = cursor.execute(sql)
    print("execute sql[{0}] affect row {1}".format(sql, n))
    if n != 1:
      raise Exception("execute sql[{0}] affect row {1}".format(sql, n))
    self.db.commit()

  def query(self, sql):
    self.reconn()
    cursor = self.db.cursor(cursorclass=MySQLdb.cursors.DictCursor)
    self.db.begin()
    n = cursor.execute(sql)
    self.db.commit()
    return cursor
    
configFile = open('conf.json', 'r')
conf = json.load(configFile)
configFile.close()

h = MysqlHandler(conf['mysql'])
h.reconn()
c = h.query('select * from skg_db.t_user')
r = c.fetchall()
for m in r:
  print m

h.update("update skg_db.t_user set lstate=2 where user_id='user5'");
