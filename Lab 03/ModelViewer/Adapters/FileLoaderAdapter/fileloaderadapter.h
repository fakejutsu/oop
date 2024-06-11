#ifndef FILELOADERADAPTER_H
#define FILELOADERADAPTER_H

#include <string>

class FileLoaderAdapter
{
public:
    FileLoaderAdapter();

    virtual std::string getSelectedFileName() = 0;
};

#endif // FILELOADERADAPTER_H
