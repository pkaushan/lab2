#include "StackCalculator.h"

#include <vector>

#include "Command.h"
#include "CommandFactory.h"
#include "Parser.h"

void check_definitions(std::vector<std::string> &arg_vector, Context &context) {
    for (auto &i : arg_vector) {
        auto it = context.findMapValueByKey(i);
        if (it != context.getEndIterator()) i = it->second;
    }
}

StackCalculator::StackCalculator(std::istream &istream, std::ostream &ostream)
    : input_stream(istream), output_stream(ostream){
}

void StackCalculator::calculate() {
    std::string command_line;

    Context context(output_stream);

    Parser parser;
    while (getline(input_stream, command_line)) {
        parser.parseLine(command_line);

        try {
            //мы добавили auto_ptr, чтобы при выходе из блока try catch или при возникновении исключения мы были уверены
            //что дистрактор объекта Command будет вызываться
            std::auto_ptr<Command> command(CommandFactory::getInstance().getCommand(parser.getCommandName()));
            std::vector<std::string> arguments = parser.getArguments();
            check_definitions(arguments, context);
            command->execute(arguments, context);
        } catch (std::exception &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
}
