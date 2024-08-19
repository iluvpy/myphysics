#include "Util.hpp"

void Util::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void Util::sleepMicro(int mcs){
    std::this_thread::sleep_for(std::chrono::microseconds(mcs));
}

