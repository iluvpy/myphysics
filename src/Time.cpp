#include "Time.hpp"


float TimeHandler::getTDiff(Moment end, Moment start) {
    return std::chrono::duration<float, std::micro>(end - start).count();
}

void TimeHandler::endFrame()
{
    m_dT = getTDiff(HRClock::now(), m_startFrameT);
    m_lastdts.push_back(m_dT);
    m_lastdtsIndex++;
    if (m_lastdtsIndex >= 100) {
        m_lastdts.erase(m_lastdts.begin(), m_lastdts.begin() + 20);
        m_lastdtsIndex = 0;
    }
}

void TimeHandler::waitForNextFrame() {
    
    auto now = HRClock::now();
    float tdiff = getTDiff(now, m_startFrameT);
    float timeForEachFrame = 1e6 / m_maxFrames; // how many microseconds per frame;
    if (tdiff >= timeForEachFrame) return; // if frame rate is lower than max frame rate then no sleep is needed
    Util::sleepMicro(timeForEachFrame - tdiff);
}

float TimeHandler::getAverageDT() {
    return std::accumulate(m_lastdts.begin(), m_lastdts.end(), 0) / m_lastdts.size();
}

float TimeHandler::getAverageFrameRate() {
    return 1e6 / getAverageDT();
}
