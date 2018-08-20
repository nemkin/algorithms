@echo off

rem
rem Helper batch file to compile all .c source files in the folder to 
rem an executable bot program
rem 
rem Please modify the output file name to <groupName>.exe
rem 

cc -I. *.c -o StarterBot.exe