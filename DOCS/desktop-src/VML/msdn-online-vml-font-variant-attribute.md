---
title: VML Font-Variant Attribute
description: VML Font-Variant Attribute
ms.assetid: f58bf3e0-e285-474c-83b1-203fce4f3c3a
ms.topic: reference
ms.date: 05/31/2018
---

# VML Font-Variant Attribute

This topic describes VML, a feature that is deprecated as of Windows Internet Explorer 9. Webpages and applications that rely on VML should be migrated to SVG or other widely supported standards.

> [!Note]  
> As of December 2011, this topic has been archived. As a result, it is no longer actively maintained. For more information, see [Archived Content](/previous-versions/windows/internet-explorer/ie-developer/). For information, recommendations, and guidance regarding the current version of Windows Internet Explorer, see [Internet Explorer Developer Center](https://msdn.microsoft.com/ie/).

 

Defines the variant style of a font. Read/write. **String**.

**Applies To**

[TextPath](msdn-online-vml-textpath-element.md)

**Tag Syntax**

<v: *element* style="font-variant: *expression* ">

**Script Syntax**

*element* .style.fontvariant="*expression*"

*expression*=*element*.style.fontvariant

**Remarks**

The values are:

-   normal (default)
-   small-caps

The values are the same as the standard HTML style attributes.

*VML Standard Attribute*

**Example**

The font is rendered as small capital letters.


```HTML
   <v:line from="50 100" to="400 100">
   <v:fill on="True" color="red"/>
   <v:path textpathok="True"/>
   <v:textpath on="True" string="VML Text"
   style="font:normal small-caps normal 36pt Arial"/>
   </v:line>
```



 

 
