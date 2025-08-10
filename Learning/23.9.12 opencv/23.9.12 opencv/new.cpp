#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("F:/Code/Learning/pictures/lena.jpg");
    if (img.empty())
    {
        cout << "Failed to read image" << endl;
        return -1;
    }
    int newW = img.cols / 2;
    int newH = img.rows / 2;

    Mat resizeImg(newW, newH, CV_8UC3);
    for (int i = 0; i < newH; i++)
    {
        for (int j = 0; j < newW; j++)
        {
            int startX = 2 * j;//邻域的起始坐标
            int startY = 2 * i;
            int endX = startX + 2;//邻域的终止坐标
            int endY = startY + 2;

            int pixel[3] = { 0 };
            for (int y = startY; y < endY; y++)
            {
                for (int x = startX; x < endX; x++)
                {
                    pixel[0] += img.at<Vec3b>(y, x)[0];
                    pixel[1] += img.at<Vec3b>(y, x)[1];
                    pixel[2] += img.at<Vec3b>(y, x)[2];
                }
            }
            Vec3b aveColor(pixel[0] / 4, pixel[1] / 4, pixel[2] / 4);
            resizeImg.at<Vec3b>(i, j) = aveColor;
        }
    }
    namedWindow("before", WINDOW_AUTOSIZE);
    namedWindow("after", WINDOW_AUTOSIZE);
    imshow("before", img);
    imshow("after", resizeImg);
    waitKey(0);
    imwrite("resized.jpg", resizeImg);

	return 0;
}


//int main()
//{
//	Mat img = imread("F:/Code/Learning/pictures/lena.jpg");
//	Mat gray (img.rows, img.cols, CV_8UC1);
//	for (int i = 0; i < img.rows; i++)//灰度化处理
//	{
//		for (int j = 0; j < img.cols; j++)
//		{
//			gray.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3.0;
//		}
//	}
//	namedWindow("before", WINDOW_AUTOSIZE);
//	imshow("before", gray);
//
//	int all[256] = { 0 };//统计
//	for (int i = 0; i < gray.rows; i++)
//	{
//		for (int j = 0; j < gray.cols; j++)
//		{
//			int value = gray.at<uchar>(i, j);
//			all[value]++;
//		}
//	}
//
//	int hist_h = 400;
//	int hist_w = 512;
//	int width = 2;
//	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC1);
//	for (int i = 0; i < gray.rows; i++)
//	{
//		line(histImage, Point(2 * i, 0 ), Point(2 * i,(400 - all[i] / 10)), (255), 2);
//	}
//
//	imshow("hist", histImage);
//
//	waitKey(0);
//
//	return 0;
//}




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
//        if (numb == 0)continue;
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

////图像灰度化(平均值法)
////灰度化处理就是把彩色的R，G，B分量相等的过程。灰度值大的像素点比较亮（像素值最大为255，为白色），反之比较暗（像素最下为0，为黑色）。
//int main()
//{
//	Mat img = imread("F:/Code/Learning/pictures/1.jpg");
//	namedWindow("before", WINDOW_AUTOSIZE);
//	imshow("before", img);
//
//	Mat gary (img.rows, img.cols, CV_8UC1);
//	for (int i = 0; i < img.rows; i++)//灰度化处理
//	{
//		for (int j = 0; j < img.cols; j++)
//		{
//			gary.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3.0;
//		}
//	}
//	namedWindow("after", WINDOW_AUTOSIZE);
//	imshow("after", gary);
//	imwrite("F:/Code/Learning/pictures/after/gary.jpg", gary);
//
//	waitKey(0);
//
//	return 0;
//}

////图像读取、显示、保存
//int main()
//{
//	Mat img;
//	img = imread("F:/Code/Learning/pictures/1.jpg",IMREAD_COLOR);//彩色读取
//	Mat gray = imread("F:/Code/Learning/pictures/1.jpg", IMREAD_GRAYSCALE);//灰度读取
//
//	namedWindow("img", WINDOW_AUTOSIZE);//窗口大小自适应
//	namedWindow("gray", WINDOW_GUI_NORMAL);//窗口大小可变
//
//	imshow("img", img);
//	imshow("gray", gray);
//	//保存图片
//	imwrite("F:/Code/Learning/pictures/after/1.bmp", img);
//
//	waitKey(0);
//
//	return 0;
//}



//int main()
//{
//	system("color F0");//把运行界面改成白色
//
//	Mat a(3, 3, CV_8UC1);
//	Mat b1(5, 5, CV_8UC1, Scalar(1, 2, 3));
//	Mat b2(5, 5, CV_8UC2, Scalar(1, 2, 3));
//	Mat b3(5, 5, CV_8UC3, Scalar(1, 2, 3));
//
//	Mat c = (cv::Mat_<int>(1, 5) << 1, 2, 3, 4, 5);//枚举法
//	Mat d = Mat::diag(c);//创建对角矩阵
//	Mat e = Mat(d, Range(2, 4), Range(0, 5));
//
//	//cout << b1 << endl;
//	cout << b2 << endl;
//	cout << b3 << endl;
//
//	//cout << c << endl;
//	//cout << d << endl;
//	//cout << e << endl;
//	//Mat类型的读取：
//	cout << c.at<int>(0, 2) << endl;//单通道读取(第3个元素)
//	Vec2b vc = b2.at<Vec2b>(1, 1);//多通道读取
//
//	cout << vc << endl;
//	cout << (int)vc[0] << endl;//原本是uchar类型
//	cout << (double)(*(b3.data + b3.step[0] * 2 + b3.step[1] * 2 + 3));//x=0 y=1 z=3
//
//	return 0;
//}

