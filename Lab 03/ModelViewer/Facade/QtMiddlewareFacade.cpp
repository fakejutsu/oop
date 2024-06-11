//
// Created by Кирилл Воробьев on 04.06.2024.
//

#include "QtMiddlewareFacade.h"

#include <utility>
#include "SceneTextListCommand.h"
#include "redrawscenecommand.h"
#include "QMessageBox"
#include "BaseException.h"

void QtMiddlewareFacade::execute(std::shared_ptr<BaseCommand> command) {
    try {
        Facade::execute(std::move(command));

        std::string newItems;
        auto refreshCommand = std::make_shared<SceneTextListCommand>(newItems);
        Facade::execute(refreshCommand);

        itemsList->setText(newItems.c_str());

        auto redraw = std::make_shared<RedrawSceneCommand>();
        Facade::execute(redraw);
    }
    catch (BaseException & ex)
    {
        QMessageBox::critical(nullptr, "Не удалось выполнить операцию", QString(ex.errorMessage().c_str()));
    }
    catch (std::exception ex){
        QMessageBox::critical(nullptr, "Не удалось выполнить операцию", ex.what());
    }
}

QtMiddlewareFacade::QtMiddlewareFacade(QTextEdit *textEdit) {
    this->itemsList = textEdit;
}
