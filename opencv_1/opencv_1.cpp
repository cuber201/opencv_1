// opencv_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


int main()
{
    string imagePath = "image.jpg";
    Mat image = imread(imagePath);
    if (image.empty())
    {
        cout << "Image not found." << endl;
        return -1;
    }
    circle(image, Point(500, 200), 100, Scalar(0, 255, 120), -100);
    circle(image, Point(400, 200), 100, Scalar(255, 255, 255), -100);
    line(image, Point(425, 200), Point(475,200), Scalar(10, 0, 10), 2);
    line(image, Point(450, 175), Point(450, 225), Scalar(10, 0, 10), 2);
    imshow("show window", image);
    Mat part1 = image(Rect(0, 0, image.cols / 2, image.rows / 2));
    Mat part2 = image(Rect(image.cols / 2, 0, image.cols / 2, image.rows / 2));
    Mat part3 = image(Rect(0, image.rows / 2, image.cols / 2, image.rows / 2));
    Mat part4 = image(Rect(image.cols / 2, image.rows / 2, image.cols / 2, image.rows / 2));
    imshow("Display window1", part1);
    imshow("Display window2", part2);
    imshow("Display window3", part3);
    imshow("Display window4", part4);

    Mat mask = Mat::zeros(image.size(), image.type());
    circle(mask, Point(image.cols / 2, image.rows / 2), 300, Scalar(255, 255, 255), -1);
    Mat r = Mat::zeros(image.size(), image.type());
    image.copyTo(r, mask);
    imshow("Result", r);
    waitKey(0);
    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
