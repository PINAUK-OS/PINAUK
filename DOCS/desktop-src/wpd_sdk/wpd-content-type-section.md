---
description: WPD\_CONTENT\_TYPE\_SECTION
ms.assetid: 8680a74b-9594-4271-a511-637f617aa12a
title: WPD_CONTENT_TYPE_SECTION
ms.topic: reference
ms.date: 05/31/2018
---

# WPD\_CONTENT\_TYPE\_SECTION

An object that describes its type as WPD\_CONTENT\_TYPE\_SECTION represents a section of data that is contained in another object. For example, a large audio file can be described as a collection of multiple chapters, and each chapter might be a WPD\_CONTENT\_TYPE\_SECTION object.

The WPD\_OBJECT\_REFERENCES property identifies a given section's parent object.

This type of object supports the following properties.



| Property Name       | Required or Optional             |
|----------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| [WPD\_OBJECT\_ID](object-properties.md)                                                                           | Required.                                                             |
| [WPD\_OBJECT\_PARENT\_ID](object-properties.md)                                                            | Required.                                                             |
| [WPD\_OBJECT\_NAME](object-properties.md)                                                                       | Required if the object represents a file.                             |
| [WPD\_OBJECT\_PERSISTENT\_UNIQUE\_ID](object-properties.md)                                     | Required.                                                             |
| [WPD\_OBJECT\_FORMAT](object-properties.md)                                                                   | Required.                                                             |
| [WPD\_OBJECT\_CONTENT\_TYPE](object-properties.md)                                                      | Required.                                                             |
| [WPD\_OBJECT\_ISHIDDEN](object-properties.md)                                                               | Required if the object is hidden.                                     |
| [WPD\_OBJECT\_ISSYSTEM](object-properties.md)                                                               | Required if the object is a system object (represents a system file). |
| [WPD\_OBJECT\_SIZE](object-properties.md)                                                                       | Required if the object has at least one resource.                     |
| [WPD\_OBJECT\_ORIGINAL\_FILE\_NAME](object-properties.md)                                         | Required if the object represents a file.                             |
| [WPD\_OBJECT\_NON\_CONSUMABLE](object-properties.md)                                                  | Recommended if the object is not meant for consumption by the device. |
| [WPD\_OBJECT\_REFERENCES](object-properties.md)                                                           | Required if the object has references to other objects.               |
| [WPD\_OBJECT\_KEYWORDS](object-properties.md)                                                               | Optional.                                                             |
| [WPD\_OBJECT\_SYNC\_ID](object-properties.md)                                                                | Optional.                                                             |
| [WPD\_OBJECT\_IS\_DRM\_PROTECTED](object-properties.md)                                             | Required if the object is protected by DRM technology.                |
| [WPD\_OBJECT\_DATE\_CREATED](object-properties.md)                                                      | Optional.                                                             |
| [WPD\_OBJECT\_DATE\_MODIFIED](object-properties.md)                                                    | Recommended.                                                          |
| [WPD\_OBJECT\_DATE\_AUTHORED](object-properties.md)                                                    | Optional.                                                             |
| [WPD\_OBJECT\_BACK\_REFERENCES](object-properties.md)                                                | Recommended if the object has references to other objects.            |
| [WPD\_OBJECT\_CONTAINER\_FUNCTIONAL\_OBJECT\_ID](object-properties.md)                | Optional.                                                             |
| [WPD\_OBJECT\_GENERATE\_THUMBNAIL\_FROM\_RESOURCE](object-properties.md)            | Optional.                                                             |
| [WPD\_OBJECT\_CAN\_DELETE](object-properties.md)                                                          | Required if the object cannot be deleted.                             |
| [WPD\_OBJECT\_LANGUAGE\_LOCALE](object-properties.md)                                                                           | Optional.                                                             |
| [WPD\_SECTION\_DATA\_OFFSET](section-attribute-properties.md)                                           | Required.                                                             |
| [WPD\_SECTION\_DATA\_LENGTH](section-attribute-properties.md)                                           | Required.                                                             |
| [WPD\_SECTION\_DATA\_UNITS](section-attribute-properties.md)                                             | Recommended.                                                          |
| [WPD\_SECTION\_DATA\_REFERENCED\_OBJECT\_RESOURCE](section-attribute-properties.md) | Recommended.                                                          |



 

## Typical Resources

These objects typically do not host resources.

## Related topics

<dl> <dt>

[**Requirements for Objects**](requirements-for-objects.md)
</dt> </dl>

 

 



