// token_manipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "token_manipulation.hpp"
#include "ntdll.hpp"

void help()
{
	std::cout << "\t[modified by combo]" << std::endl;
	std::cout << "\t--\tUsage: exefile <full_path_of_target>" << std::endl;
}

int main(int argc, char* argv[])
{
	WCHAR wname[256];
	if (argc != 2)
	{
		help();
		return 1;
	}
	if (strlen(argv[1]) >= 256)
	{
		help();
		std::cout << "the path length must be less than 256." << std::endl;
		return 1;
	}
	ntdll::initialise_functions();

	memset(wname, 0, sizeof(wname));
	MultiByteToWideChar(CP_ACP, 0, argv[1], strlen(argv[1])+1, wname,
		sizeof(wname)/sizeof(wname[0]));

	token_manipulation::run((LPCWSTR)(wname));

    return 0;
}

