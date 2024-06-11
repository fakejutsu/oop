#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addmodelcommand.h"
#include "drawmanager.h"
#include "rotatecameracommand.h"
#include "QtSceneAdapter.h"
#include "movemodelcommand.h"
#include "rotatemodelcommand.h"
#include "scalemodelcommand.h"
#include "SceneTextListCommand.h"
#include "QString"
#include "Facade/QtMiddlewareFacade.h"
#include "AddCameraCommand.h"
#include "SetNewMainCameraCommand.h"
#include "deletecameracommand.h"
#include "DeleteObjectCommand.h"
#include "SceneAdapterFactory.h"
#include "clearscenecommand.h"
#include "QMessageBox"
#include "QFileDialog"
#include "CarcassCreatorSolution.h"
#include "CarcassEdgesModelDirector.h"
#include "TextEdgesModelSource.h"
#include "DependencyManager.h"
#include "CarcassDotEdgesModelDirector.h"
#include "TextDotEdgesModelSource.h"
#include "undocommand.h"
#include "GroupModelCommand.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    facade = std::make_shared<QtMiddlewareFacade>(ui->sceneList);

    std::shared_ptr<SceneAdapterCreator> sceneCreator = std::make_shared<SceneAdapterFactory<QtSceneAdapter>>();
    sceneAdapter = sceneCreator->createDrawScene();

    scene = std::dynamic_pointer_cast<QtSceneAdapter>(sceneAdapter)->getInner();

    ui->graphicsView->setScene(scene.get());
    ui->graphicsView->setSceneRect(0, 0, 2000, 2000);

    auto carcassCreatorSolution = CarcassCreatorSolution::makeSolution(
            {{"txt", CreateCarcassCreator::createCarcassCreator<CarcassEdgesModelDirector>},
             {"dot", CreateCarcassCreator::createCarcassCreator<CarcassDotEdgesModelDirector>}}
            );

    auto dependency = ManagerCreator<DependencyManager>::CreateManager();
    dependency->setCarcassDirectorSolution(carcassCreatorSolution);

   // std::unique_ptr<AbsCarcassModelSource>(&)(std::string path)

    auto drawer = ManagerCreator<DrawManager>::CreateManager();
    drawer->setScene(sceneAdapter);
}

double MainWindow::readDoubleFromField(QLineEdit *field)
{
    bool isOk = false;
    double res = field->text().toDouble(&isOk);
    if (!isOk)
    {
        throw std::runtime_error("Не удалось считать значение из поля");
    }

    return res;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);

    dialog.exec();
    auto list = dialog.selectedFiles();
    if (list.size() > 0)
    {
        std::string path = list[0].toStdString();
        auto command = std::make_shared<AddModelCommand>(path);
        facade->execute(command);

        std::string newDescr = "";
        auto command2 = std::make_shared<SceneTextListCommand>(newDescr);

        facade->execute(command2);
        ui->sceneList->setText(QString(newDescr.c_str()));
    }



}


void MainWindow::on_pushButton_4_clicked()
{
    auto command = std::make_shared<RotateCameraCommand>(2, 0, 0);
    facade->execute(command);
}


void MainWindow::on_pushButton_5_clicked()
{
    auto command = std::make_shared<RotateCameraCommand>(0, 2, 0);
    facade->execute(command);
}


void MainWindow::on_pushButton_6_clicked()
{
    auto command = std::make_shared<RotateCameraCommand>(0, 0, 2);
    facade->execute(command);
}


void MainWindow::on_pushButton_2_clicked()
{
    transformApplyClicked();
}

void MainWindow::transformApplyClicked()
{
    int id;

    double dx, dy, dz;
    double sx, sy, sz;
    double ox, oy, oz;

    if (getObjId(id) &&  getTransformParams(dx, dy, dz) && getRotateParams(ox, oy, oz) && getScaleParams(sx, sy, sz))
    {

        auto moveCommand = std::make_shared<MoveModelCommand>(id, dx, dy, dz);

        facade->execute(moveCommand);


        auto scaleCommand = std::make_shared<ScaleModelCommand>(id, sx, sy, sz);

        facade->execute(scaleCommand);

        auto rotateCommand = std::make_shared<RotateModelCommand>(id, ox, oy, oz);

        facade->execute(rotateCommand);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    auto command = std::make_shared<RotateCameraCommand>(-2, 0, 0);
    facade->execute(command);
}


void MainWindow::on_pushButton_7_clicked()
{
    auto command = std::make_shared<RotateCameraCommand>(0, -2, 0);
    facade->execute(command);
}


void MainWindow::on_pushButton_9_clicked()
{
    auto command = std::make_shared<RotateCameraCommand>(0, 0, -2);
    facade->execute(command);
}


void MainWindow::on_pushButton_12_clicked()
{
    auto command = std::make_shared<AddCameraCommand>();
    facade->execute(command);
}


void MainWindow::on_pushButton_13_clicked()
{
    int id;
    if (getObjId(id)) {
        auto command = std::make_shared<SetNewMainCameraCommand>(id);
        facade->execute(command);
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    int id;
    if (getObjId(id)) {
        auto command = std::make_shared<DeleteCameraCommand>(id);
        facade->execute(command);
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    int id;
    if (getObjId(id)) {
        auto command = std::make_shared<DeleteObjectCommand>(id);
        facade->execute(command);
    }
}

bool MainWindow::getRotateParams(double &dx, double &dy, double &dz) {
    try {
        dx = readDoubleFromField(ui->oxRotateInput), dy = readDoubleFromField(ui->oyRotateInput), dz = readDoubleFromField(ui->ozRotateInput);
        return true;
    }
    catch (std::runtime_error ex)
    {
        QMessageBox::critical(this, "Ошибка сканирования", ex.what());
        return false;
    }
}

bool MainWindow::getTransformParams(double &dx, double &dy, double &dz) {
    try {
        dx = readDoubleFromField(ui->oxMoveInput), dy = readDoubleFromField(ui->oyMoveInput), dz = readDoubleFromField(ui->ozMoveInput);
        return true;
    }
    catch (std::runtime_error ex)
    {
        QMessageBox::critical(this, "Ошибка сканирования", ex.what());
        return false;
    }
}

bool MainWindow::getScaleParams(double &dx, double &dy, double &dz) {
    try {
        dx = readDoubleFromField(ui->oxScaleInput), dy = readDoubleFromField(ui->oyScaleInput), dz = readDoubleFromField(ui->ozScaleInput);
        return true;
    }
    catch (std::runtime_error ex)
    {
        QMessageBox::critical(this, "Ошибка сканирования", ex.what());
        return false;
    }
}

bool MainWindow::getObjId(int &objId) {
    try {
        objId = readDoubleFromField(ui->idInput);
        return true;
    }
    catch (std::runtime_error ex)
    {
        QMessageBox::critical(this, "Ошибка сканирования", "Пустой айди объекта");
        return false;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    auto command = std::make_shared<ClearSceneCommand>();
    facade->execute(command);
}


void MainWindow::on_undoButton_clicked()
{
    auto command = std::make_shared<UndoCommand>();
    facade->execute(command);
}


void MainWindow::on_resetFieldsButton_clicked()
{
    this->ui->oxMoveInput->setText("0");
    this->ui->oyMoveInput->setText("0");
    this->ui->ozMoveInput->setText("0");

    this->ui->oxScaleInput->setText("1");
    this->ui->oyScaleInput->setText("1");
    this->ui->ozScaleInput->setText("1");

    this->ui->oxRotateInput->setText("0");
    this->ui->oyRotateInput->setText("0");
    this->ui->ozRotateInput->setText("0");

}


void MainWindow::on_groupButton_clicked()
{
    QString t = ui->groupObjectsInput->text();

    std::shared_ptr<std::vector<int>> v = std::make_shared<std::vector<int>>();

    auto nums = t.split(',');
    for (int i = 0; i < nums.size(); ++i)
    {
        v->push_back(nums[i].toInt());
    }

    auto command = std::make_shared<GroupModelCommand>(v);
    facade->execute(command);
}

