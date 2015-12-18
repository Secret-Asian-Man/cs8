#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Shortest Path");

    from = false;
    to = false;

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:///places_map.qml")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    from = true;
    f = ui->lineEdit->text();
    if(f=="")
        from = false;
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    to = true;
    t = ui->lineEdit_2->text();
    if(t=="")
        to = false;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    ShortestDistance s("FinalData.xml", "airports.xml", "routes.xml", "airlines.xml");
    if(from && to)
    {
        vector<Vertex*> vec = s.shortestDistance(f.toStdString(), t.toStdString());
        vector<Vertex*>::const_iterator it = vec.begin();
            if(!vec.empty())
            {
                for(; it+1 != vec.end(); ++it)
                {
                    vector<Routes*>::const_iterator mt = (*it)->routes.begin();
                    for(; mt != (*it)->routes.end(); ++ mt)
                    {
                        if(((*(it+1))->airport_id) == (*mt)->nextAirport)
                        {
                            ui->listWidget->addItem("With one of the following carriers: ");
                            vector<string>::const_iterator mt2 = (*mt)->carriers.begin();
                            for(; mt2 != (*mt)->carriers.end(); ++ mt2)
                            {
                                ui->listWidget->addItem(QString::fromStdString(*mt2));
                            }
                        }
                    }
                    ui->listWidget->addItem("\nGo from " + QString::fromStdString((*it)->airport_iata) + ": " + QString::fromStdString((*it)->airport_name) + " Airport (" + QString::fromStdString((*it)->airport_city) + ", " + QString::fromStdString((*it)->airport_country) + ")");
                    ui->listWidget->addItem("\nArrive at " + QString::fromStdString((*(it+1))->airport_iata) + ": "  + QString::fromStdString((*(it+1))->airport_name) + " Airport (" + QString::fromStdString((*(it+1))->airport_city) + ", " + QString::fromStdString((*(it+1))->airport_country)  + "), a total of " + QString::number((*(it+1))->cost) + " miles.");
                }
            }
    }
}
