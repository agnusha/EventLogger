#include <windows.h>
#include <sddl.h>
#include <stdio.h>
#include <winevt.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma comment(lib, "wevtapi.lib")
#define ARRAY_SIZE 10
#define TIMEOUT 1000  // 1 second; Set and use in place of INFINITE in EvtNext call

// The structured XML query.
#define QUERY \
    L"<QueryList>" \
    L"  <Query Path='System'>" \
    L"    <Select>Event/System[EventID=3]</Select>" \
    L"  </Query>" \
    L"</QueryList>"

DWORD PrintQueryStatuses(EVT_HANDLE hResults);
DWORD GetQueryStatusProperty(EVT_QUERY_PROPERTY_ID Id, EVT_HANDLE hResults, PEVT_VARIANT& pProperty);
DWORD PrintResults(EVT_HANDLE hResults);
DWORD PrintEvent(EVT_HANDLE hEvent);  // Shown in the Rendering Events topic
wstring s2ws(const string& s);
BOOL DeleteRecord(LPWSTR ReadPath, LPWSTR lpEventRecordId);

int main(void)
{
    int command;
    cout << "Available commands:" << endl;
    cout << "1. Show event log by Channel and Event id" << endl;
    cout << "2. Add event" << endl;
    cout << "3. Remove event " << endl;
    cout << "Enter the number and press Enter " << endl;
    cin >> command;

    if (command == 1) {

        cout << "Enter Channel:";
        cin.ignore();
        string queryPath;
        getline(cin, queryPath);
        wstring queryPathW = s2ws(queryPath);

        cout << "Enter Event id:";
        string eventID;
        getline(cin, eventID);
        wstring eventIDhW = s2ws(eventID);

        wstring queryW  = \
            L"<QueryList>" \
            L"  <Query Path='" + queryPathW + "'>" \
            L"    <Select>Event/System[EventID=" + eventIDhW + "]</Select>" \
            L"  </Query>" \
            L"</QueryList>";

        LPCWSTR queryL = queryW.c_str();

        DWORD status = ERROR_SUCCESS;
        EVT_HANDLE hResults = NULL;

        hResults = EvtQuery(NULL, NULL, queryL, EvtQueryChannelPath | EvtQueryTolerateQueryErrors);
        if (NULL == hResults)
        {
            // Handle error.
            goto cleanup;
        }

        // Print the status of each query. If all the queries succeeded,
        // print the events in the result set. The status can be
        // ERROR_EVT_CHANNEL_NOT_FOUND or ERROR_EVT_INVALID_QUERY among others.
        if (ERROR_SUCCESS == PrintQueryStatuses(hResults))
            PrintResults(hResults);
    cleanup:

        if (hResults)
            EvtClose(hResults);
    }
    //create event
    else if (command == 2) {
            cout << "Enter Type (SUCCESS, ERROR, WARNING, INFORMATION) :";
            cin.ignore();
            string type;
            getline(cin, type);

            cout << "Enter Event id (1-1000):";
            string eventID;
            getline(cin, eventID);

            cout << "Enter source:";
            string source;
            getline(cin, source);

            cout << "Enter description:";
            string description;
            getline(cin, description);

            stringstream ss;
            ss << "EventCreate /t " << type << " /id " << eventID << " /l APPLICATION /so " << source << " /d \"" << description << "\"";
            system(ss.str().c_str());
    }

    //delete event
    else if (command == 3) {
        cout << "Enter Event record id:";
        cin.ignore();
        std::string eventRecordId;
        cin >> eventRecordId;
        const char* eventRecordIdC = eventRecordId.c_str();

        cout << "Enter source:";
        string source;
        cin >> source;
        source += ".evtx";
        const char* sourceC = source.c_str();

        wchar_t ReadPath[100];
        swprintf(ReadPath, 100, L"%hs", sourceC);
        _wcslwr_s(ReadPath, wcslen(ReadPath) + 1);

        wchar_t lpEventRecordId[100];
        swprintf(lpEventRecordId, 100, L"%hs", eventRecordIdC);
        _wcslwr_s(lpEventRecordId, wcslen(lpEventRecordId) + 1);

        if (DeleteRecord(ReadPath, lpEventRecordId))
            cout << "Delete success" << endl;
        else
            cout << "Delete error" << endl;
    }
}

wstring s2ws(const string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    wstring r(buf);
    delete[] buf;
    return r;
}

// DeleteRecord from event log
BOOL DeleteRecord(LPWSTR ReadPath, LPWSTR lpEventRecordId)
{
    LPWSTR lpPath = new WCHAR[MAX_PATH];
    LPWSTR lpQuery = new WCHAR[MAX_PATH];
    LPWSTR lpTargetLogFile = new WCHAR[MAX_PATH];

    ZeroMemory(lpPath, MAX_PATH);
    ZeroMemory(lpQuery, MAX_PATH);
    ZeroMemory(lpTargetLogFile, MAX_PATH);

    GetSystemDirectory(lpPath, MAX_PATH);
    lstrcat(lpPath, L"\\winevt\\logs\\");
    lstrcat(lpPath, ReadPath);

    lstrcat(lpQuery, L"Event/System[EventRecordID!=");
    lstrcat(lpQuery, lpEventRecordId);
    lstrcat(lpQuery, L"]");
    lstrcat(lpTargetLogFile, L".\\temp.evtx");

    if (!EvtExportLog(NULL, lpPath, lpQuery, lpTargetLogFile, EvtExportLogFilePath)) {
        cout << "EvtExportLog error " << GetLastError() << endl;
        return FALSE;
    }
    return TRUE;
}

// Enumerate all the events in the result set. 
DWORD PrintResults(EVT_HANDLE hResults)
{
    DWORD status = ERROR_SUCCESS;
    EVT_HANDLE hEvents[ARRAY_SIZE];
    DWORD dwReturned = 0;

    while (true)
    {
        // Get a block of events from the result set.
        if (!EvtNext(hResults, ARRAY_SIZE, hEvents, INFINITE, 0, &dwReturned))
        {
            if (ERROR_NO_MORE_ITEMS != (status = GetLastError()))
            {
                wprintf(L"EvtNext failed with %lu\n", status);
            }

            goto cleanup;
        }

        // For each event, call the PrintEvent function which renders the
        // event for display. PrintEvent is shown in RenderingEvents.
        for (DWORD i = 0; i < dwReturned; i++)
        {
            if (ERROR_SUCCESS == (status = PrintEvent(hEvents[i])))
            {
                EvtClose(hEvents[i]);
                hEvents[i] = NULL;
            }
            else
            {
                goto cleanup;
            }
        }
    }

cleanup:

    for (DWORD i = 0; i < dwReturned; i++)
    {
        if (NULL != hEvents[i])
            EvtClose(hEvents[i]);
    }

    return status;
}

// Get the list of paths in the query and the status for each path. Return
// the sum of the statuses, so the caller can decide whether to enumerate 
// the results.
DWORD PrintQueryStatuses(EVT_HANDLE hResults)
{
    DWORD status = ERROR_SUCCESS;
    PEVT_VARIANT pPaths = NULL;
    PEVT_VARIANT pStatuses = NULL;

    wprintf(L"List of channels/logs that were queried and their status\n\n");

    if (status = GetQueryStatusProperty(EvtQueryNames, hResults, pPaths))
        goto cleanup;

    if (status = GetQueryStatusProperty(EvtQueryStatuses, hResults, pStatuses))
        goto cleanup;

    for (DWORD i = 0; i < pPaths->Count; i++)
    {
        wprintf(L"%s (%lu)\n", pPaths->StringArr[i], pStatuses->UInt32Arr[i]);
        status += pStatuses->UInt32Arr[i];
    }

cleanup:

    if (pPaths)
        free(pPaths);

    if (pStatuses)
        free(pStatuses);

    return status;
}


// Get the list of paths specified in the query or the list of status values 
// for each path.
DWORD GetQueryStatusProperty(EVT_QUERY_PROPERTY_ID Id, EVT_HANDLE hResults, PEVT_VARIANT& pProperty)
{
    DWORD status = ERROR_SUCCESS;
    DWORD dwBufferSize = 0;
    DWORD dwBufferUsed = 0;

    if (!EvtGetQueryInfo(hResults, Id, dwBufferSize, pProperty, &dwBufferUsed))
    {
        status = GetLastError();
        if (ERROR_INSUFFICIENT_BUFFER == status)
        {
            dwBufferSize = dwBufferUsed;
            pProperty = (PEVT_VARIANT)malloc(dwBufferSize);
            if (pProperty)
            {
                EvtGetQueryInfo(hResults, Id, dwBufferSize, pProperty, &dwBufferUsed);
            }
            else
            {
                wprintf(L"realloc failed\n");
                status = ERROR_OUTOFMEMORY;
                goto cleanup;
            }
        }

        if (ERROR_SUCCESS != (status = GetLastError()))
        {
            wprintf(L"EvtGetQueryInfo failed with %d\n", GetLastError());
            goto cleanup;
        }
    }

cleanup:

    return status;
}

DWORD PrintEvent(EVT_HANDLE hEvent)
{
    DWORD status = ERROR_SUCCESS;
    DWORD dwBufferSize = 0;
    DWORD dwBufferUsed = 0;
    DWORD dwPropertyCount = 0;
    LPWSTR pRenderedContent = NULL;

    // The EvtRenderEventXml flag tells EvtRender to render the event as an XML string.
    if (!EvtRender(NULL, hEvent, EvtRenderEventXml, dwBufferSize, pRenderedContent, &dwBufferUsed, &dwPropertyCount))
    {
        if (ERROR_INSUFFICIENT_BUFFER == (status = GetLastError()))
        {
            dwBufferSize = dwBufferUsed;
            pRenderedContent = (LPWSTR)malloc(dwBufferSize);
            if (pRenderedContent)
            {
                EvtRender(NULL, hEvent, EvtRenderEventXml, dwBufferSize, pRenderedContent, &dwBufferUsed, &dwPropertyCount);
            }
            else
            {
                wprintf(L"malloc failed\n");
                status = ERROR_OUTOFMEMORY;
                goto cleanup;
            }
        }

        if (ERROR_SUCCESS != (status = GetLastError()))
        {
            wprintf(L"EvtRender failed with %d\n", GetLastError());
            goto cleanup;
        }
    }

    wprintf(L"\n\n%s", pRenderedContent);

cleanup:

    if (pRenderedContent)
        free(pRenderedContent);

    return status;
}