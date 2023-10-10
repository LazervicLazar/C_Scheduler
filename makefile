# Target that makes the links and makes the executable file for the program "renaming" the ./a.out.
project10_scheduler: job.o project10_scheduler.o
	gcc -o project10_scheduler job.o project10_scheduler.o
# Target that precompiles and updates our main function file.
project10_scheduler.o: project10_scheduler.c job.h
	gcc -c project10_scheduler.c 
# Target that precompiles and updates our modular functions file.
job.o: job.c job.h
	gcc -c job.c
# Bonus target that deletes all the precompiled files.
clear:
	rm *.o
# Bonus target that runs the file.
go:
	./project10_scheduler
	
