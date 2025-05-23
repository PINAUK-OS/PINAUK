---
title: VML Left Attribute
description: VML Left Attribute
ms.assetid: a0558d24-c0a5-48ef-9042-743d6eab6f86
ms.topic: reference
ms.date: 05/31/2018
---

# VML Left Attribute

This topic describes VML, a feature that is deprecated as of Windows Internet Explorer 9. Webpages and applications that rely on VML should be migrated to SVG or other widely supported standards.

> [!Note]  
> As of December 2011, this topic has been archived. As a result, it is no longer actively maintained. For more information, see [Archived Content](/previous-versions/windows/internet-explorer/ie-developer/). For information, recommendations, and guidance regarding the current version of Windows Internet Explorer, see [Internet Explorer Developer Center](https://msdn.microsoft.com/ie/).

 

Determines the position of the shape relative to the element left of it in the document flow. Read/write. **String**.

**Applies To**

[Shape](shape-element--vml.md)

**Tag Syntax**

<v: *element* style="left: *expression* ">

**Script Syntax**

*element* .style.left="*expression*"

*expression*=*element*.style.left

**Remarks**

The **Left** attribute is similar to the standard HTML **Left** attribute for styles.

Units may be mapped to the parent element or may be in absolute units. This attribute will not be written out for shapes anchored inline.

Values include:



| Value      | Description                                                                                                                                                      |
|------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Auto       | Default position of an element in the flow of the page.                                                                                                          |
| units      | A number with an absolute units designator (cm, mm, in, pt, pc, or px) or a relative units designator (em or ex). If no units are given, pixels (px) is assumed. |
| percentage | Value expressed as a percentage of the parent object's width.                                                                                                    |



 

*VML Standard Attribute*

**See Also**

[Units](msdn-online-vml-units.md)

**Example**

The left value of the shape is set to 1 in the example below.


```HTML
   <v:rect id=myrect fillcolor="red"
   style="position:relative;top:1;left:1;width:20;height:20">
   </v:rect>
```



[Left Attribute Example](https://samples.msdn.microsoft.com/workshop/samples/vml/shape/examples/x_left.md). (Requires Microsoft Internet Explorer 5 or greater.)

 

 
