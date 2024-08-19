#include "Keyboard.hpp"

void Keyboard::press(int key) {
    m_keys[key] = true;
    m_wasPressedKeys.push_back(key);
}

void Keyboard::release(int key) {
    m_keys[key] = false;
    m_wasReleasedKeys.push_back(key);
}

bool Keyboard::isKeyPressed(int key) {
    if (m_keys.find(key) != m_keys.end()) return m_keys[key];
    return false;
}

void Keyboard::clear() {
    m_wasPressedKeys.clear();
    m_wasReleasedKeys.clear();
}


bool Keyboard::wasPressed(int key) {
    for (int k : m_wasPressedKeys) {
        if (k == key) return true;
    }
    return false;
}

bool Keyboard::wasReleased(int key) {
    for (int k : m_wasReleasedKeys) {
        if (k == key) return true;
    }
    return false;
}