#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Mensaje.h"

using namespace std;

class Logger {

private:
	string archivo; //file name where the logger is become to write all messages
	int nivel;   //TODO(joha): create a level struct with 3 log values: high, medium and low
	vector<string> logMessages;

public:
	Logger();
	Logger(string fileName, int level);
	Logger(int level);
	virtual ~Logger();

    string getFile() const;
    void setFile(string file);


	int getLevel() const;
	void setLevel(int level);

	int validateFileName();
	int validateLevel();
	int addLogMessage(string logMessage);

};

#endif /* LOGGER_H_ */
