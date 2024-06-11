//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_NOTFOUNDITEMSCENE_H
#define MODELVIEWER_NOTFOUNDITEMSCENE_H

#include "BaseException.h"

class NotFoundItemScene : public BaseException
{
public:
    NotFoundItemScene(std::string message = "No found items", const char * file = "", int line = -1) : BaseException(message, file, line)
    {

    }
};

#endif //MODELVIEWER_NOTFOUNDITEMSCENE_H
