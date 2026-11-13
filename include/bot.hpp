#pragma once

#include <dpp/dpp.h>
#include <string>

class Bot{
public:
    explicit Bot(const std::string& token);

    void run();
private:
    dpp::cluster bot;
    
};