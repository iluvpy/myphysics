#include "Time.hpp"

#include "Util.hpp"

float TimeHandler::getTDiff(Moment end, Moment start) {
    return std::chrono::duration<float, std::milli>(end - start).count();
}

void TimeHandler::endFrame()
{
    m_dT = getTDiff(HRClock::now(), m_startFrameT);
}

void TimeHandler::waitForNextFrame() {
    
    auto now = HRClock::now();
    float tdiff = getTDiff(now, m_startFrameT);
    float frameRate = 1.0f / tdiff;
    if (frameRate < m_maxFrames) return; // framerate is below max, so the program doesn't need to sleep
    float timeForEachFrame = 1.0f / m_maxFrames;
    Util::sleep(timeForEachFrame - tdiff);
}

