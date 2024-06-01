#include "filereader.h"
#include <string>

FileReader::FileReader(std::string fileName) {
    this->file = std::ifstream(fileName);
}

bool FileReader::readLine(std::string &buffer)
{
    return bool(getline(this->file, buffer));
}

FileReader::~FileReader()
{
    this->file.close();
}
