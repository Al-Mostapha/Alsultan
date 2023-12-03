#pragma once 
#include <variant>

template <typename... Args>
using GVar = std::variant<Args...>;