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