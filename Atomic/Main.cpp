#include <iostream>
#include "Atomic/Exceptions.h"
#include "Atomic/Config/Parser.h"
#include "Atomic/API/Rolimons.h"
#include "Atomic/API/Wrapper.h"
#include "Atomic/Config/Parser.h"
#include "Atomic/Conversion.h"
#include "Atomic/User.h"
#include "Atomic/Functions.h"

int main()
{
#ifndef VS_DEBUG
    try {
#endif
        
#ifndef VS_DEBUG
    }
    catch (...) {
        std::cerr << "Unhandled exception occured, ignoring...\n";
    }
#endif
    return EXIT_SUCCESS;
}