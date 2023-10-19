#include "scheduler.h"

void Scheduler::setTimeout(void (*cb)(void), int timeout)
{
    FunctionState functionState;
    functionState.time = timeout;
    functionState.cb = cb;

    functionStateList.push_back(functionState);
}

void Scheduler::tick(void)
{
    if (functionStateList.empty())
    {
        return;
    }

    for (int i = 0; i < functionStateList.size(); i++)
    {
        if (--functionStateList[i].time <= 0)
        {
            functionStateList[i].cb();

            functionStateList.erase(functionStateList.cbegin() + i);
        }
    }
}
