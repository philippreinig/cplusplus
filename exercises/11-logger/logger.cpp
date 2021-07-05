#define _CRT_SECURE_NO_WARNINGS	// For Windows-Users (ctime gets warnings) - all other can delete or ignore this line
#include <ctime>

#include "logger.hpp"
#include "policy.hpp"
#include "consolepolicy.hpp"

//  GRUPPENEINREICHUNG MIT JANNIS RÖMERMANN und DANNY SCHMIDT

/// \brief Helper function to get a time-string with second resolution.
static std::string getTimeString()
{
	std::string timeStr;
	time_t rawTime;
	time( &rawTime );
	timeStr = ctime( &rawTime );
	return timeStr.substr( 0 , timeStr.size() - 1 );
}

Logger::Logger(){}

Logger* Logger::logger_instance = nullptr;

Logger& Logger::instance(){
	
	if (logger_instance == nullptr) logger_instance = new Logger();
	return *logger_instance;
}

void Logger::registerPolicy(std::unique_ptr<Policy> policy){
	this->policies.push_back(std::move(policy));
	if(this->policies.size() == 1){
		policies[0]->write(this->m_history);
	}
}

void Logger::write(const std::string& file, long line, const std::string& message){
	std::string output = getTimeString() + " [" + file + " : " + std::to_string(line) + "] " + message + "\n";
	if (this->policies.empty()) this->m_history.append(output);
	else{
		for (size_t i = 0; i < policies.size(); ++i){
			policies[i]-> write(output);
		}
	}
}