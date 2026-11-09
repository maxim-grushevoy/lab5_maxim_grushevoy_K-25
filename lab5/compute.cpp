#include "compute.h"
#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>

using namespace std;

namespace calc
{
    void compute(const string& name, int seconds)
    {
        this_thread::sleep_for(chrono::seconds(seconds));
        osyncstream(cout) << name << endl;
    }
    void slow(const string& name) { compute(name, 7); }
    void quick(const string& name) { compute(name, 1); }
}