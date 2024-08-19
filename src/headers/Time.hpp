#pragma once

#include <chrono>

using HRClock = std::chrono::high_resolution_clock;
using Moment = std::chrono::_V2::system_clock::time_point;

class TimeHandler {
private:
    int m_maxFrames;
    Moment m_startFrameT;
    float m_dT;

    static float getTDiff(Moment end, Moment start);

public:
    TimeHandler(int maxFrames) {
        m_maxFrames = maxFrames;
        Moment clock_ = HRClock::now();

    }
    inline void startFrame() { m_startFrameT = HRClock::now(); }
    void endFrame();
    void waitForNextFrame();
    inline float getFrameRate() {return 1000.0f / m_dT;}
    inline float getDeltaT() { return m_dT; }

};