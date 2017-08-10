// MrFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include <iostream>

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
	scanf("%s");
    return 0;
}


