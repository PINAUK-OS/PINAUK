---
description: Learn about the PageBlackGenerationProcessingGrayComponentReplacementLevel element, which specifies the percentage of gray component replacement.
ms.assetid: e33634bb-5db5-4197-889d-82caf2e74191
title: PageBlackGenerationProcessingGrayComponentReplacementLevel
ms.topic: reference
ms.date: 05/31/2018
---

# PageBlackGenerationProcessingGrayComponentReplacementLevel

This topic is not current. For the most current information, see the [Print Schema Specification](https://download.microsoft.com/download/D/E/C/DECA6E6B-3E81-48E7-B7EF-6D92A547D03C/print-schema-spec-2-0.zip).

Specifies the percentage of gray component replacement to perform.

-   [Element Information](#element-information)
-   [Structure Content](#structure-content)

## Element Information



| Name | Value |
|----------------------------|------------------------------------------------------------|
| Element Type <br/>   | ParameterDef<br/>                                    |
| Scoping Prefix <br/> | Page<br/>                                            |
| Notes <br/>          | Linked to PageBlackGenerationProcessing element<br/> |



 

## Structure Content

The XML structure of this element is:

``` syntax
<psf:ParameterDef name="psk:PageBlackGenerationProcessingGrayComponentReplacementLevel">
  <psf:Property name="psf:DataType">
    <psf:Value xsi:type="xs:string">xs:integer</psf:Value>
  </psf:Property>
  <psf:Property name="psf:DefaultValue">
    <psf:Value xsi:type="xs:string">_Undefined_</psf:Value>
  </psf:Property>
  <psf:Property name="psf:MaxValue">
    <psf:Value xsi:type="xs:integer">100</psf:Value>
  </psf:Property>
  <psf:Property name="psf:MinValue">
    <psf:Value xsi:type="xs:integer">0</psf:Value>
  </psf:Property>
  <psf:Property name="psf:Multiple">
    <psf:Value xsi:type="xs:integer">1</psf:Value>
  </psf:Property>
  <psf:Property name="psf:Mandatory">
    <psf:Value xsi:type="xs:string">psk:Conditional</psf:Value>
  </psf:Property>
  <psf:Property name="psf:UnitType">
    <psf:Value xsi:type="xs:string">percent</psf:Value>
  </psf:Property>
</psf:ParameterDef>
```

## Structure Properties

The following table outlines the characteristics of the variables defined in the XML structure.



| Property                | xsi:type           | Value                      |
|-------------------------|--------------------|----------------------------|
| DataType<br/>     | string<br/>  | xs:integer<br/>      |
| DefaultValue<br/> | string<br/>  | undefined<br/>       |
| MaxValue<br/>     | integer<br/> | 100<br/>             |
| MinValue<br/>     | integer<br/> | 0<br/>               |
| Multiple<br/>     | integer<br/> | 1<br/>               |
| Mandatory<br/>    | string<br/>  | psk:Conditional<br/> |
| UnitType<br/>     | string<br/>  | percent<br/>         |



 

## Related topics

<dl> <dt>

[Print Schema Specification](https://download.microsoft.com/download/D/E/C/DECA6E6B-3E81-48E7-B7EF-6D92A547D03C/print-schema-spec-2-0.zip)
</dt> </dl>

 

 




