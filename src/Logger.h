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
	char* archivo; //file name where the logger is become to write all messages
	int nivel;   //TODO(joha): create a level struct with 3 log values: high, medium and low
	vector<string> logMessages;

public:
	Logger();
	Logger(char *fileName, int level);
	Logger(int level);
	virtual ~Logger();

	int getLevel() const;
	void setLevel(int level);

	int validateFileName();
	int validateLevel();
	int addLogMessage(string logMessage);
    char *getArchivo() const;
    void setArchivo(char *archivo);

};

#endif /* LOGGER_H_ */
