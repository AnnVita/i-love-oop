#include "stdafx.h"
#include "../HttpUrl/CHttpUrl.h"
#include "../HttpUrl/CUrlParsingError.h"
#include "../HttpUrl/errorTitles.h"



void VerifyHttpUrl(const CHttpUrl & url, Protocol expectedProtocol, const std::string & expectedDomain, const std::string & expectedFile, unsigned short expectedPort)
{
	BOOST_CHECK_EQUAL(url.GetProtocol(), expectedProtocol);
	BOOST_CHECK_EQUAL(url.GetDomain(), expectedDomain);
	BOOST_CHECK_EQUAL(url.GetFile(), expectedFile);
	BOOST_CHECK_EQUAL(url.GetPort(), expectedPort);
}

BOOST_AUTO_TEST_SUITE(HttpUrl_class)
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_valid_url)
	{
		{
			CHttpUrl url("http://good1.domain/veryGoodFolder/file.f");
			VerifyHttpUrl(url, Protocol::HTTP, "good1.domain", "/veryGoodFolder/file.f", 80);
		}
		{
			CHttpUrl url("https://good.domain/folder1/folder2/file.f");
			VerifyHttpUrl(url, Protocol::HTTPS, "good.domain", "/folder1/folder2/file.f", 443);
		}
		{
			CHttpUrl url("http://good.domain:900/folder1/folder2/file.f");
			VerifyHttpUrl(url, Protocol::HTTP, "good.domain", "/folder1/folder2/file.f", 900);
		}
		{
			CHttpUrl url("http://good.domain42");
			VerifyHttpUrl(url, Protocol::HTTP, "good.domain42", "/", 80);
		}
		{
			CHttpUrl url("http://localhost:800");
			VerifyHttpUrl(url, Protocol::HTTP, "localhost", "/", 800);
		}
		{
			CHttpUrl url("http://localhost:630/my_project/my_app.html");
			VerifyHttpUrl(url, Protocol::HTTP, "localhost", "/my_project/my_app.html", 630);
		}
	}
	BOOST_AUTO_TEST_CASE(can_return_domain)
	{
		CHttpUrl url("http://smth.ru/folder1/folder2/file.f");
		BOOST_CHECK_EQUAL(url.GetDomain(), "smth.ru");
	}
	BOOST_AUTO_TEST_CASE(can_return_protocol)
	{
		CHttpUrl url("http://smth.ru/folder1/folder2/file.f");
		BOOST_CHECK_EQUAL(url.GetProtocol(), Protocol::HTTP);
	}
	BOOST_AUTO_TEST_CASE(can_return_file)
	{
		CHttpUrl url("http://smth.ru/folder1/folder2/file.f");
		BOOST_CHECK_EQUAL(url.GetFile(), "/folder1/folder2/file.f");
	}
	BOOST_AUTO_TEST_CASE(can_return_port)
	{
		CHttpUrl url("http://smth.ru/folder1/folder2/file.f");
		BOOST_CHECK_EQUAL(url.GetPort(), 80);
	}
	BOOST_AUTO_TEST_SUITE(if_constructed_from_url_string_then)
		BOOST_AUTO_TEST_CASE(throws_exeption_if_string_is_invalid)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("not an url"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(throws_exeption_if_protocol_is_invalid)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("httd://smth.ru"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl("1http://smth.ru"), CUrlParsingError);
		}

		BOOST_AUTO_TEST_CASE(throws_exeption_if_domain_is_invalid)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("http://invaliddomain:"), CUrlParsingError);
		}

		BOOST_AUTO_TEST_CASE(throws_exeption_if_file_name_is_invalid)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("http://good.domain/not\tvery good.filename"), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(can_be_constructed_from_individual_parts_of_url)
	{
		{
			CHttpUrl url("localhost", "allCultureEvents/index.html");
			VerifyHttpUrl(url, Protocol::HTTP, "localhost", "/allCultureEvents/index.html", 80);
		}
		{
			CHttpUrl url("github.com", "AnnVita", Protocol::HTTPS, 443);
			VerifyHttpUrl(url, Protocol::HTTPS, "github.com", "/AnnVita", 443);
		}
		{
			CHttpUrl url("github.com", "", Protocol::HTTPS, 443);
			VerifyHttpUrl(url, Protocol::HTTPS, "github.com", "/", 443);
		}
	}
	BOOST_AUTO_TEST_SUITE(if_constructed_from_individual_parts_of_url_then)
		BOOST_AUTO_TEST_CASE(throws_exeption_if_domain_name_is_invalid)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("bad/Domain:com", "file", Protocol::HTTPS, 443), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(throws_exeption_if_file_name_is_invalid)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("gooddomain.com", "invalid file name", Protocol::HTTPS, 443), CUrlParsingError);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(can_return_url_string)
	{
		{
			CHttpUrl url("http://smth.ru/folder1/folder2/file.f");
			BOOST_CHECK_EQUAL(url.GetURL(), "http://smth.ru/folder1/folder2/file.f");
		}
		{
			CHttpUrl url("https://smth.ru");
			BOOST_CHECK_EQUAL(url.GetURL(), "https://smth.ru/");
		}
		{
			CHttpUrl url("https://habrahabr.ru/post/64226/");
			BOOST_CHECK_EQUAL(url.GetURL(), "https://habrahabr.ru/post/64226/");
		}
		{
			CHttpUrl url("localhost", "index.html", Protocol::HTTP, 1111);
			BOOST_CHECK_EQUAL(url.GetURL(), "http://localhost:1111/index.html");
		}
		{
			CHttpUrl url("localhost", "index.html", Protocol::HTTP);
			BOOST_CHECK_EQUAL(url.GetURL(), "http://localhost/index.html");
		}
	}


BOOST_AUTO_TEST_SUITE_END()