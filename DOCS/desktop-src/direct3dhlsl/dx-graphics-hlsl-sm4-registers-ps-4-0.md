---
title: Registers - ps_4_0
description: This section contains reference information for the input and output registers implemented by pixel shader version 4\_0.
ms.assetid: 8b83667f-f599-4105-b68c-0d6aa7c528ab
ms.topic: reference
ms.date: 05/31/2018
topic_type: 
- kbArticle
api_name: 
api_type: 
api_location: 
---

# Registers - ps\_4\_0

This section contains reference information for the input and output registers implemented by pixel shader version 4\_0.

## Input Registers



| Register      | Name | Count              | R/W | Dimension | Indexable by r\# | Defaults | Requires DCL |
|---------------|------|--------------------|-----|-----------|------------------|----------|--------------|
| r\#           |      | 4096(r\#+x\#\[n\]) | R/W | 4         | No               | None     | Yes          |
| x\#\[n\]      |      | 4096(r\#+x\#\[n\]) | R/W | 4         | Yes              | None     | Yes          |
| v\#           |      | 32                 | R   | 4         | Yes              | None     | Yes          |
| t\#           |      | 128                | R   | 1         | No               | None     | Yes          |
| s\#           |      | 16                 | R   | 1         | No               | None     | Yes          |
| cb\#\[index\] |      | 15                 | R   | 4         | Yes(Contents)    | None     | Yes          |
| icb\[index\]  |      | 1                  | R   | 4         | Yes(Contents)    | None     | Yes          |



 

## Output Registers



| Register | Name            | Count | R/W | Dimension | Indexable by r\# | Defaults | Requires DCL |
|----------|-----------------|-------|-----|-----------|------------------|----------|--------------|
| NULL     | Discard Result  | N/A   | W   | N/A       | N/A              | N/A      | No           |
| o\#      | Output Register | 8     | W   | N/A       | N/A              | 4        | No           |
| oDepth   | Output Depth    | 1     | W   | N/A       | N/A              | 1        | N/A          |



 

## Related topics

<dl> <dt>

[Shader Model 4](dx-graphics-hlsl-sm4.md)
</dt> </dl>

 

 




