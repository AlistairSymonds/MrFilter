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

int main(int argc, char** argv)
{	
	/**
	* Image Import
	*/
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Bitmap* image = new Bitmap(L"test.jpg");
	img32d *img;
	gdiplus2img32d(image, img);

	/*
	* Processing
	*/
	
	auto seqStart = std::chrono::high_resolution_clock::now();

	
	auto seqFinish = std::chrono::high_resolution_clock::now();
	std::cout <<"Sequential processing took: "<< std::chrono::duration_cast<std::chrono::milliseconds>(seqFinish - seqStart).count() << "ms\n";

	/*
	* Output
	*/
	Bitmap *output;
	//img32d2gdiplusbmp();

	
	
	CLSID pngClsid;
	CLSIDFromString(L"{557CF406-1A04-11D3-9A73-0000F81EF32E}", &pngClsid);
	
	//output.Save(L"output.png", &pngClsid, NULL);
	output->Save(L"output.png", &pngClsid, NULL);
	delete image;
	scanf("%s");
    return 0;
}


