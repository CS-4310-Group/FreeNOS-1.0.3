#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ProcessClient.h>
#include <errno.h>
#include "Renice.h"
#include <libposix/unistd.h>


Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Change priority of process");
    parser().registerFlag('n', "new", "New priority level");
    parser().registerPositional("PRIO", "The updated priority of the process");
    parser().registerPositional("PID", "The changing process' ID");
}

Renice::Result Renice::exec()
{
    int pid;
    int priority;

    //Input Checking
    if ((pid = atoi(arguments().get("PID"))) < 0)
    {
        ERROR("invalid pid `" << arguments().get("PID") << "'");
        return InvalidArgument;
    }

    if ((arguments().get("new")))
    {
        int priority = atoi(arguments().get("PRIO"));
        int pid = atoi(arguments().get("PID"));
        if(renicepid(pid, priority)) 
            {
                ERROR("failed to change priority: " << strerror(errno));
                return IOError;
            }
        
    }
    

    return Success;
}