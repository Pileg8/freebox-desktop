#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AboutDialog(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    QLabel * mPixLabel;
    QLabel * mTextLabel;
    QPushButton * mCreditsButton;
    QPushButton * mLicenceButton;
    
};

#endif // ABOUTDIALOG_H
