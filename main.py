#!/usr/bin/env python3
from serial import Serial

'''
Run this in shell first:
$ stty -F /dev/ttyUSB0 cs8 9600 ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts
'''

s = Serial('/dev/ttyUSB0', 9600)
for i in range(180):
    s.write(bytes([i]))
    s.flush()
    print(s.readline().rstrip())
s.close()
