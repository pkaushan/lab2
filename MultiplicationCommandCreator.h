#ifndef LAB_2_MULTIPLICATIONCOMMANDCREATOR_H
#define LAB_2_MULTIPLICATIONCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/MultiplicationCommand.h"

class MultiplicationCommandCreator : public CommandCreator{
    Command* create() override {
        return new MultiplicationCommand();
    }
};

#endif //LAB_2_MULTIPLICATIONCOMMANDCREATOR_H
