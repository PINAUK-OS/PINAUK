---
description: Microsoft introduced the data protection application programming interface (DPAPI) in Windows.
ms.assetid: 048DEA72-39E1-4129-A554-F7D08442C2D9
title: CNG DPAPI
ms.topic: concept-article
ms.date: 06/06/2023
---

# CNG DPAPI

Microsoft introduced the data protection application programming interface (DPAPI) in Windows. The API consists of two functions, [**CryptProtectData**](/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata). DPAPI is part of CryptoAPI and was intended for developers who knew very little about using cryptography. The two functions could be used to encrypt and decrypt static data on a single computer.

Cloud computing, however, often requires that content encrypted on one computer be decrypted on another. Therefore, beginning with Windows 8, Microsoft extended the idea of using a relatively straightforward API to encompass cloud scenarios. This new API, called DPAPI-NG, enables you to securely share secrets (keys, passwords, key material) and messages by protecting them to a set of principals that can be used to remove protection from them on different computers after proper authentication and authorization. The following principals are currently supported:

- A group in an Active Directory forest.
- Web credentials.

For more information, see the following topics:

- [Protection Providers](protection-providers.md)
- [Protection Descriptors](protection-descriptors.md)
- [Protected Data Format](protected-data-format.md)
- [DPAPI backup keys on Active Directory domain controllers](cng-dpapi-backup-keys-on-ad-domain-controllers.md)

DPAPI-NG is built on top of Cryptography Next Generation (CNG) and includes the following functions:

- [**NCryptCreateProtectionDescriptor**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptcreateprotectiondescriptor)
- [**NCryptCloseProtectionDescriptor**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptcloseprotectiondescriptor)
- [**NCryptProtectSecret**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptprotectsecret)
- [**NCryptQueryProtectionDescriptorName**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptqueryprotectiondescriptorname)
- [**NCryptRegisterProtectionDescriptorName**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptregisterprotectiondescriptorname)
- [**NCryptStreamClose**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptstreamclose)
- [**NCryptStreamOpenToProtect**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect)
- [**NCryptStreamOpenToUnprotect**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptstreamopentounprotect)
- [**NCryptStreamUpdate**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptstreamupdate)
- [**NCryptUnprotectSecret**](/windows/win32/api/NCryptprotect/nf-ncryptprotect-ncryptunprotectsecret)
