// Reference: https://youtu.be/mS9755gF66w
#include <iostream>

struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x) , y(y) {};

    Vector2() : x(0.0f), y(0.0f) {};

    Vector2 Add(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Multiply(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator+(const Vector2& other) const {
        return Add(other);
    }

    Vector2 operator*(const Vector2& other) const {
        return Multiply(other);
    }
};

std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
    os << vec.x << ", " << vec.y;
    return os;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    Vector2 distance(3.2f, 4.1f);
    Vector2 speed(1.1f, 1.1f);
    Vector2 powerup(3.3f, 4.4f);

    std::cout << distance + speed * powerup;
    return 0;
}
