#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include <QWidget>

class LoadingWindow : public QWidget
{
    Q_OBJECT

public:
    LoadingWindow(QWidget *parent = 0);
    ~LoadingWindow();
};

#endif // LOADINGWINDOW_H
