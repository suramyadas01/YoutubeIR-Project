# Before starting to code, it is recommended that you look up the documentation related to the pynput library. It is easy to use and 
# simple to understand.

#

import os
import subprocess
import webbrowser
import serial
from pynput.mouse import Controller, Button
mouse = Controller()
#The Controller() lets us create a mouse object that we can later use to emulate the mouse.
#You may want to include the keyboard functions too but the problem is both the objects will call Controller() and cause an error.
#I believe there are ways around it but I didn't want the keyboard anyway so I did not think about it much.

ser = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout = 1)
# Here, the '/dev/ttyACM0' will not be same for you. Replace with wha0tever your serial port is.
# NOTE: You may have to edit this part if you disconnect your arduino from the computer. Check the serial port via the 
#	arduino IDE.

while True:	
	data = ser.readline().decode('ascii')
	print(data)
	#Just reading if any new data is available on the serial line.
	#Now we can just use an if-else ladder for various functions. 
	
	#MOVING THE MOUSE CURSOR
	if data == 'UP\r\n':
		mouse.move(0, -20)
		print("UP")
	elif data == 'UP_LEFT\r\n':
		mouse.move(-20, -20)
	elif data == 'UP_RIGHT\r\n':
		mouse.move(20, -20)
	elif data == 'DOWN\r\n':
		mouse.move(0, 20)
	elif data == 'DOWN_LEFT\r\n':
		mouse.move(-20,20)
	elif data ==  'DOWN_RIGHT\r\n':
		mouse.move(20,20)
	elif data == 'LEFT\r\n':
		mouse.move(-20, 0)
	elif data == 'RIGHT\r\n':
		mouse.move(20, 0)
	
	#EMULATING MOUSE BUTTON FUNCTIONS
	elif data == 'OK\r\n':
		mouse.press(Button.left)
		mouse.release(Button.left)
	elif data == 'BL\r\n':
		mouse.click(Button.left, 2)
	elif data == 'BR\r\n':
		mouse.click(Button.right)
	elif data == 'SC_DOWN\r\n':
		mouse.scroll(0, -3)
	elif data == 'SC_UP\r\n':
		mouse.scroll(0, 3)	
		
		
	#Lastly, we use the dedicated buttons to open Youtube and Netflix directly via a button on the remote. 
	#Surely, you can change the URLs and modify the entire thing.  
	elif data == 'YOUTUBE\r\n':
		webbrowser.open('http://www.youtube.com')
	elif data == 'NETFLIX\r\n': 
		webbrowser.open('http://www.netflix.com')
	
