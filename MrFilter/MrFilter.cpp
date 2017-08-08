// MrFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <gdiplus.h>
#include "FIlterUtil.h"
#include <chrono>
#include <iostream>
#include "Filters.h"

#pragma comment (lib, "Gdiplus.lib")

using namespace Gdiplus;

void average(int pos, int stride, unsigned int* data);

int main(int argc, char** argv)
{	
	/**
	* Image Import
	*/
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Bitmap* image = new Bitmap(L"test.jpg");
	BitmapData bitmapData;

	image->LockBits(&Rect(0, 0, image->GetWidth(), image->GetHeight()), ImageLockModeWrite, PixelFormat32bppARGB, &bitmapData);
	
	unsigned int *rawData = (unsigned int*)bitmapData.Scan0;
	int width = image->GetWidth();
	int height = image->GetHeight();

	/*
	* Processing
	*/
	int pad = 2;
	int pc = getPaddedPixelCount(image->GetHeight(), image->GetWidth(), pad);
	unsigned int *paddedBytes = (unsigned int*) malloc(pc*4);
	padImage(rawData, paddedBytes, image->GetHeight(), image->GetWidth(), pad);

	auto seqStart = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < image->GetHeight(); i++) {
		for (int j = 0; j < image->GetWidth(); j++){
			average(origPos2padPos(pad,j,i,height,width), width, paddedBytes);
		}
	}
	auto seqFinish = std::chrono::high_resolution_clock::now();
	std::cout <<"Sequential processing took: "<< std::chrono::duration_cast<std::chrono::milliseconds>(seqFinish - seqStart).count() << "ms\n";

	/*
	* Output
	*/
	int stride = 4 * image->GetWidth();
	//Bitmap output((int)image->GetWidth(), (int)image->GetHeight(), stride, PixelFormat32bppARGB, (byte*)rawData);

	Bitmap padded((int)image->GetWidth()+pad*2, (int)image->GetHeight()+pad*2, 4*(image->GetWidth()+(2*pad)), PixelFormat32bppARGB, (byte*)paddedBytes);
	
	CLSID pngClsid;
	CLSIDFromString(L"{557CF406-1A04-11D3-9A73-0000F81EF32E}", &pngClsid);
	
	//output.Save(L"output.png", &pngClsid, NULL);
	padded.Save(L"padded.png", &pngClsid, NULL);
	delete image;
	scanf("%s");
    return 0;
}


