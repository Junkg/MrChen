#ifndef CFindFile_H
#define CFindFile_H
#pragma once

class CFindFile
{
public:
	CFindFile(void);
	~CFindFile(void);
	void First(LPCTSTR lpFileName);
	void Next();
	BOOL IsOk();
	const WIN32_FIND_DATA &GetCurFile();

protected:
	HANDLE m_hFile;
	BOOL m_bFound;
	WIN32_FIND_DATA m_fileInfo;
};

#endif