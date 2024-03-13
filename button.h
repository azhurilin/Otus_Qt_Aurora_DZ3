#ifndef BUTTON_H
#define BUTTON_H

#include <QCheckBox>
#include <QObject>
#include <QPushButton>

#include <QPaintEvent>


class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QObject* parent = nullptr);
    ~Button();

protected:
    void paintEvent(QPaintEvent* event) override;
};





#endif // BUTTON_H
