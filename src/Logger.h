#ifndef LOGGER_H_
#define LOGGER_H_

#include <glog/logging.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Logger {

private:
	string file; //file name where the logger is become to write all messages
	int level;   //TODO(joha): create a level struct with 3 log values: high, medium and low
	vector<string> logMessages; //TODO(joha): create a logMessage class with attributes like timeStamp and message

public:
	Logger();
	Logger(string fileName, int level);
	Logger(int level);
	virtual ~Logger();

    string getFile() const;
    void setFile(string file);

    vector<string> getLogMessages() const;
	void setLogMessages(vector<string> logMessages);

	int getLevel() const;
	void setLevel(int level);

	int validateFileName();
	int validateLevel();
	int addLogMessage(string logMessage);

};

#endif /* LOGGER_H_ */
