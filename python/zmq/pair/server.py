#!/usr/bin/python
#coding=utf-8
import zmq
import time
port = "5566"
ctx = zmq.Context()
socket = ctx.socket(zmq.PAIR)
socket.bind("tcp://*:{}".format(port))
while True:
  socket.send("server message")
  msg = socket.recv()
  print(msg)
  time.sleep(1)
