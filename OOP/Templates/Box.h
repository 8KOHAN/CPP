#pragma once

template <typename T>
class Box {
private:
    T value;

public:
    Box() : value(T()) {} // Конструктор за замовчуванням
    Box(T val) : value(val) {}
    T getValue() const
    {
        return value;
    }
    void setValue(T val)
    {
        value = val;
    }
};