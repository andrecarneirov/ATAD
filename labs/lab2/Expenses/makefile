# Standard makefile. Must be modified if using MinGW + Powershell
# If using MinGW (on Windows) + Powershell make the following changes:
# executable = prog.exe 
# rm = del

flags = -Wall -Wextra
executable = prog
rm = rm

default:
	gcc $(flags) -o $(executable) main.c input.c expenses.c
debug:
	gcc $(flags) -o $(executable) -g main.c input.c expenses.c
clean:
	$(rm) -f $(executable)