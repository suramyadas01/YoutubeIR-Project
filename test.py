import os
import subprocess
import webbrowser
import serial
from pynput.mouse import Controller, Button
mouse = Controller()
ser = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout = 1)

while True:	
	data = ser.readline().decode('ascii')
	print(data)
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
	elif data == 'YOUTUBE\r\n':
		webbrowser.open('http://www.youtube.com')
	elif data == 'NETFLIX\r\n': 
		webbrowser.open('http://www.netflix.com')
	elif data == 'SPOTIFY':
		open('/home/aymar01/Videos')
