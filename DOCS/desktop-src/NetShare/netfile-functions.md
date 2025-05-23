---
description: The network file functions provide a way to monitor and close the file, device, and pipe resources open on a server. The file functions are listed following.
ms.assetid: cbcdad6e-80dd-49f0-9d69-a82a7010f10b
title: NetFile Functions (Network Share Management)
ms.topic: reference
ms.date: 05/31/2018
---

# NetFile Functions (Network Share Management)

The network file functions provide a way to monitor and close the file, device, and pipe resources open on a server. The file functions are listed following.



| Function                                 | Description                                                          |
|------------------------------------------|----------------------------------------------------------------------|
| [**NetFileClose**](/windows/desktop/api/Lmshare/nf-lmshare-netfileclose)     | Forces a resource to close.                                          |
| [**NetFileEnum**](/windows/desktop/api/Lmshare/nf-lmshare-netfileenum)       | Returns information about open files on a server.                    |
| [**NetFileGetInfo**](/windows/desktop/api/Lmshare/nf-lmshare-netfilegetinfo) | Returns information about a particular opening of a server resource. |



 

Call the [**NetFileClose**](/windows/desktop/api/Lmshare/nf-lmshare-netfileclose) function when the file cannot be closed by any other means. This function should be used with caution because **NetFileClose** does not write data cached on the client system to the file before closing the file.

The [**NetFileEnum**](/windows/desktop/api/Lmshare/nf-lmshare-netfileenum) function returns information about resources open on a server. A file can be opened one or more times by one or more applications. Each file opening is uniquely identified. The **NetFileEnum** function returns an entry for each file opening. The [**NetFileGetInfo**](/windows/desktop/api/Lmshare/nf-lmshare-netfilegetinfo) function returns information about one opening of a resource.

File information is available at the following levels.

<dl>

[**FILE\_INFO\_2**](/windows/desktop/api/Lmshare/ns-lmshare-file_info_2)  
[**FILE\_INFO\_3**](/windows/desktop/api/Lmshare/ns-lmshare-file_info_3)  
</dl>

Levels 0 and 1 are not supported. Level 2 returns only the identification number assigned to the resource when it was opened. Level 3 returns the identification number, permissions, file locks, and the name of the user who opened the resource.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the [**NetFileEnum**](/windows/desktop/api/Lmshare/nf-lmshare-netfileenum) and [**NetFileGetInfo**](/windows/desktop/api/Lmshare/nf-lmshare-netfilegetinfo) functions. For more information, see [**IADsResource**](/windows/desktop/api/iads/nn-iads-iadsresource) and [**IADsFileServiceOperations**](/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations).

 

 
