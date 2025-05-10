---
description: This section contains the reference for the system APIs and services offered by Windows for desktop apps.
ms.assetid: 3a3dc403-8bad-4464-9dda-361daaf8f8d3
title: System Services
ms.topic: reference
ms.date: 01/29/2024
---

# System Services

This section contains the reference for the system APIs and services offered by Windows for desktop apps. These include the traditionally available services for:

- The Component Object Model (COM).
- File compression.
- Dynamic-link libraries.
- Memory management.
- Power management.
- Secure Enclaves (Trusted Execution).
- The creation and coordination of multiple threads of execution.
- The development of service applications.
- Windows messaging.
- Obtaining Windows system information.
- The Help API.

## In this section

| Topic | Description |
|--------|--------|
| [COM](./com/component-object-model--com--portal.md) | COM is a platform-independent, distributed, object-oriented system for creating binary software components that can interact. COM is the foundation technology for Microsoft's OLE (compound documents) and ActiveX (Internet-enabled components) technologies. |
| [COM+](./cossdk/component-services-portal.md) | COM+ is an evolution of Microsoft Component Object Model (COM) and Microsoft Transaction Server (MTS). COM+ builds on and extends applications written using COM, MTS, and other COM-based technologies. COM+ handles many of the resource management tasks that you previously had to program yourself, such as thread allocation and security. COM+ also makes your applications more scalable by providing thread pooling, object pooling, and just-in-time object activation. COM+ also helps protect the integrity of your data by providing transaction support, even if a transaction spans multiple databases over a network. |
| [Activity Coordinator](./activity_coordinator/-activity-coordinator-portal.md) | The Activity Coordinator API coordinates execution of deferrable tasks on a system. Deferrable tasks are those tasks which don’t need to be run immediately. They can defer their execution to a time when the system is in a desired state where running the task does not interfere with other ongoing work. |
| [Compression API](./cmpapi/-compression-portal.md) | The Compression API exposes the Windows MSZIP, XPRESS, XPRESS\_HUFF, and LZMS compression algorithms. This enables developers of Windows applications to manage versions, service, and extend the exposed compression algorithms. |
| [Distributed Transaction Coordinator](/previous-versions/windows/desktop/ms684146(v=vs.85)) | Guide and reference documentation for system administrators and developers using the Distributed Transaction Coordinator (DTC). |
| [Microsoft.Dtc.PowerShell.Diagnostics](/previous-versions//hh438328(v=vs.85)) | Provides information about the PowerShell cmdlets provided with Microsoft Distributed Transaction Coordinator (MSDTC) for diagnostics. |
| [Microsoft.MsDtcManagement.Commands](/previous-versions//hh438356(v=vs.85)) | Provides information about the PowerShell cmdlets provided with Microsoft Distributed Transaction Coordinator (MSDTC) for management. |
| [Dynamic Link Libraries](./dlls/dynamic-link-libraries.md) | How to create and manage DLLs. |
| [Help API](/previous-versions/windows/desktop/helpapi/helpapi-portal) | The Help API allows the opening of help catalogs and the retrieval of help content items. |
| [Interprocess Communications](./ipc/interprocess-communications.md) | How to use mailslots and pipes. |
| [Kernel Transaction Manager](./ktm/kernel-transaction-manager-portal.md) | How to use transacted file and registry operations, or define transactions for other resources. |
| [Memory Management](./memory/memory-management.md) | Core memory management services. |
| [MultiPoint Services](/previous-versions/windows/desktop/multipoint/windows-multipoint-server-portal) | Server role that allows multiple users to simultaneously use the same computer, such as in a classroom environment. |
| [Operation Recorder](/previous-versions/windows/desktop/oprec/-operation-portal) | Operation Recorder enables applications to speed up operations that repeatedly access the same file data by exposing the Windows prefetching mechanism as a public interface. |
| [Power Management](./power/power-management-portal.md) | Core power management services. |
| [Processes and Threads](./procthread/processes-and-threads.md) | How to create and manage processes and threads. |
| [Remote Desktop Services](./termserv/terminal-services-portal.md) | How to programmatically interact with Remote Desktop Services. |
| [Secure Enclaves](./trusted-execution/enclaves.md) | Secure enclaves are used to create trusted execution environments. |
| [Services](./services/services.md) | How to create and manage services. |
| [Synchronization](./sync/synchronization.md) | How to coordinate multiple threads of execution. |
| [Windows Desktop Sharing](/previous-versions/windows/desktop/rdp/rdp-portal) | Windows Desktop Sharing is a multiple-party screen-sharing technology. Key scenarios include remote assistance, real-time collaboration and conferencing, and video communication. |
| [Windows Notification Framework](/previous-versions/windows/desktop/wnf/windows-setup-and-migration-portal) | Documents the functions (and function callback prototypes) used to detect and possibly repair an application after a setup or migration has occurred. |
| [Windows Subsystem for Linux](/previous-versions/windows/desktop/wsl/windows-subsystem-for-linux-portal) | Reference information for the Windows Subsystem for Linux (WSL) programming interfaces. |
| [Windows System Information](./sysinfo/windows-system-information.md) | How to programmatically access the registry and key system configuration and version information. |
