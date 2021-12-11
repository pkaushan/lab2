#ifndef LAB_2_DIVISIONCOMMANDCREATOR_H
#define LAB_2_DIVISIONCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/DivisionCommand.h"

class DivisionCommandCreator : public CommandCreator {
    Command* create() override {
        return new DivisionCommand();
    }
};

#endif //LAB_2_DIVISIONCOMMANDCREATOR_H
