#pragma once
#include <string>

class Song {
public:
	std::string title;
	Song() {};
	Song(std::string title) : title(title) {};
	~Song() {};

	friend std::ostream& operator<<(std::ostream& os, const Song& song) {
		os << song.title;
		return os;
	}
};