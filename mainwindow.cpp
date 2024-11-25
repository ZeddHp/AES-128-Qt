#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aes.h"
#include <QFileDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Setup tabs
    auto tabWidget = new QTabWidget(this);
    QWidget *encryptTab = new QWidget();
    QWidget *decryptTab = new QWidget();

    // Setup layouts for each tab
    QVBoxLayout *encryptLayout = new QVBoxLayout(encryptTab);
    QVBoxLayout *decryptLayout = new QVBoxLayout(decryptTab);

    // Add components to encryptTab for text encryption
    QLineEdit *encryptInput = new QLineEdit();
    QLineEdit *encryptKey = new QLineEdit();
    QPushButton *encryptButton = new QPushButton("Encrypt Text");
    QTextEdit *encryptOutput = new QTextEdit();

    encryptLayout->addWidget(new QLabel("Plaintext:"));
    encryptLayout->addWidget(encryptInput);
    encryptLayout->addWidget(new QLabel("Key:"));
    encryptLayout->addWidget(encryptKey);
    encryptLayout->addWidget(encryptButton);
    encryptLayout->addWidget(new QLabel("Encrypted Text:"));
    encryptLayout->addWidget(encryptOutput);

    // Add components to decryptTab for text decryption
    QLineEdit *decryptInput = new QLineEdit();
    QLineEdit *decryptKey = new QLineEdit();
    QPushButton *decryptButton = new QPushButton("Decrypt Text");
    QTextEdit *decryptOutput = new QTextEdit();

    decryptLayout->addWidget(new QLabel("Encrypted Text:"));
    decryptLayout->addWidget(decryptInput);
    decryptLayout->addWidget(new QLabel("Key:"));
    decryptLayout->addWidget(decryptKey);
    decryptLayout->addWidget(decryptButton);
    decryptLayout->addWidget(new QLabel("Decrypted Text:"));
    decryptLayout->addWidget(decryptOutput);

    // Add tabs to tabWidget
    tabWidget->addTab(encryptTab, "Encrypt");
    tabWidget->addTab(decryptTab, "Decrypt");

    setCentralWidget(tabWidget);

    // Connect signals to slots for text encryption/decryption
    connect(encryptButton, &QPushButton::clicked, [this, encryptInput, encryptKey, encryptOutput](){
        AES aes(encryptKey->text());
        encryptOutput->setText(aes.encrypt(encryptInput->text()));
    });
    connect(decryptButton, &QPushButton::clicked, [this, decryptInput, decryptKey, decryptOutput](){
        AES aes(decryptKey->text());
        decryptOutput->setText(aes.decrypt(decryptInput->text()));
    });

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonEncrypt_clicked() {
    QString key = ui->lineEditKey->text();
    QString plainText = ui->lineEditInput->text();
    AES aes(key);
    QString encryptedText = aes.encrypt(plainText);
    ui->textEditOutput->setText(encryptedText);
}

void MainWindow::on_pushButtonDecrypt_clicked() {
    QString key = ui->lineEditKey->text();
    QString cipherText = ui->textEditOutput->toPlainText();
    AES aes(key);
    QString decryptedText = aes.decrypt(cipherText);
    ui->lineEditInput->setText(decryptedText);
}
