/*
 * Filename: transfer.h
 */
#ifndef TRANSFER_H
#define TRANSFER_H
#include <QMessageBox>
#include <QDialog>
#include "iofunctions.h"

namespace Ui {
class Transfer;
}

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = nullptr);
    ~Transfer();
    int getReceiver() const;
    double getTotal() const;
    double getSum() const;
    void setCommission(int curCommission);

private slots:
    void on_cancel_clicked();

    void on_transfer_clicked();

    void on_sum_valueChanged(double arg1);

    void on_to_textChanged(const QString &arg1);

private:
    bool numIsCorrect;
    int receiver;
    double total;
    double sum;
    int commission;
    Ui::Transfer *ui;
};

#endif // TRANSFER_H
