---
title: IAgentBalloonEx SetStyle
description: IAgentBalloonEx SetStyle
ms.assetid: 5be569b7-8a2d-437b-b5db-401af343bc78
ms.topic: reference
ms.date: 05/31/2018
---

# IAgentBalloonEx::SetStyle

\[Microsoft Agent is deprecated as of Windows 7, and may be unavailable in subsequent versions of Windows.\]

``` syntax
HRESULT SetStyle(
   long lStyle,  // style settings
);
```

Retrieves the character's word balloon style settings.

-   Returns S\_OK to indicate the operation was successful.

<dl> <dt>

<span id="lStyle"></span><span id="lstyle"></span><span id="LSTYLE"></span>*lStyle*
</dt> <dd>

Style settings for the word balloon, which can be a combination of any of the following values:



| Value                                                                            | Description                                                 |
|----------------------------------------------------------------------------------|-------------------------------------------------------------|
| **const unsigned short** **BALLOON\_STYLE\_BALLOONON = 0x00000001;**<br/>  | The balloon is supported for output.                        |
| **const unsigned short** **BALLOON\_STYLE \_SIZETOTEXT = 0x0000002;**<br/> | The balloon height is sized to accommodate the text output. |
| **const unsigned short** **BALLOON\_STYLE \_AUTOHIDE = 0x00000004;**<br/>  | The balloon is automatically hidden.                        |
| **const unsigned short** **BALLOON\_STYLE \_AUTOPACE = 0x00000008;**<br/>  | The text output is paced based on the output rate.          |



 

</dd> </dl>

When the **BalloonOn** style bit is set, the word balloon appears when the [**Speak**](speak-method.md) or [**Think**](think-method.md) method is used, unless the user overrides its display in the Microsoft Agent property sheet. When not set, no balloon appears.

When the **SizeToText** style bit is set, the word balloon automatically sizes the height of the balloon to the current size of the text specified in the [**Speak**](speak-method.md) or [**Think**](think-method.md) method. When not set, the balloon's height is based on the balloon's number of lines property setting. This style bit is set to 1 and an attempt to use [**IAgentBalloonEx::SetNumLines**](iagentballoonex--setnumlines.md) will result in an error.

When the **AutoHide** style bit is set, the word balloon automatically hides after a short timeout. When not set, the balloon displays until a new [**Speak**](speak-method.md) or [**Think**](think-method.md) call, the character is hidden, or the user clicks or drags the character.

When the **AutoPace** style bit is set, the word balloon paces the output based on the current output rate, for example, one word at a time. When output exceeds the size of the balloon, the former text is automatically scrolled. When not set, all text included in a [**Speak**](speak-method.md) or [**Think**](think-method.md) statement displays at once.

The Balloon's style property can be set even if the user has disabled display of the Balloon using the Microsoft Agent property sheet.

This property applies only to your client application's use of the character; the setting does not affect other clients of the character or other characters of your client application.

The defaults for these style bits are based on their settings when the character is compiled with the Microsoft Agent Character Editor.

## See Also

[**IAgentBalloonEx::GetStyle**](iagentballoonex--getstyle.md)


 

 





