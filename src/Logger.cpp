/*
 * Logger.cpp
 *
 *  Created on: 18/03/2017
 *      Author: joha
 */

#include "Logger.h"

Logger::Logger() {
	 google::InitGoogleLogging(file);
	 LOG(INFO) << "Found ";
}


vector<string> Logger::getLogMessages() const
{
    return logMessages;
}
void Logger::setLevel(int level)
{
    this->level = level;
}

const char *Logger::getFile() const
{
    return file;
}

int Logger::getLevel() const
{
    return level;
}

void Logger::setLogMessages(vector<string> logMessages)
{
    this->logMessages = logMessages;
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}
