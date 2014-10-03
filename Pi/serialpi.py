
import os
import RPi.GPIO as GPIO
import time
import serial
GPIO.setmode(GPIO.BCM)
#GPIO.setup(17, GPIO.OUT)
#GPIO.setup(27, GPIO.OUT)
#GPIO.setup(27, GPIO.OUT)

ser = serial.Serial('/dev/ttyACM0' , 9600 , parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,  timeout=3)
ser.open()
list = []
time.sleep(5)
ser.write('1')
while(True):

        for x in range (0,4)
                list[x] = ser.readline()



        print(ser.readline())
        time.sleep(0.1)

