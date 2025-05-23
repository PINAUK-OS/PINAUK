---
title: Installing Custom I/O Procedures
description: Installing Custom I/O Procedures
ms.assetid: 7b26a062-fa52-4de3-b8c8-b9f9167068fc
keywords:
- multimedia file I/O,custom procedures
- file I/O,custom procedures
- input and output (I/O),custom procedures
- I/O (input and output),custom procedures
- installing custom I/O procedures
- custom I/O
- mmioInstallIOProc function
ms.topic: install-set-up-deploy
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Installing Custom I/O Procedures

\[The feature associated with this page, [Multimedia File I/O](/windows/win32/multimedia/multimedia-file-i-o), is a legacy feature. It has been superseded by [Source Reader](/windows/win32/medfound/source-reader). **Source Reader** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** instead of **Multimedia File I/O**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

To install an I/O procedure associated with the .ARC filename extension, use the [**mmioInstallIOProc**](/windows/win32/api/mmiscapi/nf-mmiscapi-mmioinstallioproc) function as follows:


```C++
mmioInstallIOProc (mmioFOURCC('A', 'R', 'C', ' '), 
    (LPMMIOPROC)lpmmioproc, MMIO_INSTALLPROC); 
```



When you install an I/O procedure using [**mmioInstallIOProc**](/windows/win32/api/mmiscapi/nf-mmiscapi-mmioinstallioproc), the procedure remains installed until you remove it. The I/O procedure is used for any file you open as long as the file has the appropriate filename extension.

You can also temporarily install an I/O procedure by using the [**mmioOpen**](/windows/win32/api/mmiscapi/nf-mmiscapi-mmioopen) function. In this case, the I/O procedure is used only with a file opened by using **mmioOpen** and is removed when the file is closed by using the [**mmioClose**](/windows/win32/api/mmiscapi/nf-mmiscapi-mmioclose) function. To specify an I/O procedure when you open a file by using **mmioOpen**, use the *lpmmioinfo* parameter to reference an [**MMIOINFO**](/previous-versions//dd757322(v=vs.85)) structure as follows:

1.  Set the **fccIOProc** member to **NULL**.
2.  Set the **pIOProc** member to the procedure-instance address of the I/O procedure.
3.  Set all other members to zero (unless you are opening a memory file, or directly reading or writing to the file I/O buffer).

Be sure to remove any I/O procedures you have installed before you exit your application.

 

 
