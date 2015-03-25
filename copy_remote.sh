#!/bin/sh

#scp -r pi@192.168.1.11:~/CanbotTeamA/* ~/Documents/raspberry/canbot

LOC_DIR="~/Documents/raspberry"
REM_DIR="~/CanbotTeamA/robo2015"
rsync -avr -e ssh --include "*.cpp$" --include "*.h$" --include "Makefile$" --exclude "*.o" --exclude "*.swp" . pi@192.168.1.11:~/CanbotTeamA/robo2015
