#include "CommandManager.h"
#include "Exceptions.h"

int main()
{
    copy_unsuccessful_exception_class copy_unsuccessful_exception;

    CommandManager manager;
    auto ping = [](const std::deque<std::string> &args) { printf("pong!\n"); };
    manager.add("ping", ping);

    auto count = [](const std::deque<std::string> &args)
    {
         printf("Counted %d args.\n", args.size());
    };
    manager.add("count", count);

    auto times = [x = 0](const std::deque<std::string> &args) mutable
    {
        x++;
        printf("Times was called %d times.\n", x);
    };
    manager.add("times", times);

    auto copy = [copy_unsuccessful_exception](const std::deque<std::string> &args)
    {
        /*if(args.size() < 2)
        {
            printf("Insufficient arguments: %d/2. Usage: copy file1.ext file2.ext.\ncopy", args.size());
            return;
        }
        if(args.size() > 2)
        {
            printf("Too many arguments: %d/2. Usage: copy file1.ext file2.ext.\n", args.size());
            return;
        }*/

        if(args.size() != 2)
        {
            return;
        }

        try
        {
            bool result = std::filesystem::copy_file(args[0], args[1]);
            if(!result)
                throw copy_unsuccessful_exception;

            printf("Copy made succesfully!\n");
        }
        catch(std::exception &ex)
        {
            printf("%s", ex.what());
        }
    };

    manager.add("copy", copy);

    auto alloc = [](const std::deque<std::string> &args)
    {
        try
        {
            int* x = (int*)malloc(std::atoi(args[0].c_str())*sizeof(int));
            if(x == nullptr)
            {
                throw std::bad_alloc();
            }
            x = nullptr;
        }
        catch(std::exception &ex)
        {
            printf(ex.what());
        }
    };

    manager.add("alloc", alloc);
    manager.run();
    printf("Goodbye.\n");

}