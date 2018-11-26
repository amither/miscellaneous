#!/usr/bin/python
#coding=utf-8
import zmq
import time
import threading
import Queue
#import queue if python3
port = "5566"
port_send="5577"
ctx = zmq.Context()
socket = ctx.socket(zmq.PULL)
socket.bind("tcp://*:{}".format(port))
socket_send = ctx.socket(zmq.PUSH)
socket_send.bind("tcp://*:{}".format(port_send))
workQueue = Queue.Queue()

def recv(q):
    while True:
      msg = socket.recv()
      print("recv {}".format(msg))
      q.put(msg)

def send(q):
    while True:
      msg = q.get()
      socket_send.send(msg)
      print("send {}".format(msg))


t1 = threading.Thread(target=recv, args=(workQueue, ))
t1.start()
t2 = threading.Thread(target=send, args=(workQueue, ))
t2.start()
