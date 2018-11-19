#!/usr/bin/python
#coding=utf-8
import zmq
import time
import threading

def consume(id):
    port = "5577"
    ctx = zmq.Context()
    socket = ctx.socket(zmq.PULL)
    socket.connect("tcp://localhost:{}".format(port))
    for i in range(1000):
      msg =  socket.recv()
      print("consume {} recv: {}".format(id, msg))
      time.sleep(3)
for i in range(2):
    t = threading.Thread(target=consume, args=(i,))
    t.start()

