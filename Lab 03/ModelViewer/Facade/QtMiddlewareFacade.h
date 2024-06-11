//
// Created by Кирилл Воробьев on 04.06.2024.
//

#ifndef MODELVIEWER_QTMIDDLEWAREFACADE_H
#define MODELVIEWER_QTMIDDLEWAREFACADE_H

#include "facade.h"
#include "QTextEdit"

class QtMiddlewareFacade : public Facade {
public:
    QtMiddlewareFacade(QTextEdit *textEdit);
    virtual void execute(std::shared_ptr<BaseCommand> command) override;

private:
    QTextEdit *itemsList;
};


#endif //MODELVIEWER_QTMIDDLEWAREFACADE_H
