---
title: EAPHost and Legacy Schema
description: This article describes the EAPHost schema and legacy schema for creating configuration XML and credential XML.
ms.assetid: d4572866-7e2b-4e7c-afe1-66394b549bc4
ms.topic: reference
ms.date: 07/10/2023
---

# EAPHost and Legacy Schema

This topic describes the EAPHost schema and legacy schema for creating configuration XML and credential XML.

## About EAPHost and Legacy Schema

Creating configuration XML commences with the [eaphostconfig](eaphostconfigschema-schema.md) schema; creating credential XML commences with the [eaphostusercredentials](eaphostusercredentialsschema-schema.md) schema.

Several of the native and legacy schema contain common schema elements. Common elements used in method configuration and method credentials are abstracted into a single schema file, referred to as the "common schema".

The terms "method configuration" and "connection properties" are used interchangeably. Likewise, the terms "method credentials" and "user properties" are also used interchangeably.

## EAPHost Schema

| Schema                                                                       | Description                                        |
|------------------------------------------------------------------------------|----------------------------------------------------|
| [baseeapmethodconfig](baseeapmethodconfigschema-schema.md)                   | Contains common configuration schema elements.     |
| [baseeapmethodusercredentials](baseeapmethodusercredentialsschema-schema.md) | Contains common credential schema elements.        |
| [eapcommon](eapcommonschema-schema.md)                                       | Contains the **EapMethodType** element definition. |
| [eaphostconfig](eaphostconfigschema-schema.md)                               | Contains EAPHost configuration schema.             |
| [eaphostusercredentials](eaphostusercredentialsschema-schema.md)             | Contains EAPHost credential schema.                |

## Legacy Schema

| Schema | Description |
|--------|--------|
| [baseeapconnectionpropertiesv1](baseeapconnectionpropertiesv1schema-schema.md)         | Contains common configuration schema elements.                                               |
| [baseeapuserpropertiesv1](baseeapuserpropertiesv1schema-schema.md)                     | Contains common credential schema elements.                                                  |
| [eapconnectionpropertiesv1](eapconnectionpropertiesv1schema-schema.md)                 | Contains common configuration schema elements.                                               |
| [eapuserpropertiesv1](eapuserpropertiesv1schema-schema.md)                             | Contains common credential schema elements.                                                  |
| [eapsimconnectionpropertiesv1](eapsimconnectionpropertiesv1schema-schema.md)           | Is used with EAP-SIM to describe authentication configuration data.                         |
| [eapteapconnectionpropertiesv1](eapteapconnectionpropertiesv1schema-schema.md)         | Is used with EAP-TEAP to describe authentication configuration data.                         |
| [eaptlsconnectionpropertiesv1](eaptlsconnectionpropertiesv1schema-schema.md)           | Is used with EAP-TLS to describe authentication configuration data.                          |
| [eaptlsconnectionpropertiesv2](eaptlsconnectionpropertiesv2schema-schema.md)           | Is used with EAP-TLS to describe authentication configuration data beginning with Windows 7. |
| [eaptlsconnectionpropertiesv3](eaptlsconnectionpropertiesv3schema-schema.md)           | Is used with EAP-TLS to describe authentication configuration data beginning with Windows 8. |
| [eaptlsuserpropertiesv1](eaptlsuserpropertiesv1schema-schema.md)                       | Is used with EAP-TLS to describe authentication credentials and credential options.          |
| [eapttlsconnectionpropertiesv1](eapttlsconnectionpropertiesv1schema-schema.md)         | Is used to specify configuration settings for the Microsoft EAP implementation of the TTLS method beginning with Windows 8. |
| [mschapv2connectionpropertiesv1](mschapv2connectionpropertiesv1schema-schema.md)       | Is used with MS-CHAPv2 to describe authentication configuration data.                        |
| [mschapv2userpropertiesv1](mschapv2userpropertiesv1schema-schema.md)                   | Is used with MS-CHAPv2 to describe authentication credentials and credential options.        |
| [mspeapconnectionpropertiesv1](mspeapconnectionpropertiesv1schema-schema.md)           | Is used with PEAPv0 to describe authentication configuration data.                           |
| [mspeapconnectionpropertiesv2](mspeapconnectionpropertiesv2schema-schema.md)           | Is used with PEAPv0 to describe authentication configuration data beginning with Windows 7.  |
| [mspeapconnectionpropertiesv3](mspeapconnectionpropertiesv3schema-schema.md)           | Is used with PEAPv0 to describe authentication configuration data beginning with Windows 8.  |
| [mspeapuserpropertiesv1](mspeapuserpropertiesv1schema-schema.md)                       | Is used with PEAPv0 to describe authentication credentials and credential options.           |
| [eapakaconnectionpropertiesv1](eapakaconnectionpropertiesv1schema-schema.md)           | Is used with EAP-AKA to describe authentication configuration data.                         |
| [eapakaprimeconnectionpropertiesv1](eapakaprimeconnectionpropertiesv1schema-schema.md) | Is used with EAP-AKA to describe authentication configuration data.                         |

## Related content

[Components of EAPHost](eaphost-components.md)
