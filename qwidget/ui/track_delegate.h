#pragma once

#include <QStyledItemDelegate>
#include <QLabel>

class track_delegate : public QStyledItemDelegate {
    Q_OBJECT

    QLabel title;

public:
    explicit track_delegate(QObject *parent = nullptr);
};

