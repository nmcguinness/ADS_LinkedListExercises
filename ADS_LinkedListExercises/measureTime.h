#pragma once

/// @brief A template function to measure the time, in nanoseconds, that a function takes to execute
/// @tparam FuncType A struct or class which implements the function call operator (i.e. is a functor)
/// @param func A functor which calls the target method in the operator()(){} code
/// @return Time in nanoseconds for the function called by the functor to execute
template <typename FuncType>
double measureTime(FuncType func)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> st = std::chrono::high_resolution_clock::now();
	func();
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	return (end - st) / std::chrono::nanoseconds(1);
}
