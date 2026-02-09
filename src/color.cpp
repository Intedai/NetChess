#include "color.hpp"

std::string colorToString(Color color) {
    switch (color) {
        case Color::black: return "Black";
        case Color::white: return "White";
        default: return ""; 
    }
}