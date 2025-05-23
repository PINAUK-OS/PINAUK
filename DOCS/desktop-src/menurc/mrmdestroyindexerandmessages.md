---
title: MrmDestroyIndexerAndMessages function (MrmResourceIndexer.h)
description: Releases resources associated with a resource indexer.
ms.assetid: AD770F40-BEDB-46C3-9527-DC46169C6193
keywords:
- MrmDestroyIndexerAndMessages function Menus and Other Resources
topic_type:
- apiref
api_name:
- MrmDestroyIndexerAndMessages
api_location:
- Mrmsupport.dll
api_type:
- DllExport
ms.topic: reference
ms.date: 05/31/2018
---

# MrmDestroyIndexerAndMessages function

Releases resources associated with a resource indexer. Destroys the handle, frees the indexer, and deletes any messages
retrieved via **MrmPeekResourceIndexerMessages**. 

Note this *does not* free memory allocated via functions such as **MrmCreateConfigInMemory** or 
**MrmCreateResourceFileInMemory** that produce outputs; that memory must be freed by using **MrmFreeMemory**, 
as outlined in the specific API topics.

## Syntax


```C++
HRESULT HRESULT MrmDestroyIndexerAndMessages(
  _In_ MrmResourceIndexerHandle indexer
);
```


## Parameters

<dl> <dt>

*indexer* \[in\]
</dt> <dd>

Type: **[**MrmResourceIndexerHandle**](mrmresourceindexerhandle.md)**

A handle identifying the resource indexer to destroy.

</dd> </dl>

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h) 
to determine success or failure.

## Requirements



| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br/> | Windows 10, version 1803 \[desktop apps only\]<br/>                                       |
| Minimum supported server<br/> | Windows Server \[desktop apps only\]<br/>                                                 |
| Header<br/>                   | <dl> <dt>MrmResourceIndexer.h</dt> </dl> |
| Library<br/>                  | <dl> <dt>Mrmsupport.lib</dt> </dl>       |
| DLL<br/>                      | <dl> <dt>Mrmsupport.dll</dt> </dl>       |



## See also

<dl> <dt>

[**MrmFreeMemory**](mrmfreememory.md)
</dt></dl>
<dl> <dt>

[Package resource indexing (PRI) APIs and custom build systems](/windows/uwp/app-resources/pri-apis-custom-build-systems)
</dt> </dl>

 

