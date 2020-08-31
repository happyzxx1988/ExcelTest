#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QList<QCameraInfo> list;
    list = QCameraInfo::availableCameras();
    for (int i = 0; i < list.size(); i++)
    {
        qDebug() << list.at(i).deviceName(); //获取设备名称
        qDebug() << list.at(i).description();
        qDebug() << list.at(i).position();
        qDebug() << "###############";
    }

    camera=new QCamera("@device:pnp:\\\\?\\usb#vid_0bda&pid_57f3&mi_00#6&6766a4&0&0000#{65e8773d-8f56-11d0-a3b9-00a0c9223196}\\global",this); //这是设备名称，注意！！！获取的设备名称中，\要改为\，要不然会和转义字符产生混淆，导致编译器报错，我这里已经做了更改


//    camera = new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);

    ui->ImageView->addWidget(viewfinder);
    ui->ImageCapture->setScaledContents(true);

    camera->setViewfinder(viewfinder);
    camera->start();

    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));

    connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(ui->buttonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::captureImage()
{
    ui->statusBar->showMessage(tr("capturing..."), 1000);
    imageCapture->capture();
}

void MainWindow::displayImage(int , QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));

    ui->statusBar->showMessage(tr("capture OK!"), 5000);
}

void MainWindow::saveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), QDir::homePath(), tr("jpegfile(*.jpg)"));
    if(fileName.isEmpty()) {
        ui->statusBar->showMessage(tr("save cancel"), 5000);
        return;
    }
    const QPixmap* pixmap=ui->ImageCapture->pixmap();
    if(pixmap) {
        pixmap->save(fileName);
        ui->statusBar->showMessage(tr("save OK"), 5000);
    }
}
