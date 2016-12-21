#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

void PrintUrlInfo(const CHttpUrl & url);

int main()
{
	std::string url;
	while (std::getline(std::cin, url))
	{
		try
		{
			CHttpUrl httpUrl(url);
			PrintUrlInfo(url);
		}
		catch (CUrlParsingError const & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}

void PrintUrlInfo(const CHttpUrl & url)
{
	std::cout << "URL info:" << std::endl
		<< "Protocol: " << url.ProtocolToString(url.GetProtocol()) << std::endl
		<< "Domain: " << url.GetDomain() << std::endl
		<< "Port: " << url.GetPort() << std::endl
		<< "File: " << url.GetFile() << std::endl
		<< "URL: " << url.GetURL() << std::endl;
}