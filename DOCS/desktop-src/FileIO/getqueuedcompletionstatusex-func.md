---
description: This function retrieves multiple completion port entries simultaneously and waits for pending I/O operations to complete.
ms.assetid: 3996c02c-562c-4697-a091-e241ad54b239
title: GetQueuedCompletionStatusEx function (IoAPI.h)
ms.topic: reference
ms.date: 05/31/2018
topic_type: 
- APIRef
- kbSyntax
api_name: 
- GetQueuedCompletionStatusEx
api_type: 
- DllExport
api_location: 
- Kernel32.dll
- API-MS-Win-Core-io-l1-1-0.dll
- KernelBase.dll
- MinKernelBase.dll
- API-MS-Win-Core-io-l1-1-1.dll
- api-ms-win-downlevel-kernel32-l1-1-0.dll
---

# GetQueuedCompletionStatusEx function

Retrieves multiple completion port entries simultaneously. It waits for pending I/O operations that are associated with the specified completion port to complete.

To dequeue I/O completion packets one at a time, use the [**GetQueuedCompletionStatus**](/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

## Syntax

```C++
BOOL WINAPI GetQueuedCompletionStatusEx(
  _In_  HANDLE             CompletionPort,
  _Out_ LPOVERLAPPED_ENTRY lpCompletionPortEntries,
  _In_  ULONG              ulCount,
  _Out_ PULONG             ulNumEntriesRemoved,
  _In_  DWORD              dwMilliseconds,
  _In_  BOOL               fAlertable
);
```

## Parameters

*CompletionPort* `[in]`

A handle to the completion port. To create a completion port, use the [CreateIoCompletionPort](createiocompletionport.md) function.

*lpCompletionPortEntries* `[out]`

On input, points to a pre-allocated array of [OVERLAPPED\_ENTRY](/windows/win32/api/MinWinBase/ns-minwinbase-overlapped_entry) structures.

On output, receives an array of [OVERLAPPED\_ENTRY](/windows/win32/api/MinWinBase/ns-minwinbase-overlapped_entry) structures that hold the entries. The number of array elements is provided by *ulNumEntriesRemoved*.

The number of bytes transferred during each I/O, the completion key that indicates on which file each I/O occurred, and the overlapped structure address used in each original I/O are all returned in the *lpCompletionPortEntries* array.

*ulCount* `[in]`

The maximum number of entries to remove.

*ulNumEntriesRemoved* `[out]`

A pointer to a variable that receives the number of entries actually removed.

*dwMilliseconds* `[in]`

The number of milliseconds that the caller is willing to wait for a completion packet to appear at the completion port. If a completion packet does not appear within the specified time, the function times out and returns `FALSE`.

If *dwMilliseconds* is **INFINITE** (`0xFFFFFFFF`), the function will never time out. If *dwMilliseconds* is zero and there is no I/O operation to dequeue, the function will time out immediately.

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008 and Windows Server 2008 R2:** The *dwMilliseconds* value does include time spent in low-power states. For example, the timeout does keep counting down while the computer is asleep.

**Windows 8, Windows Server 2012, Windows 8.1, Windows Server 2012 R2, Windows 10 and Windows Server 2016:** The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not keep counting down while the computer is asleep.

*fAlertable* `[in]`

If this parameter is `FALSE`, the function does not return until the time-out period has elapsed or an entry is retrieved.

If the parameter is `TRUE` and there are no available entries, the function performs an alertable wait. The thread returns when the system queues an I/O completion routine or APC to the thread and the thread executes the function.

A completion routine is queued when the [ReadFileEx](/windows/win32/api/FileAPI/nf-fileapi-readfileex) or [WriteFileEx](/windows/win32/api/FileAPI/nf-fileapi-writefileex) function in which it was specified has completed, and the calling thread is the thread that initiated the operation. An APC is queued when you call [QueueUserAPC](/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc).

## Return value

Returns nonzero `TRUE` if successful or zero `FALSE` otherwise.

To get extended error information, call [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function associates a thread with the specified completion port. A thread can be associated with at most one completion port.

This function returns `TRUE` when at least one pending I/O is completed, but it is possible that one or more I/O operations failed. Note that it is up to the user of this function to check the list of returned entries in the *lpCompletionPortEntries* parameter to determine which of them correspond to any possible failed I/O operations by looking at the status contained in the **lpOverlapped** member in each [OVERLAPPED\_ENTRY](/windows/win32/api/MinWinBase/ns-minwinbase-overlapped_entry).

This function returns `FALSE` when no I/O operation was dequeued. This typically means that an error occurred while processing the parameters to this call, or that the *CompletionPort* handle was closed or is otherwise invalid. The [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function provides extended error information.

If a call to [GetQueuedCompletionStatusEx](/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) fails because the handle associated with it is closed, the function returns `FALSE` and [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return `ERROR_ABANDONED_WAIT_0`.

Server applications may have several threads calling the **GetQueuedCompletionStatusEx** function for the same completion port. As I/O operations complete, they are queued to this port in first-in-first-out order. If a thread is actively waiting on this call, one or more queued requests complete the call for that thread only.

For more information on I/O completion port theory, usage, and associated functions, see [I/O Completion Ports](i-o-completion-ports.md).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology                                | Supported |
|-------------------------------------------|-----------|
| Server Message Block (SMB) 3.0 protocol   | Yes       |
| SMB 3.0 Transparent Failover (TFO)        | Yes       |
| SMB 3.0 with Scale-out File Shares (SO)   | Yes       |
| Cluster Shared Volume File System (CsvFS) | Yes       |
| Resilient File System (ReFS)              | Yes       |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client | Windows Vista \[desktop apps \| UWP apps\] |
| Minimum supported server | Windows Server 2008 \[desktop apps \| UWP apps\] |
| Header | `IoAPI.h` (include `Windows.h`)<br/>`WinBase.h` on Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista (include `Windows.h`) |
| Library | `Kernel32.lib` |
| DLL | `Kernel32.dll` |

## See also

**Overview Topics**

[File Management Functions](file-management-functions.md)

[I/O Completion Ports](i-o-completion-ports.md)

[Using the Windows Headers](/windows/desktop/WinProg/using-the-windows-headers)

**Functions**

[ConnectNamedPipe](/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[CreateIoCompletionPort](createiocompletionport.md)

[DeviceIoControl](/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[LockFileEx](/windows/desktop/api/FileAPI/nf-fileapi-lockfileex)

[ReadFile](/windows/desktop/api/FileAPI/nf-fileapi-readfile)

[PostQueuedCompletionStatus](postqueuedcompletionstatus.md)

[TransactNamedPipe](/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe)

[WaitCommEvent](/windows/desktop/api/winbase/nf-winbase-waitcommevent)

[WriteFile](/windows/desktop/api/FileAPI/nf-fileapi-writefile)
