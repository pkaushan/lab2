#ifndef LAB_2_COMMANDCREATOR_H
#define LAB_2_COMMANDCREATOR_H

#include "Command.h"

class CommandCreator {
    public:        
        virtual Command* create() = 0;
};

#endif //LAB_2_COMMANDCREATOR_H
