all: processEmp.c

processEmp.c: main.o getHours.o getGross.o getOvertimeHours.o createReport.o
	gcc -o processEmp.c main.o getHours.o getGross.o getOvertimeHours.o createReport.o

main.o: main.c employees.h
	gcc -c main.c

getHours.o: getHours.c employees.h
	gcc -c getHours.c

getGross.o: getGross.c employees.h 
	gcc -c getGross.c

getOvertimeHours.o: getOvertimeHours.c employees.h
	gcc -c getOvertimeHours.c

createReport.o: createReport.c employees.h
	gcc -c createReport.c

clean:
	rm -rf *o processEmp.c