---
description: Retrieves a specified number of random bytes from the system random number generator.
ms.assetid: 04746229-9dc1-4748-80c1-f1960bd1b768
title: SystemPrng function
ms.topic: reference
ms.date: 02/14/2025
topic_type: 
- APIRef
- kbSyntax
api_name: 
- SystemPrng
api_type: 
- DllExport
api_location: 
- Ksecdd.sys
- Cng.sys
---

# SystemPrng function

\[**SystemPrng** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [**BCryptGenRandom**](/windows/desktop/api/Bcrypt/nf-bcrypt-bcryptgenrandom).\]

The **SystemPrng** function retrieves a specified number of random bytes from the system random number generator.

> [!NOTE]  
> This function has no associated header file or import library. To call this function, you must create a user-defined header file.

## Syntax

```C++
BOOL SystemPrng(
  _Out_ PBYTE  pbRandomData,
        SIZE_T cbRandomData
);
```

## Parameters

<dl> <dt>

*pbRandomData* \[out\]
</dt> <dd>

A pointer to a buffer that receives the retrieved bytes.

</dd> <dt>

*cbRandomData* \[in\]
</dt> <dd>

The number of bytes to retrieve.

</dd> </dl>

## Return value

Always returns **TRUE**.

## Requirements

| Requirement | Value |
|--------|--------|
| Minimum supported client | Windows Vista with SP1 \[desktop apps only\] |
| Minimum supported server | Windows Server 2008 \[desktop apps only\] |
| DLL                      | `Ksecdd.sys` on Windows Server 2008 and Windows Vista with SP1<br/>`Cng.sys` on Windows 7 and Windows Server 2008 R2 |
