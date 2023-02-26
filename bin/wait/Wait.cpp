#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"
#include <sys/wait.h>
#include <sys/types.h>

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Stop executing until giving application finishes");
    parser().registerPositional("PID", "Stop executing until application with given PID finishes");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
    int pid;
    int status;

    // Convert input to pid
    if ((pid = atoi(arguments().get("PID"))) < 0)
    {
        ERROR("invalid pid `" << arguments().get("PID") << "'");
        return InvalidArgument;
    }

    // Wait now
    if (waitpid(pid, &status, 0) == -1)
    {
        ERROR("failed to wait: " << strerror(errno));
        return IOError;
    }

    // Done
    return Success;
}
