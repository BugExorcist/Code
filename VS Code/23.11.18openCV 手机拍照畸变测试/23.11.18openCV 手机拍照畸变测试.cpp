#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

#include <conio.h>  //按键事件头文件
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture inputVideo(0);
	inputVideo.set(CAP_PROP_FRAME_WIDTH, 960);
	inputVideo.set(CAP_PROP_FRAME_HEIGHT, 480);
	if (!inputVideo.isOpened())
	{
		cout << "Could not open the input video " << endl;
		return -1;
	}
	Mat frame;
	string imgname;
	int f = 1;
	int ch;
	while (1) //Show the image captured in the window and repeat
	{
		inputVideo >> frame;              // read
		if (frame.empty()) break;         // check if at end
		imshow("Camera", frame);

		if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
			ch = _getch();//使用_getch()函数获取按下的键值
			//cout << ch;
			if (ch == 27)
			{ 
				imgname = to_string(f++) + ".jpg";
				imwrite(imgname, frame);
			
			}//当按下ESC时循环，ESC键的键值时27.
		}

		char key = waitKey(10);

	}
	cout << "Finished writing" << endl;
	return 0;
}