#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

// ȫ�ֱ���
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;

Mat src; 
Mat dst;
//����˵��
char initImage[] = "ԭͼ��";
char blurImage[] = "��ֵƽ��--blur";
char GaussianBlurImage[] = "��˹ƽ��--GaussianBlur";
char medianBlurImage[] = "��ֵƽ��--medianBlur";
char bilateralFilterImage[] = "˫��ƽ��--bilateralFilter";


int main()
{
	// ����ԭͼ��
	src = imread("psb.bmp", 1);
	dst = src.clone();
	namedWindow(initImage, WINDOW_NORMAL);
	moveWindow(initImage, 0, 0);
	imshow(initImage, src);
	waitKey(DELAY_CAPTION);
	destroyWindow(initImage);
	// ʹ�� ��ֵƽ��
	namedWindow(blurImage, WINDOW_NORMAL);
	moveWindow(blurImage, 0, 0);
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		blur(src, dst, Size(i, i), Point(-1, -1));
		imshow(blurImage, dst);
		waitKey(DELAY_BLUR);
	}
	destroyWindow(blurImage);

	// ʹ�ø�˹ƽ��
	namedWindow(GaussianBlurImage, WINDOW_NORMAL);
	moveWindow(GaussianBlurImage, 0, 0);
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		imshow(GaussianBlurImage, dst);
		waitKey(DELAY_BLUR);
	}
	destroyWindow(GaussianBlurImage);

	// ʹ����ֵƽ��
	namedWindow(medianBlurImage, WINDOW_NORMAL);
	moveWindow(medianBlurImage, 0, 0);
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(src, dst, i);
		imshow(medianBlurImage, dst);
		waitKey(DELAY_BLUR);
	}
	destroyWindow(medianBlurImage);

	// ʹ��˫��ƽ��
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