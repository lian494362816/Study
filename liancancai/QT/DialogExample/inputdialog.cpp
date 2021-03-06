#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent)
{

    nameLabel1 = new QLabel;
    nameLabel1->setText(tr("姓名:"));
    nameLabel2 = new QLabel;
    nameLabel2->setText(tr("张三"));
    nameLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    nameButton = new QPushButton;
    nameButton->setText(tr("修改姓名"));

    sexLabel1 = new QLabel;
    sexLabel1->setText(tr("性别:"));
    sexLabel2 = new QLabel;
    sexLabel2->setText(tr("男"));
    sexLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    sexButton = new QPushButton;
    sexButton->setText(tr("修改性别"));

    ageLabel1 = new QLabel;
    ageLabel1->setText(tr("年龄:"));
    ageLabel2 = new QLabel;
    ageLabel2->setText(tr("20"));
    ageLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ageButton = new QPushButton;
    ageButton->setText(tr("修改年龄"));

    resultLabel1 = new QLabel;
    resultLabel1->setText(tr("成绩:"));
    resultLabel2 = new QLabel;
    resultLabel2->setText(tr("80"));
    resultLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    resultButton = new QPushButton;
    resultButton->setText(tr("修改成绩"));

     mainLayout = new QGridLayout(this);
     mainLayout->addWidget(nameLabel1,0,0);
     mainLayout->addWidget(nameLabel2,0,1);
     mainLayout->addWidget(nameButton,0,2);

     mainLayout->addWidget(sexLabel1,1,0);
     mainLayout->addWidget(sexLabel2,1,1);
     mainLayout->addWidget(sexButton,1,2);

     mainLayout->addWidget(ageLabel1,2,0);
     mainLayout->addWidget(ageLabel2,2,1);
     mainLayout->addWidget(ageButton,2,2);

     mainLayout->addWidget(resultLabel1,3,0);
     mainLayout->addWidget(resultLabel2,3,1);
     mainLayout->addWidget(resultButton,3,2);
	
     mainLayout->setMargin(15);
     mainLayout->setSpacing(10);

    QObject::connect(nameButton, SIGNAL(clicked()), this, SLOT(changeNameSlot()));
    QObject::connect(sexButton, SIGNAL(clicked()), this, SLOT(changeSexSlot()));
    QObject::connect(ageButton, SIGNAL(clicked()), this, SLOT(changeAgeSlot()));
    QObject::connect(resultButton, SIGNAL(clicked()), this, SLOT(changeResultSlot()));
}

void InputDialog::changeNameSlot()
{
    qDebug() << "name";
    /*
bool ok;
     QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                          tr("User name:"), QLineEdit::Normal,
                                          QDir::home().dirName(), &ok);
     if (ok && !text.isEmpty())
         textLabel->setText(text);
     */
    bool ok;
    QString text = QInputDialog::getText(this, tr("标准字符串输入对话框"),
                  tr("请输入姓名："),QLineEdit::Normal,nameLabel2->text(),&ok);
    if (ok && !text.isEmpty())//表示QLineEdit是否为空
    {
        nameLabel2->setText(text);
    }
}

void InputDialog::changeSexSlot()
{
    qDebug() << "sex";
    /*
QStringList items;
     items << tr("Spring") << tr("Summer") << tr("Fall") << tr("Winter");

     bool ok;
     QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                          tr("Season:"), items, 0, false, &ok);
     if (ok && !item.isEmpty())
         itemLabel->setText(item);
     */
    QStringList items;
    items << tr("男") << tr("女");
    bool ok;
    QString item = QInputDialog::getItem(this, tr("标准条目选择对话框"),tr("轻选择性别："),items,0,false,&ok);
    if (ok && !item.isEmpty())
    {
        sexLabel2->setText(item);
    }
}
void InputDialog::changeAgeSlot()
{
    qDebug() << "age";
}
void InputDialog::changeResultSlot()
{
    qDebug() << "result";
}
