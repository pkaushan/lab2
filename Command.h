#include <vector>
#include <string>
#include "Context.h"


class Command {
    public:
       
        virtual void execute(std::vector<std::string>, Context &context) = 0;
};


#endif 
