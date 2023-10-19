#ifndef SCHEDULER
#define SCHEDULER
#include <vector>

struct FunctionState
{
    int time;
    void (*cb)(void);
};

class Scheduler
{

public:
    void setTimeout(void (*cb)(void), int timeout);
    void tick(void);

private:
    std::vector<FunctionState> functionStateList;
};

#endif // SCHEDULER