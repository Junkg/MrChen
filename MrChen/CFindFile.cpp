#include "stdafx.h"
#include "CFindFile.h"


CFindFile::CFindFile(void)
{
	m_hFile = INVALID_HANDLE_VALUE;
	m_bFound = FALSE;
	memset(&m_fileInfo, 0, sizeof(m_fileInfo));
}

CFindFile::~CFindFile(void)
{
	if (m_hFile != INVALID_HANDLE_VALUE)
		FindClose(m_hFile);
}

void CFindFile::First(LPCTSTR lpFileName)
{
	if (m_hFile != INVALID_HANDLE_VALUE)
		FindClose(m_hFile);
	m_hFile = FindFirstFile(lpFileName, &m_fileInfo);
	if (m_hFile != INVALID_HANDLE_VALUE)
		m_bFound = TRUE;
	else
		m_bFound = FALSE;
}

void CFindFile::Next()
{
	m_bFound = FindNextFile(m_hFile, &m_fileInfo);
}

BOOL CFindFile::IsOk()
{
	return m_bFound;
}

const WIN32_FIND_DATA &CFindFile::GetCurFile()
{
	return m_fileInfo;
}