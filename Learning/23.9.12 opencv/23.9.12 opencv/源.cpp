//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    Mat img = imread("F:/Code/Learning/pictures/lena.jpg");
//    namedWindow("before", WINDOW_AUTOSIZE);
//    imshow("before", img);
//    Mat gray(img.rows, img.cols, CV_8UC1);
//    for (int i = 0; i < img.rows; i++)//灰度化处理
//    {
//        for (int j = 0; j < img.cols; j++)
//        {
//            gray.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3.0;
//        }
//    }
//
//    //====================用OSTU法找到阈值====================//
//    //原理如下：
//    //1.统计图像中每个灰度级别的像素数量，并计算总像素数
//    //2.对于每个可能的阈值（0到255），计算在该阈值下背景和前景的类间方差
//    //其中 类间方差 = (背景的像素数 / 总像素数) * (前景的像素数 / 总像素数) * (背景的平均灰度值 - 前景的平均灰度值)^2
//    //3.在所有阈值中，选择使得类间方差最大的阈值作为最佳阈值
//    //========================================================//
//
//    int all[256] = { 0 };
//    int total = gray.rows * gray.cols;//统计图像中所有的灰度级别数量
//    for (int i = 0; i < gray.rows; i++)
//    {
//        for (int j = 0; j < gray.cols; j++)//遍历统计出每个像素的灰度
//        {
//            int value = gray.at<uchar>(i, j);
//            all[value]++;
//        }
//    }
//    //计算每个灰度级别的像素占图像总像素数的比例和对应的累积概率
//    int threshold = 0;//阈值
//    int maxVariance = 0;//记录最大方差
//    int sum = 0, sumb = 0;
//    int numb = 0,numf = 0;
//
//    for (int i = 0; i < 256; i++)
//        sum += i * all[i];
//
//    for (int i = 0; i < 256; i++)
//    {
//        numb += all[i];
//        numf = total - numb;
//        if (numf == 0)break;
//        sumb += i * all[i];// 背景部分像素的灰度值之和
//
//        int Pb = 0, Pf = 0, Variance = 0;//记录背景像素占比 前景像素占比 当前方差
//        Pb = sumb / numb;//背景像素占比
//        Pf = (sum - sumb) / numf;//前景像素占比
//
//        Variance = numb * numf * (Pb - Pf) * (Pb - Pf);// 计算方差
//
//        if (maxVariance < Variance) {
//            maxVariance = Variance;
//            threshold = i;//记录类间方差最大的阈值
//        }
//    }
//
//    Mat binaryImage(img.rows, img.cols, CV_8UC1);//二值化操作
//    for (int i = 0; i < img.rows; i++) {
//        for (int j = 0; j < img.cols; j++) {
//            int pixelValue = gray.at<uchar>(i, j);
//            if (pixelValue > threshold)
//                binaryImage.at<uchar>(i, j) = 255;
//            else
//                binaryImage.at<uchar>(i, j) = 0;
//        }
//    }
//    namedWindow("after", WINDOW_AUTOSIZE);
//    imshow("after", binaryImage);
//
//    waitKey(0);
//    imwrite("F:/Code/Learning/pictures/after/binaryImage.jpg", binaryImage);
//
//    return 0;
//}