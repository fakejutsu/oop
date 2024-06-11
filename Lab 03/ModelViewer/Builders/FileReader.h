//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_FILEREADER_H
#define MODELVIEWER_FILEREADER_H

#include <string>
#include <iostream>
#include <fstream>

class FileReader {
public:
    FileReader(std::string path);
    ~FileReader();
    virtual std::ifstream & getIn();

protected:
    std::ifstream in;
};


#endif //MODELVIEWER_FILEREADER_H
