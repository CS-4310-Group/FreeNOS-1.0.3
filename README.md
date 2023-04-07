Project 3: Prioritize It
Matthew Cheser
Gabriel Khachatryan
Parker Vallier

-----------------------------------------------------------
Video Link:

https://youtu.be/k6vZTCHSsl8/
-----------------------------------------------------------
Features:
	Changing priority levels of processes
	User Input Error Checking
	ML Algorithm Scheduling
	Error Checking for Unsuccessful Priority Changes

-----------------------------------------------------------
Contents of Branches

bin:
	ps:
		Main.cpp
		ProcessList.cpp
		ProcessList.h
		SConscript

	renice:
		Main.cpp
		Renice.cpp
		Renice.h
		SConscript

	sc:
		Main.cpp
		SConscript
		SlowCalc.cpp
		SlowCalc.h
kernel:
	Scheduler.cpp
	Scheduler.h

lib:
	libposix:
		renicepid.cpp
-----------------------------------------------------------
Comments:
Priority level changes make the slow_calcs repeat the result with a different process ID due to the ML Algorithm scheduling.
-----------------------------------------------------------
Contributions: 
	Matthew: Priority levels
	Gabriel: Renice
	Parker: Scheduler
-----------------------------------------------------------