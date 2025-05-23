---
title: Meters
description: Meters
ms.assetid: 11a98d2a-7cdd-4249-bba9-7edc51d7f8b0
keywords:
- audio mixers,controls
- audio mixers,meters
- mixers,controls
- mixers,meters
- meter controls
- MIXERCONTROLDETAILS_BOOLEAN structure
- MIXERCONTROLDETAILS_SIGNED structure
- MIXERCONTROLDETAILS_UNSIGNED structure
- Boolean control
- peak control
- signed control
- unsigned control
ms.topic: reference
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Meters

\[The feature associated with this page, [Audio Mixers](/windows/win32/multimedia/audio-mixers), is a legacy feature. It has been superseded by [Volume Controls](/windows/win32/coreaudio/volume-controls). **Volume Controls** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Volume Controls** instead of **Audio Mixers**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The meter controls measure data passing through an audio line. These controls use the [**MIXERCONTROLDETAILS\_BOOLEAN**](/previous-versions//dd757295(v=vs.85)), [**MIXERCONTROLDETAILS\_SIGNED**](/previous-versions//dd757297(v=vs.85)), and [**MIXERCONTROLDETAILS\_UNSIGNED**](/previous-versions//dd757298(v=vs.85)) structures to retrieve and set control properties. The following table describes the types of meters.



| Control  | Description                                                                                                                                            |
|----------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| Boolean  | Measures whether an integer value is FALSE/OFF (zero) or TRUE/ON (nonzero).                                                                            |
| Peak     | Measures the deflection from 0 in both the positive and negative directions. The range of integer values for the peak meter is –32,768 through 32,767. |
| Signed   | Measures integer values in the range of –231 through (231 – 1). The mixer driver defines the limits of this meter.                                     |
| Unsigned | Measures integer values in the range of 0 through (232 – 1). The mixer driver defines the limits of this meter.                                        |



 

 

 
