# Makefile voor het CanBot project team A 
# Kevin Vancauwenbergh

All:	CanbotA

CanbotA: Main.o Pad.o Client.o RoboInterface.o Robo.o wiringPi.o wiringSerial.o piHiPri.o
	g++ Main.o Pad.o Client.o RoboInterface.o Robo.o wiringPi.o wiringSerial.o piHiPri.o -lpthread -o CanbotA
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
RoboInterface.o: RoboInterface/RoboInterface.cpp
	g++ RoboInterface/RoboInterface.cpp $(opt)
Robo.o: RoboInterface/Robo.cpp
	g++ -c RoboInterface/Robo.cpp

