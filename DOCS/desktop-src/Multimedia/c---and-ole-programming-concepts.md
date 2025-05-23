---
title: C++ and OLE Programming Concepts
description: C++ and OLE Programming Concepts
ms.assetid: 2c6c3f29-aa5d-4e55-8c4d-16c5fb223fb9
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# C++ and OLE Programming Concepts

\[The feature associated with this page, [Custom File and Stream Handlers](/windows/win32/multimedia/custom-file-and-stream-handlers), is a legacy feature. It has been superseded by [MediaStreamSource class](/uwp/api/Windows.Media.Core.MediaStreamSource). **MediaStreamSource class** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaStreamSource class** instead of **Custom File and Stream Handlers**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The file and stream handlers included with Windows use an object-oriented design to promote a standard interface and to share functionality. These handlers are written in C++ and use the OLE Component Object Model.

You can develop custom handlers using the C or C++ development systems; however, using C++ is strongly recommended, because it provides an easier and more straightforward approach to implement a handler. Using C++, you can explicitly define data as objects, and you can associate the functions that manipulate the data with the member functions of an object.

This section identifies and briefly summarizes the important concepts of C++ and the OLE Component Object Model that apply to designing and implementing file and stream handlers. There are many books written about C++ programming that you can reference for more information. For more information on OLE, please see the *OLE Programmer's Reference*.

 

 




