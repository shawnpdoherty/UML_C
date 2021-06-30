all: processEmp.c

processEmp.c: main.o getHours.o getOvertimeHours.o getGrossPay.c getEmpInfo.c printEmp.o
	gcc -o processEmp.c main.o getHours.o getOvertimeHours.o getGrossPay.c getEmpInfo.c printEmp.o 

main.o: main.c
	gcc -c main.c

getHours.o: getHours.c
	gcc -c getHours.c

getEmpInfo.o: getEmpInfo.c
	gcc -c getEmpInfo.c

getOvertimeHours.o: getOvertimeHours.c
	gcc -c getOvertimeHours.c

getGrossPay.o: getGrossPay.c
	gcc -c getGrossPay.c

printEmp.o: printEmp.c
	gcc -c printEmp.c

clean:
	rm -rf *o processEmp.c