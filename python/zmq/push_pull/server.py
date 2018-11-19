#!/usr/bin/python
#coding=utf-8
import zmq
import time
port = "5566"
port_send="5577"
ctx = zmq.Context()
socket = ctx.socket(zmq.PULL)
socket.bind("tcp://*:{}".format(port))
socket_send = ctx.socket(zmq.PUSH)
socket_send.bind("tcp://*:{}".format(port_send))
while True:
  msg = socket.recv()
  print(msg)
  socket_send.send(msg)
  time.sleep(1)
