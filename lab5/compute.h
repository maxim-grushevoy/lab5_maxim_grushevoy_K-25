#pragma once
#include <string>

namespace calc
{
    void compute(const std::string& name, int seconds); // універсальна
    void slow(const std::string& name);                 // 7 с
    void quick(const std::string& name);                // 1 с
}
void work();