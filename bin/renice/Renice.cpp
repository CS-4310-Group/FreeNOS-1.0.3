#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Renice.h"

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

    //Input Checking
    if ((pid = atoi(arguments().get("PID"))) < 0)
    {
        ERROR("invalid pid `" << arguments().get("PID") << "'");
        return InvalidArgument;
    }


    

    



    return Success;
}