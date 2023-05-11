#pragma once
#include <map>
#include <string>
#include <functional>
#include <deque>
#include <cstdio>
#include <iostream>
#include <filesystem>


class CommandManager {
private:
    std::map<std::string, std::function<void(std::deque<std::string>)>> commands;
public:

    void add(std::string _input, std::function<void(std::deque<std::string>)> _fn);
    void run();
};