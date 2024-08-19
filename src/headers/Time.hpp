#pragma once

#include <chrono>
#include <vector>
#include <numeric>
#include <iostream>

#include "Util.hpp"

using HRClock = std::chrono::high_resolution_clock;
using Moment = std::chrono::_V2::system_clock::time_point;

class TimeHandler {
private:
    int m_maxFrames;
    Moment m_startFrameT;
    double m_dT;
    std::vector<float> m_lastdts;
    int m_lastdtsIndex = 0;
    static float getTDiff(Moment end, Moment start);

public:
    TimeHandler(int maxFrames) {
        m_maxFrames = maxFrames;
        Moment clock_ = HRClock::now();

    }
    inline void startFrame() { m_startFrameT = HRClock::now(); }
    void endFrame();
    void waitForNextFrame();
    inline float getFrameRate() {return 1000.0 / m_dT;}
    inline float getDeltaT() { return m_dT; }
    float getAverageFrameRate();
    float getAverageDT();

};