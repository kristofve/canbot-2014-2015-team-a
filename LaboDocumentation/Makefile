# Makefile voor het CanBot project team A 
# Kevin Vancauwenbergh

All:	CanbotA

CanbotA: Main.o Pad.o Client.o Robot.o Robodriver.o wiringPi.o wiringSerial.o piHiPri.o
	g++ Main.o Pad.o Client.o Robot.o Robodriver.o wiringPi.o wiringSerial.o piHiPri.o -lpthread -o CanbotA
# Variable with the options for all the seperate files
opt = -c -O1

Main.o: Main.cpp
	g++ Main.cpp $(opt)

# Compile the lowlevel files
Pad.o: Pad/Pad.cpp
	g++ Pad/Pad.cpp $(opt)

Client.o: UDP/Client.cpp
	g++ UDP/Client.cpp $(opt)
	
# Compile the wifi files
Robot.o: RoboInterface/Robot.cpp
	g++ RoboInterface/Robot.cpp $(opt)
Robodriver.o: RoboInterface/Robodriver.cpp
	g++ RoboInterface/Robodriver.cpp $(opt)
wiringPi.o: RoboInterface/wiringPi.c
	cc RoboInterface/wiringPi.c $(opt)
wiringSerial.o: RoboInterface/wiringSerial.c
	cc RoboInterface/wiringSerial.c $(opt)
piHiPri.o: RoboInterface/piHiPri.c
	cc RoboInterface/piHiPri.c $(opt)
