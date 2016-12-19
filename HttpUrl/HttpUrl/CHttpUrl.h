#pragma once
#include "stdafx.h"

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const & url);
	CHttpUrl(const std::string & domain, const std::string & file, Protocol protocol, unsigned short port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetFile() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	const std::pair<std::string, std::string> ParseUrl(const std::string & url);
	const std::string ParseProtocol(const std::string & protocol);
	const std::pair<std::string, std::string> ParseAddress(const std::string & address);
	const std::pair<std::string, unsigned short> ParseDomain(const std::string & domain);
	const std::string ParseFile(const std::string & file);
	const std::string to_string(Protocol protocolValue);
	const Protocol from_string(const std::string & value);

	std::string m_domain, m_file;
	Protocol m_protocol;
	unsigned short m_port;
};
