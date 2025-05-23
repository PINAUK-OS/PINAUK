---
description: The WMI log files are no longer supported.
ms.assetid: 4ba80063-7aa6-42df-a620-1b366b795034
ms.tgt_platform: multiple
title: Logging WMI Activity
ms.topic: how-to
ms.date: 05/31/2018
---

# Logging WMI Activity

The WMI log files are no longer supported. Starting with Windows Vista, WMI uses [Event Tracing for Windows (ETW](/windows/desktop/ETW/event-tracing-portal)) and events that are available through the **Event Viewer** UI or the Wevtutil command line tool. For more information, see the ETW provider and the [Wevutil](/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/cc732848(v=ws.11)) command-line documentation.

The following sections are discussed in this topic:

-   [WMI Log Files Before Windows Vista](#wmi-log-files-before-windows-vista)
-   [Logging Activities for WMI Core Components Before Windows Vista](#logging-activities-for-wmi-core-components-before-windows-vista)
-   [Logging Activities for WMI Provider Components Before Windows Vista](#logging-activities-for-wmi-provider-components-before-windows-vista)
-   [Related topics](#related-topics)

## WMI Log Files Before Windows Vista

The log files created by WMI and various providers record: events, trace or diagnostic data, errors, and various activities. Only administrators have read access to the WMI log folder found at %windir%\\system32\\wbem\\logs.

Only WMI core components or WMI providers write to log files. You can only read or view the data in these logs for diagnostic purposes. You can create and store your own log files in the WMI log directory.

## Logging Activities for WMI Core Components Before Windows Vista

These files do not contain a consistent format that is suitable for reading programmatically. For more information about specific logs, see [WMI Log Files](wmi-log-files.md).

Logging activities for WMI core components occurs when the following registry keys are set:

-   Logging level

    Changes to the logging level registry value take effect immediately. No restart of the WMI service is necessary.

    **HKEY\_LOCAL\_MACHINE**\\**SOFTWARE**\\**Microsoft**\\**WBEM**\\**CIMOM**\\**Logging** = 2

    The following list lists the logging levels that can be defined in the registry.

    

    | Logging level | Description               |
    |---------------|---------------------------|
    | 0             | No Logging                |
    | 1             | Log only errors           |
    | 2             | Verbose Logging (default) |

    

     

-   Log file location

    For changes to log file location to take effect, restart the WMI service.

    **HKEY\_LOCAL\_MACHINE**\\**SOFTWARE**\\**Microsoft**\\**WBEM**\\**CIMOM**\\**Logging Directory** = %windir%\\system32\\wbem\\logs

-   Maximum log file size, in bytes

    **HKEY\_LOCAL\_MACHINE**\\**SOFTWARE**\\**Microsoft**\\**WBEM**\\**CIMOM**\\**Log File Max Size** = 65536

You can change these registry key values through the Registry Editor or through the WMI snap-in for the Microsoft Management Console.

**To set the logging level for WMI before Windows Vista**

1.  Click **Start**, and then click **Run**.
2.  Type **wmimgmt.msc**
3.  On the **Action** menu, click **Properties**.
4.  On the **Logging** tab, set the logging level to **Disabled**, **Enabled**, or **Verbose**.
5.  In **Location:**, type the path to the log file folder and in **Maximum size (bytes):**, set the maximum size, in bytes, of the log file.

For more information about setting the log file properties, see the online Help for the WMI Control application.

## Logging Activities for WMI Provider Components Before Windows Vista

When logging for WMI core components is enabled, logging is also enabled for any provider with logging capabilities.

The following list lists the required values.

<dl> <dt>

<span id="File"></span><span id="file"></span><span id="FILE"></span>**File**
</dt> <dd>

Full path and file name of the log file. The default value is %windir%\\system32\\wbem\\logs. The **Type** named value must be set to = File for this named value to be used.

</dd> <dt>

<span id="Level"></span><span id="level"></span><span id="LEVEL"></span>**Level**
</dt> <dd>

A 32-bit logical mask that defines the type of debugging output generated by the provider. This value is provider-dependent. The default value is 0 (zero).

</dd> <dt>

<span id="MaxFileSize"></span><span id="maxfilesize"></span><span id="MAXFILESIZE"></span>**MaxFileSize**
</dt> <dd>

Maximum file size, in bytes, of the log file. This integer value must be in the range 1024 to 2^32-1. When the file size exceeds this value, the file is renamed to **~filename** and a new, empty log file is created. The disk space required for the log file is twice the value of **MaxFileSize**. The default value is 65,535.

</dd> <dt>

<span id="Type"></span><span id="type"></span><span id="TYPE"></span>**Type**
</dt> <dd>

Can be set to = File or = Debugger. If set to = File, the trace information is written to the log file specified in the **File** named value. The default value is = File.

</dd> </dl>

For example, to log query and get instance calls from the View Provider, use the following registry key values. The log will be located in the log folder and will be the default file size.

**HKEY\_LOCAL\_MACHINE**\\**SOFTWARE**\\**Microsoft**\\**WBEM**\\**PROVIDERS**\\**Logging**\\**ViewProvider**\\**File** = C:\\Windows\\system32\\WBEM\\Logs\\ViewProvider.log

**HKEY\_LOCAL\_MACHINE**\\**SOFTWARE**\\**Microsoft**\\**WBEM**\\**PROVIDERS**\\**Logging**\\**ViewProvider**\\**Level** = 2

**HKEY\_LOCAL\_MACHINE**\\**SOFTWARE**\\**Microsoft**\\**WBEM**\\**PROVIDERS**\\**Logging**\\**ViewProvider**\\**MaxFileSize** = 65535

**HKEY\_LOCAL\_MACHINE**\\**SOFTWARE**\\**Microsoft**\\**WBEM**\\**PROVIDERS**\\**Logging**\\**ViewProvider**\\**Type** = File

> [!Note]  
> For your own providers with logging capabilities, you need to write the necessary registry keys and values to enable logging.

 

## Related topics

<dl> <dt>

[WMI Troubleshooting](wmi-troubleshooting.md)
</dt> <dt>

[WMI Log Files](wmi-log-files.md)
</dt> <dt>

[WMI Troubleshooting Classes](wmi-troubleshooting-classes.md)
</dt> <dt>

[Tracing WMI Activity](tracing-wmi-activity.md)
</dt> </dl>

 

 
