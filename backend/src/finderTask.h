#ifndef FINDER_TASK_H
#define FINDER_TASK_H

#include <iostream>
#include <vector>
#include "passService.h"
#include "finderTask.h"

using namespace std;

class finderTask {
    public:
        finderTask();
        ~finderTask();

        vector<passService> findTasks(string dni, int communityCode);
};

#endif
