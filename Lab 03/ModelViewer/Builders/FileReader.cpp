//
// Created by Кирилл Воробьев on 06.06.2024.
//

#include "FileReader.h"

FileReader::FileReader(std::string path) : in(path) {
    if (in.fail())
    {
        throw std::runtime_error("File open error");
    }
}

FileReader::~FileReader()
{
    in.close();
}

std::ifstream & FileReader::getIn() {
    return in;
}
