# Project 3: Prioritize It <br />
Matthew Cheser<br />
Gabriel Khachatryan<br />
Parker Vallier<br />
<br />
-----------------------------------------------------------<br />
Video Link:<br />
<br />
https://youtu.be/k6vZTCHSsl8/<br />
-----------------------------------------------------------<br />
Features:<br />
	Changing priority levels of processes<br />
	User Input Error Checking<br />
	ML Algorithm Scheduling<br />
	Error Checking for Unsuccessful Priority Changes<br />
<br />
-----------------------------------------------------------<br />
Contents of Branches<br />
<br />
bin:<br />
	ps:<br />
		Main.cpp<br />
		ProcessList.cpp<br />
		ProcessList.h<br />
		SConscript<br />
<br />
	renice:<br />
		Main.cpp<br />
		Renice.cpp<br />
		Renice.h<br />
		SConscript<br />
<br />
	sc:<br />
		Main.cpp<br />
		SConscript<br />
		SlowCalc.cpp<br />
		SlowCalc.h<br />
kernel:<br />
	Scheduler.cpp<br />
	Scheduler.h<br />
<br />
lib:<br />
	libposix:<br />
		renicepid.cpp<br />
-----------------------------------------------------------<br />
Comments:<br />
Priority level changes make the slow_calcs repeat the result with a different process ID due to the ML Algorithm scheduling.<br />
-----------------------------------------------------------<br />
Contributions: <br />
	Matthew: Priority levels<br />
	Gabriel: Renice<br />
	Parker: Scheduler<br />
-----------------------------------------------------------<br />
