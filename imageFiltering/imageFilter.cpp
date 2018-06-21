#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

// 全局变量
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;

Mat src; 
Mat dst;
//名称说明
char initImage[] = "原图像";
char blurImage[] = "均值平滑--blur";
char GaussianBlurImage[] = "高斯平滑--GaussianBlur";
char medianBlurImage[] = "中值平滑--medianBlur";
char bilateralFilterImage[] = "双边平滑--bilateralFilter";


int main()
{
	// 载入原图像
	src = imread("psb.bmp", 1);
	dst = src.clone();
	namedWindow(initImage, WINDOW_NORMAL);
	moveWindow(initImage, 0, 0);
	imshow(initImage, src);
	waitKey(DELAY_CAPTION);
	destroyWindow(initImage);
	// 使用 均值平滑
	namedWindow(blurImage, WINDOW_NORMAL);
	moveWindow(blurImage, 0, 0);
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		blur(src, dst, Size(i, i), Point(-1, -1));
		imshow(blurImage, dst);
		waitKey(DELAY_BLUR);
	}
	destroyWindow(blurImage);

	// 使用高斯平滑
	namedWindow(GaussianBlurImage, WINDOW_NORMAL);
	moveWindow(GaussianBlurImage, 0, 0);
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		imshow(GaussianBlurImage, dst);
		waitKey(DELAY_BLUR);
	}
	destroyWindow(GaussianBlurImage);

	// 使用中值平滑
	namedWindow(medianBlurImage, WINDOW_NORMAL);
	moveWindow(medianBlurImage, 0, 0);
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(src, dst, i);
		imshow(medianBlurImage, dst);
		waitKey(DELAY_BLUR);
	}
	destroyWindow(medianBlurImage);

	// 使用双边平滑
	namedWindow(bilateralFilterImage, WINDOW_NORMAL);
	moveWindow(bilateralFilterImage, 0, 0);
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		bilateralFilter(src, dst, i, i * 2, i / 2);
		imshow(bilateralFilterImage, dst);
		waitKey(DELAY_BLUR);
	}
	destroyWindow(bilateralFilterImage);
	waitKey(0);
	return 0;
}