// Reference: Episode 6, Jason Turner, CPP-Weekly
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

//template <typename T>
//std::string print_multiple_args_impl(const T& val) {
//    std::stringstream ss;
//    ss << val << "";
//    return ss.str();
//}

std::vector<std::string> print_multiple_args() {
    return {};
}

template <typename SingleParam, typename ... VariadicParam>
std::vector<std::string> print_multiple_args(const SingleParam& sP, const VariadicParam& ... mP) {
    std::vector<std::string> whole_string;
    whole_string.push_back(print_multiple_args_impl(sP));

    const auto remainder = print_multiple_args(mP...);
    whole_string.insert(whole_string.end(), remainder.begin(), remainder.end());

    return whole_string;
}

template <typename ... VariadicParam>
std::vector<std::string> fast_print_multiple_args(const VariadicParam& ... mP) {
    const auto print_multiple_args_impl = [](const auto &p) {
        std::stringstream ss;
        ss << p;
        return ss.str();
    };
    return {print_multiple_args_impl(mP)...};
}

int main() {
    const auto vec_output = fast_print_multiple_args("Hi", ", ", "Whats", " Up!", " ", 3.3f);
    for (const auto& it: vec_output) {
        std::cout << it;
    }
    std::cout << '\n';
    return 0;
}
