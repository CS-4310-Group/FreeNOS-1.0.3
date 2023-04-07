#include <FreeNOS/User.h>
#include <stdio.h>
#include <ProcessClient.h>
#include <ProcessManager.h>
#include <Kernel.h>
#include <Process.h>
#include <string.h>
#include <stdlib.h>
#include <FreeNOS/Kernel.h>
#include "unistd.h"
#include "errno.h"


unsigned int renicepid(unsigned int pid, unsigned int priority)
{
    if (ProcessCtl(pid, SetPriority, 0, priority))
    {
        errno = EIO;
        return pid;
    }
    printf("Changed the priority to %d\n", priority);
    return 0;
}