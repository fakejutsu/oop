#include "undocommand.h"
#include "managercreator.h"
#include "HistoryManager.h"

UndoCommand::UndoCommand() {}

void UndoCommand::execute() {
    auto manager = ManagerCreator<HistoryManager>::CreateManager();
    manager->undo();
}
