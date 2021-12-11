#ifndef LAB_2_PUSHCOMMANDCREATOR_H
#define LAB_2_PUSHCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/PushCommand.h"

class PushCommandCreator : public CommandCreator {
public:
    Command* create() override {
        return new PushCommand();
    }
};

#endif //LAB_2_PUSHCOMMANDCREATOR_H
