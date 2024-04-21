#include "extension.h"

bool sendclipboarddata(const std::wstring&text,HWND hwnd);
bool ProcessSentence(std::wstring& sentence, SentenceInfo sentenceInfo) 
{
	if (sentenceInfo["current select"] && sentenceInfo["process id"] != 0 &&sentenceInfo["toclipboard"])
	{
		sendclipboarddata(sentence,(HWND)sentenceInfo["HostHWND"]);
	}
	return false;
}