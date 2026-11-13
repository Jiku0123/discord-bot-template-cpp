#include "bot.hpp"

#include <iostream>

Bot::Bot(const std::string& token) : bot(token){
    
}

void Bot::run(){
    bot.on_ready([](const dpp::ready_t& event){
        std::cout << "Discord connected successfully!" << std::endl;
    });
    std::cout << "Starting Discord bot..." << std::endl;
    bot.on_log(dpp::utility::cout_logger());
    bot.start(dpp::st_wait);
}