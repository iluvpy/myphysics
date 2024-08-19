#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class Keyboard {
private:
    std::map<char, bool> m_keys;
    std::vector<int> m_wasPressedKeys;
    std::vector<int> m_wasReleasedKeys;
public:

    void press(int key);
    void release(int key);
    bool isKeyPressed(int key);
    void clear();
    bool wasPressed(int key);
    bool wasReleased(int key);
};