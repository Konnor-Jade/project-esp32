# This file is executed on every boot (including wake-boot from deepsleep)
#import esp
#esp.osdebug(None)
#import webrepl
#webrepl.start()
from machine import Pin
from time import sleep

p4 = Pin(4, Pin.OUT)
p4.value(0)

if __name__ == '__main__':

    while True:
        p4.value(1)
        sleep(1)
        p4.value(0)
        sleep(1)
        