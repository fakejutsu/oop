#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <iostream>
#include <fstream>

class FileReader
{
public:
    FileReader(std::string fileName);
    ~FileReader();

    virtual bool readLine(std::string &buffer);

protected:
    std::ifstream file;

};

#endif // FILEREADER_H
