#include "mainwindow.h"
#include <QApplication>
#include <QtXlsx>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //    QXlsx::Document xlsx;

    //        QXlsx::Format   format; //格式化对象
    //        format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);//水平居中
    //        format.setVerticalAlignment(QXlsx::Format::AlignVCenter);//垂直居中
    //        format.setBorderStyle(QXlsx::Format::BorderThin);//设置边框
    //        format.setShrinkToFit(true);//单元格内容缩放

    //        xlsx.write(3, 1, "Hello world!", format);//A3
    //        xlsx.write(4, 1, "Hello Qt!", format);//A4

    //        xlsx.write("B3", 250);
    //        xlsx.mergeCells("B3:D4", format); // 合并单元格 B3:D4


    //        format.setFontBold(true);
    //        format.setFontSize(24);
    //        format.setFontColor(Qt::red);
    //        xlsx.write("A1", "报表标题"); // 大标题
    //            xlsx.insertImage(1, 3, QImage("nike.png"));//传入LOGO
    //            xlsx.mergeCells("A1:D2", format); // 合并单元格 A1：D2

    //        xlsx.saveAs("test.xlsx");



//    QXlsx::Document xlsx;
//    QXlsx::Format format1;
//    format1.setFontColor(QColor(Qt::red));
//    format1.setFontSize(15);
//    format1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
//    format1.setBorderStyle(QXlsx::Format::BorderDashDotDot);
//    xlsx.write("A1", "Hello Qt!", format1);
//    xlsx.write("B3", 12345, format1);

//    QXlsx::Format format2;
//    format2.setFontBold(true);
//    format2.setFontUnderline(QXlsx::Format::FontUnderlineDouble);
//    format2.setFillPattern(QXlsx::Format::PatternLightUp);
//    xlsx.write("C5", "=44+33", format2);
//    xlsx.write("D7", true, format2);

//    QXlsx::Format format3;
//    format3.setFontBold(true);
//    format3.setFontColor(QColor(Qt::blue));
//    format3.setFontSize(20);
//    xlsx.write(11, 1, "Hello Row Style");
//    xlsx.write(11, 6, "Blue Color");
//    xlsx.setRowFormat(11, 41, format3);

//    QXlsx::Format format4;
//    format4.setFontBold(true);
//    format4.setFontColor(QColor(Qt::magenta));
//    for (int row=21; row<=10000; row++)
//        for (int col=9; col<16; col++)
//            xlsx.write(row, col, row+col);
//    xlsx.setColumnFormat(9, 16, format4);

//    xlsx.write("A5", QDate(2013, 8, 29));

//    QXlsx::Format format6;
//    format6.setPatternBackgroundColor(QColor(Qt::green));
//    xlsx.write("A6", "测试Background color: green", format6);

//    xlsx.saveAs("book1.xlsx");

        MainWindow w;
        w.show();

    return a.exec();
}
