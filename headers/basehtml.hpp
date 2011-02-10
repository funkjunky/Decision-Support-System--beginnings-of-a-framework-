#ifndef BASEHTML_HPP
#define BASEHTML_HPP

#include <string>
#include <vector>

namespace dss
{
	typedef std::string Filename;
	typedef std::string HTMLContent;

	//base class for all HTML sections/pages.
	class HTMLDocument
	{
		public:
		HTMLDocument(const std::string& _title);

		void addJavascript(const Filename& filename);
		void removeJavascript(const Filename& filename);

		void addCSS(const Filename& filename);
		void removeCSS(const Filename& filename);

		virtual HTMLContent getHTML() = 0;

		private:
		std::string title;
		std::vector<Filename> jsFiles;
		std::vector<Filename> cssFiles;
		std::vector<HTMLDocument> htmlDocuments;
	};

	//creates a full proper HTML webpage using an HTMLDocument.
	class HTMLComplete : HTMLDocument
	{
		public:
		HTMLComplete(const std::string& _title);
		
		HTMLContent getHTML();
		
		private:
		HTMLContent getHead();
		HTMLContent getJavascriptHTML();
		HTMLContent getCSSHTML();
		HTMLContent bodyHTML();	//not called "get*", because it HAS the HTML.
	};
}

#endif
