#pragma once

class Entity {
    public:
        virtual void display() const = 0; // Pure virtual function; // Pure virtual function
        virtual ~Entity() {} // Virtual destructor
    };