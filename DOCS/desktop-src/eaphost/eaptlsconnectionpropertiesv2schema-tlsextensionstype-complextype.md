---
title: TLSExtensionsType Complex Type
description: Learn about the TLSExtensionsType complex type. This type enables future enhancements to the schema.
ms.assetid: 5e4f8ef8-1adb-4683-8001-ba7d2d392523
ms.topic: reference
ms.date: 05/31/2018
---

# TLSExtensionsType Complex Type

The **TLSExtensionsType** complex type enables future enhancements to the schema.

```XML
<xs:complexType name="TLSExtensionsType">
    <xs:sequence>
        <xs:any processContents="lax" 
            minOccurs="0" 
            maxOccurs="unbounded" 
            namespace="##other"
        />
    <xs:sequence>
</xs:complexType>

```

## Remarks

The **TLSExtensionsType** element is optional.

## See also

- [EAPHost and Legacy Schema](eaphost-schemas.md)
- [eaptlsconnectionpropertiesv2](eaptlsconnectionpropertiesv2schema-schema.md)
- [eaptlsconnectionpropertiesv2 Complex Types](eaptlsconnectionpropertiesv2schema-complex-types.md)
- [**TLSExtensions (TLSExtensionsType)**](eaptlsconnectionpropertiesv2schema-performservervalidation-eaptype-element.md)
