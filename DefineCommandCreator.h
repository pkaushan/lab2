#ifndef LAB_2_DEFINECOMMANDCREATOR_H
#define LAB_2_DEFINECOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/DefineCommand.h"

class DefineCommandCreator : public CommandCreator{
    Command* create() override {
        return new DefineCommand();
    }
};

#endif //LAB_2_DEFINECOMMANDCREATOR_H
