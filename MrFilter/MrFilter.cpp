// MrFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	scanf("%s");
    return 0;
}


