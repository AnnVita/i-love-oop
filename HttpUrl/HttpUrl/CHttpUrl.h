#pragma once
#include "stdafx.h"

enum Protocol
{
	HTTP = 80,
	HTTPS = 443
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const & url);
	CHttpUrl::CHttpUrl(std::string const & domain, std::string const & file, Protocol protocol = Protocol::HTTP, unsigned short port = static_cast<unsigned short>(Protocol::HTTP));


	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetFile() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	std::pair<std::string, std::string> ParseUrl(const std::string & url) const;
	std::string ParseProtocol(const std::string & protocol) const;
	std::pair<std::string, std::string> ParseAddress(const std::string & address) const;
	std::pair<std::string, std::string> ParseDomain(const std::string & domain) const;
	std::string ParseFile(const std::string & file) const;
	std::string ProtocolToString(Protocol protocolValue) const;
	Protocol StringToProtocol(const std::string & value) const;
	void CheckDomainName(const std::string & domain) const;

	std::string m_domain, m_file;
	Protocol m_protocol;
	unsigned short m_port;
};
