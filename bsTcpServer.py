#!/usr/bin/env python

import socket

def throw(cube_throws):
    total_throws = []

    for cube_throw in range(cube_throws):
        total_throws.append(random.randint(1,6))
        return Counter(total_throws)

TCP_IP = '127.0.0.1'
TCP_PORT = 5005
BUFFER_SIZE = 20  # Normally 1024, but we want fast response

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

conn, addr = s.accept()
print 'Connection address:', addr
while 1:
  data = conn.recv(BUFFER_SIZE)
  if not data: break
  print "received data:", data
  conn.send(data)  # echo
conn.close()
