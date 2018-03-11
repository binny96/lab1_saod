#include <iostream>
#include <fstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <time.h>
#include <conio.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <QLineEdit>
#include <ctime>


#define size 10000

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

//пузырьком
void BubbleSort(int *A, int n)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }


}

//гномья
void GnomeSort(int *A, int N)
{
    int i = 0;
    while(i < N)
    {
        if(i == 0 || A[i - 1] <= A[i])
        {
            ++i;
        }
        else
        {
            int Temp = A[i];
            A[i] = A[i - 1];
            A[i - 1] = Temp;
            --i;
        }
    }
}

//методом Шелла
void ShellSort(int *A, int n)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = A[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < A[j - step])
                    A[j] = A[j - step];
                else
                    break;
            }
            A[j] = tmp;
        }
}

//восходящая
void MergeSort(int *A, int n)
{
    int step = 1;
    int *temp = (int*)malloc(n * sizeof(temp));
    while (step < n)
    {
        int index = 0;
        int l = 0;
        int m = l + step;
        int r = l + step * 2;
        do
        {
            m = m < n ? m : n;
            r = r < n ? r : n;
            int i1 = l, i2 = m;
            for (; i1 < m && i2 < r; )
            {
                if (A[i1] < A[i2])
                    { temp[index++] = A[i1++]; }
                else
                    { temp[index++] = A[i2++]; }
            }
            while (i1 < m)
                temp[index++] = A[i1++];
            while (i2 < r)
                temp[index++] = A[i2++];
            l += step * 2;
            m += step * 2;
            r += step * 2;
        } while (l < n);
        for (int i = 0; i < n; i++)
            A[i] = temp[i];
        step *= 2;
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())//пузырьком
    {
        ifstream f;
        int n=0;
        int A[size];
        f.open("C:/Qt/2010.05/qt/GGNV-build-desktop/10.txt", ios::in);

        clock_t start = clock();
        if(f)
        {
            while(!f.eof())
            {
                f>>A[n];
                n++;
            }
            BubbleSort(A,n);
            f.close();
        }
        clock_t end = clock();
        double t=(double)(end-start)/CLOCKS_PER_SEC;

        ui->lineEdit->setText(QString::number(t));
        for(int i=0; i<n-1; i++)
        {
            ui->textEdit_2->append(QString::number(A[i]));
        }
    }


    if(ui->radioButton_2->isChecked())//гномья
    {
        ifstream f;
        int n=0;
        int A[size];
        f.open("C:/Qt/2010.05/qt/GGNV-build-desktop/10.txt", ios::in);

        clock_t start = clock();
        if(f)
        {
            while(!f.eof())
            {
                f>>A[n];
                n++;
            }
            GnomeSort(A,n);
            f.close();
        }
        clock_t end = clock();
        double t=(double)(end-start)/CLOCKS_PER_SEC;

        ui->lineEdit->setText(QString::number(t));
        for(int i=0; i<n-1; i++)
        {
            ui->textEdit_2->append(QString::number(A[i]));
        }
    }

    if(ui->radioButton_3->isChecked())//методом Шелла
    {
        ifstream f;
        int n=0;
        int A[size];
        f.open("C:/Qt/2010.05/qt/GGNV-build-desktop/10.txt", ios::in);

        clock_t start = clock();
        if(f)
        {
            while(!f.eof())
            {
                f>>A[n];
                n++;
            }
            ShellSort(A,n);
            f.close();
        }
        clock_t end = clock();
        double t=(double)(end-start)/CLOCKS_PER_SEC;

        ui->lineEdit->setText(QString::number(t));
        for(int i=0; i<n-1; i++)
        {
            ui->textEdit_2->append(QString::number(A[i]));
        }
    }

    if(ui->radioButton_4->isChecked())//восходящая
    {
        ifstream f;
        int n=0;
        int A[size];
        f.open("C:/Qt/2010.05/qt/GGNV-build-desktop/10.txt", ios::in);

        clock_t start = clock();
        if(f)
        {
            while(!f.eof())
            {
                f>>A[n];
                n++;
            }
            MergeSort(A,n);
            f.close();
        }
        clock_t end = clock();
        double t=(double)(end-start)/CLOCKS_PER_SEC;

        ui->lineEdit->setText(QString::number(t));
        for(int i=0; i<n-1; i++)
        {
            ui->textEdit_2->append(QString::number(A[i]));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ifstream f, g;
    int n=0;
    int B[size];
    f.open("C:/Qt/2010.05/qt/GGNV-build-desktop/10.txt", ios::in);
    if(f)
    {
        while(!f.eof())
        {
            f>>B[n];
            n++;
        }
        for(int i=0; i<n-1; i++)
        {
            ui->textEdit->append(QString::number(B[i]));
        }
        f.close();
    }
}
