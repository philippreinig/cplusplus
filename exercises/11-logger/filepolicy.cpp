#include "filepolicy.hpp"

FilePolicy::FilePolicy(const std::string& filename){
    this->outputfilestream.open(filename);
}

FilePolicy::~FilePolicy(){
    this->outputfilestream.close();
}

void FilePolicy::write(const::std::string& message){
    this->outputfilestream << message << std::flush;
}

