//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_FILEREADERCREATOR_H
#define MODELVIEWER_FILEREADERCREATOR_H

#include <memory>
#include "FileReader.h"

class FileReaderCreator {
public:
    virtual ~FileReaderCreator() = default;
    virtual std::shared_ptr<FileReader> create(std::string path) = 0;
};

template <typename T>
class FileReaderFactory : public FileReaderCreator
{
public:
    std::shared_ptr<FileReader> create(std::string path) override
    {
        return std::make_shared<T>(path);
    };
};


#endif //MODELVIEWER_FILEREADERCREATOR_H
