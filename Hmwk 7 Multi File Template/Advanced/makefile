all: processEmp.c

processEmp.c: main.o getHours.o getEmpInfo.c printEmp.o
	gcc -o processEmp.c main.o getHours.o getEmpInfo.c printEmp.o 

main.o: main.c
	gcc -c main.c

getHours.o: getHours.c
	gcc -c getHours.c

getEmpInfo.o: getEmpInfo.c
	gcc -c getEmpInfo.c

printEmp.o: printEmp.c
	gcc -c printEmp.c

clean:
	rm -rf *o processEmp.c