//
// Created by Кирилл Воробьев on 10.06.2024.
//

#ifndef MODELVIEWER_GROUPMODELCOMMAND_H
#define MODELVIEWER_GROUPMODELCOMMAND_H

#include "basecommand.h"
#include <memory>

class GroupModelCommand : public BaseCommand {
public:
    GroupModelCommand(std::shared_ptr<std::vector<int>> v);
    virtual void execute() override;


protected:
    std::shared_ptr<std::vector<int>> v;

};


#endif //MODELVIEWER_GROUPMODELCOMMAND_H
