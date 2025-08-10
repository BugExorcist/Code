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
            int startX = 2 * j;//�������ʼ����
            int startY = 2 * i;
            int endX = startX + 2;//�������ֹ����
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
//	for (int i = 0; i < img.rows; i++)//�ҶȻ�����
//	{
//		for (int j = 0; j < img.cols; j++)
//		{
//			gray.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3.0;
//		}
//	}
//	namedWindow("before", WINDOW_AUTOSIZE);
//	imshow("before", gray);
//
//	int all[256] = { 0 };//ͳ��
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
//    for (int i = 0; i < img.rows; i++)//�ҶȻ�����
//    {
//        for (int j = 0; j < img.cols; j++)
//        {
//            gray.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3.0;
//        }
//    }
//
//    //====================��OSTU���ҵ���ֵ====================//
//    //ԭ�����£�
//    //1.ͳ��ͼ����ÿ���Ҷȼ����������������������������
//    //2.����ÿ�����ܵ���ֵ��0��255���������ڸ���ֵ�±�����ǰ������䷽��
//    //���� ��䷽�� = (������������ / ��������) * (ǰ���������� / ��������) * (������ƽ���Ҷ�ֵ - ǰ����ƽ���Ҷ�ֵ)^2
//    //3.��������ֵ�У�ѡ��ʹ����䷽��������ֵ��Ϊ�����ֵ
//    //========================================================//
//
//    int all[256] = { 0 };
//    int total = gray.rows * gray.cols;//ͳ��ͼ�������еĻҶȼ�������
//    for (int i = 0; i < gray.rows; i++)
//    {
//        for (int j = 0; j < gray.cols; j++)//����ͳ�Ƴ�ÿ�����صĻҶ�
//        {
//            int value = gray.at<uchar>(i, j);
//            all[value]++;
//        }
//    }
//    //����ÿ���Ҷȼ��������ռͼ�����������ı����Ͷ�Ӧ���ۻ�����
//    int threshold = 0;//��ֵ
//    int maxVariance = 0;//��¼��󷽲�
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
//        sumb += i * all[i];// �����������صĻҶ�ֵ֮��
//
//        int Pb = 0, Pf = 0, Variance = 0;//��¼��������ռ�� ǰ������ռ�� ��ǰ����
//        Pb = sumb / numb;//��������ռ��
//        Pf = (sum - sumb) / numf;//ǰ������ռ��
//
//        Variance = numb * numf * (Pb - Pf) * (Pb - Pf);// ���㷽��
//
//        if (maxVariance < Variance) {
//            maxVariance = Variance;
//            threshold = i;//��¼��䷽��������ֵ
//        }
//    }
//
//    Mat binaryImage(img.rows, img.cols, CV_8UC1);//��ֵ������
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

////ͼ��ҶȻ�(ƽ��ֵ��)
////�ҶȻ�������ǰѲ�ɫ��R��G��B������ȵĹ��̡��Ҷ�ֵ������ص�Ƚ���������ֵ���Ϊ255��Ϊ��ɫ������֮�Ƚϰ�����������Ϊ0��Ϊ��ɫ����
//int main()
//{
//	Mat img = imread("F:/Code/Learning/pictures/1.jpg");
//	namedWindow("before", WINDOW_AUTOSIZE);
//	imshow("before", img);
//
//	Mat gary (img.rows, img.cols, CV_8UC1);
//	for (int i = 0; i < img.rows; i++)//�ҶȻ�����
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

////ͼ���ȡ����ʾ������
//int main()
//{
//	Mat img;
//	img = imread("F:/Code/Learning/pictures/1.jpg",IMREAD_COLOR);//��ɫ��ȡ
//	Mat gray = imread("F:/Code/Learning/pictures/1.jpg", IMREAD_GRAYSCALE);//�Ҷȶ�ȡ
//
//	namedWindow("img", WINDOW_AUTOSIZE);//���ڴ�С����Ӧ
//	namedWindow("gray", WINDOW_GUI_NORMAL);//���ڴ�С�ɱ�
//
//	imshow("img", img);
//	imshow("gray", gray);
//	//����ͼƬ
//	imwrite("F:/Code/Learning/pictures/after/1.bmp", img);
//
//	waitKey(0);
//
//	return 0;
//}



//int main()
//{
//	system("color F0");//�����н���ĳɰ�ɫ
//
//	Mat a(3, 3, CV_8UC1);
//	Mat b1(5, 5, CV_8UC1, Scalar(1, 2, 3));
//	Mat b2(5, 5, CV_8UC2, Scalar(1, 2, 3));
//	Mat b3(5, 5, CV_8UC3, Scalar(1, 2, 3));
//
//	Mat c = (cv::Mat_<int>(1, 5) << 1, 2, 3, 4, 5);//ö�ٷ�
//	Mat d = Mat::diag(c);//�����ԽǾ���
//	Mat e = Mat(d, Range(2, 4), Range(0, 5));
//
//	//cout << b1 << endl;
//	cout << b2 << endl;
//	cout << b3 << endl;
//
//	//cout << c << endl;
//	//cout << d << endl;
//	//cout << e << endl;
//	//Mat���͵Ķ�ȡ��
//	cout << c.at<int>(0, 2) << endl;//��ͨ����ȡ(��3��Ԫ��)
//	Vec2b vc = b2.at<Vec2b>(1, 1);//��ͨ����ȡ
//
//	cout << vc << endl;
//	cout << (int)vc[0] << endl;//ԭ����uchar����
//	cout << (double)(*(b3.data + b3.step[0] * 2 + b3.step[1] * 2 + 3));//x=0 y=1 z=3
//
//	return 0;
//}

