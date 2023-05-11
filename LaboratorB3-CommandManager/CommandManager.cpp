#include "CommandManager.h"

void CommandManager::add(std::string _input, std::function<void(std::deque<std::string>)> _fn)
{
    this->commands[_input] = _fn;
}

void CommandManager::run()
{
    std::string _input;
    while(true)
    {
        std::getline(std::cin, _input);
        if(_input.empty())
        {
            continue;
        }
        std::deque<std::basic_string<char>> inputArgs;
        std::string aux;
        for (int index = 0; index < _input.size(); index++)
        {
            if ((_input[index] != ' ') && (_input[index] != '\0'))
            {
                aux += _input[index];
            }
            else
            {
                if(!aux.empty())
                {
                    inputArgs.emplace_back(aux);
                }
                aux.clear();
            }
        }
        if(!aux.empty())
        {
            inputArgs.emplace_back(aux);
        }
        aux.clear();
        if(inputArgs.at(0).compare("stop") == 0)
        {
            printf("Program stopped.");
            return;
        }
        bool foundCommandInMap = false;
        auto resultCommand = this->commands[inputArgs.at(0)];
        if(resultCommand == nullptr)
        {
            printf("Command was not found!\n");
            continue;
        }
        inputArgs.pop_front();
        try{
            resultCommand(inputArgs);
        }
        catch(std::exception &ex)
        {
            printf(ex.what());
        }
        inputArgs.clear();
        _input.clear();
    }
}