import serial
 
ser = serial.Serial()
ser.baudrate = 115200
ser.port = 'COM6'
ser.port = '/dev/tty6' # there isn't a capital S after all
# COM 3,4, and 6 are the options
# Make Packet Headeer
#Send Packet header
ser.open()
 
values = bytearray([4, 9, 62, 144, 56, 30, 147, 3, 210, 89, 111, 78, 184, 151, 17, 129])
cur = ser.read()
print()
ser.write(values)
ser.close()