#pragma once

#include <QMainWindow>

class main_window : public QMainWindow {
    Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();
};
