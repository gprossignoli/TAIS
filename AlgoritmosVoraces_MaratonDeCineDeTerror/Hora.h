#ifndef Hora_h
#define Hora_h

#include <string>

class hour {
private:

	int hourInMinutes;
	std::string timeStamp;

public:
	hour(std::string const& h) {
		hourInMinutes = std::stoi(h.substr(0,2)) * 60 + std::stoi(h.substr(3,2));
		timeStamp = h;
	}

	int getHourInMinutes() const {
		return hourInMinutes;
	}

	std::string getTimeStamp() const {
		return timeStamp;
	}
};
#endif
