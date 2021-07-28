all: employeePayroll.exe

employeePayroll.exe: main.o printEmp.o processEmp.o utility.o employees.o
	gcc -g -o employeePayroll.exe main.o printEmp.o processEmp.o utility.o employees.o

main.o: main.c employees.h
	gcc -g -c main.c

employees.o: employees.c employees.h
	gcc -g -c employees.c	

printEmp.o: printEmp.c employees.h
	gcc -g -c printEmp.c

processEmp.o: processEmp.c employees.h
	gcc -g -c processEmp.c

utility.o : utility.c employees.h
	gcc -g -c utility.c

clean:
	rm -rf *.o employeePayroll.exe