#include "stdafx.h"
#include "CUrlParsingError.h"
#include "CHttpUrl.h"

CHttpUrl::CHttpUrl(std::string const & url)
{
	std::pair<std::string, std::string> parsedUrl = ParseUrl(url);
	m_protocol = from_string(ParseProtocol(parsedUrl.first));
	std::pair<std::string, std::string> parsedAddress = ParseAddress(parsedUrl.second);
	std::pair<std::string, unsigned short> parsedDomain = ParseDomain(parsedAddress.second);
	m_domain = parsedDomain.first;
	m_port = parsedDomain.second;
	m_file = ParseFile(parsedAddress.second);
}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & file, Protocol protocol = HTTP, unsigned short port = 80)
{
	m_domain = domain;
	m_file = file;
	m_protocol = protocol;
	m_port = port;
}

const std::pair<std::string, std::string> CHttpUrl::ParseUrl(const std::string & url)
{
	boost::regex urlRegEx("(\\w+)://(\\S+)");
	boost::smatch urlResults;
	if (!boost::regex_match(url, urlResults, urlRegEx))
		throw CUrlParsingError("invalid string");
	return std::make_pair<std::string, std::string>(urlResults[1], urlResults[2]);
}

const std::string CHttpUrl::ParseProtocol(const std::string & protocol)
{
	boost::regex protocolRegEx("(?i)https?");
	if (!boost::regex_match(protocol, protocolRegEx))
		throw CUrlParsingError("invalid protocol");
	return boost::algorithm::to_lower_copy(protocol);
}

const std::string CHttpUrl::to_string(Protocol protocolValue)
{
	return (protocolValue == Protocol::HTTPS) ? "https" : "http";
}

const Protocol CHttpUrl::from_string(const std::string & value)
{
	return (value == "https") ? Protocol::HTTPS : Protocol::HTTP;
}

const std::pair<std::string, std::string> CHttpUrl::ParseAddress(const std::string & address)
{
	boost::regex addressRegEx("([^\\s/]+)(/\\S*)?");
	boost::smatch addressResults;
	if (!boost::regex_match(address, addressResults, addressRegEx))
		throw CUrlParsingError("invalid address");
	return std::make_pair<std::string, std::string>(addressResults[1], addressResults[2]);
}

const std::pair<std::string, unsigned short> CHttpUrl::ParseDomain(const std::string & domain)
{
	boost::regex domainRegEx("([^\\s/:]+\\.[^\\s/:]+)+:?(\\d+)?");
	boost::smatch domainResults;
	if (!boost::regex_match(domain, domainResults, domainRegEx))
		throw CUrlParsingError("invalid domain");
	return std::pair<std::string, unsigned short>(domainResults[1], static_cast<unsigned short>(std::stoi(domainResults[2])));
}

const std::string CHttpUrl::ParseFile(const std::string & file)
{
	boost::regex fileRegEx("/?([^\\s]+)");
	if(!boost::regex_match(file, fileRegEx))
		throw CUrlParsingError("invalid file name");
	return (file[0] == '/') ? file : "/" + file;
}

std::string CHttpUrl::GetURL() const
{
	std::string protocolString = (m_protocol == Protocol::HTTPS) ? "https" : "http";
	return protocolString + "://" + m_domain + m_file;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetFile() const
{
	return m_file;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}