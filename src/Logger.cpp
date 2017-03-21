/*
 * Logger.cpp
 *
 *  Created on: 18/03/2017
 *      Author: joha
 */

#include "Logger.h"

Logger::Logger() {
	this->level = 2;
}

Logger::Logger(string fileName, int level){
	this->file = fileName;
	this->level = level;
}

Logger::Logger(int level){
	this->level = level;
}

vector<string> Logger::getLogMessages() const
{
    return logMessages;
}
void Logger::setLevel(int level)
{
    this->level = level;
}


int Logger::getLevel() const
{
    return level;
}

void Logger::setLogMessages(vector<string> logMessages)
{
    this->logMessages = logMessages;
}

int Logger::validateFileName(){
	return 0;
}
int Logger::validateLevel(){
	return 0;

}
int Logger::addLogMessage(string logMessage){
	if (validateFileName() == 0){
		ofstream myfile;
		time_t t = time(NULL);
		char *dateTime;
		strftime(dateTime, 100, "%d/%m/%Y %T", localtime(&t));
		myfile.open("file");
		myfile << "["<< this->level<< "] "<<dateTime << logMessage;
		myfile.close();
		return 0;
	}

	return -1;
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}
