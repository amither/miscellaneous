#!/usr/bin/python
#coding=utf-8
import zmq
import time
port = "5566"
ctx = zmq.Context()
socket = ctx.socket(zmq.PAIR)
socket.connect("tcp://localhost:{}".format(port))
while True:
  msg = socket.recv()
  print(msg)
  socket.send("client message")
  time.sleep(1)
