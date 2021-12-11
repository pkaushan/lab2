#include "Command.h"


class CommandCreator {
    public:
        
        virtual Command* create() = 0;
};

#endif 
