#include "compute.h"
#include <chrono>
#include <format>
#include <future>
#include <iostream>
#include <syncstream>

using namespace std;
using namespace calc;

void work()
{
    auto start = chrono::steady_clock::now();

    auto slowA3 = async(launch::async, [] { slow("A3"); });

    auto fastTail = async(launch::async, []
        {
            quick("A2");
            quick("B2");
            quick("A4");
        });

    slow("A1");
    
    fastTail.get();

    quick("B1");
    quick("C");

    slowA3.get();

    chrono::duration<double> elapsed = chrono::steady_clock::now() - start;
    osyncstream(cout) << format("Time: {:.1f} s", elapsed.count()) << endl;
    osyncstream(cout) << "Work is done!" << endl;
}