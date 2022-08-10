#pragma once
#include "mlCommon.h"

namespace LE{
    class Application{
    private:
        /* data */
    public:
        Application(/* args */);
        virtual ~Application();

        bool Run();
    };
}