#include <map>

#include "CommandCreator.h"
#include "Exceptions/WrongCommandNameException.h"

class CommandFactory {

    private:
        //Мы разместили конструктор в приватной области, чтобы было невозможно создавать объекты типа CommandFactory.
        //Мы не можем использовать "новое" ключевое слово
        CommandFactory() = default;

        //Создаем \container\ "map" в которой хранятся команды.
        std::map<std::string, CommandCreator*> commands;

    public:
        virtual ~CommandFactory() {
            for (auto item : commands) {
                delete item.second;
            }
        };

        static CommandFactory& getInstance() {
            //Переменная commandFactory типа CommandFactory будет в области статической памяти только после вызова метода
            static CommandFactory commandFactory;
            return commandFactory;
        }

        Command* getCommand(const std::string &name) {
            auto it = commands.find(name);
            if (it == commands.end()) {
                throw WrongCommandNameException("Command not registered yet");
            }
            return  it->second->create();
        }

        void registerCommand(const std::string &name, CommandCreator *creator) {
            //Находим элемент из map-container "container" с ключом "name" 
            auto it = commands.find(name);
            //Если в map-container уже есть элемент с ключом "name"
            if (it != commands.end()) {
                //Если значение элемента, которое мы нашли, является conteiner, который мы передали функции в качестве аргумента, возращаемся
                if (it->second == creator) return;
                else delete it->second;
            }
            commands[name] = creator;
        }
};

#endif 
