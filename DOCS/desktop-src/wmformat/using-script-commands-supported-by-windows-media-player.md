---
title: Using Script Commands Supported by Windows Media Player
description: Using Script Commands Supported by Windows Media Player
ms.assetid: 7054ce49-c000-4978-891e-825a83bfda5c
keywords:
- Windows Media Format SDK,script commands
- Windows Media Format SDK,Windows Media Player
- Advanced Systems Format (ASF),script commands
- ASF (Advanced Systems Format),script commands
- Advanced Systems Format (ASF),Windows Media Player
- ASF (Advanced Systems Format),Windows Media Player
- scripts,commands
- scripts,Windows Media Player
- Windows Media Player
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Using Script Commands Supported by Windows Media Player

\[The feature associated with this page, [Windows Media Format 11 SDK](/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](/windows/win32/medfound/source-reader) and [Sink Writer](/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The Windows Media Format SDK does not provide native support for parsing and responding to script commands. You must include any logic related to script commands in your application. The script types that you use must also be defined in your application.

You can include code to handle the same script commands that are supported by Windows Media Player. Maintaining compatibility with Windows Media Player makes your files more universal than if you embed custom script commands.

The following table lists script types that are supported by Windows Media Player.



| Script type | Description                                                                                                                                                                                                                                                                              |
|-------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| URL         | The player sends the specified URL to the browser for display to the user. If an embedded player control is being used, you can add a specific frame reference to the URL by using the &&*framename* syntax.                                                                             |
| FILENAME    | A URL to another media file to be played.                                                                                                                                                                                                                                                |
| CAPTION     | A text string that is displayed in the captions area of Windows Media Player. This type supports standard HTML formatting, so the text can be formatted as you wish. An example of use is closed captioning.                                                                             |
| EVENT       | The name of an event that is to occur. The EVENT type supports customization for your own uses. The code for the specified event must be defined in the Windows Media metafile for the stream in order for the player to perform the specified event. An example of use is ad insertion. |
| OPENEVENT   | This script precedes the actual EVENT. The OPENEVENT allows the player to pre-buffer the content so that when the EVENT occurs, the switch between streams appears to be seamless.                                                                                                       |
| TEXT        | A TEXT string that is displayed in the captions area of Windows Media Player. Can be plain text, SAMI, or HTML formatted text.                                                                                                                                                           |



 

## Related topics

<dl> <dt>

[**Using Script Commands**](using-script-commands.md)
</dt> </dl>

 

 




