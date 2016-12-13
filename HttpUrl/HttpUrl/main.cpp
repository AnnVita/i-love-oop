#include "stdafx.h"


int main()
{
	std::string url("https://abcbca.domain1.domain8132/ab/dabc.file");
	boost::regex urlRegEx("(\\w+)://(\\S+)");
	boost::smatch xUrlFirstResults;
	std::cout << "==========================UrlResults============================== \n";
	std::cout << "Does this line match our needs? " << std::boolalpha << boost::regex_match(url, xUrlFirstResults, urlRegEx) << "\n";
	std::cout << "Print entire match:\n " << xUrlFirstResults[0] << std::endl;
	std::cout << "Print the former string into another format:\n" << xUrlFirstResults[1] << "+"
		<< xUrlFirstResults[2] << std::endl;

	boost::regex protocolRegEx("(?i)https?");
	std::string protocol = xUrlFirstResults[1];
	std::cout << "==========================ProtocolResults============================== \n";
	std::cout << "Does this line match our needs? " << std::boolalpha << boost::regex_match(protocol, protocolRegEx) << "\n";
	std::cout << "Print entire match:\n " << protocol << std::endl;

	boost::regex addressRegEx("([^\\s/]+)(/\\S*)?");
	std::string address = xUrlFirstResults[2];
	boost::smatch xUrlSecondResults;
	std::cout << "==========================AddessResults============================== \n";
	std::cout << "Does this line match our needs? " << std::boolalpha << boost::regex_match(address, xUrlSecondResults, addressRegEx) << "\n";
	std::cout << "Print entire match:\n " << xUrlSecondResults[0] << std::endl;
	std::cout << "Print the former string into another format:\n" << xUrlSecondResults[1] << "+"
		<< xUrlSecondResults[2] << std::endl;

	boost::regex domainRegEx("([^\\s/:]+\\.[^\\s/:]+)+:?(\\d+)?");
	std::string domain = xUrlSecondResults[1];
	boost::smatch xUrlDomainResults;
	std::cout << "==========================DomainResults============================== \n";
	std::cout << "Does this line match our needs? " << std::boolalpha << boost::regex_match(domain, xUrlDomainResults, domainRegEx) << "\n";
	std::cout << "Print entire match:\n " << xUrlDomainResults[0] << std::endl;
	std::cout << "Print the former string into another format:\n" << xUrlDomainResults[1] << "+"
		<< xUrlDomainResults[2] << std::endl;

	boost::regex fileRegEx("/?([^\\s]+)");
	std::string file = xUrlSecondResults[2];
	std::cout << "==========================FileResults============================== \n";
	std::cout << "Does this line match our needs? " << std::boolalpha << boost::regex_match(file, fileRegEx) << "\n";
	std::cout << "Print entire match:\n " << file << std::endl;

}

