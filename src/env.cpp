#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Utils/Env.hpp"

std::vector<std::string> utl::getEnv(const char *const *envp)
{
#ifdef _WIN32
    LPCH envStrings = GetEnvironmentStringsA();
    if (!envStrings)
        return 1;

    for (LPCH var = envStrings; *var; var += strlen(var) + 1)
    {
        std::cout << var << "\n";
    }

    FreeEnvironmentStringsA(envStrings);
#elif __unix__

#endif
}
