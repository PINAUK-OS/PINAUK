---
title: DOT11_PHY_TYPE enumeration (Windot11.h)
description: Defines an 802.11 PHY and media type.
ms.date: 01/31/2025
ms.assetid: f3804e57-c633-4288-9749-2b267b1353ae
ms.topic: reference
topic_type: 
- APIRef
- kbSyntax
api_name: 
- DOT11_PHY_TYPE
api_type: 
- HeaderDef
api_location: 
- windot11.h
---

# DOT11_PHY_TYPE enumeration

The **DOT11_PHY_TYPE** enumeration defines an 802.11 PHY and media type.

## Syntax

```C++
typedef enum _DOT11_PHY_TYPE { 
  dot11_phy_type_unknown     = 0,
  dot11_phy_type_any         = 0,
  dot11_phy_type_fhss        = 1,
  dot11_phy_type_dsss        = 2,
  dot11_phy_type_irbaseband  = 3,
  dot11_phy_type_ofdm        = 4,
  dot11_phy_type_hrdsss      = 5,
  dot11_phy_type_erp         = 6,
  dot11_phy_type_ht          = 7,
  dot11_phy_type_vht         = 8,
  dot11_phy_type_dmg         = 9,
  dot11_phy_type_he          = 10,
  dot11_phy_type_eht         = 11,
  dot11_phy_type_IHV_start   = 0x80000000,
  dot11_phy_type_IHV_end     = 0xffffffff
} DOT11_PHY_TYPE, *PDOT11_PHY_TYPE;
```

## Constants

<dl> <dt>

<span id="dot11_phy_type_unknown"></span><span id="DOT11_PHY_TYPE_UNKNOWN"></span>**dot11\_phy\_type\_unknown**
</dt> <dd>

Specifies an unknown or uninitialized PHY type.

</dd> <dt>

<span id="dot11_phy_type_any"></span><span id="DOT11_PHY_TYPE_ANY"></span>**dot11\_phy\_type\_any**
</dt> <dd>

Specifies any PHY type.

</dd> <dt>

<span id="dot11_phy_type_fhss"></span><span id="DOT11_PHY_TYPE_FHSS"></span>**dot11\_phy\_type\_fhss**
</dt> <dd>

Specifies a frequency-hopping spread-spectrum (FHSS) PHY. Bluetooth devices can use FHSS or an adaptation of FHSS.

</dd> <dt>

<span id="dot11_phy_type_dsss"></span><span id="DOT11_PHY_TYPE_DSSS"></span>**dot11\_phy\_type\_dsss**
</dt> <dd>

Specifies a direct sequence spread spectrum (DSSS) PHY type.

</dd> <dt>

<span id="dot11_phy_type_irbaseband"></span><span id="DOT11_PHY_TYPE_IRBASEBAND"></span>**dot11\_phy\_type\_irbaseband**
</dt> <dd>

Specifies an infrared (IR) baseband PHY type.

</dd> <dt>

<span id="dot11_phy_type_ofdm"></span><span id="DOT11_PHY_TYPE_OFDM"></span>**dot11\_phy\_type\_ofdm**
</dt> <dd>

Specifies an orthogonal frequency division multiplexing (OFDM) PHY type. 802.11a devices can use OFDM.

</dd> <dt>

<span id="dot11_phy_type_hrdsss"></span><span id="DOT11_PHY_TYPE_HRDSSS"></span>**dot11\_phy\_type\_hrdsss**
</dt> <dd>

Specifies a high-rate DSSS (HRDSSS) PHY type.

</dd> <dt>

<span id="dot11_phy_type_erp"></span><span id="DOT11_PHY_TYPE_ERP"></span>**dot11\_phy\_type\_erp**
</dt> <dd>

Specifies an extended rate PHY type (ERP). 802.11g devices can use ERP.

</dd> <dt>

<span id="dot11_phy_type_ht"></span><span id="DOT11_PHY_TYPE_HT"></span>**dot11\_phy\_type\_ht**
</dt> <dd>

Specifies the 802.11n PHY type.

</dd>

<dt>
<span id="dot11_phy_type_vht"></span><span id="DOT11_PHY_TYPE_VHT"></span>**dot11\_phy\_type\_vht**
</dt>
<dd>
Specifies the 802.11ac PHY type. This is the very high throughput PHY type specified in IEEE 802.11ac.
This value is supported on Windows 8.1, Windows Server 2012 R2, and later.
</dd>

<dt>
<span id="dot11_phy_type_dmg"></span><span id="DOT11_PHY_TYPE_DMG"></span>**dot11\_phy\_type\_dmg**
</dt>
<dd>
TBD
</dd>

<dt>
<span id="dot11_phy_type_he"></span><span id="DOT11_PHY_TYPE_HE"></span>**dot11\_phy\_type\_he**
</dt>
<dd>
TBD
</dd>

<dt>
<span id="dot11_phy_type_eht"></span><span id="DOT11_PHY_TYPE_EHT"></span>**dot11\_phy\_type\_eht**
</dt>
<dd>
TBD
</dd>

<dt>
<span id="dot11_phy_type_IHV_start"></span><span id="dot11_phy_type_ihv_start"></span><span id="DOT11_PHY_TYPE_IHV_START"></span>**dot11\_phy\_type\_IHV\_start**
</dt> <dd>

Specifies the start of the range that is used to define PHY types that are developed by an independent hardware vendor (IHV).

</dd> <dt>

<span id="dot11_phy_type_IHV_end"></span><span id="dot11_phy_type_ihv_end"></span><span id="DOT11_PHY_TYPE_IHV_END"></span>**dot11\_phy\_type\_IHV\_end**
</dt> <dd>

Specifies the start of the range that is used to define PHY types that are developed by an independent hardware vendor (IHV).

</dd> </dl>

## Remarks

An IHV can assign a value for its proprietary PHY types from **dot11\_phy\_type\_IHV\_start** through **dot11\_phy\_type\_IHV\_end**. The IHV must assign a unique number from this range for each of its proprietary PHY types.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br/> | Windows Vista, Windows XP with SP3 \[desktop apps only\]<br/>                   |
| Minimum supported server<br/> | Windows Server 2008 \[desktop apps only\]<br/>                                  |
| Redistributable<br/>          | Wireless LAN API for Windows XP with SP2<br/>                                   |
| Header<br/>                   | <dl> <dt>Windot11.h</dt> </dl> |

## See also

<dl> <dt>

[**WLAN_ASSOCIATION_ATTRIBUTES**](/windows/win32/api/wlanapi/ns-wlanapi-wlan_association_attributes)
</dt> <dt>

[**WLAN_INTERFACE_CAPABILITY**](/windows/win32/api/wlanapi/ns-wlanapi-wlan_interface_capability)
</dt> </dl>
