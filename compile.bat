@echo off

set SFML_PATH=C:\SFML\

set INPUT_FILE_NAME=Main.cpp Game.cpp Bird.cpp
set OUTPUT_FILE_NAME=game.exe


g++ -c -I"%SFML_PATH%\include" -DSFML_STATIC %INPUT_FILE_NAME%
if not %errorlevel%==0 goto terminate

echo compiled

g++ *.o -o %OUTPUT_FILE_NAME% -L"%SFML_PATH%\lib" -lsfml-graphics -lsfml-window -lsfml-system
if not %errorlevel%==0 goto terminate

echo linked

%OUTPUT_FILE_NAME%		:: Run the build file
exit

:terminate
pause
exit

