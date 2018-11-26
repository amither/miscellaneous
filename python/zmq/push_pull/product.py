#!/usr/bin/python
#coding=utf-8
import zmq
import time
import threading

def product(id):
    port = "5566"
    ctx = zmq.Context()
    socket = ctx.socket(zmq.PUSH)
    socket.connect("tcp://localhost:{}".format(port))
    for i in range(1000):
      msg = "product{} message {}".format(id, i)
      socket.send(msg)
      print(msg)
      


for i in range(2):
    t = threading.Thread(target=product, args=(i, ))
    t.start()

