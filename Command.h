#ifndef LAB_2_COMMAND_H
#define LAB_2_COMMAND_H

#include <vector>
#include <string>
#include "Context.h"

//Interface
//Мы не можем создать обьект типа Command
//Класс Command не имеет свойств
//У методов класса Command нет определенных методов тел.
class Command {
    public:
        //виртуальная функиця
        //Каждый дочерний класс ДОЛЖЕН иметь собственную версию метода execute (), потому что = 0 означает, что виртуальный метод
        //execute () не имеет тела в классе Command
        virtual void execute(std::vector<std::string>, Context &context) = 0;
};


#endif //LAB_2_COMMAND_H
