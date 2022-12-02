/*****************************************************************//**
 * \file   winAPI_GetCommandLineA.cpp
 * \brief  Using Windows API getCommandLineA()
 * 
 * g++ .\winAPI_GetCommandLineA.cpp
 * ./a.exe
 * 
 * \author Xuhua Huang
 * \date   June 2022
 *********************************************************************/

#include <windows.h>
#include <iostream>

int main(void)
{
    std::cout << GetCommandLineA() << "\n";

    char* const pBuf = GetCommandLineA();
    if (pBuf != nullptr)
    {
        char* pVar = pBuf;

        while (*pVar)
        {
            std::cout << *pVar << "\n";
            pVar += strlen(pVar) + 1;
        }
    }

    FreeEnvironmentStringsA(pBuf);

    /**
     * Printing all environmental variables.
     */
    unsigned long size = GetEnvironmentVariableA("PATH", nullptr, 0);
    if (size == 0) {
        std::cout << "Environment variable does not exist." << "\n";
    }
    else {
        char* val = new char[size];
        if (GetEnvironmentVariableA("PATH", val, size) != 0)
        {
            std::string path{};
            std::string all_env_path{ val };
            size_t pos = 0;
            while ((pos = all_env_path.find(";")) != std::string::npos) {
                path = all_env_path.substr(0, pos);
                std::cout << "Path = " << path << "\n";
                // remove printed path from the long system path variable with delimiter
                // and print the next one
                all_env_path.erase(0, pos + std::string(";").length());
            }
            //std::cout << "Path = " << val << "\n";
        }
        delete[] val;
    }

    return 0;
}
