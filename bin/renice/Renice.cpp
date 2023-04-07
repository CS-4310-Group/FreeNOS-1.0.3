

#include "Renice.h"

Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Output system process list");
    parser().registerFlag('l', "list", "List of priority levels");
}

ProcessList::Result ProcessList::exec()
{
    const ProcessClient process;
    String out;

    if(arguments().get("list")){
        out << "ID  PARENT  PRIORITY  USER GROUP STATUS     CMD\r\n";

        // Loop processes
        for (ProcessID pid = 0; pid < ProcessClient::MaximumProcesses; pid++)
        {
            ProcessClient::Info info;

            const ProcessClient::Result result = process.processInfo(pid, info);
            if (result == ProcessClient::Success)
            {
                DEBUG("PID " << pid << " state = " << *info.textState);

                // Output a line
                char line[128];
                snprintf(line, sizeof(line),
                        "%3d %7d %9d %4d %5d %10s %32s\r\n",
                        pid, info.kernelState.parent, info.kernelState.priority,
                        0, 0, *info.textState, *info.command);
                out << line;
            }
        }
    }
    else{
        // Print header
        out << "ID  PARENT  USER GROUP STATUS     CMD\r\n";

        // Loop processes
        for (ProcessID pid = 0; pid < ProcessClient::MaximumProcesses; pid++)
        {
            ProcessClient::Info info;

            const ProcessClient::Result result = process.processInfo(pid, info);
            if (result == ProcessClient::Success)
            {
                DEBUG("PID " << pid << " state = " << *info.textState);

                // Output a line
                char line[128];
                snprintf(line, sizeof(line),
                        "%3d %7d %4d %5d %10s %32s\r\n",
                        pid, info.kernelState.parent,
                        0, 0, *info.textState, *info.command);
                out << line;
            }
        }

    }


    // Output the table
    write(1, *out, out.length());
    return Success;
}