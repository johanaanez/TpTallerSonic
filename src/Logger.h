#ifndef LOGGER_H_
#define LOGGER_H_

#include <glog/logging.h>
#include <string>
#include <iostream>

using namespace std;

class Logger {

private:
	const char* file; //file name where the logger is become to write all messages
	int level;   //TODO(joha): create a level struct with 3 log values: high, medium and low
	vector<string> logMessages; //TODO(joha): create a logMessage class with attributes like timeStamp and message

public:
	Logger();
	virtual ~Logger();

    vector<string> getLogMessages() const;
    void setFile(string file);

    void setLevel(int level);
    void setLogMessages(vector<string> logMessages);
    const char *getFile() const;
    int getLevel() const;
};

#endif /* LOGGER_H_ */
