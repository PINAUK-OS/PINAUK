---
title: Using Custom Sinks
description: Using Custom Sinks
ms.assetid: 7151583a-c7ab-40b0-a7bf-ddd56f93b7aa
keywords:
- Advanced Systems Format (ASF),custom sinks
- ASF (Advanced Systems Format),custom sinks
- Advanced Systems Format (ASF),sinks
- ASF (Advanced Systems Format),sinks
- sinks,custom sinks
- custom sinks,about
- writer sinks,custom sinks
- custom sinks,IWMWriterSink interface
- IWMWriterSink
- writer sinks,IWMWriterSink interface
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Using Custom Sinks

\[The feature associated with this page, [Windows Media Format 11 SDK](/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](/windows/win32/medfound/source-reader) and [Sink Writer](/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

If you have a special writing need, you can create your own writer sinks. The writer maintains one-way communication with a sink by making calls to the methods of [**IWMWriterSink**](/previous-versions/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwritersink). To create your own sink, implement the **IWMWriterSink** interface in a class in your application. This process is very similar to implementing any other callback interface used by the objects of the Windows Media Format SDK. For more information about callbacks, see [Using the Callback Methods](using-the-callback-methods.md).

The buffer received in [**IWMWriterSink::OnHeader**](/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmwritersink-onheader) should be written to the beginning of the file, and all buffers received in [**OnDataUnit**](/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmwritersink-ondataunit) should be written out sequentially. **OnHeader** will be called at the beginning but might be called at other times, too, and if it is, you should, if possible, overwrite the original header. If your application is not able to do this for some reason, then simply ignore the subsequent **OnHeader** calls.

Your custom sink should communicate its status to your writing application by making calls to the [**IWMStatusCallback::OnStatus**](/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback method. If you implement your sink as a COM object, you may want to expose the [**IWMRegisterCallback**](/previous-versions/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistercallback) interface. However, you can pass the address of the **OnStatus** callback to your sink and set a context in any way you like.

## Related topics

<dl> <dt>

[**Working with Writer Sinks**](working-with-writer-sinks.md)
</dt> </dl>

 

 




