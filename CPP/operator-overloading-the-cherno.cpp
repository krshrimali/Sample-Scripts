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

    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
};

std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
    os << vec.x << ", " << vec.y;
    return os;
}

int main() {
    Vector2 distance(3.2f, 4.1f);
    Vector2 speed(1.1f, 1.1f);
    Vector2 powerup(3.3f, 4.4f);

    Vector2 result1 = distance.Add(speed.Multiply(powerup));
    Vector2 result2 = distance + speed * powerup;

    if (result1 == result2) {
        std::cout << "Validated" << '\n';
    } else {
        std::cout << "Something wrong with the operator overloading code" << '\n';
        std::cout << result1 << ", does not match with: " << result2 << '\n';
    }

    std::cout << "Distance + speed * powerup = " << distance + speed * powerup;
    return 0;
}