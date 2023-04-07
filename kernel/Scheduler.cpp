/*
 * Copyright (C) 2015 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Log.h>
#include "Kernel.h"
#include "Scheduler.h"

Scheduler::Scheduler()
{

    prioQueues[0] = m_q_1;
    prioQueues[1] = m_q_2;
    prioQueues[2] = m_q_3;
    prioQueues[3] = m_q_4;
    prioQueues[4] = m_q_5;

    DEBUG("");
}

Size Scheduler::count() const
{
    return prioQueues[0].count()
         + prioQueues[1].count()
         + prioQueues[2].count()
         + prioQueues[3].count()
         + prioQueues[4].count();
}

Scheduler::Result Scheduler::enqueue(Process *proc, bool ignoreState)
{
    if (proc->getState() != Process::Ready && !ignoreState)
    {
        ERROR("process ID " << proc->getID() << " not in Ready state");
        return InvalidArgument;
    }

    int priority = proc->getPriority();
    if(priority < 1 || priority > 5) {
        ERROR("invalid priority");
        return InvalidArgument;
    }

    prioQueues[priority-1].push(proc);
    return Success;
}

Scheduler::Result Scheduler::dequeue(Process *proc, bool ignoreState)
{
    if (proc->getState() == Process::Ready && !ignoreState)
    {
        ERROR("process ID " << proc->getID() << " is in Ready state");
        return InvalidArgument;
    }


    Size count;

    for (int prio_i = 4; prio_i >= 0; prio_i--){
        count = prioQueues[prio_i].count();

        for(Size i = 0; i < count; i++){
            Process *p = prioQueues[prio_i].pop();

            if (p == proc)
                return Success;
            else{
                if(prio_i > 0)
                    prioQueues[prio_i-1].push(p);
                else
                    prioQueues[0].push(p);
            }
                
        }
    }


   
    FATAL("process ID " << proc->getID() << " is not in the schedule");
    return InvalidArgument;
}

Process * Scheduler::select()
{
    Process *p;


    if(prioQueues[4].count() > 0) {
        p = prioQueues[4].pop();
        prioQueues[4].push(p);
        return p;
    }else if(prioQueues[3].count() > 0) {
        p = prioQueues[3].pop();
        prioQueues[3].push(p);
        return p;
    }else if(prioQueues[2].count() > 0) {
        p = prioQueues[2].pop();
        prioQueues[2].push(p);
        return p;
    }else if(prioQueues[1].count() > 0) {
        p = prioQueues[1].pop();
        prioQueues[1].push(p);
        return p;
    }else if(prioQueues[0].count() > 0) {
        p = prioQueues[0].pop();
        prioQueues[0].push(p);
        return p;
    }


    return (Process *) NULL;
}
