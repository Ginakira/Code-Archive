#include "mainwindow.h"
#include <QJsonDocument>
#include <QNetworkReply>
#include "NetWorker.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStatisticLabel();
}

void MainWindow::initStatisticLabel() {
    NetWorker *netWorker = NetWorker::instance();

    QRegularExpression rxlen("^jsonpgz\\((.*)\\)");

    netWorker->get(QString("http://fundgz.1234567.com.cn/js/161725.js"));
    connect(netWorker, &NetWorker::finished, this, [=](QNetworkReply *reply) {
        auto res = reply->readAll();
        auto json = rxlen.match(res).captured(1);
        QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8());
        QVariantMap result = jsonDocument.toVariant().toMap();

        QString name = result["name"].toString();
        QString estimatedValue = result["gsz"].toString();
        double estimatedGrowthRate = result["gszzl"].toDouble();
        QString styleSheet =
            estimatedGrowthRate > 0 ? "color: red" : "color: green";

        ui->fundStatLabel->setText(name + " " + estimatedValue);
        ui->fundStatLabel->setStyleSheet(styleSheet);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
