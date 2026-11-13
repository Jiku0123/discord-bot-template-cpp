#include <dotenv.h>
#include <dpp/dpp.h>
#include <cstdlib>
#include <iostream>

#include "bot.hpp"

int main(){
    dotenv::init();
    
    const char* token = std::getenv("DISCORD_TOKEN");

    if(token == nullptr || token[0] == '\0'){
        std::cerr << "DISCORD_TOKEN not found" << std::endl;
        return 1;
    }

    std::cout << "Token loaded." << std::endl;

    Bot bot(token);
    bot.run();

    return 0;
}